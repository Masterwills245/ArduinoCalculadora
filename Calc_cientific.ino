
#include<LiquidCrystal_I2C.h> // biblioteca LCD
#include <Keypad.h> // Biblioteca de teclado matricial

LiquidCrystal_I2C lcd(0x27, 16,2); // pines LCD
const byte linhas = 4; // número de Lineas '4'
const byte colunas = 4; // número de columnas '4'

char teclado [linhas][colunas]={
{'1','2','3','+'},
{'4','5','6','-'},
{'7','8','9','x'},
{'.','0','=','/'}
}; //variáble teclado

byte linhasPinos[linhas]={2,3,4,5}; //configuracion de lineas
byte colunaPinos[colunas]={6,7,8,9}; // configuracion de columnas

Keypad calcu = Keypad (makeKeymap(teclado),linhasPinos, colunaPinos, linhas, colunas);

//variábles de control
boolean inicio = false; 
boolean final = false;
boolean inicio2 = false; 
boolean final2 = false;// 
boolean flag;

String num1, num2, num3,num4, num5, num6, num7, num8, num9, num10, num11, num12;
float ans;
char op;
float ans2;
char op2;
int C;
int menu;
float raiz=0;
float expo=0;
float seno=0;
float pi=3.141592654;
float coss=0;
float tang=0;
float asen=0;
float acoss=0;
float atang=0;
float loga=0;
float ex=0;
void setup()
{ 
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PROYECTO DE MAQUINAS");
  lcd.setCursor(0, 1);
  lcd.print("CALCULADORA ARDUINO");
  lcd.setCursor(0, 2);
  lcd.print("Farid-Yaser-Luis");

  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.blink();
  Serial.begin(9600);
}

void loop(){
  
  char keye = calcu.getKey();
  menu=digitalRead(A1);
  if(keye == '/'){
    menu_op();
  }
  
  else{
    calculadora();
  }
}

//__________________________________________________________________
void calculadora(){
  char key = calcu.getKey();
  
  if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {lcd.clear();
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(19-numLength,0);
      lcd.print(num1); 
  }
     else
     {num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(19-numLength,2);
      lcd.print(num2);
      final = true;
  }
 
}
if (inicio == false && key != NO_KEY && (key == '+' || key == '-' || key == 'x' || key == '/'))

{inicio = true;
 op = key;
 lcd.setCursor(19,1);
 lcd.print (op); 

}
if (final == true && key !=NO_KEY && key == '=')
{
    if (op == '+')
    {ans= num1.toFloat() + num2.toFloat();}
    if (op == '-')
    {ans= num1.toFloat() - num2.toFloat();}
    if (op == 'x')
    {ans= num1.toFloat() * num2.toFloat();}
    if (op == '/')
    {menu_op();}
    
    
    lcd.clear();
    lcd.setCursor(19,0);
    lcd.autoscroll();
    lcd.print(ans,2);
    lcd.noAutoscroll();    
}
 C=digitalRead(A0);
  if(key=='.'){resetar();}
}//end void calculadora
//__________________________________________________________________

void menu_op(){
  flag=1;
   

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1-Raiz");
  lcd.setCursor(0, 1);
  lcd.print("2-Quad");
  lcd.setCursor(0, 2);
  lcd.print("3-Sen");
  lcd.setCursor(0, 3);
  lcd.print("4-Cos");
  lcd.setCursor(7, 0);
  lcd.print("5-Tan");
  lcd.setCursor(7, 1);
  lcd.print("6-Sen");
  lcd.write(B11101001);
  lcd.setCursor(7, 2);
  lcd.print("7-Cos");
  lcd.write(B11101001);
  lcd.setCursor(7, 3);
  lcd.print("8-Tan");
  lcd.write(B11101001);
  lcd.setCursor(14, 0);
  lcd.print("9-LN");
  lcd.setCursor(14, 1);
  lcd.print("0-e");
  lcd.write(B11101011);
  
  //-------------------------------------------------------
  
while(flag==1){
char key = calcu.getKey();
if(key !=NO_KEY && key == '1')
{  
  inicio = false;
  Raiz();
  final = true; 
 
}
if(key !=NO_KEY && key == '2')
{
  inicio = false;
  Expo();
  final = true;
  
}
if(key !=NO_KEY && key == '3')
{  
  inicio = false;
  Sen();
  final = true;  
}
if(key !=NO_KEY && key == '4')
{  
  inicio = false;
  Cos();
  final = true;  
}
if(key !=NO_KEY && key == '5')
{  
  inicio = false;
  Tan();
  final = true;  
}
if(key !=NO_KEY && key == '6')
{  
  inicio = false;
  Asen();
  final = true;  
}
if(key !=NO_KEY && key == '7')
{  
  inicio = false;
  Acoss();
  final = true;  
}
if(key !=NO_KEY && key == '8')
{  
  inicio = false;
  Atan();
  final = true;  
}
if(key !=NO_KEY && key == '9')
{  
  inicio = false;
  Log();
  final = true;  
}
if(key !=NO_KEY && key == '0')
{  
  inicio = false;
  Ex();
  final = true;  
}
 C=digitalRead(A0);
 if(key=='.'){resetar();}   
}//end While flag
}//end menu_op
void resetar(){
    if(C==LOW){
   lcd.clear();
  inicio = false;
  final = false;
  num1 = "";
  num2 = "";
  num3 = "";
  num4 = "";
  num5 = "";
  num6 = "";
  num7 = "";
  num8 = "";
  num9 = "";
  num10 = "";
  num11 = "";
  num12 = "";

  ans = 0;
  op = ' ';
  lcd.setCursor(19,3);
  lcd.print("0");
  flag=0;
  raiz=0;
  expo=0;
  seno=0;
  coss=0;
  tang=0;
  asen=0;
  acoss=0;
  atang=0;
  loga=0;
  ex=0;
  }
}
void Raiz(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Raiz de:");

while(raiz==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num3 = num3 + key;
      int numLength = num3.length();
      lcd.setCursor(12,0);
      lcd.print(num3); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   raiz=num3.toDouble(); 
   double raizresult=sqrt (raiz); 
   int numLength = num3.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(12,1);
   lcd.print(raizresult);
 
   
}
}
   
}//end void Raiz

