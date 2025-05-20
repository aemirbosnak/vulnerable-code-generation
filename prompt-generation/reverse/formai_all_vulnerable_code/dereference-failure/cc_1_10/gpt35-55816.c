//FormAI DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MASK 0x8005
#define WIDTH 16
#define TOPBIT (1 << (WIDTH - 1))

unsigned short crc16(unsigned char *data_p, unsigned short length);
void generate_qr_code(char *data);

int main() {
    char data[256];
    printf("Enter text to generate QR code: ");
    scanf("%[^\n]s", data);
    generate_qr_code(data);
    return 0;
}

/* Function to generate QR code */
void generate_qr_code(char *data) {
    int data_len = strlen(data);
    char qr_code[data_len * 8]; // each character can be represented in 8 bits in QR code
    int i, j, k, count = 0;
    
    // Binary representation of the data
    for (i = 0; i < data_len; i++) {
        char temp[9];
        int ascii = (int) data[i];
        for (j = 0; j < 8; j++) {
            if (ascii % 2 == 0) {
                temp[7 - j] = '0';
            } else {
                temp[7 - j] = '1';
            }
            ascii = ascii / 2;
        }
        temp[8] = '\0';
        strcat(qr_code, temp);
    }
    
    // Append 0000 to the end of data to mark the end
    strcat(qr_code, "0000");

    // Generate CRC16 checksum and append to data
    unsigned short crc = crc16((unsigned char *) qr_code, strlen(qr_code));
    char crc_bits[16];
    for (i = 0; i < 16; i++) {
        if (crc % 2 == 0) {
            crc_bits[15 - i] = '0';
        } else {
            crc_bits[15 - i] = '1';
        }
        crc = crc >> 1;
    }
    strcat(qr_code, crc_bits);

    printf("QR code for %s is %s\n", data, qr_code);
}

/* Function to calculate CRC16 checksum */
unsigned short crc16(unsigned char *data_p, unsigned short length){
    unsigned char i;
    unsigned int data;
    unsigned int crc = 0xffff;

    if (length == 0) {
        return (~crc);
    }

    do {
        for (i = 0, data = (unsigned int)0xff & *data_p++; i < 8; i++, data >>= 1) {
            if ((crc & 0x0001) ^ (data & 0x0001)) {
                crc = (crc >> 1) ^ MASK;
            } else {
                crc >>= 1;
            }
        }
    } while (--length);

    crc = ~crc;
    data = crc;
    crc = (crc << 8) | (data >> 8 & 0xff);

    return crc;
}