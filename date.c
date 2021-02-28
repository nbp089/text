#include <stdio.h>
#include <stdlib.h>


#include "date.h"


extern int fd;
extern int ***base,***pose;				//定义指针指向数据



//向前,向下为正方向	旋转角度方向





//分配肢体数组空间

int ***ZhiTi(int geshu)
{

	int ***p;
	int i,j;
	
	p = (int ***)malloc(geshu * sizeof(int **));
	for(i = 0; i < geshu; i++)
	{
		p[i] = (int **)malloc(ZHITIgeshu * sizeof(int *));
		for(j=0;j<ZHITIgeshu;j++)
			{
				p[i][j]=(int *)malloc(GUANJIEgeshu * sizeof(int));
			}
	}
	

	//释放二位数组
	//for(i = 0; i < 20; i++)
	//{
	//	 free(p[i]);
	//}
	//free(p);
	if(p==NULL)
		printf("分配肢体空间失败\n");
	return p;

}




void Load_base()
{

//舵机号
	base[Duoji_Hao][A_DUOJI][Jian]			=	29;
	base[Duoji_Hao][A_DUOJI][XiBi]			=	30;
	base[Duoji_Hao][A_DUOJI][Shou]			=	31;

	base[Duoji_Hao][B_DUOJI][Jian]			=	26;
	base[Duoji_Hao][B_DUOJI][XiBi]			=	27;
	base[Duoji_Hao][B_DUOJI][Shou]			=	28;
	
	base[Duoji_Hao][C_DUOJI][Jian]			=	0;
	base[Duoji_Hao][C_DUOJI][XiBi]			= 	1;
	base[Duoji_Hao][C_DUOJI][Shou]			=	2;
	
	base[Duoji_Hao][D_DUOJI][Jian]			=	7;
	base[Duoji_Hao][D_DUOJI][XiBi]			=	8;
	base[Duoji_Hao][D_DUOJI][Shou]			=	9;
	
	base[Duoji_Hao][E_DUOJI][Jian]			=	4;
	base[Duoji_Hao][E_DUOJI][XiBi]			= 	5;
	base[Duoji_Hao][E_DUOJI][Shou]			=	6;
	
	base[Duoji_Hao][F_DUOJI][Jian]			=	24;
	base[Duoji_Hao][F_DUOJI][XiBi]			=	23;
	base[Duoji_Hao][F_DUOJI][Shou]			=	22;

//舵机基准
	base[Duoji_Jizhun][A_DUOJI][Jian]		=45;
	base[Duoji_Jizhun][A_DUOJI][XiBi]		=120;
	base[Duoji_Jizhun][A_DUOJI][Shou]		=150;
	
	base[Duoji_Jizhun][B_DUOJI][Jian]		=90;
	base[Duoji_Jizhun][B_DUOJI][XiBi]		=120;
	base[Duoji_Jizhun][B_DUOJI][Shou]		=150;
	
	base[Duoji_Jizhun][C_DUOJI][Jian]		=100;
	base[Duoji_Jizhun][C_DUOJI][XiBi]		=40;
	base[Duoji_Jizhun][C_DUOJI][Shou]		=10;
	
	base[Duoji_Jizhun][D_DUOJI][Jian]		=45;
	base[Duoji_Jizhun][D_DUOJI][XiBi]		=120;
	base[Duoji_Jizhun][D_DUOJI][Shou]		=150;
	
	base[Duoji_Jizhun][E_DUOJI][Jian]		=90;
	base[Duoji_Jizhun][E_DUOJI][XiBi]		=40;
	base[Duoji_Jizhun][E_DUOJI][Shou]		=10;
	
	base[Duoji_Jizhun][F_DUOJI][Jian]		=45;
	base[Duoji_Jizhun][F_DUOJI][XiBi]		=40;
	base[Duoji_Jizhun][F_DUOJI][Shou]		=10;

//最小值
	base[Jiaod_Low][A_DUOJI][Jian]		= 0;
	base[Jiaod_Low][A_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][A_DUOJI][Shou]		= 0;
	
	base[Jiaod_Low][B_DUOJI][Jian]		= 45;
	base[Jiaod_Low][B_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][B_DUOJI][Shou]		= 0;
	
	base[Jiaod_Low][C_DUOJI][Jian]		= 0;
	base[Jiaod_Low][C_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][C_DUOJI][Shou]		= 0;
	
	base[Jiaod_Low][D_DUOJI][Jian]		= 0;
	base[Jiaod_Low][D_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][D_DUOJI][Shou]		= 0;
	
	base[Jiaod_Low][E_DUOJI][Jian]		= 45;
	base[Jiaod_Low][E_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][E_DUOJI][Shou]		= 0;
	
	base[Jiaod_Low][F_DUOJI][Jian]		= 0;
	base[Jiaod_Low][F_DUOJI][XiBi]		= 0;
	base[Jiaod_Low][F_DUOJI][Shou]		= 0;
//最大值
	base[Jiaod_Large][A_DUOJI][Jian]		= 145;
	base[Jiaod_Large][A_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][A_DUOJI][Shou]		= 160;
	
	base[Jiaod_Large][B_DUOJI][Jian]		= 135;
	base[Jiaod_Large][B_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][B_DUOJI][Shou]		= 160;
	
	base[Jiaod_Large][C_DUOJI][Jian]		= 145;
	base[Jiaod_Large][C_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][C_DUOJI][Shou]		= 160;
	
	base[Jiaod_Large][D_DUOJI][Jian]		= 145;
	base[Jiaod_Large][D_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][D_DUOJI][Shou]		= 160;
	
	base[Jiaod_Large][E_DUOJI][Jian]		= 135;
	base[Jiaod_Large][E_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][E_DUOJI][Shou]		= 160;
	
	base[Jiaod_Large][F_DUOJI][Jian]		= 145;
	base[Jiaod_Large][F_DUOJI][XiBi]		= 160;
	base[Jiaod_Large][F_DUOJI][Shou]		= 160;

//微调
	base[Jiaod_WeiTiao][A_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][A_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][A_DUOJI][Shou]		=0;
	
	base[Jiaod_WeiTiao][B_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][B_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][B_DUOJI][Shou]		=0;
	
	base[Jiaod_WeiTiao][C_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][C_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][C_DUOJI][Shou]		=0;
	
	base[Jiaod_WeiTiao][D_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][D_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][D_DUOJI][Shou]		=0;
	
	base[Jiaod_WeiTiao][E_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][E_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][E_DUOJI][Shou]		=0;
	
	base[Jiaod_WeiTiao][F_DUOJI][Jian]		=0;
	base[Jiaod_WeiTiao][F_DUOJI][XiBi]		=0;
	base[Jiaod_WeiTiao][F_DUOJI][Shou]		=0;


}

