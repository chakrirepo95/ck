// RCC_AHBIENR = 0x40023800 + 0x30 = 0x40023830 
// GPIOB_MODER = 0x40020400 + 0x00 = 0x40020400
// GPIOB_ODR   = 0x40020400 + 0x14 = 0x40020414

#define RCC_AHBIENR  (*(int *)0x40023830)
#define GPIOB_MODER  (*(int *)0x40020400)
#define GPIOB_ODR    (*(int *)0x40020414)
void delay(int);
int main()
{
	RCC_AHBIENR |= 0x02;          // set clock to 1 for GPIOB
	while(!(RCC_AHBIENR & 0x2));  // checking for clock set or not 
	GPIOB_MODER |= 0x04000000;    // set port to output mode
	while(1)
	{
		GPIOB_ODR &= ~(0x1<<13);     // LED set to ON
		delay(50);
		GPIOB_ODR |= (0x1<<13);      // LED set to OFF
		delay(1300);
	}
	return 0;
}

void delay(int a)
{
	int i;
	for(i=4000*a;i>0;i--);
}
