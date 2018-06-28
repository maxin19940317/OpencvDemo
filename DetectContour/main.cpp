/*
 * 检测图片中的闭合区域
 *
 * void findContours(InputOutputArray image,        // 单通道图像矩阵，一般是二值化图像，也可以是膨胀后的图像
 *                  OutputArrayOfArrays contours,   // 每个轮廓保存的点集
 *                  int mode,                       // 轮廓的检索模式有以下四种
 *                                                  // CV_RETR_EXTERNAL     只检测最外围轮廓，包含在外围轮廓内的内围轮廓被忽略
 *                                                  // CV_RETR_LIST         检测所有的轮廓，包括内围、外围轮廓，但是检测到的轮廓不建立等级关系
 *                                                  // CV_RETR_CCOMP        检测所有的轮廓，但所有轮廓只建立两个等级关系
 *                                                  // CV_RETR_TREE         检测所有轮廓，所有轮廓建立一个等级树结构
 *                  int method,                     // 定义轮廓的近似方法
 *                                                  // CV_CHAIN_APPROX_NONE     保存物体边界上所有连续的轮廓点到contours向量内
 *                                                  // CV_CHAIN_APPROX_SIMPLE   仅保存轮廓的拐点信息，把所有轮廓拐点处的点保存入contours
 *                                                                               向量内，拐点与拐点之间直线段上的信息点不予保留
 *                  Point offset=Point());          // Point偏移量，所有的轮廓信息相对于原始图像对应点的偏移量
 */

#include <iostream>
#include <cassert>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // 加载原图
    const string imagePath = "/home/maxin/Code/openCV_Code/检测轮廓/DetectContour/contour.jpeg";
    Mat image = imread(imagePath);
    assert(image.data != nullptr);
    imshow("image", image);

    // 转灰度
    Mat gray(image.size(), CV_8U);
    cvtColor(image, gray, CV_BGR2GRAY);
    imshow("gray", gray);

    // 二值化
    threshold(gray, gray, 145, 255, THRESH_BINARY_INV);
    imshow("binary", gray);

    // 膨胀
    Mat element(5, 5, CV_8U, Scalar(255));
    dilate(gray, gray, element);
    imshow("dilate", gray);

    // 检测边缘
    vector<vector<Point>> contours;
    cv::findContours(gray, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
    Mat result(image.size(), CV_8U, Scalar(255));
    drawContours(result, contours, -1, cv::Scalar(0), 2);

    // 结果图
    imshow("result", result);

    waitKey(0);
    return 0;
}