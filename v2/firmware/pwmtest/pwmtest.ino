int heatpin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(heatpin, OUTPUT);

}

int i = 255;

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(heatpin,i);
delay(1000);
i=i-50;
if(i<=0) i=255;
}
