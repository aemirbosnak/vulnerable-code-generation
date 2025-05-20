//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void read_qrcode(char *filename);
void parse_qrcode(char *data);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [QR code filename]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    read_qrcode(filename);

    return 0;
}

void read_qrcode(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *data = malloc(filesize + 1);
    fread(data, filesize, 1, fp);
    fclose(fp);

    parse_qrcode(data);
}

void parse_qrcode(char *data) {
    int version = data[0] - '0';
    int error_correction_level = (data[1] - '0') / 10;
    int mask = (data[1] - '0') % 10;

    int data_bits = 0;
    int bit_count = 0;
    int byte_count = 0;
    int last_bit = 0;

    char *result = malloc(1024);
    memset(result, 0, 1024);

    while (data_bits < strlen(data) * 8) {
        int bit = (data[data_bits / 8] >> (7 - (data_bits % 8))) & 1;
        if (last_bit == 0 && bit == 0) {
            continue;
        }

        last_bit = bit;
        data_bits++;

        if (bit_count == 8) {
            result[byte_count++] = bit + '0';
            bit_count = 0;
        } else {
            bit_count++;
        }
    }

    printf("QR code data: %s\n", result);
}