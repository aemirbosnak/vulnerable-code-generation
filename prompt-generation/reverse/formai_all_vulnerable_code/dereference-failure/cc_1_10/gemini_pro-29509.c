//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    size_t len;
} Buffer;

void init_buffer(Buffer *buffer, size_t len) {
    buffer->data = malloc(len);
    buffer->len = len;
}

void free_buffer(Buffer *buffer) {
    free(buffer->data);
}

void xor_buffers(Buffer *a, Buffer *b) {
    for (size_t i = 0; i < a->len; i++) {
        a->data[i] ^= b->data[i];
    }
}

void pad_buffer(Buffer *buffer, size_t block_size) {
    size_t pad_len = block_size - (buffer->len % block_size);
    buffer->data = realloc(buffer->data, buffer->len + pad_len);
    memset(buffer->data + buffer->len, 0, pad_len);
    buffer->len += pad_len;
}

unsigned char *unpad_buffer(Buffer *buffer) {
    size_t pad_len = buffer->data[buffer->len - 1];
    if (pad_len > 0 && pad_len <= buffer->len) {
        for (size_t i = buffer->len - pad_len; i < buffer->len; i++) {
            if (buffer->data[i] != pad_len) {
                return NULL;
            }
        }
        return buffer->data + pad_len;
    } else {
        return NULL;
    }
}

int encrypt(Buffer *plaintext, Buffer *key, Buffer *ciphertext) {
    pad_buffer(plaintext, key->len);
    xor_buffers(plaintext, key);
    memcpy(ciphertext, plaintext, plaintext->len);
    return 0;
}

int decrypt(Buffer *ciphertext, Buffer *key, Buffer *plaintext) {
    xor_buffers(ciphertext, key);
    unsigned char *unpadded = unpad_buffer(ciphertext);
    if (unpadded != NULL) {
        plaintext->data = unpadded;
        plaintext->len = ciphertext->len - key->len;
        return 0;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s plaintext key ciphertext\n", argv[0]);
        return 1;
    }

    Buffer plaintext, key, ciphertext;
    init_buffer(&plaintext, strlen(argv[1]));
    init_buffer(&key, strlen(argv[2]));
    init_buffer(&ciphertext, strlen(argv[1]));
    memcpy(plaintext.data, argv[1], plaintext.len);
    memcpy(key.data, argv[2], key.len);

    if (encrypt(&plaintext, &key, &ciphertext) != 0) {
        fprintf(stderr, "Error encrypting plaintext\n");
        return 1;
    }

    if (decrypt(&ciphertext, &key, &plaintext) != 0) {
        fprintf(stderr, "Error decrypting ciphertext\n");
        return 1;
    }

    printf("Plaintext: %s\n", plaintext.data);

    free_buffer(&plaintext);
    free_buffer(&key);
    free_buffer(&ciphertext);

    return 0;
}