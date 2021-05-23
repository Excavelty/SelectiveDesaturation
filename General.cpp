#include "General.h"

// Function return the value of the pixel saturation
int calculateSaturation(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int result;
	double s = 0.;
	double min, max;
	min = static_cast<double>(findMin(r, g, b));
	max = static_cast<double>(findMax(r, g, b));
	s = (max - min) / max;
	s = s * 255;

	result = static_cast<int>(s);

	return result;
}

int calculateLighteness(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int min, max, result;
	min = findMin(r, g, b);
	max = findMax(r, g, b);
	result = (max + min) / 2;
	return result;
}

int calculateHue(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int red, green, blue, result, angle, max, min, mid;
	result = 0;
	red = static_cast<int>(r);
	green = static_cast<int>(g);
	blue = static_cast<int>(b);

	angle = checkAngleOnColorWheel(r, g, b);

	max = findMax(r, g, b);
	mid = findMid(r, g, b);
	min = findMin(r, g, b);

	if (max != min) {
		result = static_cast<int>((mid - min) / (max - min) * 60) + angle;
	}
	return result;
}

// Function which calculate the angle of color on the color wheel. It's important for calcualteHue function. 
int checkAngleOnColorWheel(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int min, max, result, tempR, tempG, tempB;
	min = findMin(r, g, b);
	max = findMax(r, g, b);

	tempR = static_cast<int>(r);
	tempG = static_cast<int>(g);
	tempB = static_cast<int>(b);
	//Poni¿sze warunki s¹ zgodnie z informacjami z prezentacji W3
	result = 0;
	if ((tempR == max) && (tempB == min)) {
		result = 0;
	}
	else if ((tempG == max) && (tempB == min)) {
		result = 60;
	}
	else if ((tempG == max) && (tempR == min)) {
		result = 120;
	}
	else if ((tempB == max) && (tempR == min)) {
		result = 180;
	}
	else if ((tempB == max) && (tempG == min)) {
		result = 240;
	}
	else if ((tempR == max) && (tempG == min)) {
		result = 300;
	}
	

	return result;
}

int findMin(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int min;
	int red, green, blue;
	red = static_cast<int>(r);
	green = static_cast<int>(g);
	blue = static_cast<int>(b);
	if (red < green) {
		if (red < blue) {
			min = red;
		}
		else {
			min = blue;
		}
	}
	else {
		if (green < blue) {
			min = green;
		}
		else {
			min = blue;
		}
	}
	return min;
}

int findMid(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int min, mid, max, red, green, blue;
	min = findMin(r, g, b);
	max = findMax(r, g, b);
	red = static_cast<int>(r);
	green = static_cast<int>(g);
	blue = static_cast<int>(b);

	if (red == min) {
		if (green == max) {
			mid = blue;
		}
		else {
			mid = green;
		}
	}
	else if (green == min) {
		if (red == max) {
			mid = blue;
		}
		else {
			mid = red;
		}
	}
	else {
		if (green == max) {
			mid = red;
		}
		else {
			mid = green;
		}
	}

	return mid;
}

int findMax(unsigned char &r, unsigned char &g, unsigned char &b)
{
	int max;
	int red, green, blue;
	red = static_cast<int>(r);
	green = static_cast<int>(g);
	blue = static_cast<int>(b);
	if (red > green) {
		if (red > blue) {
			max = red;
		}
		else {
			max = blue;
		}
	}
	else {
		if (green > blue) {
			max = green;
		}
		else {
			max = blue;
		}
	}
	return max;
}

int calculateMedian(std::array<unsigned char, 9> &matrix) {
	std::sort(matrix.begin(), matrix.end());
	int result = static_cast<int>(matrix[4]);
	return result;
}

void partlyDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter) {

	double deltaR, deltaG, deltaB;
	//Sprawdzamy ró¿nicê miêdzy wartoœci¹ maksymaln¹ a danym pikselem
	deltaR = static_cast<double>(max) - static_cast<double>(r);
	deltaG = static_cast<double>(max) - static_cast<double>(g);
	deltaB = static_cast<double>(max) - static_cast<double>(b);

	//Mno¿ymy dan¹ ró¿nicê przez odpowiedni procent
	deltaR = deltaR * (1.0 - (static_cast<double>(saturationParameter) / 100.0));
	deltaG = deltaG * (1.0 - (static_cast<double>(saturationParameter) / 100.0));
	deltaB = deltaB * (1.0 - (static_cast<double>(saturationParameter) / 100.0));

	//Aktualizujemy przes³ane wartoœci
	r += static_cast<int>(deltaR);
	g += static_cast<int>(deltaG);
	b += static_cast<int>(deltaB);

}

//Podobne do powy¿ej
void blurDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter, int &blurParameter, int &delta) {
	double deltaR, deltaG, deltaB;
	deltaR = static_cast<double>(max) - static_cast<double>(r);
	deltaG = static_cast<double>(max) - static_cast<double>(g);
	deltaB = static_cast<double>(max) - static_cast<double>(b);

	deltaR = deltaR * (1.0 - (static_cast<double>(saturationParameter) / 100.0));
	deltaG = deltaG * (1.0 - (static_cast<double>(saturationParameter) / 100.0));
	deltaB = deltaB * (1.0 - (static_cast<double>(saturationParameter) / 100.0));

	if(deltaR > 0.){
		deltaR = deltaR * (1.0 - (static_cast<double>(delta)) / static_cast<double>(blurParameter));
	}
	if (deltaG > 0.) {
		deltaG = deltaG * (1.0 - (static_cast<double>(delta)) / static_cast<double>(blurParameter));
	}
	if (deltaB > 0.) {
		deltaB = deltaB * (1.0 - (static_cast<double>(delta)) / static_cast<double>(blurParameter));
	}
	r += static_cast<int>(deltaR);
	g += static_cast<int>(deltaG);
	b += static_cast<int>(deltaB);
}

//Wiem, ¿e ten cast na double wygl¹da dziwnie w powy¿szych funkcjach, ale przynajmniej na moim komputerze 
// dzia³ania na int'ach nie dzia³aj¹