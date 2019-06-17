

#include <IRremote.h>

int RECV_PIN = 12;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
  //  Serial.print(results->bits, DEC);
    Serial.println(" bits)");
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
