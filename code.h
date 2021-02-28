/////////////////////////////宏定义通讯协议////////////////////////
#define HUANCUN_SIZE 128			//协议最大长度
#define XIEYI_Head 	0x55            //协议 帧头
#define XIEYI_Order 0x03            //协议 指令序号


struct learn {

	char temp0;		//低八位
	char temp1;		//高八位
};


int Moshi();


//循环模式输入
void Loop_Hunhuan();





