char a[200];
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  int i = 0;
  for (i = 0; i < 100; i++) a[i] = i;
  for (i = 0; i < 100; i++) a[i + 100] = 100 - i;
}


int j=60;
int k=40;
int y=0;

void loop() {
  // put your main code here, to run repeatedly:
 

  analogWrite( 3, a[j]);
  analogWrite( 5, a[k]);
  analogWrite( 6, a[y]);
 j++;
 k++;
 y++;
 if(j== 200) j=0;
 if(k== 200) k=0;
 if(y== 200) y=0;

delay(4);

}
