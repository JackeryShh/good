#include <iostream>
#include "SOIL/SOIL.h"


class LoadTexture{

public:
	LoadTexture(const char* path);
	~LoadTexture();
	unsigned char* Load_Image();
public:
	const char* image_path;//ͼƬ��·��
	int *width;
	int *height;
	unsigned char* imagedata;

};
