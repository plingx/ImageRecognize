#include "widget.h"
#include "ui_widget.h"
#include "ocr.h"
#include <highgui.h>
#include <cv.h>
#include <QTimer>
#include <QDesktopWidget>
#include <QStyle>
#include <QRect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QDesktopWidget *deskTopWidget = QApplication::desktop();
//    QRect deskRect = deskTopWidget->availableGeometry();
//    int appH = deskRect.height();
//    int appW = deskRect.width();
//    this->setFixedSize(appW, appH);
//    setGeometry(0, 0, appW, appH);

    InitCamara();

    connect(&timer,SIGNAL(timeout()),this,SLOT(ReadFrame()));
}

void Widget::InitCamara()
{
    //打开摄像头
    //这句代码的意思是打开 video4，括号中的參数仅仅要有:
    // 0 , -1, 202 但要依据你自己的情况改,实測 204 可以成功打开
    camera = cvCreateCameraCapture(204);

    timer.start(50); //启动定时器，1000 为 1S ，50 为 50ms，超时则发出 timeoout 信号
}


// 设置 APPID/AK/SK
std::string app_id = "26512942";
std::string api_key = "YDYmOUefkA3KLCzIiSdEIdwy";
std::string secret_key = "LIGQnn6qTodYKnPvag5Yz7mgmBeS6X7N";
aip::Ocr client(app_id, api_key, secret_key);


std::string GetPlateNumber(std::string PicturePath)
{
    //我们只要把我们用摄像头拍的照片传到下面的这个函数就可以了
    //aip::get_file_content("/assets/sample.jpg", &image)
    Json::Value result;

    std::string image;
    aip::get_file_content(PicturePath.c_str(), &image);

    // 调用车牌识别
    result = client.license_plate(image, aip::null);

    // 如果有可选参数
    std::map<std::string, std::string> options;
    options["multi_detect"] = "true";

    // 带参数调用车牌识别
    result = client.license_plate(image, options);

    if(result["error_code"].isNull())
    {
        return (result["words_result"][0]["number"].asString() + ",欢迎光临.");
    }
    else
    {
        return ("识别失败");
    }

    return ("识别失败");
}



Widget::~Widget()
{
    delete ui;
}


void Widget::ReadFrame()
{
    //从摄像头读取一张图片
    //这个函数 cvQueryFrame 作用是从摄像头或者文件中抓取一帧
    //参数为视频获取结构也就是我在初始化摄像头声明的 CvCapture *camera;
    frame = cvQueryFrame(camera);

    //将图片格式转换成 QImage 格式，否则不能在 lable 上显示
    imag = QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888).rgbSwapped();//用 label 显示一张图片

    ui->frame->setPixmap(QPixmap::fromImage(imag));
}

void Widget::on_identifyBt_clicked()
{
    std::string PlateNumber ;
    // int Ret;

    frame = cvQueryFrame(camera);

    //将图片格式转换成 QImage 格式，否则不能再 lable 上显示
    imag = QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888).rgbSwapped();

    //用 label 显示一张图片
    ui->picture->setPixmap(QPixmap::fromImage(imag));

    //保存图片到本地
    imag.save("./PlateNumber.jpg", "JPG", 100);

    //把拍下来的照片传递给百度 AI 接口获取车牌号
    PlateNumber = GetPlateNumber("./PlateNumber.jpg");

    //把接口返回来的数据显示到屏幕上
    ui->recve->setText(QString::fromStdString(PlateNumber));

}
