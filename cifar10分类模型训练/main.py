import  torch
from    torch.utils.data import DataLoader
from    torchvision import datasets
from    torchvision import transforms
from    torch import nn, optim
<<<<<<< HEAD
from    lenet5 import Lenet5
=======
from    Lenet5 import Lenet5
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)
from    utils import plot_image, plot_curve, one_hot

def main():

    BATCH_SIZE = 32
<<<<<<< HEAD
=======
    EPOCH = 100
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)

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

    
<<<<<<< HEAD
    #  device = torch.device('cuda')
    #  model = Lenet5().to(device)
    # 分类问题使用CrossEntropyLoss 逼近问题使用MSELoss
    criteon = nn.CrossEntropyLoss()
    net = Lenet5()
=======
    device = torch.device('cuda')# GPU
    net = Lenet5().to(device)# GPU
    #net = Lenet5()# CPU
    # 分类问题使用CrossEntropyLoss 逼近问题使用MSELoss
    criteon = nn.CrossEntropyLoss().to(device)
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)
    optimizer = optim.Adam(net.parameters(), lr=1e-3)

    train_loss = []
    acc_plus = []
    
<<<<<<< HEAD
    for epoch in range(1000):
        net.train()
        for batchidx, (x, label) in enumerate(cifar_train):
            # x = [b, 3, 32, 32], label = [b]
            #x, label = x.to(device), label.to(device)
=======
    for epoch in range(EPOCH):
        net.train()
        for batchidx, (x, label) in enumerate(cifar_train):
            # x = [b, 3, 32, 32], label = [b]
            x, label = x.to(device), label.to(device)# GPU
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)
            logits = net(x)
            # logits: [b, 10], label: [b]
            loss = criteon(logits, label)
            optimizer.zero_grad()
            loss.backward()
            optimizer.step()

            train_loss.append(loss.item())

<<<<<<< HEAD
        print(epoch, loss.item())
=======
        print(epoch, "loss =", loss.item())
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)

        net.eval()
        with torch.no_grad():
            # 测试
            total_correct = 0
            total_num = 0
            for x, label in cifar_test:
<<<<<<< HEAD

=======
                x, label = x.to(device), label.to(device)# GPU
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)
                logits = net(x)
                pred = logits.argmax(dim=1)# 一维上数据最大值的索引
                total_correct += pred.eq(label).float().sum().item()
                total_num += x.size(0)

            acc = total_correct / total_num
<<<<<<< HEAD
            print(epoch, acc)
=======
            print(epoch, "acc =", acc)
>>>>>>> b29facb (yolov7自定义数据集汽 水识别+cifar10新增三种经典卷积)

            acc_plus.append(acc)


    plot_curve(train_loss)# 显示训练过程Loss下降折线图
    plot_curve(acc_plus)# 显示训练过程acc上升折线图

if __name__ == '__main__':
    main()