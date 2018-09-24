/*
   Скетч выводит напряжение питания платы, а также позволяет откалибровать константу
   (измеряем вольтметром напряжение на 5V и GND, отправляем в setConstant().
   Калибровка завершена, теперь getVCC() даёт очень точное напряжение питания)
   getVoltage() возвращает напряжение (в мВ) с аналогового пина с учётом напряжения питания
   getTemp() возвращает примерную температуру ядра (встроенный термометр)
*/

#include "GyverHacks.h"

void setup() {
  Serial.begin(9600);

  Serial.println(getVCC());         		// напряжение питания в милливольтах
  float voltage_const = getConstant(4610);  // пишем сюда реальное напряжение на 5V и GND в милливольтах, получаем константу
  Serial.println(voltage_const);
  setConstant(voltage_const);
  Serial.println(getVCC());         		// напряжение питания в милливольтах с правильной константой
  Serial.println(getVoltage(0));    		// напряжение на аналоговом пине в мВ
  Serial.println(getTemp());        		// температура ядра
}

void loop() {

}