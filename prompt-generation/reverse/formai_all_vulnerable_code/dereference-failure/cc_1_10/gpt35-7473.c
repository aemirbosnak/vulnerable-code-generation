//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct QRCode{
    char code[61];
    char version[4];
    char error_correction[4];
    char mask_pattern[4];
    char data[45];
    char padding[15];
    
}QRCode;

void generateQRCode(QRCode *qr){

    // Create the version number
    sprintf(qr->version, "%02d", rand() % 40);

    // Create the error correction level
    int ec_level = rand() % 4;
    switch(ec_level){
        case 0:
            strcpy(qr->error_correction, "L");
            break;
        case 1:
            strcpy(qr->error_correction, "M");
            break;
        case 2:
            strcpy(qr->error_correction, "Q");
            break;
        case 3:
            strcpy(qr->error_correction, "H");
            break;
    }

    // Create the mask pattern
    sprintf(qr->mask_pattern, "%02d", rand() % 8);

    // Create the data for the QR code
    for(int i=0; i<45; i++){
        int chance = rand() % 100;
        if(chance < 50){
            qr->data[i] = '0';
        }else{
            qr->data[i] = '1';
        }
    }

    // Create the padding
    strcpy(qr->padding, "000000000000000");

    // Combine all the values to create the QR code
    sprintf(qr->code, "%s%s%s%s", qr->version, qr->error_correction, qr->mask_pattern, qr->data);
    strcat(qr->code, qr->padding);

}

int main(){
    QRCode qr;
    generateQRCode(&qr);
    printf("QR Code: %s", qr.code);
    return 0;
}