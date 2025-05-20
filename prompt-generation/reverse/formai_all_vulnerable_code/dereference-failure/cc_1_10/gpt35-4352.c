//FormAI DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 256

bool verify_checksum(const uint8_t* buf, const int len) {
    uint16_t chksum = 0;
    for (int i = 0; i < len - 2; i++) {
        chksum += buf[i];
    }
    return (chksum == (buf[len - 2] << 8 | buf[len - 1]));
}

void process_code(const uint8_t* code, const int len) {
    if (len > MAX_CODE_LENGTH) {
        printf("Error: code too long!\n");
        return;
    }
    if (!verify_checksum(code, len)) {
        printf("Error: checksum check failed!\n");
        return;
    }
    char str[MAX_CODE_LENGTH];
    strncpy(str, (char*)code, len - 2);
    printf("QR code message: %s\n", str);
}

void read_code_from_file(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: failed to open file!\n");
        return;
    }
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t code[MAX_CODE_LENGTH];
    fread(code, 1, len, fp);
    fclose(fp);
    process_code(code, len);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename.qr>\n", argv[0]);
        return 1;
    }
    read_code_from_file(argv[1]);
    return 0;
}