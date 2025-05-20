//FormAI DATASET v1.0 Category: QR code reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 256

typedef struct {
    char* data;
    int length;
} QRCode;

typedef struct {
    QRCode* codes;
    int count;
} QRCodeList;

QRCode* readQRCode() {
    char input[MAX_INPUT_LENGTH];
    printf("Scan QR code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    QRCode* code = (QRCode*)malloc(sizeof(QRCode));
    code->data = strdup(input);
    code->length = strlen(input) - 1; // remove newline character

    return code;
}

void displayQRCode(QRCode* code) {
    printf("QR code data: %s", code->data);
}

void displayQRCodeList(QRCodeList* list) {
    printf("QR codes:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->codes[i].data);
    }
}

void addQRCode(QRCodeList* list, QRCode* code) {
    list->count++;
    list->codes = (QRCode*)realloc(list->codes, list->count * sizeof(QRCode));
    list->codes[list->count-1] = *code;
}

void freeQRCode(QRCode* code) {
    free(code->data);
    free(code);
}

void freeQRCodeList(QRCodeList* list) {
    for (int i = 0; i < list->count; i++) {
        freeQRCode(&list->codes[i]);
    }
    free(list->codes);
}

int main() {
    QRCodeList codeList = { NULL, 0 };
    char command[MAX_INPUT_LENGTH];
    bool exitRequested = false;

    while (!exitRequested) {
        printf("[1] Scan QR code\n");
        printf("[2] Display QR codes\n");
        printf("[3] Exit\n");

        printf("Enter command: ");
        fgets(command, MAX_INPUT_LENGTH, stdin);

        switch (atoi(command)) {
        case 1:
            addQRCode(&codeList, readQRCode());
            break;
        case 2:
            displayQRCodeList(&codeList);
            break;
        case 3:
            exitRequested = true;
            break;
        default:
            printf("Invalid command.\n");
            break;
        }

        printf("\n");
    }

    freeQRCodeList(&codeList);

    return 0;
}