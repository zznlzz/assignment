import  torch
from    torch import nn
import    torch.nn.functional as F




class Lenet5(nn.Module):

    def __init__(self):
        super(Lenet5, self).__init__()

        self.conv_unit = nn.Sequential(# 两个卷积层
            #x: [b, 3, 32, 32] -> [b, 6, , ]
            nn.Conv2d(3, 6, kernel_size=5, stride=1, padding=0),# stride：卷积核一次移动距离， padding：图片最外侧补0
            nn.AvgPool2d(kernel_size=2, stride=2, padding=0),# 图片大小变为原来一半
            
            nn.Conv2d(6, 16, kernel_size=5, stride=1, padding=0),
            nn.AvgPool2d(kernel_size=2, stride=2, padding=0),
        )
        # 打平
        self.fc_unit = nn.Sequential(# 全连接层
            nn.Linear(16*5*5, 120),# 其中第一个数据需由下面注释代码计算出来
            nn.ReLU(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84,10),
        )


        # #[b, 3, 32, 32]
        # tmp = torch.randn(2, 3, 32, 32)
        # out = self.conv_unit(tmp)
        # #输出[b, 16, 5, 5]
        # print('conv_out',out.shape)

        # # 分类问题使用CrossEntropyLoss 逼近问题使用MSELoss
        # self.criteon = nn.CrossEntropyLoss()
        

    def forward(self, x):

        batch_size = x.size(0)
        # [b, 3, 32, 32] -> [b, 16, 5, 5]
        x = self.conv_unit(x)
        # 打平：[b, 16, 5, 5] -> [b, 16*5*5]
        x = x.view(batch_size, -1)
        # [6, 16*5*5] -> [b,10]
        logits = self.fc_unit(x)

        # loss = self.criteon(logits, y)

        return  logits


def main():
    net = Lenet5()


if __name__ == '__main__':
    main()
