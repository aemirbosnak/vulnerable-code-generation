//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _CipherKey {
    unsigned int key[4];
} CipherKey;

typedef struct _CipherData {
    char *data;
    size_t data_length;
    char *result;
    size_t result_length;
} CipherData;

#define KEY_LENGTH (64 / 8)
#define KEY_LENGTH_BYTES (64 / 8)

#define ENCRYPT 1
#define DECRYPT 0

void print_as_hex(unsigned int v) {
    unsigned int mask = 0xf0000000;
    for (int i = 0; i < 8; i++) {
        unsigned int val = (v & mask) >> (4 * i);
        if (val < 10)
            putchar('0' + val);
        else
            putchar('a' + (val - 10));
        mask >>= 4;
    }
}

void print_as_hex_array(unsigned int *arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; i++) {
        print_as_hex(arr[i]);
        putchar(' ');
    }
    putchar('\n');
}

void print_as_char_array(char *arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; i++) {
        putchar(arr[i]);
    }
    putchar('\n');
}

void init_cipher_key(CipherKey *key, const char *key_str) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key->key[i] = 0x0;
    }
    memcpy(key->key, key_str, KEY_LENGTH_BYTES);
}

void print_cipher_key(CipherKey *key) {
    print_as_hex_array(key->key, KEY_LENGTH);
}

void init_cipher_data(CipherData *data, const char *data_str) {
    data->data = strdup(data_str);
    data->data_length = strlen(data->data);
    data->result = NULL;
    data->result_length = 0;
}

void free_cipher_data(CipherData *data) {
    free(data->data);
    free(data->result);
}

void print_cipher_data(CipherData *data) {
    print_as_char_array(data->data, data->data_length);
}

void print_cipher_result(CipherData *data) {
    print_as_char_array(data->result, data->result_length);
}

void encrypt_decrypt(CipherData *data, CipherKey *key, int mode) {
    unsigned int left_key[KEY_LENGTH];
    unsigned int right_key[KEY_LENGTH];
    memcpy(left_key, key->key, KEY_LENGTH_BYTES);
    memcpy(right_key, key->key, KEY_LENGTH_BYTES);

    unsigned int data_len = data->data_length;
    unsigned int *data_ptr = (unsigned int *)data->data;
    unsigned int *result_ptr = (unsigned int *)malloc(data_len);
    data->result = (char *)result_ptr;
    data->result_length = data_len;

    for (unsigned int i = 0; i < data_len; i++) {
        unsigned int left = left_key[i % KEY_LENGTH];
        unsigned int right = right_key[i % KEY_LENGTH];

        unsigned int temp = left;
        left = right;
        right = (temp << 4) | (temp >> 28);

        left_key[i % KEY_LENGTH] = left;
        right_key[i % KEY_LENGTH] = right;

        unsigned int result = data_ptr[i];
        if (mode == ENCRYPT) {
            result ^= left;
        } else if (mode == DECRYPT) {
            result ^= right;
        }
        result_ptr[i] = result;
    }
}

int main() {
    CipherKey key;
    init_cipher_key(&key, "This is a secret key!");
    print_cipher_key(&key);

    CipherData data;
    init_cipher_data(&data, "Hello world!");
    print_cipher_data(&data);

    encrypt_decrypt(&data, &key, ENCRYPT);
    print_cipher_result(&data);

    encrypt_decrypt(&data, &key, DECRYPT);
    print_cipher_result(&data);

    free_cipher_data(&data);
    return 0;
}