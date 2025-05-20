//FormAI DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define QR_VERSION 1
#define QR_DATA_SIZE 128

struct QRStruct {
  uint8_t L, M, Q, H;
  uint8_t data[QR_DATA_SIZE];
  uint16_t length;
};

void XORArrays(uint8_t *data, uint8_t *mask, uint8_t length){
  for(int i=0; i<length; i++) {
    data[i] = data[i] ^ mask[i%4];
  }
}

void AppendBytes(struct QRStruct *qr, uint8_t *data, uint16_t length){
  memcpy(qr->data + qr->length, data, length);
  qr->length += length;
}

void AppendNumeric(struct QRStruct *qr, uint32_t number, uint8_t padding){
  uint8_t number_length = sprintf((char*) qr->data + qr->length, "%0*u", padding, number);
  qr->length += number_length;
}

void GenerateQR(struct QRStruct *qr, char *url, uint16_t url_length){
  uint8_t code[] = {0x4D, 0x40, 0x1E, 0x3C, 0x4F};

  srand(time(NULL));

  uint8_t mask[4];

  for(int i=0; i<4; i++){
    mask[i] = rand() % 256;
  }

  qr->L = QR_VERSION;
  qr->M = 0;
  qr->Q = 0;
  qr->H = 0;

  AppendBytes(qr, code, sizeof(code));
  AppendNumeric(qr, url_length, 2);
  AppendBytes(qr, (uint8_t*)url, url_length);

  XORArrays(qr->data, mask, qr->length);

  AppendBytes(qr, mask, sizeof(mask));
}

int main(int argc, char** argv){
  char url[] = "https://www.example.com/c-qr-generator/";
  uint16_t url_length = strlen(url);

  struct QRStruct qr;

  GenerateQR(&qr, url, url_length);

  uint8_t *qr_data = qr.data;
  uint16_t qr_length = qr.length;

  // Display the QR code data in hexadecimal format
  for(int i=0; i<qr_length; i++) {
    printf("%02X ", qr_data[i]);
    if(i%16 == 15){
      printf("\n");
    }
  }

  return 0;
}