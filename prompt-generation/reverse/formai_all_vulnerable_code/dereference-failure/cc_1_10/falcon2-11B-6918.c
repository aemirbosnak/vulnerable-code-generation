//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define BITS_PER_PIXEL 8

#define FILE_NAME "test.jpg"
#define MESSAGE "A message to hide"

#define THREADS 4

typedef struct {
    unsigned char* data;
    int length;
} Message;

void* hideMessage(void* message) {
    Message* m = (Message*) message;

    FILE* img = fopen(FILE_NAME, "rb");
    if (img == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    FILE* out = fopen("output.jpg", "wb");
    if (out == NULL) {
        printf("Error opening output file.\n");
        fclose(img);
        return NULL;
    }

    char* buffer = (char*) malloc(m->length);
    unsigned char* image = (unsigned char*) malloc(m->length);
    unsigned char* pixel;

    fread(image, 1, m->length, img);
    fread(buffer, 1, m->length, out);

    for (int i = 0; i < m->length; i++) {
        pixel = &image[i];
        buffer[i] ^= pixel[BITS_PER_PIXEL - 1];
    }

    fwrite(buffer, 1, m->length, out);
    fclose(img);
    fclose(out);

    free(buffer);
    free(image);

    return NULL;
}

int main() {
    srand(time(NULL));
    Message m;
    m.data = (unsigned char*) malloc(m.length = strlen(MESSAGE) + 1);
    m.data[m.length - 1] = '\0';
    memset(m.data, 0, m.length);
    for (int i = 0; i < strlen(MESSAGE); i++) {
        m.data[i] = MESSAGE[i];
    }

    pthread_t threads[THREADS];
    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, hideMessage, (void*) &m);
    }
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Message hidden successfully!\n");

    return 0;
}