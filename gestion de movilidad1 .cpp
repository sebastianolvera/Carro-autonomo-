const int pin2 = 2;   // Motor 1 - IN1
const int pin4 = 4;   // Motor 1 - IN2
const int pin18 = 18; // Motor 2 - IN3
const int pin19 = 19; // Motor 2 - IN4
const int pinEN1 = 12; // Motor 1 - ENA (Velocidad, requerido para que el motor se mueva)
const int pinEN2 = 13; // Motor 2 - ENB (Velocidad, requerido para que el motor se mueva)

void setup() {
  Serial.begin(115200);

  // Inicialización de Pines de Control de Movilidad (OUTPUT)
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin19, OUTPUT);
  pinMode(pinEN1, OUTPUT);
  pinMode(pinEN2, OUTPUT);
  
  // Establece una velocidad de inicio constante (se podría considerar gestión de potencia, pero es esencial para la movilidad)
  analogWrite(pinEN1, 100);
  analogWrite(pinEN2, 100);
}

void loop() {
  // === GESTIÓN DE MOVILIDAD (Ejemplo de movimiento hacia adelante) ===
  
  // Avanzar
  digitalWrite(pin2, HIGH);  // Motor 1 (lado izquierdo) adelante
  digitalWrite(pin4, LOW);   // Motor 1 (lado izquierdo)
  digitalWrite(pin18, HIGH); // Motor 2 (lado derecho) adelante
  digitalWrite(pin19, LOW);  // Motor 2 (lado derecho)
  Serial.println("Avanzar");

  delay(2000); // Avanza por 2 segundos
  
  // Girar a la Derecha (Giro diferencial: un motor adelante, el otro atrás)
  digitalWrite(pin2, HIGH); // Motor 1 adelante
  digitalWrite(pin4, LOW);
  digitalWrite(pin18, LOW); // Motor 2 atrás
  digitalWrite(pin19, HIGH);
  Serial.println("Girar Derecha");

  delay(1000); // Gira por 1 segundo
  
  // Detener
  digitalWrite(pin2, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin18, LOW);
  digitalWrite(pin19, LOW);
  Serial.println("Detener");
  
  delay(1000); // Detenido por 1 segundo
}