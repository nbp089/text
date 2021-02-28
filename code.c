#include <stdio.h>
#include <stdlib.h>
			//read,write,close
#include <unistd.h>	
			//O_RDWR ,O_CREAT
#include <fcntl.h>	


#include "code.h"
#include "date.h"
#include "key.h"

#include "move.h"



//extern  
unsigned char buffer[HUANCUN_SIZE]="\0";		//协议传递内存数组





extern int fd;
extern int ***base,***pose;				//定义指针指向数据
extern int aerfa[ZHITIgeshu][GUANJIEgeshu];							//当前数据

int loop_pose=1;			//循环赋值
int loop_step=1;			//循环赋值

int pose_num=1; 	//动作组初始化
int forward	=1;		//前进
int turn	=1;		//转向


int Moshi()
{
	int i;
	i=1;		//i为0 写入usb0端口,为1写入1.txt
	
	switch (i)
		{
					//打开文件(open);
		case 0 :fd= open("/dev/ttyUSB0",O_RDWR);
			break;
		case 1 :fd= open("/home/samba/robot/m_robot_m_robot_1.0/1.txt",O_RDWR|O_CREAT);
			break;
		default :printf("模式i赋值错误\n");
		}
	return fd;
}



//步骤一: 赋予初始pose

void aerfa_read_pose(int num)
{
	int i,j;
	for(i=0;i<ZHITIgeshu;i++)
		{
			for(j=0;j<GUANJIEgeshu;j++)
				{
					aerfa[i][j]	=	pose[num][i][j];
				}
		}


}




//步骤二:读取键盘信息

void key_callback(void *obj, int key, int type)
{
/*
	if(key==17)		//w
		{
			forward = 1;
		}
	
	else if(key==31)	//s
		{
			forward = -1;
		}

	else if(key==30)	//a
		{
			turn = -1;
		}
	else if(key==32)	//d
		{
			turn = 1;
		}
	/////////姿态////////////
	else if(key==2) 		//1
		{
	
			pose_num	=0;
			loop_step	=0;
			sleep(0.1);
			loop_step	=1;

		}

	else if(key==3) 		//2
		{
			pose_num	=1;
			loop_step	=0;
			sleep(0.1);
			loop_step	=1;

		}

	else if(key==4)			//3
		{
			pose_num	=2;
			loop_step	=0;
			sleep(0.1);
			loop_step	=1;
		}
	else if(key==5)			//4
		{

			pose_num	=3;
			loop_step	=0;
			sleep(0.1);
			loop_step	=1;

		}

	/////////退出////////////
	else if(key==1)			//esc
		{
			loop_pose	=0;
			loop_step	=0;
		}
   printf("key/%d type/%d\r\n", key, type);
   */
}



//步骤三:aerfa move移动
//参见move.c


					
//步骤四: 加入base数据
void aerfa_read_base(int i,int j)
{
	//int Xiugai_jiaodu(struct Node *pnode,int ***base,int i,int j)

	

	switch(i)
		{
			case A_DUOJI:
				{
					switch(j)
						{	
							case Jian:
								{									
									aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
									break;
								}
							case XiBi:
								{
									aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
									break;
								}
							case Shou:
								{
									aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
									break;
								}
								
							default:				
								printf("关节输入失败 关节:%d\n",j);
								break;
						
						}
					break;
				}
			
			case B_DUOJI:
				
			{
				switch(j)
					{
						case Jian:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
						case XiBi:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
						case Shou:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
							
						default:				
							printf("关节输入失败 关节:%d\n",j);
							break;
					
					}
				break;
			}

			case C_DUOJI:
				
			{
				switch(j)
					{
						case Jian:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
						case XiBi:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case Shou:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
							
						default:				
							printf("关节输入失败 关节:%d\n",j);
							break;
					
					}
				break;
			}
				
			
			case D_DUOJI:
				
			{
				switch(j)
					{
						case Jian:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case XiBi:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
						case Shou:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
							
						default:				
							printf("关节输入失败 关节:%d\n",j);
							break;
					
					}
				break;
			}

			case E_DUOJI:
				
			{
				switch(j)
					{
						case Jian:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case XiBi:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case Shou:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
							
						default:				
							printf("关节输入失败 关节:%d\n",j);
							break;
					
					}
				break;
			}

			case F_DUOJI:
				
			{
				switch(j)
					{
						case Jian:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case XiBi:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]-aerfa[i][j];
								break;
							}
						case Shou:
							{
								aerfa[i][j]=base[Duoji_Jizhun][i][j]+base[Jiaod_WeiTiao][i][j]+aerfa[i][j];
								break;
							}
							
						default:				
							printf("关节输入失败 关节:%d\n",j);
							break;
					
					}
				break;
			}
				
			default:				
				printf("肢体输入失败 肢体:%d\n",i);
				break;
		}





}

					
//步骤五: 转换为真实数据700到2500
void aerfa_change_ture(int i,int j)
{
	int jiao;
	aerfa[i][j] = aerfa[i][j]*10+700;

	jiao = aerfa[i][j];
	if(jiao>2300||jiao<700)
			{
				printf("角度超出舵机范围\n");
				printf("角度=%d\t范围700到2300\n",jiao);
				loop_step = 0;
			}
}


