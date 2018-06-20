//Sketch para teste de entradas digitais do ESP8266-07

#define GPIO4   4
#define GPIO5   5
#define GPIO12 12
#define GPIO13 13

const int GPIO[4]={4,5,12,13};
int i;

char charRead;

void setup() 
{
  Serial.begin(4800);

  for(i=0;i<=3;i++)
    pinMode(GPIO[i],INPUT);
  
  inicio();
}

void inicio()
{
  Serial.println("TESTE DE ENTRADAS DIGITAIS DO ESP8266-07 COM RETORNO NA SERIAL");
  Serial.println();
  Serial.println("Selecione qual GPIO sera testado:");
  Serial.println();
  Serial.println("1 - GPIO4");
  Serial.println("2 - GPIO5");
  Serial.println("3 - GPIO12");
  Serial.println("4 - GPIO13");
  Serial.println("5 - Para identificar a GPIO acionada automaticamente");
  Serial.println();
}

void loop() 
{
  volatile int flag=1;
  
  while(Serial.available() > 0)
  {
    charRead=Serial.read();

    switch(charRead)
    {
      case '1':
      {
        Serial.println();
        Serial.println("GPIO4 Selecionado:");
        Serial.println("Acione a entrada digital correspondente ao GPIO4");
        delay(4000);
            
           if(digitalRead(GPIO4)==0)
           {
             Serial.println();
             Serial.println("A entrada digital esta funcionando");
             Serial.println();
           }
          
            else
            {
              Serial.println();
              Serial.println("A entrada digital nao foi acionada");
              Serial.println();
            }
        
      break;
      }
      
      case '2':
      {
        Serial.println();
        Serial.println("GPIO5 Selecionado:");
        Serial.println("Acione a entrada digital correspondente ao GPIO5");
        delay(4000);
            
           if(digitalRead(GPIO5)==0)
           {
             Serial.println();
             Serial.println("A entrada digital esta funcionando");
             Serial.println();
           }
          
            else
            {
              Serial.println();
              Serial.println("A entrada digital nao foi acionada");
              Serial.println();
            }
      break;
      }
      
      case '3':
      {
        Serial.println();
        Serial.println("GPIO12 Selecionado:");
        Serial.println("Acione a entrada digital correspondente ao GPIO12");
        delay(4000);
            
           if(digitalRead(GPIO12)==0)
           {
             Serial.println();
             Serial.println("A entrada digital esta funcionando");
             Serial.println();
           }
          
            else
            {
              Serial.println();
              Serial.println("A entrada digital nao foi acionada");
              Serial.println();
            }
      
      break;
      }
      
      case '4':
      {
        Serial.println();
        Serial.println("GPIO13 Selecionado");
        Serial.println("Acione a entrada digital correspondente ao GPIO13");
        delay(4000);
            
           if(digitalRead(GPIO13)==0)
           {
             Serial.println();
             Serial.println("A entrada digital esta funcionando");
             Serial.println();
           }
          
            else
            {
              Serial.println();
              Serial.println("A entrada digital nao foi acionada");
              Serial.println();
            }
        
      break;
      }

      case '5':
      {
        Serial.println();
        Serial.println("Acione a GPIO desejada:");
        Serial.println();
        delay(4000);
        
        for(i=0;i<=3;i++)
        {
          if(digitalRead(GPIO[i])==0)
          {
            Serial.print("A entrada GPIO");
            Serial.print(GPIO[i]);
            Serial.println(" foi acionada");
            Serial.println();

            flag=0;
          }
        }
        if(flag==1)
        {
          Serial.println("Nenhuma entrada GPIO foi acionada");
          Serial.println();
        }
      
      break;
      }

      default:
      {
        Serial.println("Opcao invalida");
        Serial.println();
      }
      
    }
  }
}
