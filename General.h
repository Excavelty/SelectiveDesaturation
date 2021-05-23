#pragma once
#include <array>
#include <algorithm>


//Funkcja wyznaczaj¹ca k¹t na kole kolorów
int checkAngleOnColorWheel(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj¹ca Hue, korzysta z powy¿szej
int calculateHue(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj¹ca saturacjê
int calculateSaturation(unsigned char &r, unsigned char &g, unsigned char &b);
//Funkcja wyliczaj¹ca jaskrawoœæ
int calculateLighteness(unsigned char &r, unsigned char &g, unsigned char &b);
//Min, max, œrednia wartoœæ
int findMin(unsigned char &r, unsigned char &g, unsigned char &b);
int findMax(unsigned char &r, unsigned char &g, unsigned char &b);
int findMid(unsigned char &r, unsigned char &g, unsigned char &b);
//Wyznaczenie mediany z wartoœci
int calculateMedian(std::array<unsigned char, 9> &matrix);
//Czêœciowa saturacja
void partlyDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter);
//Przejœciowa saturacja
void blurDesaturation(unsigned char &r, unsigned char &g, unsigned char &b, int &max, int &saturationParameter, int &blurParameter, int &delta);
