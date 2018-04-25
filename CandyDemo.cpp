#include <opencv2/opencv.hpp>
using namespace cv;

const int lowThreshold = 3;
const int ratio = 3;
const kernel_size = 3;	// 设定内核尺寸为3(Canny函数内部调用Sobel操作)

int main(void)
{
	Mat imgSrc = imread("/home/maxin/Pictures/cat.jpg");
	if (imgSrc.data != NULL)
	{
		return -1;
	}
	imshow("imgSrc", imgSrc);

	//将原始图转化为灰度图
	Mat imgGray;
	cvtColor(imgSrc, imgGray, COLOR_BGR2GRAY);

	//先使用3*3内核来降噪
	Mat imgEdge;
	blur(imgGray, imgEdge, Size(3, 3));

	// 运行Canny算子
	Canny(imgEdge, imgEdge, lowThreshold, lowThreshold * ratio, kernel_size);

	// 使用Canny算子输出边缘作为掩码显示原图像
	Mat imgDst = Scalar::all(0);
	imgSrc.copyTo(imgDst, imgEdge);
	imshow("imgDst", imgDst);

	waitKey(0);

	return 0;
}