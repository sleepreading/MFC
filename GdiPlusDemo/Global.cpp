#include "StdAfx.h"
#include "Global.h"

int GetImageEncoderClsid(const WCHAR* format, CLSID* pClsid)
{  
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes
	ImageCodecInfo* pImageCodecInfo = NULL;
	
	//2.获取GDI+支持的图像格式编码器种类数以及ImageCodecInfo数组的存放大小
	GetImageEncodersSize(&num, &size);
	if (size == 0) return -1;  // Failure
	
	//3.为ImageCodecInfo数组分配足额空间 
	pImageCodecInfo = (ImageCodecInfo*)malloc(size); //size = num * sizeof(ImageCodeInfo)
	if (pImageCodecInfo == NULL) return -1;  // Failure
	
	//4.获取所有的图像编码器信息
	GetImageEncoders(num, size, pImageCodecInfo);
	
	//5.查找符合的图像编码器的Clsid
	for (UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}
	
	//6.释放步骤3分配的内存
	free(pImageCodecInfo);
	return -1;  // Failure
}
