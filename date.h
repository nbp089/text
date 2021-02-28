
////////////////////////////宏定义硬件对应关系/////////////////////
#define A_DUOJI 0
#define B_DUOJI 1
#define C_DUOJI 2
#define D_DUOJI 3
#define E_DUOJI 4
#define F_DUOJI 5
#define Jian		0	//肩膀
#define XiBi 		1	//小臂
#define Shou		2	//手

#define POSEgeshu		128			//pose个数
#define ZHITIgeshu		6			//肢体个数
#define GUANJIEgeshu	3			//关节个数



#define Duoji_Hao				0			//舵机编号
#define Duoji_Jizhun			1			//基准
#define Jiaod_Low				2			//最小值
#define Jiaod_Large				3			//最大值
#define Jiaod_WeiTiao			4			//微调

#define Pose_Chushi		0			//pose编号
#define Pose_Stand		1			//pose编号






//分配肢体数组空间
int ***ZhiTi(int geshu);

//
void Load_base();

//
void Load_pose();



