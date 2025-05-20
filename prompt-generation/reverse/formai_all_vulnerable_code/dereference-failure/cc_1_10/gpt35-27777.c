//FormAI DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FILENAME "inputImage.ppm"
#define SECRETMSG "This is a secret message"

void *hideMessage(void *arg);
void *extractMessage(void *arg);

unsigned char *imageData;
int imageWidth, imageHeight, imageSize, secretMsgLength;
pthread_mutex_t lock;
pthread_cond_t hideCond, extractCond;
int hideReady = 0, extractReady = 0;

int main() {
    FILE *fp;
    char c, buffer[20];
    int i = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((c = fgetc(fp)) != '\n') {
        buffer[i++] = c;
    }

    buffer[i] = '\0';
    imageWidth = atoi(buffer);
    i = 0;

    while ((c = fgetc(fp)) != '\n') {
        buffer[i++] = c;
    }

    buffer[i] = '\0';
    imageHeight = atoi(buffer);
    i = 0;

    while ((c = fgetc(fp)) != '\n'); // skip over max color value

    imageSize = imageHeight * imageWidth * 3;
    imageData = (unsigned char *) malloc(imageSize * sizeof(unsigned char));

    for (i = 0; i < imageSize; i++) {
        imageData[i] = fgetc(fp);
    }

    fclose(fp);

    secretMsgLength = strlen(SECRETMSG);

    pthread_t hideThread, extractThread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&hideCond, NULL);
    pthread_cond_init(&extractCond, NULL);

    pthread_create(&hideThread, NULL, hideMessage, NULL);
    pthread_create(&extractThread, NULL, extractMessage, NULL);

    pthread_join(hideThread, NULL);
    pthread_join(extractThread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&hideCond);
    pthread_cond_destroy(&extractCond);

    free(imageData);

    return 0;
}

void *hideMessage(void *arg) {
    int i, j, k;

    pthread_mutex_lock(&lock);
    while (!extractReady) {
        pthread_cond_wait(&hideCond, &lock);
    }

    for (i = 0; i < secretMsgLength; i++) {
        unsigned char c = SECRETMSG[i];

        for (j = 0; j < 8; j++) {
            unsigned char bit = (c >> (7 - j)) & 1;
            k = 3 * (i * 8 + j) + 2;
            imageData[k] = (imageData[k] & 0xFE) | bit;
        }
    }

    printf("Message hidden successfully!\n");

    hideReady = 1;
    pthread_cond_signal(&extractCond);
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *extractMessage(void *arg) {
    int i, j;
    char messageBuffer[100];
    int bufferIndex = 0;

    pthread_mutex_lock(&lock);
    while (!hideReady) {
        pthread_cond_wait(&extractCond, &lock);
    }

    for (i = 0; i < secretMsgLength; i++) {
        unsigned char c = 0;

        for (j = 0; j < 8; j++) {
            int k = 3 * (i * 8 + j) + 2;
            c = (c << 1) | (imageData[k] & 1);
        }

        messageBuffer[bufferIndex++] = c;
    }

    messageBuffer[bufferIndex] = '\0';
    printf("Secret message: %s\n", messageBuffer);

    extractReady = 1;
    pthread_cond_signal(&hideCond);
    pthread_mutex_unlock(&lock);

    return NULL;
}