//FormAI DATASET v1.0 Category: QR code generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define VERSION "1.0.0"

#define QR_MAX_CAPACITY 2953

#define QR_VERSION_MIN 1
#define QR_VERSION_MAX 40

typedef struct QRCode{
    int version;
    int capacity;
    uint8_t *data;
} QRCode;

void printQR(QRCode *code);
void initQR(QRCode *code);
void setVersion(QRCode *code, int version);
void setData(QRCode *code, uint8_t *data, int data_len);
void freeQR(QRCode *code);

int main(){
    QRCode code;
    char input[256];
    int version;

    initQR(&code);

    printf("Enter your data string (up to %d characters):\n", code.capacity/8-1);
    fgets(input, 256, stdin);
    setData(&code, (uint8_t*)input, strlen(input)-1);

    printf("Enter version number (%d-%d):\n", QR_VERSION_MIN, QR_VERSION_MAX);
    scanf("%d", &version);
    setVersion(&code, version);

    printQR(&code);

    freeQR(&code);

    return 0;
}

void printQR(QRCode *code){
    int i, j;

    printf("\nQR Code Version %d:\n\n", code->version);

    for(i=0; i<code->version+4; i++){
        for(j=0; j<code->version+4; j++){
            if(i>1 && i<code->version+2 && j>1 && j<code->version+2){
                if(code->data[(i-2)*code->version+(j-2)]){
                    printf("##");
                }
                else{
                    printf("  ");
                }
            }
            else{
                printf("##");
            }
        }

        printf("##\n");
    }

    for(i=0; i<code->version+4; i++){
        printf("##");
    }

    printf("\n\n");
}

void initQR(QRCode *code){
    code->version = 1;
    code->capacity = QR_MAX_CAPACITY;
    code->data = (uint8_t*)malloc(code->capacity*sizeof(uint8_t));
    memset(code->data, 0, code->capacity*sizeof(uint8_t));
}

void setVersion(QRCode *code, int version){
    if(version < QR_VERSION_MIN || version > QR_VERSION_MAX){
        printf("Invalid version number! Using default version 1.\n");
        version = 1;
    }

    code->version = version;
    code->capacity = ((code->version-1)/4+1)*17;
    code->capacity *= code->capacity;
    code->capacity -= 60;
}

void setData(QRCode *code, uint8_t *data, int data_len){
    int i, j;
    uint8_t bit;

    if(data_len*8 > code->capacity-1){
        printf("Data string too long! Truncating to %d characters.\n", (code->capacity-1)/8);
        data_len = (code->capacity-1)/8;
    }

    memset(code->data, 0, code->capacity*sizeof(uint8_t));

    for(i=0; i<data_len; i++){
        for(j=7; j>=0; j--){
            bit = (data[i] >> j) & 1;

            if(bit){
                code->data[i*8+(7-j)] = 1;
            }
        }
    }

    code->data[data_len*8] = 1;
}

void freeQR(QRCode *code){
    free(code->data);
}