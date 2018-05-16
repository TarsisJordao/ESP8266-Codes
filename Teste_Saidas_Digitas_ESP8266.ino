const int GPIO5=5;
const int GPIO4=4;
const int GPIO12=12;
const int GPIO13=13;
const int GPIO16=16;
const int GPIO14=14;

boolean valGPIO5, valGPIO4, valGPIO12, valGPIO13, valGPIO16, valGPIO14;

unsigned int contGPIO5=0, contGPIO4=0, contGPIO12=0, contGPIO13=0, contGPIO16=0, contGPIO14=0;

unsigned long int previusMillis=0;

unsigned int tempoCiclo=4000;

void setup() 
{
  Serial.begin(115200);
  
  pinMode(GPIO5,INPUT);
  pinMode(GPIO4,INPUT);
  pinMode(GPIO12,INPUT);
  pinMode(GPIO13,INPUT);
  pinMode(GPIO16,INPUT);
  pinMode(GPIO14,INPUT);
}

void loop() 
{ 
  unsigned long int currentMillis=millis();

  if(currentMillis - previusMillis < tempoCiclo)
  {
      valGPIO5 = digitalRead(GPIO5);
      
      if(valGPIO5==0)
        contGPIO5++;
      
      valGPIO4 = digitalRead(GPIO4);
      
      if(valGPIO4==0)
        contGPIO4++;
        
      valGPIO12 = digitalRead(GPIO12);

      if(valGPIO12==0)
        contGPIO12++;
        
      valGPIO13 = digitalRead(GPIO13);
      
      if(valGPIO13==0)
        contGPIO13++;
        
      valGPIO16 = digitalRead(GPIO16);
      
      if(valGPIO16==0)
        contGPIO16++;
        
      valGPIO14 = digitalRead(GPIO14);
      if(valGPIO14==0)
        contGPIO14++;
        
  previusMillis=currentMillis;
  }
          
  escreveValorSaidas();

  escreveNumPulsos();
  
}

void escreveValorSaidas()
{
  Serial.println("Valores das Saidas Digitais:");
  Serial.println();
  Serial.print("GPIO5: ");
  Serial.println(valGPIO5);
  Serial.print("GPIO4: ");
  Serial.println(valGPIO4);
  Serial.print("GPIO12: ");
  Serial.println(valGPIO12);
  Serial.print("GPIO13: ");
  Serial.println(valGPIO13);
  Serial.print("GPIO16: ");
  Serial.println(valGPIO16);
  Serial.print("GPIO14: ");
  Serial.println(valGPIO14);
  Serial.println();
}

void escreveNumPulsos()
{
  Serial.println("Numero de Pulsos em cada Saida Digital:");
  Serial.println();
  Serial.print("GPIO5: ");
  Serial.println(contGPIO5);
  Serial.print("GPIO4: ");
  Serial.println(contGPIO4);
  Serial.print("GPIO12: ");
  Serial.println(contGPIO12);
  Serial.print("GPIO13: ");
  Serial.println(contGPIO13);
  Serial.print("GPIO16: ");
  Serial.println(contGPIO16);
  Serial.print("GPIO14: ");
  Serial.println(contGPIO14);
  Serial.println();
}
