//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_VALUE_SIZE 1024

typedef struct {
    uint8_t value[MAX_VALUE_SIZE];
    size_t size;
} QRCodeValue;

QRCodeValue *qrcode_decode(const uint8_t *data, size_t data_size) {
    QRCodeValue *value = (QRCodeValue *)malloc(sizeof(QRCodeValue));
    value->size = 0;

    for (int i = 0; i < data_size; i++) {
        if (data[i] == 0x1B && i + 2 < data_size && data[i + 1] == 0x5B && data[i + 2] == 0x31) {
            i += 3;
            while (i < data_size && data[i]!= 0x1B) {
                if (value->size >= MAX_VALUE_SIZE) {
                    break;
                }
                value->value[value->size++] = data[i++];
            }
        }
    }

    return value;
}

int main() {
    FILE *fp = fopen("qrcode.png", "rb");
    if (fp == NULL) {
        printf("Cannot open qrcode.png\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    uint8_t *data = (uint8_t *)malloc(file_size);
    if (fread(data, file_size, 1, fp)!= 1) {
        printf("Cannot read qrcode.png\n");
        free(data);
        fclose(fp);
        return 2;
    }

    fclose(fp);

    QRCodeValue *value = qrcode_decode(data, file_size);
    if (value == NULL) {
        printf("Cannot decode qrcode\n");
        free(data);
        return 3;
    }

    printf("Decoded value: %s\n", value->value);

    free(value->value);
    free(value);
    free(data);

    return 0;
}