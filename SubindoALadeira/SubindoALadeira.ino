#include <Adafruit_NeoPixel.h> // Biblioteca para a Matriz de Leds
#define PIN 8 //Pino de dados do Neopixel
#define NUMPIXELS 64  //Numero de leds da matriz 
void (*funcao_Reset)() = 0; //Reset do Arduino
byte buzzer = 7;  //Porta de saída para o buzzer
byte estadoBotao = 0; //Seta o estado inicial das variáveis estadoBotao
long randNumber; // Gerador de números aleatórios

/// Variáveis do jogo /// 
int led = 0;         
int novalinha = 8;
int tempo = 300;
int posicaoatual = 8;
int posicaoverde = 2;
int posicaovermelho = 3;
int posicaoazul = 4;
int pontos = 0;
int gabarito = 0;
int gabaritovermelho;
int gabaritoverde;
int gabaritoazul;
int tentativas = 0;
int linha = 1;
/// Função de tempo com comando millis ///
void dunilay(unsigned long int tempo);

/// Configuração básica da Biblioteca Neopixel /// 
Adafruit_NeoPixel pixels=Adafruit_NeoPixel(NUMPIXELS,PIN,NEO_GRB+NEO_KHZ800);

void setup()
{
  Serial.begin(115200); //Inicia a velocidade da serial (usado para testes no programa)
  // Se o pino de entrada analógica 0(zero) é deixado desconectado,
  // o ruído aleatório analógico irá causar a chamada de randomSeed()
  //  gerando números aleatórias diferentes cada vez que o sketch roda.
  // randomSeed() basicamente "embaralha" a função random().
  randomSeed(analogRead(0)); 
  pinMode(buzzer, OUTPUT); //Seta como saída
  pinMode(12, INPUT_PULLUP); //Porta para o botão 
  pixels.begin(); // Chamada da função
  pixels.setBrightness(50); // Modificar o brilho dos leds

  //////////////////////////////////////////////////////////////////////////////////////
  /// POSICIONA OS TRÊS LEDS DE GABARITO, FAZ UM VAI E VEM E SORTEIA A POSIÇÃO FINAL ///
  //////////////////////////////////////////////////////////////////////////////////////

  for (int inicio  = 0; inicio <=3; inicio++)
  {
  for (int coluna = 0; coluna <= 5 ; coluna++)
  {
  pixels.setPixelColor(coluna-1, pixels.Color(0, 0, 0));
  pixels.show();
  dunilay(50);
  pixels.setPixelColor(coluna, pixels.Color(255, 0, 0));
  pixels.setPixelColor(coluna+1, pixels.Color(0, 255, 0));
  pixels.setPixelColor(coluna+2, pixels.Color(0, 0, 255));
  pixels.show();
  tone(buzzer, 600, 100);
  dunilay(50);
  }

  for (int coluna = 6; coluna >= 2 ; coluna--)
  {
  pixels.setPixelColor(coluna+1, pixels.Color(0, 0, 0));
  pixels.show(); 
  dunilay(50);
  pixels.setPixelColor(coluna, pixels.Color(255, 0, 0));
  pixels.setPixelColor(coluna-2, pixels.Color(0, 255, 0));
  pixels.setPixelColor(coluna-1, pixels.Color(0, 0, 255));
  pixels.show();
  tone(buzzer, 250, 100);
  dunilay(50);
  }
  }
////////////////////////////////////////
// POSIÇÃO FINAL.                     //
// GERAR NÚMERO ALEATÓRIO ENTRE 1 E 5 // 
// PARA POSICIONAR O GABARITO.        //
////////////////////////////////////////

  for(int f = 0; f<=10; f++)
  {
  randNumber = random(1, 5);
  }
  pixels.clear();
  gabarito = randNumber;
  pixels.setPixelColor(gabarito, pixels.Color(255, 0, 0));
  pixels.setPixelColor(gabarito+1, pixels.Color(0, 255, 0));
  pixels.setPixelColor(gabarito+2, pixels.Color(0, 0, 255));
  pixels.show();
  
////////////////////////////////////////////////////////////////
// GERAR NÚMERO ALEATÓRIO ENTRE 1 E 3 PARA COR DO LED JOGADOR //
////////////////////////////////////////////////////////////////
for(int f = 0; f<=10; f++)
  {
  randNumber = random(1, 4);
  }
}

