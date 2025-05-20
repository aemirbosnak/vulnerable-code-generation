//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <qrencode.h>

#define NUM_THREADS 4 // Number of threads to create
#define DATA_SIZE 100 // Maximum size of data to be encoded

typedef struct {
    char data[DATA_SIZE]; // Data to be encoded
    int version; // QR code version
    QRecLevel ec_level; // Error correction level
    pthread_mutex_t lock; // Mutex lock to ensure thread safety
} qr_data_t;

void* generate_qr_code(void* params) {
    qr_data_t* data = (qr_data_t*) params;
    QRcode* qr = QRcode_encodeString(data->data, 0, data->ec_level, QR_MODE_8, 1);
    pthread_mutex_lock(&(data->lock)); // Lock the mutex before accessing the shared variable
    if (qr != NULL) {
        // Print the QR code to stdout
        printf("Version: %d, Error correction level: %c\n", data->version, '0' + data->ec_level);
        int i, j;
        for (i = 0; i < qr->width; i++) {
            for (j = 0; j < qr->width; j++) {
                if (qr->data[i * qr->width + j] & 1) {
                    printf("  "); // White module
                }
                else {
                    printf("██"); // Black module
                }
            }
            printf("\n");
        }
        printf("\n");
        QRcode_free(qr);
    }
    pthread_mutex_unlock(&(data->lock)); // Unlock the mutex after accessing the shared variable
    pthread_exit(NULL);
}

int main() {
    char data[DATA_SIZE];
    printf("Enter the data to be encoded: ");
    fgets(data, DATA_SIZE, stdin);
    int versions[] = {1, 2, 3, 4}; // QR code versions to be generated
    QRecLevel ec_levels[] = {QR_ECLEVEL_L, QR_ECLEVEL_M, QR_ECLEVEL_Q, QR_ECLEVEL_H}; // Error correction levels
    pthread_t threads[NUM_THREADS];
    int rc, i, j;
    qr_data_t* qr_data = (qr_data_t*) malloc(sizeof(qr_data_t));
    qr_data->version = 0;
    pthread_mutex_init(&(qr_data->lock), NULL); // Initialize the mutex lock
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&(threads[i]), NULL, generate_qr_code, (void*) qr_data);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (i = 0; i < sizeof(versions) / sizeof(int); i++) {
        for (j = 0; j < sizeof(ec_levels) / sizeof(QRecLevel); j++) {
            pthread_mutex_lock(&(qr_data->lock)); // Lock the mutex before updating the shared variable
            qr_data->version = versions[i];
            qr_data->ec_level = ec_levels[j];
            qr_data->data[0] = '\0'; // Clear the data buffer
            strcat(qr_data->data, data);
            pthread_mutex_unlock(&(qr_data->lock)); // Unlock the mutex after updating the shared variable
            usleep(500000); // Sleep for 0.5 seconds to allow the threads to finish generating the current QR code
        }
    }
    pthread_mutex_destroy(&(qr_data->lock)); // Destroy the mutex lock
    free(qr_data);
    pthread_exit(NULL);
}