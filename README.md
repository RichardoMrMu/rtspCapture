# ScreenCapture

## Use
```shell
mkdir build
cmake ..
make 
./test
```

this project tests opencv capture hikvision video stream like :
```shell
rtsp://[username]:[password]@[ip]:[port]/[codec]/[channel]/[subtype]/av_stream
1) username  用户名，常用 admin
2) password  密码，常用 12345
3) ip        摄像头IP，如 192.0.0.64
4) port      端口号，默认为 554，可以不写
5) codec     视频编码模式，有 h264、MPEG-4、mpeg4 等，可以不写
6) channel   通道号，起始为1，例如通道1，则为 ch1
7) subtype   码流类型，主码流为 main，辅码流为 sub
```
this url may meet 
```shell
[h264 @ 0x15e6f60] error while decoding MB 59 31, bytestream (-20)
[h264 @ 0x15e8200] error while decoding MB 61 27, bytestream (-3)
[h264 @ 0x109c880] missing picture in access unit
[h264 @ 0x109c000] no frame!
```
To solve this error
```shell
String url = "rtsp://admin:123456@114.114.114.114/ch1-s1?tcp";
//海康
//"rtsp://admin:123456@114.114.114.114/ch1-s1?tcp"
//大华
//“rtsp://admin:123456@114.114.114.114/cam/realmonitor?channel=1&subtype=1?tcp”
//宇视
//"rtsp://admin:123456@114.114.114.114/video1?tcp"

VideoCapture cap(url);
Mat frame;
cap>>frame;
```
