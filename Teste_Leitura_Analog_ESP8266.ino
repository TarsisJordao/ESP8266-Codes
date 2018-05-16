
const int portaADC=0;
int matValADC[100];
volatile int valorADC_medio;

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  int soma=0;
  
  for(int i=0; i<100; i++)
  {
    matValADC[i]= analogRead(portaADC);
    delay(100);
  }
  
  for(int i=0; i<100; i++)
  {
    soma+= matValADC[i];
  }

  valorADC_medio=soma/100;
  
  Serial.print("valor ADC: ");
  Serial.print(valorADC_medio);
  Serial.println();

  delay(1000);

}
