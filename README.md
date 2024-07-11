# LPRNet_rknn_Cplusplus
车牌识别 LPRNet : License Plate Recognition via Deep Neural Networks 部署rk3588，C++实现。


## 编译和运行

1）编译

```
cd examples/rknn_LicenseRec_LPRNet

bash build-linux_RK3588.sh

```

2）运行

```
cd install/rknn_LPRNet_LicenseRec_demo_Linux

./rknn_LPRNet_LicenseRec_demo

```

注意：修改模型、测试图像、保存图像的路径，修改文件为src下的main.cc

```C++

int main(int argc, char **argv)
{
    char model_path[256] = "/home/firefly/zhangqian/rknn/rknpu2_1.4.0/examples/rknn_LicenseRec_LPRNet/model/RK3588/LPRNet.rknn";
    char image_path[256] = "/home/firefly/zhangqian/rknn/rknpu2_1.4.0/examples/rknn_LicenseRec_LPRNet/test.jpg";
    char save_image_path[256] = "/home/firefly/zhangqian/rknn/rknpu2_1.4.0/examples/rknn_LicenseRec_LPRNet/test_result.jpg";

    detect(model_path, image_path, save_image_path);
    return 0;
}
```

# 板端测试效果

说明：由于中文显示出现乱码，示例代码中用拼英简写对中文进行了规避。

![image](https://github.com/cqu20160901/LPRNet_rknn_Cplusplus/blob/main/examples/rknn_LicenseRec_LPRNet/test_result.jpg)


板端时耗也贴出供参考：模型LPRNet，模型输入分辨率94x24, rk3588芯片。

![image](https://github.com/cqu20160901/LPRNet_rknn_Cplusplus/assets/22290931/c771ae1a-98a2-4e99-bd25-e8f1b37e5e21)

模型这么小在rk3588上推理时耗是比较长的，毫无疑问是模型推理过程中有操作切换到CPU上了。如果对性能要求的比较高，可以针对切换的CPU上的操作进行规避或替换。切换到CPU上操作的部分算子。

![image](https://github.com/cqu20160901/LPRNet_rknn_Cplusplus/assets/22290931/5c4c2fab-235c-40cb-8f5c-8548269333bd)