//////////////////////////////
/// LOOP PRINCIPAL DO JOGO ///
//////////////////////////////

void loop()
{ 
  // SETA GABARITOS POR LINHA //
  //////////////////////////////
  //        GABARITO 1        //
  //////////////////////////////
  if (gabarito == 1 and linha == 1)
  {
    gabaritovermelho = 14;
    gabaritoverde = 13;
    gabaritoazul = 12;
  }
  if (gabarito == 1 and linha == 2)
  {
   gabaritovermelho = 17;
    gabaritoverde = 18;
    gabaritoazul = 19;
  }
  if (gabarito == 1 and linha == 3)
  {
    gabaritovermelho = 30;
    gabaritoverde = 29;
    gabaritoazul = 28;
  }
  if (gabarito == 1 and linha == 4)
  {
    gabaritovermelho = 33;
    gabaritoverde = 34;
    gabaritoazul = 35;
  }
  if (gabarito == 1 and linha == 5)
  {
    gabaritovermelho = 46;
    gabaritoverde = 45;
    gabaritoazul = 44;
  }
  if (gabarito == 1 and linha == 6)
  {
    gabaritovermelho = 49;
    gabaritoverde = 50;
    gabaritoazul = 51;
  }
  if (gabarito == 1 and linha == 7)
  {
    gabaritovermelho = 62;
    gabaritoverde = 61;
    gabaritoazul = 60;
  }

  //////////////////////////////
  //        GABARITO 2        //
  //////////////////////////////
  if (gabarito == 2 and linha == 1)
  {
    gabaritovermelho = 13;
    gabaritoverde = 12;
    gabaritoazul = 11;
  }
  if (gabarito == 2 and linha == 2)
  {
   gabaritovermelho = 18;
    gabaritoverde = 19;
    gabaritoazul = 20;
  }
  if (gabarito == 2 and linha == 3)
  {
    gabaritovermelho = 29;
    gabaritoverde = 28;
    gabaritoazul = 27;
  }
  if (gabarito == 2 and linha == 4)
  {
    gabaritovermelho = 34;
    gabaritoverde = 35;
    gabaritoazul = 36;
  }
  if (gabarito == 2 and linha == 5)
  {
    gabaritovermelho = 45;
    gabaritoverde = 44;
    gabaritoazul = 43;
  }
  if (gabarito == 2 and linha == 6)
  {
    gabaritovermelho = 50;
    gabaritoverde = 51;
    gabaritoazul = 52;
  }
  if (gabarito == 2 and linha == 7)
  {
    gabaritovermelho = 61;
    gabaritoverde = 60;
    gabaritoazul = 59;
  }

  //////////////////////////////
  //        GABARITO 3        //
  //////////////////////////////
  if (gabarito == 3 and linha == 1)
  {
    gabaritovermelho = 12;
    gabaritoverde = 11;
    gabaritoazul = 10;
  }
  if (gabarito == 3 and linha == 2)
  {
   gabaritovermelho = 19;
    gabaritoverde = 20;
    gabaritoazul = 21;
  }
  if (gabarito == 3 and linha == 3)
  {
    gabaritovermelho = 28;
    gabaritoverde = 27;
    gabaritoazul = 26;
  }
  if (gabarito == 3 and linha == 4)
  {
    gabaritovermelho = 35;
    gabaritoverde = 36;
    gabaritoazul = 37;
  }
  if (gabarito == 3 and linha == 5)
  {
    gabaritovermelho = 44;
    gabaritoverde = 43;
    gabaritoazul = 42;
  }
  if (gabarito == 3 and linha == 6)
  {
    gabaritovermelho = 51;
    gabaritoverde = 52;
    gabaritoazul = 53;
  }
  if (gabarito == 3 and linha == 7)
  {
    gabaritovermelho = 60;
    gabaritoverde = 59;
    gabaritoazul = 58;
  }

  //////////////////////////////
  //        GABARITO 4        //
  //////////////////////////////
  if (gabarito == 4 and linha == 1)
  {
    gabaritovermelho = 11;
    gabaritoverde = 10;
    gabaritoazul = 9;
  }
  if (gabarito == 4 and linha == 2)
  {
   gabaritovermelho = 20;
    gabaritoverde = 21;
    gabaritoazul = 22;
  }
  if (gabarito == 4 and linha == 3)
  {
    gabaritovermelho = 27;
    gabaritoverde = 26;
    gabaritoazul = 25;
  }
  if (gabarito == 4 and linha == 4)
  {
    gabaritovermelho = 36;
    gabaritoverde = 37;
    gabaritoazul = 38;
  }
  if (gabarito == 4 and linha == 5)
  {
    gabaritovermelho = 43;
    gabaritoverde = 42;
    gabaritoazul = 41;
  }
  if (gabarito == 4 and linha == 6)
  {
    gabaritovermelho = 52;
    gabaritoverde = 53;
    gabaritoazul = 54;
  }
  if (gabarito == 4 and linha == 7)
  {
    gabaritovermelho = 59;
    gabaritoverde = 58;
    gabaritoazul = 57;
  }
  
  //Serial.print("PONTOS = "); //////////////////////////////////
  //Serial.println(pontos);    // Foi usado para ver os pontos //
  //dunilay(20);               //////////////////////////////////
  
  /////////////////////
  /// FINAL DO JOGO ///
  /////////////////////
  
  if (tentativas == 7)
  { 
   if (pontos <= 0 or pontos == 1)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    for(int f = 0; f<=10; f++)
    {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(7, pixels.Color(255, 0, 0));
    pixels.setPixelColor(9, pixels.Color(255, 0, 0));
    pixels.setPixelColor(14, pixels.Color(255, 0, 0));
    pixels.setPixelColor(18, pixels.Color(255, 0, 0));
    pixels.setPixelColor(21, pixels.Color(255, 0, 0));
    pixels.setPixelColor(27, pixels.Color(255, 0, 0));
    pixels.setPixelColor(28, pixels.Color(255, 0, 0));
    pixels.setPixelColor(35, pixels.Color(255, 0, 0));
    pixels.setPixelColor(36, pixels.Color(255, 0, 0));
    pixels.setPixelColor(42, pixels.Color(255, 0, 0));
    pixels.setPixelColor(45, pixels.Color(255, 0, 0));
    pixels.setPixelColor(49, pixels.Color(255, 0, 0));
    pixels.setPixelColor(54, pixels.Color(255, 0, 0));
    pixels.setPixelColor(56, pixels.Color(255, 0, 0));
    pixels.setPixelColor(63, pixels.Color(255, 0, 0));
    pixels.show();
    dunilay (200);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));
    pixels.setPixelColor(14, pixels.Color(0, 0, 0));
    pixels.setPixelColor(18, pixels.Color(0, 0, 0));
    pixels.setPixelColor(21, pixels.Color(0, 0, 0));
    pixels.setPixelColor(27, pixels.Color(0, 0, 0));
    pixels.setPixelColor(28, pixels.Color(0, 0, 0));
    pixels.setPixelColor(35, pixels.Color(0, 0, 0));
    pixels.setPixelColor(36, pixels.Color(0, 0, 0));
    pixels.setPixelColor(42, pixels.Color(0, 0, 0));
    pixels.setPixelColor(45, pixels.Color(0, 0, 0));
    pixels.setPixelColor(49, pixels.Color(0, 0, 0));
    pixels.setPixelColor(54, pixels.Color(0, 0, 0));
    pixels.setPixelColor(56, pixels.Color(0, 0, 0));
    pixels.setPixelColor(63, pixels.Color(0, 0, 0));
    pixels.show();
    dunilay (200);
    }
   }
