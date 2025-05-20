//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define MAX_KEY_LENGTH 2048
#define PRIME_LENGTH 512
#define SIEVE_LENGTH (1 << 8)

/* Struct to hold public and private keys */
typedef struct {
    uint8_t *public_key;
    uint8_t *private_key;
}
keypair_t;

/* Generate an array of 8 bytes of entropy */
static uint64_t get_entropy() {
    uint64_t entropy;

    FILE *fhandle;

    fhandle = fopen("/dev/random", "rb");

    if (fhandle == NULL) {
        fprintf(stderr, "Failed to generate entropy\n");

        exit(EXIT_FAILURE);
    }

    size_t read_size = fread(&entropy, sizeof(uint64_t), 1, fhandle);

    if (read_size != 1) {
        fprintf(stderr, "Failed to read entropy\n");

        exit(EXIT_FAILURE);
    }

    fclose(fhandle);

    return entropy;
}

/* Generate a prime number of the given length */
static void generate_prime(unsigned char *prime, size_t length) {
    unsigned char *sieve = calloc(SIEVE_LENGTH, sizeof(unsigned char));

    /* Set bit 0 in sieve so we skip 0 */
    sieve[0] = 1;

    /* Set bit 1 in sieve so we skip 1 */
    sieve[1] = 1;

    /* Generate an array of 8 bytes of entropy */
    uint64_t entropy = get_entropy();

    /* Set the LSB of the prime to 1 */
    prime[0] = (unsigned char)(entropy | 1);

    /* Turn off the MSB to make it odd */
    prime[0] &= ~(1 << 7);

    /* Set the rest of the bytes */
    for (size_t idx = 1; idx < length; ++idx) {
        prime[idx] = (unsigned char)(get_entropy() & UINT8_MAX);
    }

    /* Set the MSB to 1 to make it odd */
    prime[length - 1] |= (1 << 7);

    /* Iterate over the sieve */
    for (size_t idx = 2; idx < SIEVE_LENGTH; ++idx) {
        if (sieve[idx] == 0) {
            /* Iterate over multiples of idx */
            for (size_t multiples = idx * 2; multiples < SIEVE_LENGTH; multiples += idx) {
                sieve[multiples] = 1;
            }

            /* Iterate over the bytes in the prime */
            for (size_t byte_idx = 0; byte_idx < length; ++byte_idx) {
                uint8_t byte = prime[byte_idx];

                for (size_t bit_idx = 0; bit_idx < 8; ++bit_idx) {
                    /* If the bit is set in the sieve */
                    if (sieve[idx << 3 | bit_idx]) {
                        /* If the bit is already zero */
                        if ((byte & 1) == 0) {
                            byte |= 1;
                        } else {
                            byte += 2;
                        }

                        prime[byte_idx] = byte;
                    }
                }
            }

            /* Reset the sieve */
            memset(sieve, 0, SIEVE_LENGTH * sizeof(unsigned char));
        }
    }

    /* Free the sieve */
    free(sieve);
}

/* Generate public/private keypair */
static keypair_t *generate_keypair() {
    keypair_t *keypair = malloc(sizeof(keypair_t));

    if (keypair == NULL) {
        fprintf(stderr, "Failed to allocate memory for keypair\n");

        exit(EXIT_FAILURE);
    }

    keypair->public_key = calloc(MAX_KEY_LENGTH, sizeof(uint8_t));
    keypair->private_key = calloc(MAX_KEY_LENGTH, sizeof(uint8_t));

    if (keypair->public_key == NULL || keypair->private_key == NULL) {
        fprintf(stderr, "Failed to allocate memory for keys\n");

        exit(EXIT_FAILURE);
    }

    /* Generate 2 prime numbers */
    unsigned char p[PRIME_LENGTH] = {0}, q[PRIME_LENGTH] = {0};

    generate_prime(p, PRIME_LENGTH);
    generate_prime(q, PRIME_LENGTH);

    /* Compute n = p*q */
    uint8_t n[MAX_KEY_LENGTH] = {0};

    /* Convert p and q to uint64_t */
    uint64_t uint_p = 0, uint_q = 0;

    for (size_t idx = 0; idx < PRIME_LENGTH; ++idx) {
        uint_p |= (uint64_t) p[idx] << (idx * 8);
        uint_q |= (uint64_t) q[idx] << (idx * 8);
    }

    uint64_t uint_n = uint_p * uint_q;

    /* Convert uint64_t to uint8_t */
    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        n[idx] = (uint8_t) (uint_n & UINT8_MAX);
        uint_n >>= 8;
    }

    size_t n_length = MAX_KEY_LENGTH;

    /* Compute phi = (p-1) * (q-1) */
    uint8_t p_minus_one[PRIME_LENGTH] = {0}, q_minus_one[PRIME_LENGTH] = {0};

    memcpy(p_minus_one, p, PRIME_LENGTH);
    memcpy(q_minus_one, q, PRIME_LENGTH);

    p_minus_one[0]--;
    q_minus_one[0]--;

    uint8_t phi[MAX_KEY_LENGTH] = {0};

    uint64_t uint_p_minus_one = 0, uint_q_minus_one = 0;

    for (size_t idx = 0; idx < PRIME_LENGTH; ++idx) {
        uint_p_minus_one |= (uint64_t) p_minus_one[idx] << (idx * 8);
        uint_q_minus_one |= (uint64_t) q_minus_one[idx] << (idx * 8);
    }

    uint64_t uint_phi = uint_p_minus_one * uint_q_minus_one;

    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        phi[idx] = (uint8_t) (uint_phi & UINT8_MAX);
        uint_phi >>= 8;
    }

    size_t phi_length = MAX_KEY_LENGTH;

    /* Find e such that gcd(e, phi) = 1 */
    uint8_t e[PRIME_LENGTH] = {0};
    uint64_t uint_e;

    while(1) {
        uint_e = ((uint64_t)rand() << 32 | rand()) % (uint_p_minus_one * uint_q_minus_one - 2) + 2;

        /* Compute gcd(e, phi) */
        uint64_t a = uint_phi, b = uint_e, c;

        while (b != 0) {
            c = a % b;
            a = b;
            b = c;
        }

        if (a == 1) {
            break;
        }
    }

    /* Convert uint64_t to uint8_t */
    for (size_t idx = 0; idx < PRIME_LENGTH; ++idx) {
        e[idx] = (uint8_t) (uint_e & UINT8_MAX);
        uint_e >>= 8;
    }

    size_t e_length = PRIME_LENGTH;

    /* Compute d such that d*e mod phi = 1 */
    uint8_t d[MAX_KEY_LENGTH] = {0};

    uint64_t uint_d = 1;
    uint64_t for_phi = uint_phi;

    for (size_t idx = 0; idx < MAX_KEY_LENGTH * 8; ++idx) {
        if (uint_e & 1) {
            uint_d = (uint_d * for_phi) % (uint64_t)UINT64_MAX;
        }

        for_phi = (for_phi * for_phi) % (uint64_t)UINT64_MAX;
        uint_e >>= 1;
    }

    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        d[idx] = (uint8_t) (uint_d & UINT8_MAX);
        uint_d >>= 8;
    }

    size_t d_length = MAX_KEY_LENGTH;

    /* Copy values to keypair */
    memcpy(keypair->public_key, n, n_length);
    memcpy(keypair->public_key + n_length, e, e_length);

    memcpy(keypair->private_key, n, n_length);
    memcpy(keypair->private_key + n_length, d, d_length);

    return keypair;
}

