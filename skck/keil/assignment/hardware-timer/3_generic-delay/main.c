// RCC_AHBIENR = 0x40023800 + 0x30 = 0x40023830 
// GPIOB_MODER = 0x40020400 + 0x00 = 0x40020400
// GPIOB_ODR   = 0x40020400 + 0x14 = 0x40020414
// STK_CTRL    = 0xE000E010 + 0x00 = 0xE000E010
// STK_LOAD    = 0xE000E010 + 0x04 = 0xE000E014
// STK_VAL     = 0xE000E010 + 0x08 = 0xE000E018

#define RCC_AHBIENR  (*(int *)0x40023830)
#define GPIOB_MODER  (*(int *)0x40020400)
#define GPIOB_ODR    (*(int *)0x40020414)
#define STK_CTRL     (*(int *)0xE000E010)
#define STK_LOAD     (*(int *)0xE000E014)
#define STK_VAL      (*(int *)0xE000E018)	
	
void sk_us(int a);
void sk_ms(int a);

int main()
{
	RCC_AHBIENR |= 0x02;          // set clock to 1 for GPIOB
	while(!(RCC_AHBIENR & 0x2));  // checking for clock set or not 
	GPIOB_MODER |= 0x14000000;    // set port to output mode
	STK_CTRL |= 0x7;
	GPIOB_ODR |= 0x3<<13;
	STK_VAL = 0x1;
	sk_ms(1000);
// sk_us(100);

	while(1)
	{
		GPIOB_ODR ^= (0x1<<14);
		while(!(STK_CTRL & 0x1<<16));
	}
	return 0;
}

void sk_ms(int a)
	{
		STK_LOAD = 16000*a;
	}
	
void sk_us(int a)
	{
		STK_LOAD = 16*a;
	}
	
void SysTick_Handler(void)
{
		GPIOB_ODR ^= (0x1<<13);      // LED set to OFF
}
