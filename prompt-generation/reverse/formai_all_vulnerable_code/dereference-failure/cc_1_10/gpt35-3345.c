//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Surrealist C Cryptographic Hash Function Example Program
// by the "Mad Hasher"

// Define the size of the hash
#define HASH_SIZE 128

// Define the maximum size of the input buffer
#define BUFFER_SIZE 256

// Define the number of rounds to iterate
#define ROUNDS 13

// Define the maximum number of characters in the alphabet
#define ALPHA_SIZE 26

// Define a struct to hold the hash
typedef struct {
  char hash[HASH_SIZE];
} hash_t;

// Generate a random alphabet
char *generate_alphabet() {
  char *alphabet = malloc(sizeof(char) * ALPHA_SIZE);
  for (int i = 0; i < ALPHA_SIZE; i++) {
    alphabet[i] = 'a' + i;
  }
  return alphabet;
}

// Generate a random salt
char *generate_salt() {
  char *salt = malloc(sizeof(char) * 10);
  for (int i = 0; i < 10; i++) {
    salt[i] = rand() % ALPHA_SIZE;
  }
  return salt;
}

// Perform a single round of the hash function
void round(hash_t *hash, char *input, char *alphabet, char *salt) {
  int input_length = strlen(input);
  int salt_length = strlen(salt);
  int index_sum = 0;
  for (int i = 0; i < input_length; i++) {
    index_sum += input[i];
  }
  for (int i = 0; i < salt_length; i++) {
    index_sum += salt[i];
  }
  for (int i = 0; i < HASH_SIZE; i++) {
    char next_char = alphabet[(index_sum + i) % ALPHA_SIZE];
    hash->hash[i] ^= next_char;
  }
}

int main() {
  srand(time(NULL));

  char *input = malloc(sizeof(char) * BUFFER_SIZE);
  scanf("%s", input);

  char *alphabet = generate_alphabet();
  char *salt = generate_salt();

  hash_t hash = {0};

  for (int i = 0; i < ROUNDS; i++) {
    round(&hash, input, alphabet, salt);
  }

  printf("Hash: ");
  for (int i = 0; i < HASH_SIZE; i++) {
    printf("%02x", hash.hash[i]);
  }
  printf("\n");

  free(input);
  free(alphabet);
  free(salt);

  return 0;
}