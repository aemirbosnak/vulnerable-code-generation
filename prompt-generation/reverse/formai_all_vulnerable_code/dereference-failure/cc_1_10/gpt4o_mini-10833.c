//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <qrencode.h>

#define THREAD_COUNT 4
#define DATA_SIZE 256

typedef struct {
    char data[DATA_SIZE];
    int index;
} ThreadData;

void *generate_qr(void *arg) {
    ThreadData *threadData = (ThreadData *)arg;
    QRcode *qrcode;
    
    // Create QR code
    qrcode = QRcode_encodeString(threadData->data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (qrcode == NULL) {
        fprintf(stderr, "Could not generate QR code for index %d\n", threadData->index);
        return NULL;
    }

    // Print QR code
    printf("QR Code for thread %d:\n", threadData->index);
    for (int y = 0; y < qrcode->width; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            printf("%s", (qrcode->data[y * qrcode->width + x] & 1) ? "██" : "  ");
        }
        printf("\n");
    }
    printf("\n");

    // Free QR code
    QRcode_free(qrcode);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <data1> <data2> ... <dataN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int dataCount = argc - 1;
    pthread_t threads[THREAD_COUNT];
    ThreadData threadData[THREAD_COUNT];

    // Create threads to generate QR codes
    for (int i = 0; i < THREAD_COUNT && i < dataCount; i++) {
        strncpy(threadData[i].data, argv[i + 1], DATA_SIZE - 1);
        threadData[i].data[DATA_SIZE - 1] = '\0'; // Ensure null-termination
        threadData[i].index = i + 1;

        if (pthread_create(&threads[i], NULL, generate_qr, &threadData[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT && i < dataCount; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}