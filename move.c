

//在站立pose中ACE BDF交替使肩膀角度匀速扫过一个角度,落脚点向后移动固定距离L,
//过程中落脚点距离肩轴心的x方向距离不变,z方向高度不变,各个舵机角度变化

//过程中小臂和手部的角度不均匀的变化,采取分割法,
	//把L分割为若干个长度,求出划过每一个长度所需要的时间,舵机的角度变化
	//x=肩膀角度,y=小臂角度,z=手角度,随着x的匀速缓慢增加,求z

#include<stdio.h>


#include <math.h>
		//在链接的时候，需要-lm，并且只需要-lm，而不需要指定目录,	具体目录/usr/lib目录名为libm.a的库文件，从而找出需要的数学函数，正确链接
#include "move.h"
#include "date.h"

double zuobiao[ZHITIgeshu][2];							//坐标数据		 0=X  1=Y  2=Z

int zhicheng = 0;		//换脚
int taiqi = 1;		//换脚



extern int forward;		//前进
extern int turn;		//转向

extern int aerfa[ZHITIgeshu][GUANJIEgeshu];				//阿尔法数据




//角度转换为hudu
double jiaodu_hudu(int jiaodu)
{
	double hudu;
	hudu = jiaodu*2*pi/360;

	return hudu;
}

//hudu转换为角度
int hudu_jiaodu(double hudu)
{
	int jiaodu;
	jiaodu = hudu*180/pi ;
						
	return jiaodu;
}


//double   A_hudu,double B_hudu,double C_hudu

//落脚点到轴x方向距离
double  lenth_X(double   A_hudu,double B_hudu,double C_hudu)//参数 3个组舵机的角度,舵机号						
{
	//A为肩膀,B为小臂,C为手
	double  X_Min;

	X_Min=cos(A_hudu)*(Lenth_Jian+Lenth_XiBi*cos(B_hudu)+Lenth_Shou*cos(C_hudu+B_hudu));
	
	return X_Min;
}

//落脚点到轴y方向的距离(前后差为步幅)
double  lenth_Y(double   A_hudu,double B_hudu,double C_hudu)//参数 3个组舵机的角度,舵机号						
{
	//A为肩膀,B为小臂,C为手
	double  Y_bufu;

	Y_bufu=sin(A_hudu)*(Lenth_Jian+Lenth_XiBi*cos(B_hudu)+Lenth_Shou*cos(C_hudu+B_hudu));
	
	return Y_bufu;
}

//落脚点到轴z方向的高度
double  lenth_Z(double B_hudu,double C_hudu)//参数 3个组舵机的角度,舵机号						
{
	//A为肩膀,B为小臂,C为手
	double  Z_gaodu;

	Z_gaodu=Lenth_XiBi*sin(B_hudu)+Lenth_Shou*sin(C_hudu+B_hudu);
	
	return Z_gaodu;
}


//坐标初始化
void pose_zuobiao()
{
	int i;
	double   j_hudu,x_hudu,s_hudu;
	
	for(i=0;i<ZHITIgeshu;i++)
		{
			//int角度转化为hudu
			j_hudu =  jiaodu_hudu(aerfa[i][0]);
			x_hudu =  jiaodu_hudu(aerfa[i][1]);
			s_hudu =  jiaodu_hudu(aerfa[i][2]);
			
			zuobiao[i][0] = lenth_X(j_hudu,x_hudu,s_hudu);
			zuobiao[i][1] = lenth_Y(j_hudu, x_hudu, s_hudu);
			zuobiao[i][2] = lenth_Z(j_hudu, s_hudu);
			
		}
	zhicheng = 0;
	printf("x:%f\t",zuobiao[0][0]);
	printf("y:%f\t",zuobiao[0][1]);
	printf("z:%f\n",zuobiao[0][2]);


}



//换腿
void huantui()
{
			if(aerfa[E_DUOJI][0]-bufu*forward >bufa || aerfa[E_DUOJI][0]-bufu*forward <-bufa)
			{
				if(zhicheng=0)
					{
						zhicheng = 1;
						taiqi = 0;
					}

				if(zhicheng=1)
					{
						zhicheng = 0;
						taiqi = 1;
					}
		}

}