//步骤六: 转换为十六进制
struct learn aerfa_hex(int i)
{


//转换int类型转换hex值										范围待改进////////////////////////////////////////////////////////////////////////////////////

	struct learn hex;
	int yushu,shang;

	
	if(i<65535&&i>=0)
		{
			yushu=i%256;
			shang=i/256;
			
			hex.temp0=yushu;
			hex.temp1=shang;	
		}
	else	
		printf("角度范围出错:%d\n",i);

	return hex;
}




					
//步骤七: 写入控制器
void aerfa_write(int i,int j)
{
			struct learn change;
			int k,p,lenth,jiao,bianhao;
			int num = GUANJIEgeshu*ZHITIgeshu;

			int number ;
			int shijian;
			
			lenth =num*3+5;
			
			buffer[0]=0x55;
			buffer[1]=0x55;
		change=aerfa_hex(lenth);
			buffer[2]=change.temp0;
			if(change.temp1!=0) 		loop_step = 0;
			buffer[3]=XIEYI_Order;
		change=aerfa_hex(num);
			buffer[4]=change.temp0;
			if(change.temp1!=0) 		loop_step = 0;
		change=aerfa_hex(shijian);
			buffer[5]=change.temp0;
			buffer[6]=change.temp1; 










			
			
		for(p=0;p<num;p++)
			{
					k=7+3*p;
					bianhao=base[Duoji_Hao][i][j];\
					change	=aerfa_hex(bianhao);//
				buffer[j]	=change.temp0;
					jiao =aerfa[i][j];
					change	=aerfa_hex(jiao);
				buffer[j+1]=change.temp0;
				buffer[j+2]=change.temp1;
			}
			
		write(fd,buffer,lenth+2);




}




//输出

void aerfa_change_output()
{


		int i,j;
			for(i=0;i<ZHITIgeshu;i++)
				{
					for(j=0;j<GUANJIEgeshu;j++)
						{	
						
								//判断范围


								//步骤四: 加入base数据
								aerfa_read_base(i,j);

								//步骤五: 转换为真实数据700到2500
								aerfa_change_ture(i,j);
								
								//步骤七: 写入控制器
								aerfa_write(i,j);
						
						}
				}

}





//循环		//遇到错误,无输入, 不改变链表,不写入重复信息,保持上一个状态
void Loop_Hunhuan()
{

	int shijian=2000;	//时间初始化
	
	



	//key_register(NULL, &key_callback);

	//while(1)			//赋予初始pose开始循环
	//	{

					//步骤一: 赋予初始pose
			aerfa_read_pose(pose_num);
					//坐标初始化
			pose_zuobiao();
			
			//循环动作
	//		while(1)
	//			{

					if(forward!=0 ||turn !=0)
						{
							//步骤三: aerfa move移动
							aerfa_move();
					
							//输出
							aerfa_change_output();
						}
	//			}	
	//	}




}





