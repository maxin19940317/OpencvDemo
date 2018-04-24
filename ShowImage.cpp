#include <opencv2/opencv.hpp>
using namespace cv;

int main(void)
{
	Mat mat = imread("/home/maxin/Pictures/cat.jpg");
	imshow("cat", mat);
	waitKey(0);
	return 0;
}