//支撑 抬起
void move_qianjin()	
{
			int i;
			//x,z保持不变,y变化,aerfa1递减
			printf("支撑:%d\n" ,zhicheng);
			printf("aerfa[支撑][0]%d\n",aerfa[zhicheng][0]);
			printf("bufu:%d\n",bufu);

			
			aerfa[zhicheng][0]		=aerfa[zhicheng][0]		-bufu;
			aerfa[zhicheng+2][0]	=aerfa[zhicheng+2][0]	-bufu;
			aerfa[zhicheng+4][0]	=aerfa[zhicheng+4][0]	-bufu;


			aerfa[taiqi][0]		=aerfa[taiqi][0]	+bufu;
			aerfa[taiqi+2][0]	=aerfa[taiqi+2][0]	+bufu;
			aerfa[taiqi+4][0]	=aerfa[taiqi+4][0]	+bufu;

			
			for(i=0;i<ZHITIgeshu;i++)
				{
					zuobiao[i][1] = zuobiao[i][0] * tan(aerfa[i][0]);
				}

}

//转换中心坐标
void zhongxin()
{	
	//X坐标
	zuobiao[A_DUOJI][0] =zuobiao[A_DUOJI][0]	+m_kuandu;
	zuobiao[B_DUOJI][0] =zuobiao[B_DUOJI][0]	+m_kuandu;
	zuobiao[C_DUOJI][0] =zuobiao[C_DUOJI][0]	+m_kuandu;
	
	zuobiao[D_DUOJI][0] =-zuobiao[D_DUOJI][0]	-m_kuandu;
	zuobiao[E_DUOJI][0] =-zuobiao[E_DUOJI][0]	-m_kuandu;
	zuobiao[F_DUOJI][0] =-zuobiao[F_DUOJI][0]	-m_kuandu;

	//Y坐标
	zuobiao[A_DUOJI][1] =zuobiao[A_DUOJI][0]	+n_changdu;
	zuobiao[F_DUOJI][1] =zuobiao[F_DUOJI][0]	+n_changdu;


	zuobiao[D_DUOJI][1] =zuobiao[D_DUOJI][0]	-n_changdu;
	zuobiao[C_DUOJI][1] =zuobiao[C_DUOJI][0]	-n_changdu;

}

//转换为各个肢体轴心的坐标
void un_zhongxin()
{
	//X坐标
		zuobiao[A_DUOJI][0] =zuobiao[A_DUOJI][0]	-m_kuandu;
		zuobiao[B_DUOJI][0] =zuobiao[B_DUOJI][0]	-m_kuandu;
		zuobiao[C_DUOJI][0] =zuobiao[C_DUOJI][0]	-m_kuandu;
		
		zuobiao[D_DUOJI][0] =-zuobiao[D_DUOJI][0]	-m_kuandu;
		zuobiao[E_DUOJI][0] =-zuobiao[E_DUOJI][0]	-m_kuandu;
		zuobiao[F_DUOJI][0] =-zuobiao[F_DUOJI][0]	-m_kuandu;
	
		//Y坐标
		zuobiao[A_DUOJI][1] =zuobiao[A_DUOJI][0]	-n_changdu;
		zuobiao[F_DUOJI][1] =zuobiao[F_DUOJI][0]	-n_changdu;
	
	
		zuobiao[D_DUOJI][1] =zuobiao[D_DUOJI][0]	+n_changdu;
		zuobiao[C_DUOJI][1] =zuobiao[C_DUOJI][0]	+n_changdu;


}

