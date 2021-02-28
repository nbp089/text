
#include <stdio.h>
			//malloc
#include <stdlib.h>
#include <string.h>

			//read,write,close
#include <unistd.h>	


#include <fcntl.h>




#include "code.h"
#include "date.h"



int fd;
int ***base,***pose;				//定义指针指向数据
int aerfa[ZHITIgeshu][GUANJIEgeshu];							//当前数据
struct List *plist;					//定义指针指向链表




int main()
{
	
	
	
	//判断写入对象
	fd = Moshi();										//i为0 写入usb0端口,为1写入1.txt

	
	
	//初始化数据
	base=ZhiTi(5);			//创建base缓存					创建5个基本数据
	Load_base();		//载入base数据

	//载入动作数据
	pose=ZhiTi(POSEgeshu);	//创建pose缓存
	Load_pose();		//载入pose数据



	
	Loop_Hunhuan();		//进入循环

				


	//free数据
	//关闭文件
	close(fd);
	
	return 0;

}
