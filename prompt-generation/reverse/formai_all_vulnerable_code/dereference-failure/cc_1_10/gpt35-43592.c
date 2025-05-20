//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

#define QR_SIZE 21
#define BUFFER_SIZE 128

// Retro Style QR Code Generator

void printQR(uint8_t **qr) {
    printf("\n\n");
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            if (qr[i][j] == 1)
                printf("##");
            else
                printf("..");
        }
        printf("\n");
    }
}

void writeToFile(uint8_t **qr, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("[ERROR][writeToFile] Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            fprintf(fp, "%d,", qr[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

uint8_t **generateQR(char *url) {
    uint8_t **qr = malloc(sizeof(uint8_t *) * QR_SIZE);
    for (int i = 0; i < QR_SIZE; i++) {
        qr[i] = calloc(QR_SIZE, sizeof(uint8_t));
    }

    // Generate QR code here
    // ...

    return qr;
}

int main() 
{
    char buffer[BUFFER_SIZE];
    char *url = NULL;

    printf("Retro Style QR Code Generator\n");
    printf("Enter URL: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    url = strtok(buffer, "\n");

    if (strlen(url) > 0 && url[strlen(url)-1] == '\n')
        url[strlen(url)-1] = '\0';

    printf("Generating QR code... \n");
    uint8_t **qr = generateQR(url);

    printf("QR code generated: \n");
    printQR(qr);

    printf("Writing QR code to file... \n");
    char filename[BUFFER_SIZE];
    sprintf(filename, "%s_qr.csv", url);
    writeToFile(qr, filename);

    printf("[SUCCESS] QR Code generated and saved to file %s\n", filename);

    // Clean up
    for (int i = 0; i < QR_SIZE; i++) {
        free(qr[i]);
    }
    free(qr);

    return 0;
}