/////////////////////////////////////////////////


void Load_pose()
{
	//初始_旋转值
		pose[Pose_Chushi][A_DUOJI][Jian]		=0;
		pose[Pose_Chushi][A_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][A_DUOJI][Shou]		=0;
		
		pose[Pose_Chushi][B_DUOJI][Jian]		=0;
		pose[Pose_Chushi][B_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][B_DUOJI][Shou]		=0;
		
		pose[Pose_Chushi][C_DUOJI][Jian]		=0;
		pose[Pose_Chushi][C_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][C_DUOJI][Shou]		=0;
		
		pose[Pose_Chushi][D_DUOJI][Jian]		=0;
		pose[Pose_Chushi][D_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][D_DUOJI][Shou]		=0;
		
		pose[Pose_Chushi][E_DUOJI][Jian]		=0;
		pose[Pose_Chushi][E_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][E_DUOJI][Shou]		=0;
		
		pose[Pose_Chushi][F_DUOJI][Jian]		=0;
		pose[Pose_Chushi][F_DUOJI][XiBi]		=0;
		pose[Pose_Chushi][F_DUOJI][Shou]		=0;
	
	//站立 旋转值
		pose[Pose_Stand][A_DUOJI][Jian] 	=40;
		pose[Pose_Stand][A_DUOJI][XiBi] 	=-60;
		pose[Pose_Stand][A_DUOJI][Shou] 	=130;
		
		pose[Pose_Stand][B_DUOJI][Jian] 			=0;
		pose[Pose_Stand][B_DUOJI][XiBi] 			=-60;
		pose[Pose_Stand][B_DUOJI][Shou] 			=130;
		
		pose[Pose_Stand][C_DUOJI][Jian] 					=-40;
		pose[Pose_Stand][C_DUOJI][XiBi] 					=-60;
		pose[Pose_Stand][C_DUOJI][Shou] 					=130;
		
		pose[Pose_Stand][D_DUOJI][Jian] 					=-40;
		pose[Pose_Stand][D_DUOJI][XiBi] 					=-60;
		pose[Pose_Stand][D_DUOJI][Shou] 					=130;
		
		pose[Pose_Stand][E_DUOJI][Jian] 			=0;
		pose[Pose_Stand][E_DUOJI][XiBi] 			=-60;
		pose[Pose_Stand][E_DUOJI][Shou] 			=130;
		
		pose[Pose_Stand][F_DUOJI][Jian] 	=40;
		pose[Pose_Stand][F_DUOJI][XiBi] 	=-60;
		pose[Pose_Stand][F_DUOJI][Shou] 	=130;


}

int Read_base()
{
	return 0;
}



