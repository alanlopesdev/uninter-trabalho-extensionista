// Pinos
const int PINO_SENSOR = A0;
const int LED_BAIXO   = 7;
const int LED_IDEAL   = 8;
const int LED_ALTO    = 9;

// Limiares de leitura
const int LIMIAR_BAIXO = 200;
const int LIMIAR_ALTO  = 800;

void setLeds(bool baixo, bool ideal, bool alto) {
  digitalWrite(LED_BAIXO, baixo ? HIGH : LOW);
  digitalWrite(LED_IDEAL, ideal ? HIGH : LOW);
  digitalWrite(LED_ALTO,  alto  ? HIGH : LOW);
}

void setup() {
  pinMode(PINO_SENSOR, INPUT);
  pinMode(LED_BAIXO, OUTPUT);
  pinMode(LED_IDEAL, OUTPUT);
  pinMode(LED_ALTO, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(PINO_SENSOR);

  if (leitura <= LIMIAR_BAIXO) {
    setLeds(true, false, false);
    Serial.println("Nível de umidade: ABAIXO do IDEAL");
  } 
  else if (leitura <= LIMIAR_ALTO) {
    setLeds(false, true, false);
    Serial.println("Nível de umidade: IDEAL");
  } 
  else {
    setLeds(false, false, true);
    Serial.println("Nível de umidade: ACIMA do IDEAL");
  }

  delay(500); // Evita spam na serial
}
