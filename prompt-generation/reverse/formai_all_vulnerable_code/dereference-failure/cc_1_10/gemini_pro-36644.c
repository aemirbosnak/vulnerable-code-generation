//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t byte;

typedef struct {
    byte *key;
    size_t key_len;
} aes_key;

typedef struct {
    byte *iv;
    size_t iv_len;
} aes_iv;

typedef struct {
    byte *ciphertext;
    size_t ciphertext_len;
} aes_ciphertext;

typedef struct {
    aes_key key;
    aes_iv iv;
    aes_ciphertext ciphertext;
} aes_context;

static aes_key aes_key_new(const byte *key, size_t key_len) {
    aes_key key_new;
    key_new.key = malloc(key_len);
    memcpy(key_new.key, key, key_len);
    key_new.key_len = key_len;
    return key_new;
}

static void aes_key_free(aes_key *key) {
    free(key->key);
    key->key = NULL;
    key->key_len = 0;
}

static aes_iv aes_iv_new(const byte *iv, size_t iv_len) {
    aes_iv iv_new;
    iv_new.iv = malloc(iv_len);
    memcpy(iv_new.iv, iv, iv_len);
    iv_new.iv_len = iv_len;
    return iv_new;
}

static void aes_iv_free(aes_iv *iv) {
    free(iv->iv);
    iv->iv = NULL;
    iv->iv_len = 0;
}

static aes_ciphertext aes_ciphertext_new(const byte *ciphertext, size_t ciphertext_len) {
    aes_ciphertext ciphertext_new;
    ciphertext_new.ciphertext = malloc(ciphertext_len);
    memcpy(ciphertext_new.ciphertext, ciphertext, ciphertext_len);
    ciphertext_new.ciphertext_len = ciphertext_len;
    return ciphertext_new;
}

static void aes_ciphertext_free(aes_ciphertext *ciphertext) {
    free(ciphertext->ciphertext);
    ciphertext->ciphertext = NULL;
    ciphertext->ciphertext_len = 0;
}

static aes_context aes_context_new(const byte *key, size_t key_len, const byte *iv, size_t iv_len) {
    aes_context context;
    context.key = aes_key_new(key, key_len);
    context.iv = aes_iv_new(iv, iv_len);
    context.ciphertext = aes_ciphertext_new(NULL, 0);
    return context;
}

static void aes_context_free(aes_context *context) {
    aes_key_free(&context->key);
    aes_iv_free(&context->iv);
    aes_ciphertext_free(&context->ciphertext);
}

static void aes_encrypt(aes_context *context, const byte *plaintext, size_t plaintext_len) {
    // ...
}

static void aes_decrypt(aes_context *context, const byte *ciphertext, size_t ciphertext_len) {
    // ...
}

int main(void) {
    const byte *key = "my secret key";
    size_t key_len = strlen(key);
    const byte *iv = "my secret iv";
    size_t iv_len = strlen(iv);
    const byte *plaintext = "my secret message";
    size_t plaintext_len = strlen(plaintext);

    aes_context context = aes_context_new(key, key_len, iv, iv_len);

    aes_encrypt(&context, plaintext, plaintext_len);

    aes_decrypt(&context, context.ciphertext.ciphertext, context.ciphertext.ciphertext_len);

    aes_context_free(&context);

    return 0;
}