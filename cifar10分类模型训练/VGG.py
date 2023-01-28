import  torch
from    torch import nn
import    torch.nn.functional as F
import  torchvision


class VGG(nn.Module):
    def __init__(self, pretrained=True, numClasses=10):
        super(VGG, self).__init__()

        # 100% 还原特征提取层，也就是5层共13个卷积层
        self.layer1 = nn.Sequential(
            nn.Conv2d(3, 64, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(64, 64, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )
        

        self.layer2 = nn.Sequential(
            nn.Conv2d(64, 128, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(128, 128, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )

        self.layer3 = nn.Sequential(
            nn.Conv2d(128, 256, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(256, 256, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(256, 256, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )

        self.layer4 = nn.Sequential(
            nn.Conv2d(256, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(512, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(512, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )

        self.layer5 = nn.Sequential(
            nn.Conv2d(512, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(512, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(512, 512, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(kernel_size=2, stride=2),
        )

        # 从原始的 models.vgg16(pretrained=True) 中预设值参数值。
        if pretrained:
            pretrained_model = torchvision.models.vgg16(pretrained=pretrained)  # 从预训练模型加载VGG16网络参数
            pretrained_params = pretrained_model.state_dict()
            keys = list(pretrained_params.keys())
            new_dict = {}
            for index, key in enumerate(self.state_dict().keys()):
                new_dict[key] = pretrained_params[keys[index]]
            self.load_state_dict(new_dict)

        # 全连接层
        self.classifier = nn.Sequential(  
            # 原始模型vgg16输入image大小是224 x 224
            # cifar10模型输入image大小是32 x 32
            # 大小是小了 7 x 7倍
            nn.Linear(in_features=512 * 1 * 1, out_features=256),  # 自定义网络输入后的大小。
            # nn.Linear(in_features=512 * 7 * 7, out_features=256),  # 原始vgg16的大小是 512 * 7 * 7 ，由VGG16网络决定的，第二个参数为神经元个数可以微调
            nn.ReLU(True),
            nn.Dropout(),
            nn.Linear(in_features=256, out_features=256),
            nn.ReLU(True),
            nn.Dropout(),
            nn.Linear(in_features=256, out_features=numClasses),
        )

    def forward(self, x):   # output: 32 * 32 * 3
        x = self.layer1(x)  # output: 16 * 16 * 64
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)
        x = self.layer5(x)
    
        x = x.view(x.size(0), -1)# 打平
        output = self.classifier(x)# 全连接层
        return output


def main():
    net = VGG()


if __name__ == '__main__':
    main()
