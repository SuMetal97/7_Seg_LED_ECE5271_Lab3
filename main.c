#include <MKL25Z4.h>
#include <stdio.h>
#include <stdlib.h>

//Define the ports for each output to the 7 Seg LED (Port A)
#define Seg_A (1)
#define Seg_B (2)
#define Seg_C (12)
#define Seg_D (4)
#define Seg_E (5)
#define Seg_F (13)
#define Seg_G (16)

/*Define enable, is not needed for control, but is to turn the 7 Seg on
This can have a switch in to control on/off features but is not needed 
for this example*/ 

#define Enable (17) //Port A

//Define the Switches that will be controling the 7 Seg output (Port D)
#define SW_1 (5)
#define SW_2 (0)
#define SW_3 (2)
#define SW_4 (3)

#define MASK(x) (1UL << (x))
void Initialize(void);
int check_switches(void);


int check_switches(void){
	int Switch_Total = 0;
	if(PTA->PDIR & MASK(SW_1)){
	}else{
		Switch_Total +=1;
	}
	if(PTA->PDIR & MASK(SW_2)){
	}else{
		Switch_Total +=2;
	}
	if(PTA->PDIR & MASK(SW_3)){
	}else{
		Switch_Total +=4;
	}
	if(PTA->PDIR & MASK(SW_4)){
	}else{
		Switch_Total +=8;
	}
	return Switch_Total;
}

void Initialize(void){
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTA->PCR[Seg_A]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_A] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_B]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_B] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_C]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_C] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_D]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_D] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_E]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_E] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_F]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_F] |= PORT_PCR_MUX(1);
	PORTA->PCR[Seg_G]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Seg_G] |= PORT_PCR_MUX(1);
	PORTA->PCR[Enable]  &= ~PORT_PCR_MUX_MASK;
	PORTA->PCR[Enable] |= PORT_PCR_MUX(1);

	PORTD->PCR[SW_1]  &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SW_1] |= PORT_PCR_MUX(1);
	PORTD->PCR[SW_2]  &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SW_2] |= PORT_PCR_MUX(1);
	PORTD->PCR[SW_3]  &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SW_3] |= PORT_PCR_MUX(1);
	PORTD->PCR[SW_4]  &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SW_4] |= PORT_PCR_MUX(1);

	PTA->PDDR |= MASK(Seg_A) | MASK(Seg_B) | MASK(Seg_C) | MASK(Seg_D) | MASK(Seg_E) | MASK(Seg_F) | MASK(Seg_G) | MASK(Enable);
	PTD->PDDR &= ~MASK(SW_1);
	PTD->PDDR &= ~MASK(SW_2);
	PTD->PDDR &= ~MASK(SW_3);
	PTD->PDDR &= ~MASK(SW_4);
}

int main(void){
	int Switch_count;
	while (1){
		Switch_count = 0;
		Switch_count = check_switches();
		switch (Switch_count){
			case 0:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PSOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PCOR = MASK(Seg_G);
				break;
			case 1:
				PTA->PCOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PCOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PCOR = MASK(Seg_F);
				PTA->PCOR = MASK(Seg_G);
				break;
			case 2:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PCOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PSOR = MASK(Seg_E);
				PTA->PCOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
			case 3:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PCOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
			case 4:
				PTA->PCOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PCOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
			case 5:
				PTA->PSOR = MASK(Seg_A);
				PTA->PCOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
			case 6:
				PTA->PSOR = MASK(Seg_A);
				PTA->PCOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PSOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PCOR = MASK(Seg_G);
				break;
			case 7:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PCOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PCOR = MASK(Seg_F);
				PTA->PCOR = MASK(Seg_G);
				break;
			case 8:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PSOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
			case 9:
				PTA->PSOR = MASK(Seg_A);
				PTA->PSOR = MASK(Seg_B);
				PTA->PSOR = MASK(Seg_C);
				PTA->PSOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PSOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
				break;
				
			default:
				PTA->PCOR = MASK(Seg_A);
				PTA->PCOR = MASK(Seg_B);
				PTA->PCOR = MASK(Seg_C);
				PTA->PCOR = MASK(Seg_D);
				PTA->PCOR = MASK(Seg_E);
				PTA->PCOR = MASK(Seg_F);
				PTA->PSOR = MASK(Seg_G);
		
		}
	
	}



}
