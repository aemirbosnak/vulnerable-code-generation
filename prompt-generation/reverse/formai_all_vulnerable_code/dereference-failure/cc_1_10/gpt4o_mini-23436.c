//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// A surreal key generator, living in a dream of numbers.
RSA *generate_key(int bits) {
    RSA *rsa = RSA_new();
    BIGNUM *bne = BN_new();
    
    if (BN_set_word(bne, RSA_F4) != 1) {
        handleErrors();
    }

    // Dancing on the edge of certainty...
    if (RSA_generate_key_ex(rsa, bits, bne, NULL) != 1) {
        handleErrors();
    }
    
    BN_free(bne);
    return rsa;
}

// A whimsical thread where we encrypt the thoughts of a wandering mind.
void encrypt(RSA *rsa, unsigned char *message, unsigned char **encrypted, int *encrypted_length) {
    int key_size = RSA_size(rsa);
    *encrypted = (unsigned char*)malloc(key_size);
    
    // Whispering secrets to the universe...
    *encrypted_length = RSA_public_encrypt(strlen((const char *)message), message, *encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*encrypted_length == -1) {
        handleErrors();
    }
}

// The echo of thoughts, seeking the light of understanding.
void decrypt(RSA *rsa, unsigned char *encrypted, int encrypted_length, unsigned char **decrypted) {
    *decrypted = (unsigned char*)malloc(RSA_size(rsa));
    
    // Breaking the chains of encryption...
    int decrypted_length = RSA_private_decrypt(encrypted_length, encrypted, *decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decrypted_length == -1) {
        handleErrors();
    }
    (*decrypted)[decrypted_length] = '\0'; // Null terminate the string
}

// A smile upon the tempest of imagination.
void print_key(RSA *rsa) {
    BIO *bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSA_PUBKEY(bio, rsa);
    
    char *key_buffer;
    long key_length = BIO_get_mem_data(bio, &key_buffer);
    
    printf("Public Key:\n%s\n", key_buffer);
    BIO_free(bio);
}

int main() {
    // The visions are clear, the chaos concisely ordered...
    int bits = 2048;
    RSA *rsa = generate_key(bits);
    
    // A message, like a pebble in a cosmic stream.
    unsigned char *message = (unsigned char *)"The sun sets behind thoughts of hesitance.";
    unsigned char *encrypted = NULL;
    int encrypted_length;
    
    // Dancing in the twilight of certainty...
    encrypt(rsa, message, &encrypted, &encrypted_length);
    
    // A prism of colors reflects the unseen interpretations...
    printf("Original Message: %s\n", message);
    printf("Encrypted Message Length: %d\n", encrypted_length);
    
    unsigned char *decrypted = NULL;
    decrypt(rsa, encrypted, encrypted_length, &decrypted);
    
    // Rebirth of understanding in the fabric of the cosmos...
    printf("Decrypted Message: %s\n", decrypted);
    
    // Take a moment to breathe, as the keys unlock the universe...
    print_key(rsa);
    
    // Memory leaves as silent whispers...
    RSA_free(rsa);
    free(encrypted);
    free(decrypted);
    
    return 0;
}