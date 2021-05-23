#pragma once
#include <array>
#include <algorithm>


//Funkcja wyznaczaj�ca k�t na kole kolor�w
int checkAngleOnColorWheel(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj�ca Hue, korzysta z powy�szej
int calculateHue(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj�ca saturacj�
int calculateSaturation(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj�ca jaskrawo��
int calculateLighteness(unsigned char &r, unsigned char &g, unsigned char &b);
//Min, max, �rednia warto��
int findMin(unsigned char &r, unsigned char &g, unsigned char &b);
int findMax(unsigned char &r, unsigned char &g, unsigned char &b);
int findMid(unsigned char &r, unsigned char &g, unsigned char &b);
//Wyznaczenie mediany z warto�ci
int calculateMedian(std::array<unsigned char, 9> &matrix);
//Cz�ciowa saturacja
void partlyDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter);
//Przej�ciowa saturacja
void blurDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter, int &blurParameter, int &delta);
