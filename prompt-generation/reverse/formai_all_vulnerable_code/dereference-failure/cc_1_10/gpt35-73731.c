//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

static unsigned char key[KEY_SIZE] = {'k', 'e', 'y', ' ', 'f', 'o', 'r', ' ', 'e', 'n', 'c', 'r', 'y', 'p', 't', 'i'};

void encrypt(unsigned char* data, size_t length) {
    unsigned char iv[BLOCK_SIZE] = {'i', 'v', ' ', 'f', 'o', 'r', ' ', 'e', 'n', 'c', 'r', 'y', 'p', 't', 'i', 'o'};

    for(int i = 0; i < length; i += BLOCK_SIZE) {
        for(int j = 0; j < BLOCK_SIZE; j++) {
            if(i == 0) {
                data[j] ^= iv[j];
            } else {
                data[i+j] ^= data[i+j - BLOCK_SIZE];
            }
        }

        for(int j = 0; j < BLOCK_SIZE; j++) {
            data[i+j] ^= key[j];
        }
    }
}

int main() {
    char message[] = "Hello, World!";

    size_t len = strlen(message);

    unsigned char* data = malloc(len+1);

    if(!data) {
        printf("Could not allocate memory!\n");
        return -1;
    }

    memcpy(data, message, len+1);

    printf("Before encryption: %s\n", data);

    encrypt(data, len);

    printf("After encryption: %s\n", data);

    free(data);

    return 0;
}