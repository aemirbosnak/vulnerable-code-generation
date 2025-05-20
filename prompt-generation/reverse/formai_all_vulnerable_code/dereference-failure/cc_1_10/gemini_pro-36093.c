//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void hide(char *filename, char *msg) {
    FILE *f = fopen(filename, "rb+");
    if (!f) {
        perror("fopen");
        return;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    byte *data = malloc(size);
    fread(data, 1, size, f);
    long msglen = strlen(msg);
    if (msglen > (size - 1) / 8) {
        fprintf(stderr, "Message too long\n");
        free(data);
        fclose(f);
        return;
    }
    for (long i = 0; i < msglen; i++) {
        for (long j = 0; j < 8; j++) {
            data[i * 8 + j] = (data[i * 8 + j] & 0xfe) | ((msg[i] >> j) & 0x01);
        }
    }
    fseek(f, 0, SEEK_SET);
    fwrite(data, 1, size, f);
    free(data);
    fclose(f);
}

void unhide(char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        return;
    }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    byte *data = malloc(size);
    fread(data, 1, size, f);
    long msglen = (size - 1) / 8;
    char *msg = malloc(msglen + 1);
    memset(msg, 0, msglen + 1);
    for (long i = 0; i < msglen; i++) {
        for (long j = 0; j < 8; j++) {
            msg[i] |= (data[i * 8 + j] & 0x01) << j;
        }
    }
    printf("%s\n", msg);
    free(data);
    free(msg);
    fclose(f);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <filename> <hide/unhide> <message>\n", argv[0]);
        return 1;
    }
    if (!strcmp(argv[2], "hide")) {
        hide(argv[1], argv[3]);
    } else if (!strcmp(argv[2], "unhide")) {
        unhide(argv[1]);
    } else {
        fprintf(stderr, "Invalid operation\n");
        return 1;
    }
    return 0;
}