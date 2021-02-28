//move模式ACE	BDF交替运行
//计算个角度,运行并保存入pose值(学习)
//赐于物理意义步幅	旋转值 

////肢长度:82.3	手臂长:52.9	肩膀长:27.74
#define Lenth_Jian 2.774		//肩膀长度			(单位:cm)
#define Lenth_XiBi 5.29			//小臂长度			(单位:cm)
#define Lenth_Shou 8.23			//小腿长度			(单位:cm)




#define pi 3.141592653
#define bufa 45			//步伐范围(单位:度)
#define bufu 5			//步伐精度(单位:度)
#define zhuanfu 5		//转动精度(单位:度)
#define high 10			//抬腿高度(单位:度)

#define m_kuandu	3.9		//AF舵机轴心距离的一半(单位:cm)
#define n_changdu 6.74	//AC舵机轴心距离的一半(单位:cm)











void pose_zuobiao();

void aerfa_move();













/**/




