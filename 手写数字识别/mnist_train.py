import  torch
from    torch import nn
from    torch.nn import functional as F
from    torch import optim

import  torchvision
from torchvision import transforms  # pytorch 视觉库中提供了一些数据变换的接口
from torchvision import datasets  # pytorch 视觉库提供了加载数据集的接口
from    matplotlib import pyplot as plt

from    utils import plot_image, plot_curve, one_hot

BATCH_SIZE = 64 # 一次处理图片的数量
EPOCH = 15 # 迭代次数
LEARNING_RATE = 0.005 # 学习率

# 加载数据集
train_loader = torch.utils.data.DataLoader( # 训练数据
    datasets.MNIST('data', train=True, download=True, # train决定下载的图片60k训练，10k测试 | download决定如果当前文件没有'data'就从网上去下载
                   transform=transforms.Compose([ # 下载下来的文件是numpy格式
                       transforms.ToTensor(), # 将其转化为tensor
                       transforms.Normalize(mean=(0.1307,), std=(0.3081,))  # 使数据在0附近均匀分布
                   ])),
    batch_size=BATCH_SIZE, shuffle=True)  # shuffle为True指明在数据加载的时候要做随机打散

test_loader = torch.utils.data.DataLoader(# 测试数据
    datasets.MNIST('data', train=False, download=True,
                    transform=transforms.Compose([
                        transforms.ToTensor(),
                        transforms.Normalize((0.1307,), (0.3081,))
    ])),
    batch_size=BATCH_SIZE, shuffle=False)

# x, y = next(iter(train_loader))
# print(x.shape, y.shape, x.min(), x.max())
# plot_image(x, y, 'sample')


# 构建神经网络
# class Net(nn.Module):

#     def __init__(self):
#         super(Net, self).__init__()

#         # 线性层 xw+b
#         self.fc1 = nn.Linear(28*28, 256)
#         self.fc2 = nn.Linear(256, 64)
#         self.fc3 = nn.Linear(64, 10)# 十分类需要十个输出节点

#     def forward(self, x):
#         # x: [b, 1, 28, 28]
#         # h1 = relu(xw1+b1)
#         x = F.relu(self.fc1(x))
#         # h2 = relu(hiw2+b2)
#         x = F.relu(self.fc2(x))
#         # h3 = h2w3+b3  第三层加不加激活函数取决于具体任务
#         x = self.fc3(x)

#         return x

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Sequential(nn.Conv2d(1, 6, 3, 1, 2), nn.ReLU(),
                                   nn.MaxPool2d(2, 2))
        self.conv2 = nn.Sequential(nn.Conv2d(6, 16, 5), nn.ReLU(),
                                   nn.MaxPool2d(2, 2))
        self.fc1 = nn.Sequential(nn.Linear(16 * 5 * 5, 120),
                                 nn.BatchNorm1d(120), nn.ReLU())
        self.fc2 = nn.Sequential(nn.Linear(120, 84), nn.BatchNorm1d(84),
                                 nn.ReLU(), nn.Linear(84, 10))

    def forward(self, x):
        x = self.conv1(x)
        x = self.conv2(x)
        x = x.view(x.size()[0], -1)
        x = self.fc1(x)
        x = self.fc2(x)
        return x


net = Net()# 创建网络对象 初始化
optimizer = optim.SGD(net.parameters(), lr=LEARNING_RATE, momentum=0.9)#梯度下降优化器 返回[w1,b1,w2,b2,w3,b3]

train_loss = []

# 训练
for epoch in range(EPOCH):# 对此数据集迭代EPOCH次
    #net.train()
    for batch_idx, (x, y) in enumerate(train_loader):# 完成这个循环对整个数据集迭代一遍

        # x: [b, 1, 28, 28], y: [512]
        # 将[b, 1, 28, 28]打平成[b,784]
        #x = x.view(x.size(0), 28*28)
        # ->[b, 10]
        out = net(x)# 全连接层 只能接收[b,feature]
        # [b, 10] 
        y_onehot = one_hot(y)
        # 计算均方差
        loss = F.mse_loss(out, y_onehot)

        optimizer.zero_grad()# 清零梯度
        loss.backward()# 计算梯度
        # w' = w - lr*grad 
        optimizer.step()# 更新梯度 完成w和b的更新

        train_loss.append(loss.item())

        if batch_idx % 100 == 99:
            print(epoch+1, ":  ", batch_idx+1, "   loss: ", loss.item())


    # 测试
    net.eval()
    total_correct = 0
    for x,y in test_loader:
        # x = x.view(x.size(0), -1)# 打平
        out = net(x)# 得到神经网络输出: [b,10]
        pred = out.argmax(dim=1)# 得到预测值
        correct = pred.eq(y).sum().float().item()
        total_correct += correct# 总的正确预测数量

    total_num = len(test_loader.dataset)# 数据总数
    acc = total_correct / total_num # 正确率
    print("The acc is", acc)

plot_curve(train_loss)# 显示训练过程Loss下降折线图


