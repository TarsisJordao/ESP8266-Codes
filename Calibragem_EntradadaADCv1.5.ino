#define portaADC 0
#define tempo 1000

double leituraAnalogica[6],matValADC[100];

const int matrizAuxiliar[6]={0,2,4,6,8,10};

volatile int i,j,somaAux;

double tensao,coefAngular,coefLinear,valorADC_medio;

char aux;

double somatorioAD,somatorioV,mediaSomatorioAD,mediaSomatorioV,somatorioProdutoADV,somatorioAD_Quadrado,Sxy,Sxx;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
//Coleta de valores Analogicos 
//=============================================================================================================================================================================================
  j=0;
  
  while(j<6)
  {   
    if(Serial.available() >= 0)
    {
      aux=Serial.read();
      
      if(aux=='0')
      {
             
        Serial.println();
        Serial.print("Ajuste o valor de tensao de ");
        Serial.print(matrizAuxiliar[j]);
        Serial.print("V na entrada analogica");
        Serial.println();

        somaAux=0;
        
        for(i=0; i<100; i++)
        {
          matValADC[i]= analogRead(portaADC);
          delay(10);
        }
        
        for(i=0; i<100; i++)
        {
          somaAux+= matValADC[i];
        }
        
        valorADC_medio=somaAux/(i*1.0);
      
        leituraAnalogica[j]=valorADC_medio;
        
        Serial.print("O valor na entradada analogica correspondente a ");
        Serial.print(matrizAuxiliar[j]);
        Serial.print("V eh de:");
        Serial.println(leituraAnalogica[j]);
      
        delay(tempo);
        j++;
      }
    }
  }
//=============================================================================================================================================================================================
//=============================================================================================================================================================================================

//CALCULO DE REGRESSÃO LINEAR

  somatorioAD=0;
  somatorioV=0;
  somatorioProdutoADV=0;
  somatorioAD_Quadrado=0;

  for(j=0;j<6;j++)
  {
    somatorioAD+=leituraAnalogica[j];
    somatorioV+=matrizAuxiliar[j];
    somatorioProdutoADV+=leituraAnalogica[j]*matrizAuxiliar[j];
    somatorioAD_Quadrado+=leituraAnalogica[j]*leituraAnalogica[j];
  }

  mediaSomatorioAD=somatorioAD/(j*1.0);
  mediaSomatorioV=somatorioV/(j*1.0);

  Sxy=somatorioProdutoADV-(j*mediaSomatorioAD*mediaSomatorioV);
  Sxx=somatorioAD_Quadrado-(j*mediaSomatorioAD*mediaSomatorioAD);

  coefAngular=Sxy/Sxx;
  coefLinear=mediaSomatorioV-(coefAngular*mediaSomatorioAD);

//ESCREVE INFOS NA SERIAL
//=============================================================================================================================================================================================  
      for(j=0;j<6;j++)
      {
        Serial.print("O valor analogico correspondente a tensao de ");
        Serial.print(matrizAuxiliar[j]);
        Serial.print("V eh de:");
        Serial.println(leituraAnalogica[j]);
      }
      
      Serial.print("Somatorio dos valores Analogicos eh:");
      Serial.println(somatorioAD);
      Serial.print("Somatorio das Tensoes:");
      Serial.println(somatorioV);
      Serial.print("Media do somatorio dos valores Analogicos:");
      Serial.println(mediaSomatorioAD);
      Serial.print("Media do somatorio dos valores das Tensoes:");
      Serial.println(mediaSomatorioV);
      Serial.print("Somatorio do produto do valor Analogico x Tensao:");
      Serial.println(somatorioProdutoADV);
      Serial.print("Somatorio do quadrado dos valores Analogicos:");
      Serial.println(somatorioAD_Quadrado);
      Serial.print("Fator Sxy:");
      Serial.println(Sxy);
      Serial.print("Fator Sxx:");
      Serial.println(Sxx);
      Serial.println();
      
  while(1)
  {
        somaAux=0;
        
        for(i=0; i<100; i++)
        {
          matValADC[i]= analogRead(portaADC);
          delay(10);
        }
        
        for(i=0; i<100; i++)
        {
          somaAux+= matValADC[i];
        }
        
        valorADC_medio=somaAux/100;
            
      tensao=coefAngular*valorADC_medio + coefLinear;

          
      Serial.print("O coeficiente Angular eh:");
      Serial.println(coefAngular);
      Serial.print("O coeficiente Linear eh:");
      Serial.println(coefLinear);
      Serial.print("O valor de tensao em Volts eh:");
      Serial.println(tensao);
      Serial.println();
      delay(5000);
    }
//=============================================================================================================================================================================================
}
