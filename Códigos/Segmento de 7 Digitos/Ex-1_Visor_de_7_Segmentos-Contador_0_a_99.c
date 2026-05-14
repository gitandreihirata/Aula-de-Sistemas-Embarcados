/*Conexões Diretas do Arduino para os Visores de 7 Segmentos
Componentes Necessários
Arduino Uno
2 Visores de 7 segmentos de cátodo comum
14 Resistores de 220 ohms (para limitar a corrente dos segmentos dos displays)
Fios jumper para conexões
Conexão dos Displays de 7 Segmentos ao Arduino
Display 1 (dezenas):

Segmento A: Conecte ao pino digital 2 do Arduino (D2)
Segmento B: Conecte ao pino digital 3 do Arduino (D3)
Segmento C: Conecte ao pino digital 4 do Arduino (D4)
Segmento D: Conecte ao pino digital 5 do Arduino (D5)
Segmento E: Conecte ao pino digital 6 do Arduino (D6)
Segmento F: Conecte ao pino digital 7 do Arduino (D7)
Segmento G: Conecte ao pino digital 8 do Arduino (D8)
Display 2 (unidades):

Segmento A: Conecte ao pino digital 9 do Arduino (D9)
Segmento B: Conecte ao pino digital 10 do Arduino (D10)
Segmento C: Conecte ao pino digital 11 do Arduino (D11)
Segmento D: Conecte ao pino digital 12 do Arduino (D12)
Segmento E: Conecte ao pino digital 13 do Arduino (D13)
Segmento F: Conecte ao pino analógico A0 do Arduino (configurado como digital)
Segmento G: Conecte ao pino analógico A1 do Arduino (configurado como digital)
*/


// Definindo os pinos para os segmentos dos dois displays
int display1[7] = {2, 3, 4, 5, 6, 7, 8};   // Pinos do Arduino conectados ao display 1 (dezenas)
int display2[7] = {9, 10, 11, 12, 13, A0, A1}; // Pinos do Arduino conectados ao display 2 (unidades)

// Mapeamento dos segmentos para formar os números de 0 a 9
// Matriz 10 colunas e 7 linhas
const byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 0, 0, 1, 1}  // 9
};

void setup() {
  // Configurar todos os pinos dos displays como saída
  for (int i = 0; i < 7; i++) {
    pinMode(display1[i], OUTPUT);
    pinMode(display2[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 100; i++) {
    int tens = i / 10;  // Dezenas
    int units = i % 10; // Unidades

    // Atualizar display de dezenas
    displayDigit(display1, tens);
    
    // Atualizar display de unidades
    displayDigit(display2, units);

    delay(1000); // Aguardar 1 segundo antes de incrementar
  }
}

void displayDigit(int display[], int number) {
  for (int segment = 0; segment < 7; segment++) {
    digitalWrite(display[segment], digits[number][segment]);
  }
}