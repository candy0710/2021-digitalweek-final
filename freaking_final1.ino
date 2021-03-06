/*
  Melody
 */
#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


int buttonPin[8] = {7, 6, 5, 4, 3, 2, 1, 0};
int previousState[8]= {1}, presentState[8]= {1};


int latchPin = 8;
int clockPin = 12;
int dataPin =11;

int buttonread;
byte buttonPrev = 1, buttonPresent = 1; 
int buttonflag=0;

int currentNote = -1;

//int thisnote=-1,noteDuration=0;
//long presentTime=0,previousTime=0,pauseBetweenNote=0;

byte colDataMatrix[8] = {
  B11111110,
  B11111101,
  B11111011,
  B11110111,
  B11101111,
  B11011111,
  B10111111,
  B01111111
};//這掃描

byte rowDataMatrix[8] = {
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};//選圖案 心

byte rowDataMatrix2[8] = {
  B01111110,
  B01100011,
  B01100000,
  B00110000,
  B00011000,
  B00011000,
  B00000000,
  B00011000
};//選圖案 ?

byte rowDataMatrixC3[8] = {
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001,
  B00000001
};//選圖案 C3

byte rowDataMatrixD3[8] = {
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010,
  B00000010
};//選圖案 D3

byte rowDataMatrixE3[8] = {
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100,
  B00000100
};//選圖案 E3

byte rowDataMatrixF3[8] = {
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00001000
};//選圖案 F3

byte rowDataMatrixG3[8] = {
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000
};//選圖案 G3

byte rowDataMatrixA3[8] = {
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00100000
};//選圖案 A3

byte rowDataMatrixB3[8] = {
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000
};//選圖案 B3

byte rowDataMatrixC4[8] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000
};//選圖案 C4

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  for(int i = 0; i < 8; i++)pinMode(buttonPin[i], INPUT_PULLUP);
}

void loop()
{ 
  
  for(int i=0; i<8; i++){	 
  	presentState[i] = digitalRead(buttonPin[i]);
  }
  
  
  //C3
  if(presentState[0] == 0 ){
    currentNote++;
    tone(10, NOTE_C3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixC3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
     previousState[0]=0;
  }

  
  //D3
  else if(presentState[1] ==0){
    currentNote++;
    tone(10, NOTE_D3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixD3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    previousState[1]=0;
  }
    
  
  //E3
  else if(presentState[2] == 0){
    currentNote++;
    tone(10, NOTE_E3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixE3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    previousState[2]=0;
  }
  
  
  //F3
  else if(presentState[3] == 0){
    currentNote++;
    tone(10, NOTE_F3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixF3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
    previousState[3]=0;
  }
   
  
  //G3
  else if(presentState[4] == 0){
    currentNote++;
    
    tone(10, NOTE_G3, 500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixG3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
    previousState[4]=0;
  }
    
  //A3
  else if(presentState[5] == 0){
    currentNote++;
    tone(10, NOTE_A3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixA3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
    previousState[5]=0;
  }
  
  //B3
  else if(presentState[6] == 0){
    currentNote++;
    tone(10, NOTE_B3,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixB3[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
    previousState[6]=0;
   }
  
  //C4
  else if(presentState[7] == 0){
    currentNote++;
    tone(10, NOTE_C4,500);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[currentNote]);
	shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrixC4[currentNote]);
    digitalWrite(latchPin, HIGH);
    delay(1000);
    
    
    if(currentNote == 7)
    {
    	currentNote = -1;
    }
    
    previousState[7]=0;
  }
  
  for(int i=0;i<8;i++){
    if(presentState[i]==1&&previousState[i]==0){
    noTone(10);
      previousState[i]=1;
    }
  }

}

