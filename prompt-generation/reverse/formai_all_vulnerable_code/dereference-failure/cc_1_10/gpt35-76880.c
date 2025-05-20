//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include "qrencode.h"

#define MAX_THREADS 10
#define DATA_SIZE 100

/* Struct to hold relevant data for QR code generation */
typedef struct {
    char data[DATA_SIZE];
    int index;
    QRcode *code;
} QrData;

/* Function to generate a random string of length n */
char* randomString(int n) {
    char possible_chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char* str = malloc((n+1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        int random_index = rand() % strlen(possible_chars);
        str[i] = possible_chars[random_index];
    }
    str[n] = '\0';
    return str;
}

/* Function to generate a QR code from a QrData struct */
void* qrCodeGenerator(void* arg) {
    QrData *qrData = (QrData*) arg;
    qrData->code = QRcode_encodeString(qrData->data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    printf("Generated QR code %d\n", qrData->index);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    /* Generate random data for QR codes */
    char* data[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i] = randomString(DATA_SIZE);
    }

    /* Create thread array and QR code data array */
    pthread_t threads[MAX_THREADS];
    QrData qrData[MAX_THREADS];

    /* Launch threads */
    for (int i = 0; i < MAX_THREADS; i++) {
        qrData[i].index = i;
        memcpy(qrData[i].data, data[i], strlen(data[i])+1);
        pthread_create(&threads[i], NULL, qrCodeGenerator, (void*) &qrData[i]);
    }

    /* Wait for all threads to finish */
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    /* Save QR codes to PNG files */
    for (int i = 0; i < MAX_THREADS; i++) {
        char file_name[20];
        sprintf(file_name, "qr_code_%d.png", i);
        FILE *fp = fopen(file_name, "wb");
        if (!fp) {
            perror("Could not open file");
            exit(EXIT_FAILURE);
        }
        fwrite(qrData[i].code->data, sizeof(unsigned char), qrData[i].code->width*qrData[i].code->width, fp);
        fclose(fp);
    }

    return 0;
}