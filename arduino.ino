int r[4] = {0,3,6,A5};
int b[4] = {1,4,7,A4};
int g[4] = {2,5,8,A3};
int ground[4]= {12,11,10,9};
int level[4] = {13,A2,A1,A0};
/*
int r1 = 0;
int b1 = 1;
int g1 = 2;
int r2 = 3;
int b2 = 4;
int g2 = 5;
int r3 = 6;
int b3 = 7;
int g3 = 8;
int r4 = A5;
int b4 = A4;
int g4 = A3;

int ground1 = 12;
int ground2 = 11;
int ground3 = 10;
int ground4 = 9;
int level1 = 13;
int level2 = A2;
int level3 = A1;
int level4 = A0;
*/

void setup()
{
  /*
  pinMode(r1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(g4, OUTPUT);
  pinMode(ground1, OUTPUT);
  pinMode(ground2, OUTPUT);
  pinMode(ground3, OUTPUT);
  pinMode(ground4, OUTPUT);
  pinMode(level1, OUTPUT);
  pinMode(level2, OUTPUT);
  pinMode(level3, OUTPUT);
  pinMode(level4, OUTPUT);
  */
  int i =0;
  for(i=0;i<4;i++){
    pinMode(r[0], OUTPUT);
    pinMode(g[0], OUTPUT);
    pinMode(b[0], OUTPUT);
    pinMode(ground[0], OUTPUT);
    pinMode(level[0], OUTPUT);
  }
}

void setColumnColor(int column, int rr, int gg, int bb) {
 /*
  switch(column) {
   case 1:
    digitalWrite(r1, r);
    digitalWrite(g1, g);
    digitalWrite(b1, b);
    return;
   case 2:
    digitalWrite(r2, r);
    digitalWrite(g2, g);
    digitalWrite(b2, b);
    return;
   case 3:
    digitalWrite(r3, r);
    digitalWrite(g3, g);
    digitalWrite(b3, b);
    return;
   case 4:
    digitalWrite(r4, r);
    digitalWrite(g4, g);
    digitalWrite(b4, b);
    return;    
  }
  */
    digitalWrite(r[column], rr);
    digitalWrite(g[column], gg);
    digitalWrite(b[column], bb);
}

void setLevel(int levell, int state) {
  /*
  switch(levell) {
   case 1:
    digitalWrite(level1, state);
    return;
   case 2:
    digitalWrite(level2, state);
    return;
   case 3:
    digitalWrite(level3, state);
    return;
   case 4:
    digitalWrite(level4, state);
    return;    
  }
  */
  digitalWrite(level[levell],state);
}

void setRow(int row, int state) {
  /*
  switch(row) {
   case 1:
    digitalWrite(ground1, state);
    return;
   case 2:
    digitalWrite(ground2, state);
    return;
   case 3:
    digitalWrite(ground3, state);
    return;
   case 4:
    digitalWrite(ground4, state);
    return;    
  }
  */
  digitalWrite(ground[row],state);
}
void alternateLevel(int levell) {
  /*
  switch(levell) {
     case 1:
      setLevel(1,HIGH);
      setLevel(2,LOW);
      setLevel(3,LOW);
      setLevel(4,LOW);
      return;
     case 2:
      setLevel(1,LOW);
      setLevel(2,HIGH);
      setLevel(3,LOW);
      setLevel(4,LOW);
      return;
     case 3:
      setLevel(1,LOW);
      setLevel(2,LOW);
      setLevel(3,HIGH);
      setLevel(4,LOW);
      return;
     case 4:
      setLevel(1,LOW);
      setLevel(2,LOW);
      setLevel(3,LOW);
      setLevel(4,HIGH);
      return;    
    }
    */
   int i = 0;
   for(int i =0;i<4;i++){
    if(i == levell){
      setLevel(level[i],HIGH);
    }
    else{
    setLevel(level[i],LOW);
   }
   }
}

void step1() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,1,0,1);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,0);
  alternateLevel(1);  
}

void step2() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,0,1);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,0);
  alternateLevel(2);  
}

void step3() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,0,1);
  setColumnColor(4,0,0,0); 
  alternateLevel(3);  
}

void step4() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,1,0,1);
  alternateLevel(4);  
}

void step5() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0);
  setColumnColor(4,1,0,0);
  alternateLevel(1);  
}

void step6() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,0,0);
  setColumnColor(4,0,0,0);
  alternateLevel(2);  
}

void step7() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,0,0);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,0);
  alternateLevel(3);  
}

void step8() {  
  setRow(1, 1);
  setRow(2, 1);
  setRow(3, 1);
  setRow(4, 1);
  setColumnColor(1,1,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,0);
  alternateLevel(4);  
}

