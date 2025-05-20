//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_THREADS 5
#define SHIFT 3

typedef struct {
    char *text;
    char *encryptedText;
    int startIndex;
    int endIndex;
} ThreadData;

void *encrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->startIndex; i < data->endIndex; i++) {
        char c = data->text[i];
        if (c >= 'a' && c <= 'z') {
            data->encryptedText[i] = (c - 'a' + SHIFT) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            data->encryptedText[i] = (c - 'A' + SHIFT) % 26 + 'A';
        } else {
            data->encryptedText[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    data->encryptedText[data->endIndex] = '\0'; // Null terminate the string
    return NULL;
}

void divideWork(char *text, int len) {
    pthread_t threads[MAX_THREADS];
    ThreadData threadData[MAX_THREADS];
    char *encryptedText = malloc(len + 1);

    int segmentSize = len / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        threadData[i].text = text;
        threadData[i].encryptedText = encryptedText;
        threadData[i].startIndex = i * segmentSize;
        threadData[i].endIndex = (i + 1 == MAX_THREADS) ? len : (i + 1) * segmentSize;
        
        pthread_create(&threads[i], NULL, encrypt, (void*)&threadData[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Encrypted Text: %s\n", encryptedText);
    free(encryptedText);
}

int main() {
    char text[MAX_TEXT_LENGTH];

    printf("Enter the plaintext (max %d characters): ", MAX_TEXT_LENGTH - 1);
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character if exists
    text[strcspn(text, "\n")] = 0;

    int len = strlen(text);
    if (len == 0) {
        printf("No text provided. Exiting.\n");
        return 1;
    }

    divideWork(text, len);

    return 0;
}