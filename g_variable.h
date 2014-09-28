#ifndef G_VARIABLE_H__
#define G_VARIABLE_H__

#if 0
typedef unsigned   char    u8_t;    /* Unsigned 8 bit quantity         */
typedef signed     char    s8_t;    /* Signed    8 bit quantity        */
typedef unsigned   short   u16_t;   /* Unsigned 16 bit quantity        */
typedef signed     short   s16_t;   /* Signed   16 bit quantity        */
typedef unsigned   long    u32_t;   /* Unsigned 32 bit quantity        */
typedef signed     long    s32_t;   /* Signed   32 bit quantity        */
typedef u32_t mem_ptr_t;            /* Unsigned 32 bit quantity      */


typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef float          fp32;        /*  单精度浮点数（32位长度） */
typedef double         fp64;        /*  双精度浮点数（64位长度） */



typedef	struct CTRL_DSP_t
{
	uint8_t  	type;						// 帧起始
	uint8_t		Addr;
	uint8_t		rw;
    #if 0
    union{
        uint8_t   	cLength[2];
        uint16_t    iLength;
    }Length;
    #endif
    uint8_t   	Length[2];
	uint8_t		DBuf[0];					// 接收数据缓冲区指针
} CTRL_DSP_t;

#define DATA_HEAD_SIZE (sizeof(struct CTRL_DSP_t))

#define FRAME_HEAD   "info of device&"
#define FRAME_HEAD_SIZE (sizeof("info of device&")-1)



/********************************/
/* 激励器模块全部变量 start		*/
/********************************/	
/*	typedef struct 
	{
		float vol;
		float freq[4];
		float mix[4];
		uint32 select;
	}Enhanced_STR; */
/********************************/
/* 激励器模块全部变量 end 		*/
/********************************/
	
typedef struct volstr
{
	fp32 Gain;
	int8_t Pol;
	int8_t Mute;
	int8_t Reserved1;
	int8_t Reserved2;	
} VOL_STR;
#define VOLSIZE  (sizeof(struct volstr))


typedef struct eqstr 
{
	
	fp32  Q;
	fp32  Gain;
	uint16_t Fc; 
	int8_t Type;
	uint8_t En;///En=1开启EQ，En=0，bypassEQ
	
} EQ_STR;

//音调、带通
typedef struct tonestr 
{
	int32_t Fc1;
	int32_t Fc2;
	fp32  Gain;
	fp32  Q; 
	uint8_t Bypass;
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} TONE_STR;

typedef struct dlystr 
{
	fp32  Dly;
	uint8_t Bypass;
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} DLY_STR;

typedef struct hlpfstr 
{
	uint16_t Fc;
	int8_t  Type;
	uint8_t En;
} HLPF_STR;

//带通中音
typedef struct bpfstr 
{
	uint16_t Fp;
	uint16_t Fs;
	int8_t  Type;
	uint8_t En;
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
} BPF_STR;

//动态范围扩展处理【压限
typedef struct drcstr 
{   
//  float T1;
    float T2;
//  float O1;
//  float O2;
//  float k0;
//  float k1;
    float k2;
    float Attack;
	float Release; 
	uint8_t En;
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} DRC_STR;

//用不着
typedef struct _ngc_str 
{   
	float T1;
    float Attack;   			// 
	float Release;               
	uint8_t Bypass; 
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} NGC_STR;

//多进多出
typedef struct mixstr 
{   
    float fVal;
	uint8_t Start;
	uint8_t End;
	uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
} MIX_STR;

//4进1出可用于信号源选择
typedef struct Mix4Ch 
{
    float mix;
	uint8_t in;
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} Mix4Ch_STR;

typedef struct Music3DOp 
{
	DLY_STR *delay;//延时
	Mix4Ch_STR *Mix4ChNo;//3Dmusic 模型中的混音模块操作
	float mix;
    uint8_t Ch;//通道索引Ch={0,1}
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} Music3DOp_STR;

typedef struct M3D
{
	DLY_STR delay;//延时
	Mix4Ch_STR Mix4ChNo;//3Dmusic 模型中的混音模块操作
	float mix;
    uint8_t Ch;//通道索引Ch={0,1}
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
	uint8_t reserved3;  // 数据字节对齐3
} M3D;


//声音补偿
typedef struct SCTOP
{
	HLPF_STR *hpf;
	DRC_STR *AGChp;

	BPF_STR  *bpf;
	DRC_STR *AGCbp;

	HLPF_STR *lpf;
	DRC_STR *AGClp;
    
    //uint8_t en;//使能，en=1,en=0关闭
    uint8_t Ch;//通道索引Ch={0,1}
    uint8_t Type;//高中低的类型，Type ：0--SCTHP,1--SCTBP,2--SCTLP
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
}SCTOP_STR;

typedef struct SCT
{
	HLPF_STR hpf;
	DRC_STR AGChp;

	BPF_STR  bpf;
	DRC_STR AGCbp;

	HLPF_STR lpf;
	DRC_STR AGClp;
    
    //uint8_t en;//使能，en=1,en=0关闭
    uint8_t Ch;//通道索引Ch={0,1}
    uint8_t Type;//高中低的类型，Type ：0--SCTHP,1--SCTBP,2--SCTLP
    uint8_t reserved1;  // 数据字节对齐1
	uint8_t reserved2;  // 数据字节对齐2
}SCT;



//高低通【带通】滤波器类型[Type] 的预定义
#define	BW_06		0x00
#define	BW_12		0x02
#define	BW_18		0x05
#define	BW_24		0x07
#define	BW_36		0x0a
#define	BW_48		0x0d
#define	BL_06		0x01
#define	BL_12		0x03
#define	BL_18		0x06
#define	BL_24		0x08
#define	BL_36		0x0b
#define	BL_48		0x0e	
#define	LK_12		0x04
#define	LK_24		0x09
#define	LK_36		0x0c
#define	LK_48		0x0f




/*命令*/
#define CMD_RESET					0X20		/*重启*/
#define CMD_CONNECT					0X21		/*上位机查看是否和路由断开连接*/
#define	CMD_DSP_INFO				0x22		/*dsp 所有信息*/
#define CMD_SAVE					0X23		/*保存*/
#define CMD_SYS_ON					0X24
#define CMD_DOWNLOADPRESET			0X25
#define CMD_DYNA					0X26
#define CMD_OTHER					0X27
#define CMD_DEVCONNECT				0X28
#define CMD_FS						0X29
#define CMD_LOCK					0X2A


/*功能*/

/*func*/
#define FUNC_VOLUME				0X00		/*音量*/
#define FUNC_DELAY				0X01		/*延迟*/
#define FUNC_HPF				0X02		/*高通*/
#define FUNC_LPF				0X03		/*低通*/
#define FUNC_LIMIT				0X04		/*压限*/
#define FUNC_PEQ				0X05		/*均衡*/
#define FUNC_MIXERS				0X06		/*路由*/
#define FUNC_MIX4CH				0X07        /*路由4进1*/
#define FUNC_MUSIC3DOP          0x08        /*3D*/
#define FUNC_SCTOP              0X09        /*声音补偿*/
#define FUNC_BPF                0X0A        /*带通中音*/
#define FUNC_TONE               0X0B        /*音调*/
#define SIGNALSOURCE            0X0c        /*信号源*/

#define FUNC_NGC                0x0d        /**/




enum{
    CHAIN0,
    CHAIN1
};


#endif 




#endif //G_VARIABLE_H__
