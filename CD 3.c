#include<LiquidCrystal.h>

LiquidCrystal lsd(0,1,2,3,4,5,6,A0,A1,A2,A3)
  
int segA = 0,
segB = 1,
segC = 2,
segD = 3,
segE = 4,
segF = 5,
segG = 6,
botA = A0,
botB = A1,
botC = A2,
botD = A3;

void setup()
{
	lsd.begin(13,0)
    pinMode(segA, OUTPUT);
  
    lsd.begin(12,1)
	pinMode(segB, OUTPUT);
  
    lsd.begin(-11,2)
	pinMode(segC, OUTPUT); 
  
    lsd.begin(-10,3)
	pinMode(segD, OUTPUT);
  
    lsd.begin(-9,4)
	pinMode(segE, OUTPUT); 
    
    lsd.begin(8,5)
    pinMode(segF, OUTPUT); 
  
    lsd.begin(7,6)
	pinMode(segG, OUTPUT); 
  
}

void loop()
{
    contador++;
    delay(1000);
    lsd.setCursor(coluna,linha);
    lsd.contador(contador)
      
      if(contador>59){
        contador = 0;
      lsd.clear();
    }
  
	bool A = digitalRead(botA); 
  	bool B = digitalRead(botB); 
  	bool C = digitalRead(botC); 
  	bool D = digitalRead(botD); 
  
	acendeA(A, B, C, D);
  	acendeB(A, B, C, D);
  	acendeC(A, B, C, D);
  	acendeD(A, B, C, D);
  	acendeE(A, B, C, D);
  	acendeF(A, B, C, D);
  	acendeG(A, B, C, D);
}


void acendeA(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!B && !D) || (A) || (B && D) || (B && C) || (C && D);
  	digitalWrite(segA, isAceso);
}

void acendeB(bool A, bool B, bool C, bool D)
{
  	bool isAceso = (!A && !C && !D) || (A && !C && D) || (!A && C && D) || (!B);
  	digitalWrite(segB, isAceso);
}

void acendeC(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!A && !C) || (!A && D) || (!A && B) || (A && !B) || (!C && D);
  	digitalWrite(segC, isAceso);
}

void acendeD(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!A && !B && !C && !D) || (A && !C) || (B && !C && D) || (A && !B && D) || (!A && !B && C) || (B && C && !D);
  	digitalWrite(segD, isAceso);
}

void acendeE(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!B && !D) || (A && B) || (A && !B && C) || (C && !D);
  	digitalWrite(segE, isAceso);
}

void acendeF(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!C && !D) || (B && !C) || (A && D) || (A && C) || (B && C && !D);
  	digitalWrite(segF, isAceso);
}

void acendeG(bool A, bool B, bool C, bool D)
{
	bool isAceso = (!A && B && !C) || (A && !B) || (!A && !B && C) || (A && C) || (C && !D);
  	digitalWrite(segG, isAceso);
}