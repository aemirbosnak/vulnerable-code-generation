//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define KEY_SIZE 16

struct thread_data {
    unsigned char *message;
    unsigned char *key;
    unsigned char *ciphertext;
};

void *encrypt(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    unsigned char *message = data->message;
    unsigned char *key = data->key;
    unsigned char *ciphertext = data->ciphertext;

    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        ciphertext[i] = message[i] ^ key[i];
    }

    pthread_exit(NULL);
}

void print_hex(unsigned char *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%02x", array[i]);
    }
    printf("\n");
}

int main() {
    unsigned char message[KEY_SIZE] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\n', '\r', '\t', '\0'};
    unsigned char key[KEY_SIZE] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char ciphertext[KEY_SIZE];
    struct thread_data data[2];

    pthread_t threads[2];
    int rc;

    // first thread
    data[0].message = message;
    data[0].key = key;
    data[0].ciphertext = ciphertext;
    rc = pthread_create(&threads[0], NULL, encrypt, (void *) &data[0]);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(1);
    }

    // second thread
    data[1].message = &message[8];
    data[1].key = &key[8];
    data[1].ciphertext = &ciphertext[8];
    rc = pthread_create(&threads[1], NULL, encrypt, (void *) &data[1]);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(1);
    }

    // wait for threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Message: ");
    print_hex(message, KEY_SIZE);
    printf("Key:     ");
    print_hex(key, KEY_SIZE);
    printf("Cipher:  ");
    print_hex(ciphertext, KEY_SIZE);

    return 0;
}