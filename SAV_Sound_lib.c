// Sound Library by My3ukaHT (Andrew)
/*
F_TIM_CLK = 1 MHz
Note	  		Timer CNT Preload
соль4	g4		319
соль4#	g4is	301
ля4		a4		284
ля4#	a4s		268
си4		h4		253
до5		c5		239
до5#	c5is	225
ре5		d5		213
ре5#	d5is	201
ми5		e5		190
фа5		f5		179
фа5#	f5is	169
соль5	g5		159
соль5#	g5is	150
ля5		a5		142
ля5#	a5s		134
си5		h5		127

*
Немного теории:
Далее, для добавления к ноте бемоля к её названию приписывают -es (например, Ces — до-бемоль), а для добавления диеза — -is (соответственно -eses и -isis для дубль-бемоля и дубль-диеза). Исключения в названиях: Aes = As, Ees = Es, а также Нes = B
*/

#include "main.h"
#include "SAV_Sound_lib.h"
// For Sound Buzzer
//extern uint16_t Sound_Freq_Hz;// = 4000;
extern volatile uint32_t PERIOD_VALUE;// = (uint32_t)(TIM1_Freq_Hz/Sound_Freq_Hz - 1);//Period
extern volatile uint32_t PULSE1_VALUE;// = (uint32_t)(PERIOD_VALUE/2);//Capture Compare 1 Value (PWM, Volume)
extern TIM_HandleTypeDef htim1;


void Play_Sound_Note (uint16_t Sound_Freq_Hz, uint8_t Note_PWM, uint16_t Note_delay_ms)
{
	PERIOD_VALUE = (uint32_t)(TIM1_Freq_Hz / Sound_Freq_Hz - 1);//Period
	if ((Note_PWM >= 1) && (Note_PWM <= 100))
	{
		PULSE1_VALUE = (uint32_t)(PERIOD_VALUE * (Note_PWM / 100.0));//Capture Compare 1 Value (PWM, Volume)
	}
	//
	 MX_TIM1_Init();
	 HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	 HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	 HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_SET);
	 HAL_Delay(Note_delay_ms);
	 HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_RESET);
	 HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
	 HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
}

void Play_Sound_Note_FADE_IN (uint16_t Sound_Freq_Hz, uint16_t Note_delay_ms)
{
	PERIOD_VALUE = (uint32_t)(TIM1_Freq_Hz / Sound_Freq_Hz - 1);//Period
	for (uint8_t i=0; i < 50; i++)
	{
		PULSE1_VALUE = (uint32_t)(PERIOD_VALUE * (i / 100.0));//Capture Compare 1 Value (PWM, Volume)
		//
		MX_TIM1_Init();
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
		HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_SET);
		HAL_Delay(Note_delay_ms/50);
		HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_RESET);
		HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
	}
}

void Play_Sound_Note_FADE_OUT (uint16_t Sound_Freq_Hz, uint16_t Note_delay_ms)
{
	PERIOD_VALUE = (uint32_t)(TIM1_Freq_Hz / Sound_Freq_Hz - 1);//Period
	for (uint8_t i=50; i > 0; i--)
	{
		PULSE1_VALUE = (uint32_t)(PERIOD_VALUE * (i / 100.0));//Capture Compare 1 Value (PWM, Volume)
		//
		MX_TIM1_Init();
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
		HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_SET);
		HAL_Delay(Note_delay_ms/50);
		HAL_GPIO_WritePin(LD3_Green_GPIO_Port, LD3_Green_Pin, GPIO_PIN_RESET);
		HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
	}
}

void Melody1 (void)
{
	/*
	#define g4	3136
	#define g4is	3322.4
	#define a4	3520
	#define a4s	3729.3
	#define h4	3951.1
	#define c5	4186
	#define c5is	4434.9
	#define d5	4698.6
	#define d5is	4978
	#define e5	5274
	#define f5	5587.7
	#define f5is	5919.9
	#define g5	6271.9
	#define g5is	6644.9
	#define a5	7040
	#define a5is	7458.6
	#define h5	7902.1
	 */
	Play_Sound_Note(c5,50,500);
	HAL_Delay(200);
	Play_Sound_Note(g4,50,200);
	Play_Sound_Note(c5,50,500);
	HAL_Delay(200);
	Play_Sound_Note(g4,50,200);
	Play_Sound_Note(c5,50,200);
	Play_Sound_Note(g4,50,200);
	Play_Sound_Note(c5,50,200);
	Play_Sound_Note(e5,50,200);
	Play_Sound_Note(g5,50,200);
	HAL_Delay(200);

}
