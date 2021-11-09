#include <MKL25Z4.h>
#include <stdio.h>
#include <stdlib.h>

//Define the ports for each output to the 7 Seg LED (Port A)
#define Seg_A (1)
#define Seg_B (2)
#define Seg_C (3)
#define Seg_D (4)
#define Seg_E (5)
#define Seg_F (6)
#define Seg_G (7)

/*Define enable, is not needed for control, but is to turn the 7 Seg on
This can have a switch in to control on/off features but is not needed 
for this example*/ 

#define Enable (12) //Port A

//Define the Switches that will be controling the 7 Seg output (Port D)
#define SW_1 (1)
#define SW_2 (2)
#define SW_3 (3)
#define SW_4 (4)

#define MASK(x) (1UL << (x))
void Initialize(void);

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
	int Switch_Total = 0;
	
	
	while (1){
		Switch_Total(Switch_Total){
		
			default:
				PTA->PCOR = MASK(Seg_A);
		
		}
	
	}



}
