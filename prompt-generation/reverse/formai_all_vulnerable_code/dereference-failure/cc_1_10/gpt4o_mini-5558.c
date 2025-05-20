//GPT-4o-mini DATASET v1.0 Category: QR code reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <qrencode.h>
#include <unistd.h>

// Structure for passing parameters to the thread
typedef struct {
    char *data;
    int size;
} ThreadData;

// Function to generate QR code
void *generate_qr_code(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    QRcode *qrcode = QRcode_encodeString(data->data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    
    if (qrcode) {
        printf("Generated QR Code for: %s\n", data->data);
        for (int i = 0; i < qrcode->width; i++) {
            for (int j = 0; j < qrcode->width; j++) {
                printf("%s ", (qrcode->data[j + i * qrcode->width] & 1) ? "██" : "  ");
            }
            printf("\n");
        }
        QRcode_free(qrcode);
    } else {
        fprintf(stderr, "Failed to generate QR code for: %s\n", data->data);
    }
    
    free(data->data);
    free(data);
    return NULL;
}

// Function to read and decode a QR code
void *read_qr_code(void *arg) {
    // Simulating QR code reading
    sleep(2);  // Simulating delay in reading
    char *decoded_data = "Hello, World!";  // Example decoded data
    printf("Decoded QR Code: %s\n", decoded_data);
    return NULL;
}

// Main function
int main() {
    pthread_t threads[2];
    ThreadData *data;

    // Create QR code with user-defined text
    data = (ThreadData *)malloc(sizeof(ThreadData));
    data->data = strdup("Hello, QR Code!");
    data->size = strlen(data->data);
    
    // Start generating QR code asynchronously
    if (pthread_create(&threads[0], NULL, generate_qr_code, data) != 0) {
        fprintf(stderr, "Error creating thread for QR code generation\n");
        return 1;
    }

    // Start reading QR code asynchronously
    if (pthread_create(&threads[1], NULL, read_qr_code, NULL) != 0) {
        fprintf(stderr, "Error creating thread for QR code reading\n");
        return 1;
    }

    // Wait for both threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All tasks completed.\n");
    return 0;
}