void step9() {  
  int delaySize = 66;
  alternateLevel(1);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,0,1);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,1); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,1);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,1);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,1,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,1,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
}

void step10() {  
  int delaySize = 66;
  alternateLevel(2);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,1,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,1,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,1,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,1,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,0,1);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,1,0,1);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,1,0,1);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,0,1); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
}

void step11() {  
  int delaySize = 66;
  alternateLevel(3);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,1,1);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,1,1); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,1,1);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,1,1);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,1,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,1,1,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,1,1,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,1,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
}

void step12() {  
  int delaySize = 66;
  alternateLevel(4);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,1,1);
  setColumnColor(2,0,0,0);
  setColumnColor(3,1,1,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,1,1);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,1,1,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);  
  setRow(1, 1);
  setRow(2, 0);
  setRow(3, 1);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,1,1,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,1,1);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 1);
  setRow(3, 0);
  setRow(4, 1);
  setColumnColor(1,1,1,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,1,1); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  delay(delaySize);
}

void step13() {  
  int delaySize = 66;
  alternateLevel(1);  
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  
  setRow(1, 1);
  setColumnColor(1,0,0,1);
  delay(delaySize);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,1);
  delay(delaySize); 
  setRow(1, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(4, 1);
  delay(delaySize);
  setColumnColor(4,0,0,1);
  delay(delaySize);
  setColumnColor(4,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(1,0,0,1);
  delay(delaySize); 
  setRow(4, 1);
  delay(delaySize); 
  setRow(4, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);  
  delay(delaySize); 
}

void step14() {  
  int delaySize = 66;
  alternateLevel(2);  
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  
  setRow(1, 1);
  setColumnColor(1,0,0,1);
  delay(delaySize);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,1);
  delay(delaySize); 
  setRow(1, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(4, 1);
  delay(delaySize);
  setColumnColor(4,0,0,1);
  delay(delaySize);
  setColumnColor(4,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(1,0,0,1);
  delay(delaySize); 
  setRow(4, 1);
  delay(delaySize); 
  setRow(4, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);  
  delay(delaySize); 
}

void step15() {  
  int delaySize = 66;
  alternateLevel(3);  
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  
  setRow(1, 1);
  setColumnColor(1,0,0,1);
  delay(delaySize);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,1);
  delay(delaySize); 
  setRow(1, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(4, 1);
  delay(delaySize);
  setColumnColor(4,0,0,1);
  delay(delaySize);
  setColumnColor(4,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(1,0,0,1);
  delay(delaySize); 
  setRow(4, 1);
  delay(delaySize); 
  setRow(4, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);  
  delay(delaySize); 
}

void step16() {  
  int delaySize = 66;
  alternateLevel(4);  
  setRow(1, 0);
  setRow(2, 0);
  setRow(3, 0);
  setRow(4, 0);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,0); 
  setColumnColor(4,0,0,0);
  
  setRow(1, 1);
  setColumnColor(1,0,0,1);
  delay(delaySize);
  setColumnColor(1,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(4,0,0,1);
  delay(delaySize); 
  setRow(1, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(4, 1);
  delay(delaySize);
  setColumnColor(4,0,0,1);
  delay(delaySize);
  setColumnColor(4,0,0,0);
  setColumnColor(3,0,0,1);
  delay(delaySize);
  setColumnColor(3,0,0,0);
  setColumnColor(2,0,0,1);
  delay(delaySize);
  setColumnColor(2,0,0,0);
  setColumnColor(1,0,0,1);
  delay(delaySize); 
  setRow(4, 1);
  delay(delaySize); 
  setRow(4, 0);
  setRow(3, 1);
  delay(delaySize); 
  setRow(3, 0);
  setRow(2, 1);
  delay(delaySize); 
  setRow(2, 0);  
  delay(delaySize); 
}

void step() {
  int delaySize = 140;
  step1();
  delay(delaySize);
  step2();
  delay(delaySize);
  step3();
  delay(delaySize);
  step4();
  delay(delaySize);
  step5();
  delay(delaySize);
  step6();
  delay(delaySize);
  step7();
  delay(delaySize);
  step8();
  delay(delaySize);
  step9();
  delay(delaySize);
  step10();
  delay(delaySize);
  step11();
  delay(delaySize);
  step12();
  delay(delaySize);
  step13();
  delay(delaySize);
  step14();
  delay(delaySize);
  step15();
  delay(delaySize);
  step16();
  delay(delaySize);
}

void loop()
{
  while(true) {    
    step();
  }
}