/* Encrypt a data chunk */
static void encrypt(const uint8_t *data, size_t data_length, const uint8_t *public_key, size_t public_key_length, uint8_t *out) {
    /* Convert public key to uint64_t */
    uint64_t n = 0, e = 0;

    for (size_t idx = 0; idx < public_key_length / 2; ++idx) {
        n |= (uint64_t) public_key[idx] << (idx * 8);
        e |= (uint64_t) public_key[idx + public_key_length / 2] << (idx * 8);
    }

    uint64_t c = 1;

    for (size_t idx = 0; idx < data_length; ++idx) {
        uint8_t byte = data[idx];

        for (size_t bit_idx = 0; bit_idx < 8; ++bit_idx) {
            if (byte & 1) {
                c = (c * n) % (uint64_t)UINT64_MAX;
            }

            n = (n * n) % (uint64_t)UINT64_MAX;

            byte >>= 1;
        }
    }

    /* Convert uint64_t to uint8_t */
    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        out[idx] = (uint8_t) (c & UINT8_MAX);
        c >>= 8;
    }
}

/* Decrypt a data chunk */
static void decrypt(const uint8_t *data, size_t data_length, const uint8_t *private_key, size_t private_key_length, uint8_t *out) {
    /* Convert private key to uint64_t */
    uint64_t n = 0, d = 0;

    for (size_t idx = 0; idx < private_key_length / 2; ++idx) {
        n |= (uint64_t) private_key[idx] << (idx * 8);
        d |= (uint64_t) private_key[idx + private_key_length / 2] << (idx * 8);
    }

    uint64_t m = 1;

    for (size_t idx = 0; idx < data_length; ++idx) {
        uint8_t byte = data[idx];

        for (size_t bit_idx = 0; bit_idx < 8; ++bit_idx) {
            if (byte & 1) {
                m = (m * n) % (uint64_t)UINT64_MAX;
            }

            n = (n * n) % (uint64_t)UINT64_MAX;

            byte >>= 1;
        }
    }

    /* Convert uint64_t to uint8_t */
    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        out[idx] = (uint8_t) (m & UINT8_MAX);
        m >>= 8;
    }
}

/* Program entry point */
int main() {
    /* Set seed for random number generation */
    srand(time(NULL));

    /* Generate keypair */
    keypair_t *keypair = generate_keypair();

    /* Encrypt and decrypt a message */
    const uint8_t *data = "Hello, world!";
    size_t data_length = strlen((char*)data);
    printf("Original message: %s\n", data);

    uint8_t encrypted_message[MAX_KEY_LENGTH] = {0};
    encrypt(data, data_length, keypair->public_key, MAX_KEY_LENGTH, encrypted_message);
    printf("Encrypted message: ");
    for (size_t idx = 0; idx < MAX_KEY_LENGTH; ++idx) {
        printf("%02x", encrypted_message[idx]);
    }
    printf("\n");

    uint8_t decrypted_message[MAX_KEY_LENGTH] = {0};
    decrypt(encrypted_message, MAX_KEY_LENGTH, keypair->private_key, MAX_KEY_LENGTH, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}