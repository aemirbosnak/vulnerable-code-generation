//FormAI DATASET v1.0 Category: QR code reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 150

typedef struct {
    char data[MAX_SIZE];
    int length;
} String;

String* createString(char* data) {
    String* str = (String*) malloc(sizeof(String));
    strcpy(str->data, data);
    str->length = strlen(data);
    return str;
}

bool isQRCode(String* str) {
    int len = str->length;
    if (len < 21) return false;
    if (strncmp(str->data, "QR", 2) != 0) return false;
    for (int i = 2; i < len-1; i+=2) {
        if (strncmp(&str->data[i], "00", 2) != 0) return false;
    }
    if (strncmp(&str->data[len-1], "0", 1) != 0) return false;
    return true;
}

void readQRCode(char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("Could not open QR code file.\n");
        return;
    }
    char buffer[MAX_SIZE];
    while (fgets(buffer, MAX_SIZE, file)) {
        String* str = createString(buffer);
        if (isQRCode(str)) {
            printf("Valid QR code found: %s", str->data);
        }
        free(str);
    }
    fclose(file);
}

int main() {
    char* filepath = "qr_code.txt";
    readQRCode(filepath);
    return 0;
}