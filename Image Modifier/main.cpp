#include "./include/Bitmap.h"

int main() {
	Bitmap image1;
	
	image1.path = "./sample/image1.bmp";
	image1.readData();

	image1.swapRedAndBlueChannel("./sample/image1_Red_Blue_swapped.bmp");
	image1.onlyRedChannel("./sample/image1_Only_Red.bmp");
	image1.onlyGreenChannel("./sample/image1_Only_Green.bmp");
	image1.onlyBlueChannel("./sample/image1_Only_Blue.bmp");

	std::cout << "Please find all the files in sample folder";
}