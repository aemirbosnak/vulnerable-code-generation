//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <qrencode.h>

#define NUM_THREADS 16 // number of threads to generate QR codes
#define STRING_SIZE 25 // length of random strings for input

void *qrgen(void *arg) {
    char *string = (char*) arg;

    // create QR code symbol from string
    QRcode *qr = QRcode_encodeString(string, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // print out QR code in terminal
    for(int i=0; i<qr->width+2; i++) printf("##");
    printf("\n");
    for(int i=0; i<qr->width; i++) {
        printf("##");
        for(int j=0; j<qr->width; j++) {
            if(qr->data[i*qr->width+j] & 1) printf("  ");
            else printf("##");
        }
        printf("##\n");
    }
    for(int i=0; i<qr->width+2; i++) printf("##");
    printf("\n");

    QRcode_free(qr);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *strings[NUM_THREADS];

    // generate random input strings
    srand(time(NULL));
    for(int i=0; i<NUM_THREADS; i++) {
        char *str = (char*) malloc(sizeof(char) * (STRING_SIZE+1));
        for(int j=0; j<STRING_SIZE; j++) {
            str[j] = 'A' + (rand() % 26);
        }
        str[STRING_SIZE] = '\0';
        strings[i] = str;
    }

    // create threads to generate QR codes
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, qrgen, (void*) strings[i]);
    }

    // wait for threads to finish
    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // free allocated memory
    for(int i=0; i<NUM_THREADS; i++) {
        free(strings[i]);
    }

    return 0;
}