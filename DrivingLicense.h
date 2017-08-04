//
// Created by Nil on 2017/7/27.
//

#ifndef DRIVERLICENSEIDENTIFY_DRIVERLICENSE_H
#define DRIVERLICENSEIDENTIFY_DRIVERLICENSE_H

#include <iostream>
#include "RedMarkArea.h"

using namespace std;
using namespace cv;


class DrivingLicense
{
protected:
	Mat srcImage;
	Mat showImage;

	RedMarkArea *redMarkArea;
	Rect redArea;
	float ANGLE;

	Mat topSideArea;
	Mat upperSideArea;
	Rect upperSideRect;
	Mat upSideArea;
	Rect upSideRect;
	Mat rightSideArea;
	Mat downSideArea;

	// 图像处理参数
	static const int DEFAULT_MORPH_SIZE_WIDTH = 15;  // 11
	static const int DEFAULT_MORPH_SIZE_HEIGHT = 7;  // 7

	// 系数比例
	const float TOP_RATIO = 1;
	const float UPPER_RATIO = 0.5;

	const float UP_WIDH_RATIO = 4;
	const float UP_HEIGHT_RATIO = 0.57;  // 0.85

	const float RIGHT_WIDTH_RATIO = 2.05;

	const float DOWN_WIDTH_RATIO = 3.05;
	const float DOWN_HEIGHT_RATIO = 0.27;


public:
	DrivingLicense(Mat srcImage);

	Mat getRightSideArea(Rect redArea, float ratio);
	Mat getDownSideArea(Rect redArea, float widthRatio, float heightRatio);
	Mat getUpSideArea(Rect redArea, float widthRatio, float heightRatio);
	Mat getUpperSideArea(Rect upSideArea, float ratio);
	Mat getTopSideArea(Rect upperSideArea, float ratio);

	// rotete image
	void rotateImage(Mat src, Mat &img_rotate, float degree);
	Mat locateKeyword(Mat roi, float widthOffsetRatio, float heightOffsetRatio, float widthRatio, float heightRatio);


	void test();
};


#endif //DRIVERLICENSEIDENTIFY_DRIVERLICENSE_H
