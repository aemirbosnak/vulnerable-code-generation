//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// define p, q, e, and d values
const uint32_t P = 13;
const uint32_t Q = 11;
const uint32_t E = 7;
const uint32_t D = 23;

// calculate gcd of two numbers using Euclidean algorithm
uint32_t gcd(uint32_t a, uint32_t b)
{
    uint32_t temp;
    while (b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// calculate modular exponentiation using repeated squaring method
uint32_t mod_exp(uint32_t base, uint32_t exponent, uint32_t modulus)
{
    uint32_t result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result = (result * base) % modulus;
        }
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

// generate public and private key pair
void generate_key_pair(uint32_t *public_key, uint32_t *private_key)
{
    // calculate n, phi, and d values
    const uint32_t n = P * Q;
    const uint32_t phi = (P - 1) * (Q - 1);
    const uint32_t d = ((D * phi) + 1) / E;

    // set public key to the pair (n, e)
    public_key[0] = n;
    public_key[1] = E;

    // set private key to the pair (n, d)
    private_key[0] = n;
    private_key[1] = d;
}

// encrypt message using public key
void encrypt_message(uint32_t *message, size_t message_len, uint32_t *public_key, uint32_t *encrypted_message)
{
    for (size_t i = 0; i < message_len; i++)
    {
        encrypted_message[i] = mod_exp(message[i], public_key[1], public_key[0]);
    }
}

// decrypt message using private key
void decrypt_message(uint32_t *encrypted_message, size_t message_len, uint32_t *private_key, uint32_t *decrypted_message)
{
    for (size_t i = 0; i < message_len; i++)
    {
        decrypted_message[i] = mod_exp(encrypted_message[i], private_key[1], private_key[0]);
    }
}

int main(int argc, char **argv)
{
    // generate key pair
    uint32_t public_key[2], private_key[2];
    generate_key_pair(public_key, private_key);

    // print public key
    printf("Public Key: (%u, %u)\n", public_key[0], public_key[1]);

    // print private key
    printf("Private Key: (%u, %u)\n", private_key[0], private_key[1]);

    // read message from input
    const size_t MAX_MESSAGE_LEN = 1024;
    char *input_string = malloc(MAX_MESSAGE_LEN);
    printf("Enter message to encrypt: ");
    fgets(input_string, MAX_MESSAGE_LEN, stdin);

    // convert message to integers for encryption
    uint32_t *message = malloc(strlen(input_string) * sizeof(uint32_t));
    size_t message_len = strlen(input_string);
    for (size_t i = 0; i < message_len; i++)
    {
        message[i] = (uint32_t)input_string[i];
    }

    // encrypt message using public key
    uint32_t *encrypted_message = malloc(message_len * sizeof(uint32_t));
    encrypt_message(message, message_len, public_key, encrypted_message);

    // print encrypted message
    printf("Encrypted Message: ");
    for (size_t i = 0; i < message_len; i++)
    {
        printf("%u ", encrypted_message[i]);
    }
    printf("\n");

    // decrypt message using private key
    uint32_t *decrypted_message = malloc(message_len * sizeof(uint32_t));
    decrypt_message(encrypted_message, message_len, private_key, decrypted_message);

    // convert message back to plaintext
    char *output_string = malloc(message_len);
    for (size_t i = 0; i < message_len; i++)
    {
        output_string[i] = (char)decrypted_message[i];
    }

    // print decrypted message
    printf("Decrypted Message: %s\n", output_string);

    // free allocated memory
    free(input_string);
    free(message);
    free(encrypted_message);
    free(decrypted_message);
    free(output_string);

    return 0;
}