void Expo(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Quadrado de:");

while(expo==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num4 = num4 + key;
      int numLength = num4.length();
      lcd.setCursor(13,0);
      lcd.print(num4); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   expo=num4.toDouble(); 
   double exporesult=pow (expo, 2); 
   int numLength = num4.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   lcd.print(exporesult);  
}
}
  
}//end void Expo
void Sen(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Seno de:");

while(seno==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num5 = num5 + key;
      int numLength = num5.length();
      lcd.setCursor(13,0);
      lcd.print(num5); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   seno=num5.toDouble(); 
   seno=seno*(pi/180);
   double senoresult=sin (seno); 
   int numLength = num5.length();
   lcd.write(B11011111);
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   lcd.print(senoresult,5);  
}
} 
}//end void sen

void Cos(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Cosseno de:");

while(coss==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num6 = num6 + key;
      int numLength = num6.length();
      lcd.setCursor(13,0);
      lcd.print(num6); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   coss=num6.toDouble(); 
   coss=coss*(pi/180);
   double cossresult=cos (coss); 
   int numLength = num6.length();
   lcd.write(B11011111);
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   lcd.print(cossresult,5);  
}
} 
}//end void Cos

void Tan() {
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tangente de:");

while(tang==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num7 = num7 + key;
      int numLength = num7.length();
      lcd.setCursor(13,0);
      lcd.print(num7); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   tang=num7.toDouble(); 
   tang=tang*(pi/180);
   double tangresult=tan (tang); 
   int numLength = num7.length();
   lcd.write(B11011111);
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   lcd.print(tangresult,5);  
}
} 
}//end void Tan

void Asen(){

lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Arc Seno de:");

while(asen==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num8 = num8 + key;
      int numLength = num8.length();
      lcd.setCursor(13,0);
      lcd.print(num8); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   asen=num8.toDouble(); 
   double asenresult=asin (asen); 
   int numLength = num8.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   asenresult=asenresult*(180/pi);
   lcd.print(asenresult,1);
   lcd.write(B11011111);  
}
} 
}//end void Asen
void Acoss(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Arc cos de:");

while(acoss==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num9 = num9 + key;
      int numLength = num9.length();
      lcd.setCursor(13,0);
      lcd.print(num9); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   acoss=num9.toDouble(); 
   double acossresult=acos (acoss); 
   int numLength = num9.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   acossresult=acossresult*(180/pi);
   lcd.print(acossresult,1);
   lcd.write(B11011111);  
}
} 
}//end void Acoss

void Atan(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Arc Tang de:");

while(atang==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num10 = num10 + key;
      int numLength = num10.length();
      lcd.setCursor(13,0);
      lcd.print(num10); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   atang=num10.toDouble(); 
   double atangresult=atan (atang); 
   int numLength = num10.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   atangresult=atangresult*(180/pi);
   lcd.print(atangresult,1);
   lcd.write(B11011111);  
}
}
}// end void Atan

void Log(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Log Nat de:");

while(loga==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num11 = num11 + key;
      int numLength = num11.length();
      lcd.setCursor(13,0);
      lcd.print(num11); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   loga=num11.toDouble(); 
   double logaresult=log (loga); 
   int numLength = num11.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(13,1);
   lcd.print(logaresult,5);
   
}
}  
}//end void Log
void Ex(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Exponencial de:");

while(ex==0)   { 
  
    char key = calcu.getKey();
     if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'))
  {
    if(inicio == false)
      {num12 = num12 + key;
      int numLength = num12.length();
      lcd.setCursor(16,0);
      lcd.print(num12); 
      final = true;     
  }  
}
if (final == true && key !=NO_KEY && key == '=')
{
   ex=num12.toDouble(); 
   double exresult=exp (ex); 
   int numLength = num12.length();
   lcd.setCursor(0,1);
   lcd.print("Resultado:");
   lcd.setCursor(12,1);
   lcd.print(exresult,5);
   //lcd.write(B11011111);  
}
} 
}//end void Ex
