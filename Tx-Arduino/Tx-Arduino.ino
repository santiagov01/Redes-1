// Definimos los pines de salida
const int outputPin1 = 2; // Primera salida ROJO
const int outputPin2 = 3; // Segunda salida VERDE
const int outputPin3 = 4; // Tercera salida AZUL

void setup() {
  // Configuramos los pines como salidas
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);

  Serial.begin(9600); // Iniciar comunicación serial a 9600 bps
}

void loop() {
  // Número hexadecimal a convertir

  InicioTransmision();
  //F561EDAC00
  // Convertimos el número hexadecimal a binario
  String hexString = "F561EDAC00";
  String binaryString = hex_to_bin(hexString);
  Serial.print("Binario: ");
  Serial.println(binaryString);

  // Segmentamos el string binario en pares de bits
  for (int i = 0; i < binaryString.length(); i += 2) {
    String pairBits = binaryString.substring(i, i + 2); // Extrae cada par de bits

    // Imprimir el par de bits
    Serial.print("Par de bits: ");
    Serial.println(pairBits);

    // Convertimos el par de bits a entero
    int pairBitsValue = strtol(pairBits.c_str(), NULL, 2);

    // Apagar todas las salidas antes de activar la siguiente
    apagarTodasLasSalidas();

    // Activamos la salida correspondiente según el par de bits
    switch (pairBitsValue) {
      case 0: //00 ROJO
        // Controla la primera salida (pin 2)
        digitalWrite(outputPin1, HIGH);
        digitalWrite(outputPin2, LOW);
        digitalWrite(outputPin3, LOW);
        break;
      case 1: //01 VERDE
        // Controla la segunda salida (pin 3)
        digitalWrite(outputPin1, LOW);
        digitalWrite(outputPin2, HIGH);
        digitalWrite(outputPin3, LOW);
        break;
      case 2: //10 AZUL
        // Controla la tercera salida (pin 4)
        digitalWrite(outputPin1, LOW);
        digitalWrite(outputPin2, LOW);
        digitalWrite(outputPin3, HIGH);
        break;
      case 3: //11  MORADO
        // Activar simultáneamente las salidas 2 y 3
        digitalWrite(outputPin1, HIGH);
        digitalWrite(outputPin2, LOW); // Activa el pin 3
        digitalWrite(outputPin3, HIGH); // Activa el pin 4
        break;
    }

    // Mantener cada salida activada por 1 segundo
    delay(500);

    // Apagar todas las salidas antes de la siguiente activación
    apagarTodasLasSalidas();
    delay(500);
  }
}

// Función para apagar todas las salidas
void apagarTodasLasSalidas() {
  digitalWrite(outputPin1, LOW);
  digitalWrite(outputPin2, LOW);
  digitalWrite(outputPin3, LOW);
}


void  InicioTransmision() {
  int Parpadeos=7;
  for(int i=0 ; i<Parpadeos ; i++)
  {
    digitalWrite(outputPin1, HIGH);
    digitalWrite(outputPin2, HIGH);
    digitalWrite(outputPin3, HIGH);
    delay(200);
    digitalWrite(outputPin1, LOW);
    digitalWrite(outputPin2, LOW);
    digitalWrite(outputPin3, LOW);
    delay(200);
  }
  delay(1000);
}

String hex_to_bin(String hexaString){
  String hexToBin[16] = {
    "0000",  // 0
    "0001",  // 1
    "0010",  // 2
    "0011",  // 3
    "0100",  // 4
    "0101",  // 5
    "0110",  // 6
    "0111",  // 7
    "1000",  // 8
    "1001",  // 9
    "1010",  // A
    "1011",  // B
    "1100",  // C
    "1101",  // D
    "1110",  // E
    "1111"   // F
  };
  String binary = "";
  // Convertir carácter hexadecimal a índice
  for(int i = 0; i < hexaString.length(); i++){
    int index = -1;
    char hexChar = hexaString[i];
    if (hexChar >= '0' && hexChar <= '9') {
      index = hexChar - '0';
    } else if (hexChar >= 'A' && hexChar <= 'F') {
      index = hexChar - 'A' + 10;
    }
    binary += hexToBin[index];
  }
  return binary;
}