#include "pitches.h"
#define N1 NOTE_C4
#define N2 NOTE_D4
#define N3 NOTE_E4
#define N4 NOTE_F4
#define N5 NOTE_G4
#define N6 NOTE_A4
#define N7 NOTE_B4
#define N8 NOTE_C5
boolean ledstate = false;

int mixue[] = {N3,N5,N5,N6,N5,N3,N1,N1,N2,N3,N3,N2,N1,N2,N3,N5,N5,N6,N5,N3,N1,N1,N2,N3,N3,N2,N2,N1,};
int noteDurations[] = {4,4,3,8,4,4,4,9,9,4,4,4,4,2,4,4,3,8,4,4,4,9,9,4,4,4,4,2,};
int mixue2[] = {N4,N4,N4,N6,N5,N5,N3,N2};
int noteDurations2[]={2,2,4,2,2,4,4,2};

void sound(int startNote,int endNote,int score[],int duration[])
{
  for(int thisNote = startNote;thisNote < endNote;thisNote++)
  {
    if(ledstate == true)
    {
      digitalWrite(7,HIGH);
      ledstate = !ledstate;
    }
    else if(ledstate == false)
    {
      digitalWrite(7,LOW);
      ledstate = !ledstate;
    }
    int noteDuration = 1000/duration[thisNote];
    tone(8,score[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}

void setup()
{
  sound(0,14,mixue,noteDurations);/*第一节*/
  delay(500);
  
  sound(14,28,mixue,noteDurations);/*第二节*/
  delay(700);
  
  sound(0,4,mixue2,noteDurations2);/*第三节*/
  delay(500);
  
  sound(4,8,mixue2,noteDurations2);/*第四节*/
  delay(500);
  
  sound(14,28,mixue,noteDurations);/*第五节*/
  digitalWrite(7,LOW);
}

void loop()
{
  digitalWrite(13,HIGH);
}
