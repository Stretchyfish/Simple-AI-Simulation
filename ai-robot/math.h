#pragma once

double pi = 3.1415926535f;

float normalize(float min, float max, float current)
{
	return (current - min)/(max - min);
}

float deg2rad(float degree)
{
	return degree * pi / 180;
}
