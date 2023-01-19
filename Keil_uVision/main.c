#include "stm32f10x.h"

int main(){
	RCC-> APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC-> APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	//GPIOA-> CRL &= ~((1<<16) | (1<<17) );
	//GPIOA-> CRL |= ((0<<18) | (1<<19) );
	GPIOA->CRH &= ~(GPIO_CRH_MODE8);
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRL |= GPIO_CRL_MODE0;
	GPIOA->CRL &= (~GPIO_CRL_CNF0);

	while(1){
		if(GPIO_IDR_IDR8 && 0x00000001){
//		if(GPIOA->IDR & 1){
			GPIOA ->BSRR |= GPIO_BSRR_BS0;
		}
		
		else
			GPIOA ->BSRR |= (1<<(16));

	}
		
}

