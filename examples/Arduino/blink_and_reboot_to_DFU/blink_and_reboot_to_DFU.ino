//Светодиод на D13
#define LED 13
 
//Кнопка на D5
#define BUTTON 5
 
void setup() {
  //Подключение пользовательской кнопки для быстрой перезагрузки и входа в режим загрузчика (DFU)
  pinMode(BUTTON, INPUT);
 
  pinMode(LED, OUTPUT);
  // Запуск USB Device в режиме CDC (виртуальный COM-порт)
  // Для успешной сборки подключить поддержку USB CDC в Arduino IDE
  SerialUSB.begin();
}
 
bool led = false;
int i = 0;
void loop() {
  // проверка нажата ли кнопка
  if (digitalRead(BUTTON) == HIGH) {
    //перезагрузка микроконтроллера
    NVIC_SystemReset();
  }
 
  if (led) {
    led = false;
    digitalWrite(LED, HIGH);
  } else {
    led = true;
    digitalWrite(LED, LOW);
  }
  delay(250);
  i++;
  Serial.print(i);
}