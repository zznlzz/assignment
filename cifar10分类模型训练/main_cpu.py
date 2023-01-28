import  torch
from    torch.utils.data import DataLoader
from    torchvision import datasets
from    torchvision import transforms
from    torch import nn, optim
from    Lenet5 import Lenet5
from    AlexNet import AlexNet
from    VGG import VGG
from    utils import plot_image, plot_curve, one_hot

def main():

    BATCH_SIZE = 32
    EPOCH = 20

    cifar_train = datasets.CIFAR10('cifar_data', train=True, transform=transforms.Compose([
        transforms.Resize((32, 32)),
        transforms.ToTensor()
    ]), download=True)
    cifar_train = DataLoader(cifar_train, batch_size=BATCH_SIZE, shuffle=True)

    cifar_test = datasets.CIFAR10('cifar_data', train=False , transform=transforms.Compose([
        transforms.Resize((32, 32)),
        transforms.ToTensor()
    ]), download=True)
    cifar_test = DataLoader(cifar_test, batch_size=BATCH_SIZE, shuffle=False)

    
    # device = torch.device('cuda')# GPU
    # net = Lenet5().to(device)# GPU
    net = VGG()# CPU
    # 分类问题使用CrossEntropyLoss 逼近问题使用MSELoss
    criteon = nn.CrossEntropyLoss()
    optimizer = optim.Adam(net.parameters(), lr=1e-3)

    train_loss = []
    acc_plus = []
    
    for epoch in range(EPOCH):
        net.train()
        for batchidx, (x, label) in enumerate(cifar_train):
            # x = [b, 3, 32, 32], label = [b]
            #x, label = x.to(device), label.to(device)# GPU
            logits = net(x)
            # logits: [b, 10], label: [b]
            loss = criteon(logits, label)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            train_loss.append(loss.item())

        print(epoch, "loss =", loss.item())

        net.eval()
        with torch.no_grad():
            # 测试
            total_correct = 0
            total_num = 0
            for x, label in cifar_test:

                logits = net(x)
                pred = logits.argmax(dim=1)# 一维上数据最大值的索引
                total_correct += pred.eq(label).float().sum().item()
                total_num += x.size(0)

            acc = total_correct / total_num
            print(epoch, "acc =", acc)

            acc_plus.append(acc)


    plot_curve(train_loss)# 显示训练过程Loss下降折线图
    plot_curve(acc_plus)# 显示训练过程acc上升折线图

if __name__ == '__main__':
    main()
