//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
/*
 * Knuth's Cryptography Library in C
 *
 * This library implements some of the cryptographic algorithms described in Donald
 * Knuth's "The Art of Computer Programming", Volume 2: Seminumerical Algorithms,
 * Third Edition.
 *
 * This code is provided for educational purposes only and should not be used in
 * production environments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Generate a random prime number using the Sieve of Eratosthenes.
 *
 * @param n The maximum number to test for primality.
 * @return A random prime number less than or equal to n.
 */
unsigned long int eratosthenes_sieve(unsigned long int n) {
  unsigned long int *sieve = calloc(n + 1, sizeof(unsigned long int));
  if (sieve == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for sieve.\n");
    exit(EXIT_FAILURE);
  }

  for (unsigned long int i = 2; i <= n; i++) {
    if (sieve[i] == 0) {
      for (unsigned long int j = i * i; j <= n; j += i) {
        sieve[j] = 1;
      }
    }
  }

  unsigned long int prime_count = 0;
  for (unsigned long int i = 2; i <= n; i++) {
    if (sieve[i] == 0) {
      prime_count++;
    }
  }

  unsigned long int *primes = calloc(prime_count, sizeof(unsigned long int));
  if (primes == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for primes.\n");
    exit(EXIT_FAILURE);
  }

  unsigned long int prime_index = 0;
  for (unsigned long int i = 2; i <= n; i++) {
    if (sieve[i] == 0) {
      primes[prime_index++] = i;
    }
  }

  free(sieve);

  unsigned long int random_index = rand() % prime_count;

  return primes[random_index];
}

/*
 * Generate a random number using the Linear Congruential Generator (LCG).
 *
 * @param seed The seed for the LCG.
 * @param a The multiplier for the LCG.
 * @param c The increment for the LCG.
 * @param m The modulus for the LCG.
 * @return A random number.
 */
unsigned long int lcg(unsigned long int seed, unsigned long int a, unsigned long int c, unsigned long int m) {
  return (a * seed + c) % m;
}

/*
 * Encrypt a message using the RSA algorithm.
 *
 * @param message The message to encrypt.
 * @param message_length The length of the message.
 * @param e The public exponent.
 * @param n The public modulus.
 * @return The encrypted message.
 */
unsigned long int *rsa_encrypt(unsigned long int *message, unsigned long int message_length, unsigned long int e, unsigned long int n) {
  unsigned long int *encrypted_message = calloc(message_length, sizeof(unsigned long int));
  if (encrypted_message == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for encrypted message.\n");
    exit(EXIT_FAILURE);
  }

  for (unsigned long int i = 0; i < message_length; i++) {
    encrypted_message[i] = lcg(message[i], e, 0, n);
  }

  return encrypted_message;
}

/*
 * Decrypt a message using the RSA algorithm.
 *
 * @param encrypted_message The encrypted message.
 * @param encrypted_message_length The length of the encrypted message.
 * @param d The private exponent.
 * @param n The public modulus.
 * @return The decrypted message.
 */
unsigned long int *rsa_decrypt(unsigned long int *encrypted_message, unsigned long int encrypted_message_length, unsigned long int d, unsigned long int n) {
  unsigned long int *decrypted_message = calloc(encrypted_message_length, sizeof(unsigned long int));
  if (decrypted_message == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for decrypted message.\n");
    exit(EXIT_FAILURE);
  }

  for (unsigned long int i = 0; i < encrypted_message_length; i++) {
    decrypted_message[i] = lcg(encrypted_message[i], d, 0, n);
  }

  return decrypted_message;
}

/*
 * Main function.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return Exit code.
 */
int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <message> <public_exponent> <public_modulus> <private_exponent>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  unsigned long int message_length = strlen(argv[1]);
  unsigned long int *message = calloc(message_length, sizeof(unsigned long int));
  if (message == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for message.\n");
    exit(EXIT_FAILURE);
  }

  for (unsigned long int i = 0; i < message_length; i++) {
    message[i] = (unsigned long int)argv[1][i];
  }

  unsigned long int public_exponent = strtoul(argv[2], NULL, 10);
  unsigned long int public_modulus = strtoul(argv[3], NULL, 10);
  unsigned long int private_exponent = strtoul(argv[4], NULL, 10);

  unsigned long int *encrypted_message = rsa_encrypt(message, message_length, public_exponent, public_modulus);
  unsigned long int *decrypted_message = rsa_decrypt(encrypted_message, message_length, private_exponent, public_modulus);

  printf("Original message: %s\n", argv[1]);
  printf("Encrypted message: ");
  for (unsigned long int i = 0; i < message_length; i++) {
    printf("%lu ", encrypted_message[i]);
  }
  printf("\n");
  printf("Decrypted message: %s\n", decrypted_message);

  free(message);
  free(encrypted_message);
  free(decrypted_message);

  return EXIT_SUCCESS;
}