void turn_around()
{
			double turn_step;
			double temp_x,temp_y;
			turn_step = jiaodu_hudu(zhuanfu);
			turn_step = turn_step * turn;
	
			//支撑腿正转	
			temp_x = zuobiao[zhicheng][0];
			temp_y = zuobiao[zhicheng][1];
			zuobiao[zhicheng][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[zhicheng][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
	
			temp_x = zuobiao[zhicheng+2][0];
			temp_y = zuobiao[zhicheng+2][1];
			zuobiao[zhicheng+2][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[zhicheng+2][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
	
	
			temp_x = zuobiao[zhicheng+4][0];
			temp_y = zuobiao[zhicheng+4][1];
			zuobiao[zhicheng+4][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[zhicheng+4][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);

						
			//抬起腿反转
			turn_step = turn_step *(-1);
			temp_x = zuobiao[taiqi][0];
			temp_y = zuobiao[taiqi][1];
			zuobiao[taiqi][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[taiqi][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
	
			temp_x = zuobiao[taiqi+2][0];
			temp_y = zuobiao[taiqi+2][1];
			zuobiao[taiqi+2][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[taiqi+2][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
	
	
			temp_x = zuobiao[taiqi+4][0];
			temp_y = zuobiao[taiqi+4][1];
			zuobiao[taiqi+4][0] = temp_x * cos(turn_step) - temp_y * sin(turn_step);
			zuobiao[taiqi+4][1] = temp_x * cos(turn_step) - temp_y * sin(turn_step);

}


//右转
void move_turn()
{

	
	if(turn!=0)
		{
			zhongxin();		//转换为轴心坐标

			turn_around();		//旋转


			un_zhongxin();		//恢复为各个肢体坐标
		}

}




double new_jiaodu_jian(int m)
{
	double x,y,jian_jiao;

	x = zuobiao[m][0];
	y = zuobiao[m][1];

	jian_jiao = atan(y/x);
	
	return jian_jiao;
}





//坐标还原aerfa值				已知x,y,z

void zhou_aerfa(int m)
{
	int A_jiaodu;
	double z_zuobiao,x_zuobiao;
	double new_A_hudu,new_B_hudu,new_C_hudu;

	double gen;
	double n,p,k;

	z_zuobiao = zuobiao[m][2];

	x_zuobiao = zuobiao[m][0];

	A_jiaodu = aerfa[m][0];
	
	new_A_hudu = jiaodu_hudu(A_jiaodu);
	
	p = x_zuobiao/cos(new_A_hudu)-Lenth_Jian;

 	n = (p*p+z_zuobiao*z_zuobiao-Lenth_XiBi*Lenth_XiBi-Lenth_Shou*Lenth_Shou)/(2*Lenth_XiBi*Lenth_Shou);

	gen = sqrt(z_zuobiao*z_zuobiao+p*p);

	k = (p*p+z_zuobiao*z_zuobiao+Lenth_XiBi*Lenth_XiBi-Lenth_Shou*Lenth_Shou)/(2*Lenth_XiBi*gen);

	new_B_hudu = asin(k) - atan(p/z_zuobiao);
	new_C_hudu = acos(n);

	n = atan(p/z_zuobiao);
	A_jiaodu = hudu_jiaodu(n);
	printf("閪:%d\n",A_jiaodu);


	n = asin(k);
	A_jiaodu = hudu_jiaodu(n);
	printf("guan:%d\n",A_jiaodu);


	aerfa[m][0] = hudu_jiaodu(new_A_hudu);
	aerfa[m][1] = hudu_jiaodu(new_B_hudu);
	aerfa[m][2] = hudu_jiaodu(new_C_hudu);


}

//抬腿
void up_leg()
{
	aerfa[taiqi][1] 	=aerfa[taiqi][1]	-high;
	aerfa[taiqi+2][1]	=aerfa[taiqi+2][1]	-high;
	aerfa[taiqi+4][1]	=aerfa[taiqi+4][1]	-high;

}





//步骤三: aerfa move移动
void aerfa_move()
{
					int i;

					printf("a1:%d\t",aerfa[0][0]);
					printf("b1:%d\t",aerfa[0][1]);
					printf("c1:%d\n",aerfa[0][2]);


					
					printf("x1:%f\t",zuobiao[0][0]);
					printf("y1:%f\t",zuobiao[0][1]);
					printf("z1:%f\n",zuobiao[0][2]);

					huantui();		//换腿判断
					move_qianjin();		//步幅变动							//前进 后退	    	阿尔法变化

					printf("a3:%d\t",aerfa[0][0]);
					printf("b3:%d\t",aerfa[0][1]);
					printf("c3:%d\n",aerfa[0][2]);




					printf("x3:%f\t",zuobiao[0][0]);
					printf("y3:%f\t",zuobiao[0][1]);
					printf("z3:%f\n",zuobiao[0][2]);

					
					forward =0;		//关闭步幅变动开关
				/*
			if(turn!=0)
				{
					move_turn();	//右转								//顺时针为正
					turn =0;		//关闭转向变动开关
				}

			printf("x2:%f\t",zuobiao[0][0]);
			printf("y2:%f\t",zuobiao[0][1]);
			printf("z2:%f\n",zuobiao[0][2]);

*/
			//坐标还原aerfa值				已知x,y,z
			for(i=0;i<ZHITIgeshu;i++)
				{
					zhou_aerfa(i);
				}
			printf("a4:%d\t",aerfa[0][0]);
			printf("b4:%d\t",aerfa[0][1]);
			printf("c4:%d\n",aerfa[0][2]);
			

			//抬腿
			up_leg();


}



