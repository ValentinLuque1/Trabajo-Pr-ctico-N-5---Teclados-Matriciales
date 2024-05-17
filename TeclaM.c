#include "mkl25z4.h"
#include "TeclaM.h"
#include <ctype.h>

#define columnas 4
#define filas 4

int Columnas [columnas] = {1,2,3,4};
int Filas  [filas] = {5,6,7,8};

char TecladoM[filas][columnas] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8,','9','C'},
{'*','0','#','D'}
};

void Pines(char puertos){
char Puertos = toupper(puertos);
switch(puertos)
{
    case 'A':
    SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
    for(int i = 0; i < Filas; i++){
        PORTA->PCR[Filas[i]]|=PORT_PCR_MUX(1);
        PTA->PSOR|=(1<<Filas[i]);
        }
    for(int i = 0; i < Columnas; i++){
        PORTA -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        }
        break;
   
    case 'B':
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;
    for(int i = 0; i < Filas; i++){
        PORTB->PCR[Filas[i]]|=PORT_PCR_MUX(1);
        PTB->PSOR|=(1<<Filas[i]);
        }
    for(int i = 0; i < Columnas; i++){
        PORTB -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        }
   
    case 'C':
    SIM->SCGC5|=SIM_SCGC5_PORTC_MASK;
    for(int i = 0; i < Filas; i++){
        PORTC->PCR[Filas[i]]|=PORT_PCR_MUX(1);
        PTC->PSOR|=(1<<Filas[i]);
        }
    for(int i = 0; i < Columnas; i++){
        PORTC -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        }
        break;

    case 'D':
    SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
    for(int i = 0; i < Filas; i++){
        PORTD->PCR[Filas[i]]|=PORT_PCR_MUX(1);
        PTD->PSOR|=(1<<Filas[i]);
        }
    for(int i = 0; i < Columnas; i++){
        PORTD -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        }
        break;
    
    case 'E':
    SIM->SCGC5|=SIM_SCGC5_PORTE_MASK;
    for(int i = 0; i < Filas; i++){
        PORTE->PCR[Filas[i]]|=PORT_PCR_MUX(1);
        PTE->PSOR|=(1<<Filas[i]);
        }
    for(int i = 0; i < Columnas; i++){
        PORTE -> PCR[Columnas[i]]|=PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
        }
        break;
}
}

char ObtenerTecla(char puertos){

char Puertos = toupper(puertos);

switch(puertos)
{
    case'A':

    for(int i = 0; i < Filas; i++)
    {
        PTA->PSOR|=(0<<Filas[i]);
        for(int c = 0; i < Columnas; i++){
            int estCol= PTA->PDIR&(1<<Columnas[c]);
            if(estCol == 0){
                return TecladoM[i][c];
            }
        }
        PTA->PSOR|=(0<<Filas[i]);
    }
    break;

    case'B':

    for(int i = 0; i < Filas; i++)
    {
        PTB->PSOR|=(0<<Filas[i]);
        for(int c = 0; i < Columnas; i++){
            int estCol= PTB->PDIR&(1<<Columnas[c]);
            if(estCol == 0){
                return TecladoM[i][c];
            }
        }
        PTB->PSOR|=(0<<Filas[i]);
    }
    break;

    case'C':

    for(int i = 0; i < Filas; i++)
    {
        PTC->PSOR|=(0<<Filas[i]);
        for(int c = 0; i < Columnas; i++){
            int estCol= PTC->PDIR&(1<<Columnas[c]);
            if(estCol == 0){
                return TecladoM[i][c];
            }
        }
        PTC->PSOR|=(0<<Filas[i]);
    }
    break;

    case'D':

    for(int i = 0; i < Filas; i++)
    {
        PTD->PSOR|=(0<<Filas[i]);
        for(int c = 0; i < Columnas; i++){
            int estCol= PTD->PDIR&(1<<Columnas[c]);
            if(estCol == 0){
                return TecladoM[i][c];
            }
        }
        PTD->PSOR|=(0<<Filas[i]);
    }
    break;

    case'E':

    for(int i = 0; i < Filas; i++)
    {
        PTE->PSOR|=(0<<Filas[i]);
        for(int c = 0; i < Columnas; i++){
            int estCol= PTE->PDIR&(1<<Columnas[c]);
            if(estCol == 0){
                return TecladoM[i][c];
            }
        }
        PTE->PSOR|=(0<<Filas[i]);
    }
    break;
}
}