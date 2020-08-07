#include "StdAfx.h"
#include "Global.h"

int GetImageEncoderClsid(const WCHAR* format, CLSID* pClsid)
{  
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes
	ImageCodecInfo* pImageCodecInfo = NULL;
	
	//2.��ȡGDI+֧�ֵ�ͼ���ʽ�������������Լ�ImageCodecInfo����Ĵ�Ŵ�С
	GetImageEncodersSize(&num, &size);
	if (size == 0) return -1;  // Failure
	
	//3.ΪImageCodecInfo����������ռ� 
	pImageCodecInfo = (ImageCodecInfo*)malloc(size); //size = num * sizeof(ImageCodeInfo)
	if (pImageCodecInfo == NULL) return -1;  // Failure
	
	//4.��ȡ���е�ͼ���������Ϣ
	GetImageEncoders(num, size, pImageCodecInfo);
	
	//5.���ҷ��ϵ�ͼ���������Clsid
	for (UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}
	
	//6.�ͷŲ���3������ڴ�
	free(pImageCodecInfo);
	return -1;  // Failure
}
