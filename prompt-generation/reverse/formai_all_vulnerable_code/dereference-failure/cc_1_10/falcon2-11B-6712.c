//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char data[256];
    unsigned char mask[256];
} SecretMessage;

void encrypt(SecretMessage *msg, char *file) {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int fileSize = 0;
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *fileData = malloc(fileSize);
    int readSize = fread(fileData, 1, fileSize, fp);
    if (readSize!= fileSize) {
        printf("Error reading file\n");
        return;
    }

    for (int i = 0; i < fileSize; i++) {
        int index = i * 8;
        fileData[i] ^= msg->data[index];
    }

    fclose(fp);

    fp = fopen(file, "wb");
    fwrite(fileData, 1, fileSize, fp);
    fclose(fp);
}

void decrypt(SecretMessage *msg, char *file) {
    FILE *fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int fileSize = 0;
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *fileData = malloc(fileSize);
    int readSize = fread(fileData, 1, fileSize, fp);
    if (readSize!= fileSize) {
        printf("Error reading file\n");
        return;
    }

    for (int i = 0; i < fileSize; i++) {
        int index = i * 8;
        fileData[i] ^= msg->mask[index];
    }

    fclose(fp);

    fp = fopen(file, "wb");
    fwrite(fileData, 1, fileSize, fp);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <encrypt|decrypt> <file>\n", argv[0]);
        return 1;
    }

    char action = argv[1][0];
    if (action!= 'e' && action!= 'd') {
        printf("Invalid action\n");
        return 1;
    }

    char *file = argv[2];

    SecretMessage msg;
    msg.data[0] = 'A';
    msg.data[1] = 'B';
    msg.data[2] = 'C';
    msg.data[3] = 'D';
    msg.data[4] = 'E';
    msg.data[5] = 'F';
    msg.data[6] = 'G';
    msg.data[7] = 'H';

    if (action == 'e') {
        encrypt(&msg, file);
    } else if (action == 'd') {
        decrypt(&msg, file);
    }

    return 0;
}