/// Gera o valor dos pontos pra exibir na Matriz de leds ///
   if (pontos == 2)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.setPixelColor(4, pixels.Color(0, 255, 0));
    pixels.setPixelColor(5, pixels.Color(0, 255, 0));
    pixels.setPixelColor(14, pixels.Color(0, 255, 0));
    pixels.setPixelColor(18, pixels.Color(0, 255, 0));
    pixels.setPixelColor(28, pixels.Color(0, 255, 0));
    pixels.setPixelColor(36, pixels.Color(0, 255, 0));
    pixels.setPixelColor(42, pixels.Color(0, 255, 0));
    pixels.setPixelColor(42, pixels.Color(0, 255, 0));
    pixels.setPixelColor(49, pixels.Color(0, 255, 0));
    pixels.setPixelColor(53, pixels.Color(0, 255, 0));
    pixels.setPixelColor(59, pixels.Color(0, 255, 0));
    pixels.setPixelColor(60, pixels.Color(0, 255, 0));
    pixels.setPixelColor(61, pixels.Color(0, 255, 0));
    pixels.show();
   }

   if (pontos == 3)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(10, pixels.Color(0, 0, 255));
    pixels.setPixelColor(14, pixels.Color(0, 0, 255));
    pixels.setPixelColor(21, pixels.Color(0, 0, 255));
    pixels.setPixelColor(27, pixels.Color(0, 0, 255));
    pixels.setPixelColor(28, pixels.Color(0, 0, 255));
    pixels.setPixelColor(35, pixels.Color(0, 0, 255));
    pixels.setPixelColor(36, pixels.Color(0, 0, 255));
    pixels.setPixelColor(42, pixels.Color(0, 0, 255));
    pixels.setPixelColor(49, pixels.Color(0, 0, 255));
    pixels.setPixelColor(53, pixels.Color(0, 0, 255));
    pixels.setPixelColor(59, pixels.Color(0, 0, 255));
    pixels.setPixelColor(60, pixels.Color(0, 0, 255));
    pixels.setPixelColor(61, pixels.Color(0, 0, 255));
    pixels.show();
   }

    if (pontos == 4)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(11, pixels.Color(0, 0, 255));
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(20, pixels.Color(0, 0, 255));
    pixels.setPixelColor(27, pixels.Color(0, 0, 255));
    pixels.setPixelColor(33, pixels.Color(0, 0, 255));
    pixels.setPixelColor(34, pixels.Color(0, 0, 255));
    pixels.setPixelColor(35, pixels.Color(0, 0, 255));
    pixels.setPixelColor(36, pixels.Color(0, 0, 255));
    pixels.setPixelColor(43, pixels.Color(0, 0, 255));
    pixels.setPixelColor(46, pixels.Color(0, 0, 255));
    pixels.setPixelColor(49, pixels.Color(0, 0, 255));
    pixels.setPixelColor(53, pixels.Color(0, 0, 255));
    pixels.setPixelColor(59, pixels.Color(0, 0, 255));
    pixels.setPixelColor(62, pixels.Color(0, 0, 255));
    pixels.show();
   }

   if (pontos == 5)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.setPixelColor(4, pixels.Color(0, 0, 255));
    pixels.setPixelColor(10, pixels.Color(0, 0, 255));
    pixels.setPixelColor(14, pixels.Color(0, 0, 255));
    pixels.setPixelColor(21, pixels.Color(0, 0, 255));
    pixels.setPixelColor(26, pixels.Color(0, 0, 255));
    pixels.setPixelColor(33, pixels.Color(0, 0, 255));
    pixels.setPixelColor(34, pixels.Color(0, 0, 255));
    pixels.setPixelColor(35, pixels.Color(0, 0, 255));
    pixels.setPixelColor(36, pixels.Color(0, 0, 255));
    pixels.setPixelColor(46, pixels.Color(0, 0, 255));
    pixels.setPixelColor(49, pixels.Color(0, 0, 255)); 
    pixels.setPixelColor(59, pixels.Color(0, 0, 255));
    pixels.setPixelColor(60, pixels.Color(0, 0, 255));
    pixels.setPixelColor(61, pixels.Color(0, 0, 255));
    pixels.setPixelColor(62, pixels.Color(0, 0, 255));
    pixels.show();
   }

   if (pontos == 6)
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.setPixelColor(4, pixels.Color(0, 255, 0));
    pixels.setPixelColor(10, pixels.Color(0, 255, 0));
    pixels.setPixelColor(14, pixels.Color(0, 255, 0));
    pixels.setPixelColor(17, pixels.Color(0, 255, 0));
    pixels.setPixelColor(21, pixels.Color(0, 255, 0));
    pixels.setPixelColor(33, pixels.Color(0, 255, 0));
    pixels.setPixelColor(26, pixels.Color(0, 255, 0));
    pixels.setPixelColor(29, pixels.Color(0, 255, 0));
    pixels.setPixelColor(30, pixels.Color(0, 255, 0));
    pixels.setPixelColor(33, pixels.Color(0, 255, 0));
    pixels.setPixelColor(35, pixels.Color(0, 255, 0));
    pixels.setPixelColor(36, pixels.Color(0, 255, 0));
    pixels.setPixelColor(46, pixels.Color(0, 255, 0));
    pixels.setPixelColor(49, pixels.Color(0, 255, 0));
    pixels.setPixelColor(53, pixels.Color(0, 255, 0));
    pixels.setPixelColor(59, pixels.Color(0, 255, 0));
    pixels.setPixelColor(60, pixels.Color(0, 255, 0));
    pixels.setPixelColor(61, pixels.Color(0, 255, 0));
    pixels.show();
   }

   if (pontos == 7) /// Simula uma explosão de fogos - DEVO MELHORAR
   {
    pixels.clear();
    pixels.setBrightness(155); //modificar o brilho dos leds
    pixels.setPixelColor(5, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(10, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(21, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 210, 10);
    dunilay(100);
    pixels.setPixelColor(21, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 255, 10);
    dunilay(100);
    pixels.setPixelColor(27, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(27, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 220, 10);
    dunilay(100);
    pixels.setPixelColor(36, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 230, 10);
    dunilay(100);
    pixels.setPixelColor(36, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(44, pixels.Color(0, 255, 0));
    pixels.show();
    tone(buzzer, 100, 10);
    dunilay(100);
    pixels.setPixelColor(44, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 50, 10);
    dunilay(100);
    for(int f = 0; f<=20; f++)
    {
    pixels.setPixelColor(50, pixels.Color(255, 255, 255));
    pixels.show();
    tone(buzzer, 250, 10);
    dunilay(100);
    pixels.setPixelColor(50, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 200, 10);
    dunilay(100);
    
   }
    for(int f = 0; f<=50; f++)
    {
    pixels.setPixelColor(63, pixels.Color(255, 255, 0));
    pixels.setPixelColor(59, pixels.Color(0, 255, 255));
    pixels.setPixelColor(33, pixels.Color(150, 255, 30));
    pixels.setPixelColor(46, pixels.Color(0, 255, 0));
    pixels.setPixelColor(52, pixels.Color(0, 255, 0));
    pixels.setPixelColor(29, pixels.Color(0, 0, 255));
    pixels.show();
    tone(buzzer, 150, 10);
    dunilay(30);
    pixels.setPixelColor(63, pixels.Color(0, 0, 0));
    pixels.setPixelColor(59, pixels.Color(0, 0, 0));
    pixels.setPixelColor(33, pixels.Color(0, 0, 0));
    pixels.setPixelColor(46, pixels.Color(0, 0, 0));
    pixels.setPixelColor(52, pixels.Color(0, 0, 0));
    pixels.setPixelColor(29, pixels.Color(0, 0, 0));
    pixels.show();
    tone(buzzer, 25, 10);
    dunilay(30);
    }
   }


   
   dunilay(5000); //Aguarda 5 segundos
   tentativas = 0; // Zera as tentativas
   funcao_Reset(); // Reinicia o Jogo
  }
/////////////////////////////////////////////////////////////////
  int Cor = (randNumber); //SETA DE 1 A 3 NA VARIÁVEL "Cor"
  
  estadoBotao = digitalRead(12); //Registra o estado da porta
  

  ////////////////////////////////////////////////////////////////////////////////// 
  //// DESLOCA O LED NA "COR" SELECIONADA PELAS COLUNAS DE UM LADO PARA O OUTRO ////
  //////////////////////////////////////////////////////////////////////////////////
  
  if (Cor == 1 and posicaoatual <= novalinha + 6)
  {
  tone(buzzer, 250, 10);
  pixels.setPixelColor(posicaoatual, pixels.Color(255, 0, 0));
  pixels.show();
  dunilay (tempo);
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
  posicaoatual = posicaoatual + 1;
  tone(buzzer, 250, 10);
  pixels.setPixelColor(posicaoatual, pixels.Color(255, 0, 0));
  pixels.show();
  
  }

  if (Cor == 2 and posicaoatual <= novalinha + 6)
  {
  tone(buzzer, 250, 10);
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 255, 0));
  pixels.show();
  dunilay (tempo); 
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
  posicaoatual = posicaoatual + 1;
  tone(buzzer, 250, 10);
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 255, 0));
  pixels.show();
 
  }

  if (Cor == 3 and posicaoatual <= novalinha + 6)
  {
  tone(buzzer, 250, 10);  
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 255));
  pixels.show();
  dunilay (tempo);
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
  posicaoatual = posicaoatual + 1;
  tone(buzzer, 250, 10);
  pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 255));
  pixels.show();
 
     
  }
  if (posicaoatual == novalinha + 7)
  {
    dunilay (tempo);
    tone(buzzer, 250, 10);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
    pixels.show();
    dunilay (tempo);
    posicaoatual = novalinha;
 } 

  ///////////////////////////////////////////////////////////////////////////
  //// VERIFICA SE BOTÃO FOI ACIONADO E ESTACIONA O LED NA POSIÇÃO ATUAL //// 
  ///////////////////////////////////////////////////////////////////////////
  
  if (estadoBotao == LOW and Cor == 1 and posicaoatual <= 63)   ////////// LED VERMELHO
  {
    
    tone(buzzer, 250, 100);
    if (posicaoatual == gabaritovermelho)
    {
      pontos = pontos + 1;
      for (int vm = 0; vm <= 20; vm++)
    {
    tone(buzzer, 250, 100);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
    pixels.show();
    dunilay(50);
    pixels.setPixelColor(posicaoatual, pixels.Color(255, 0, 0));
    pixels.show();
    dunilay(50);
    }
    }
    else {pontos = pontos - 1;}
    novalinha = novalinha + 8;
    posicaoatual = novalinha;
    estadoBotao = 1;
    tempo = tempo - 30;
    tentativas = tentativas + 1;
    linha = linha + 1;
    dunilay (1000);
  }

  
  if (estadoBotao == LOW and Cor == 2 and posicaoatual <= 63)  ///////LED VERDE
  {
    
    tone(buzzer, 250, 100);
    if (posicaoatual == gabaritoverde)
    {
      pontos = pontos + 1;
      for (int vd = 0; vd <= 20; vd++)
    {
    tone(buzzer, 250, 100);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
    pixels.show();
    dunilay(50);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 255, 0));
    pixels.show();
    dunilay(50);
    }
    }
    else {pontos = pontos -1;}
    novalinha = novalinha + 8;
    posicaoatual = novalinha;
    estadoBotao = 1;
    tempo = tempo - 30;
    tentativas = tentativas + 1;
    linha = linha + 1;
    dunilay (1000);
  }

  if (estadoBotao == LOW and Cor == 3 and posicaoatual <= 63) ////////AZUL
  {
    
    tone(buzzer, 250, 100);
    if (posicaoatual == gabaritoazul)
    {
      pontos = pontos + 1;
      for (int az = 0; az <= 20; az++)
    {
    tone(buzzer, 250, 100);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 0));
    pixels.show();
    dunilay(50);
    pixels.setPixelColor(posicaoatual, pixels.Color(0, 0, 255));
    pixels.show();
    dunilay(50);
    }
    }
    else {pontos = pontos -1;}
    novalinha = novalinha + 8;
    posicaoatual = novalinha;
    estadoBotao = 1;
    tempo = tempo - 30;
    tentativas = tentativas + 1;
    linha = linha + 1;
    dunilay (1000);
    
  }

 
}

void dunilay(unsigned long int tempo)          /////////////////////////////////////////////////////////////////
{                                              /////////////////////////////////////////////////////////////////
  unsigned long int tempo_Inicial = millis();  // ==== Rotina de tempo, produzida pelo meu amigo Tarozzi ==== //
  while (millis() < tempo_Inicial + tempo) {}  /////////////////////////////////////////////////////////////////
}
