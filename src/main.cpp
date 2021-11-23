#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace cv;
int main(){
    std::string main_url = "rtsp://admin:wst123456@192.168.66.64:554/h264/ch1/main/av_stream?tcp" ;
    cv::VideoCapture cap_;
    int i=0;
    cap_.open(main_url);
    
    if (cap_.isOpened()){
        cv::Mat img;
        for (;;){
            if (cap_.read(img)){
                stringstream ss;
                ss<<"./img/"<<i<<"test.jpg";
                imwrite(ss.str(),img);
                i++ ;
                std::cout<<"i:"<<i<<" img path:"<<ss.str()<<std::endl;
            }
        }
         

    }
    return 1 ;
}