//master

#include <Wire.h>
void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);   
}

char chest[5][1][26];
int k=0;

void loop() {
  for(int i=2; i<4; i++)
  {
    Serial.print("Датчик № ");
    Serial.println(i);
    Wire.requestFrom(i, 26); /* request & read data of size 26 from slave */
    int j = 0;
    while(Wire.available())
    {
      char c = Wire.read();/* read data received from slave */
      Serial.print(c);
      chest[k][i-2][j] = c;
      j++;
    }
  
    Serial.println("все");

    k++;
  }


  if (k == 5)
  {
    k = 0;
    Serial.println("отправка на сервер");//send message

  }
  
  delay(10000);
  
  Serial.println();
}

