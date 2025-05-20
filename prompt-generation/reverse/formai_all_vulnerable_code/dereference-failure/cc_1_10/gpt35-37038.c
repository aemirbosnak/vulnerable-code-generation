//FormAI DATASET v1.0 Category: Bitwise operations ; Style: visionary
/*This program is a vision for creating a secure hash function using bitwise operations. 

The goal of this program is to take in a user's password input, convert it into a binary string representation and perform exclusive OR (XOR) operations on the binary string. 

The output of the XOR operations will be a unique binary string that can be converted back into a hash value and used to securely store and compare passwords. Let's begin!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Constants*/
#define BLOCK_SIZE 64
#define HASH_SIZE 32 
#define ROTR(x,y) ((x>>y) | (x<<(32-y))) 

/*Function Declarations*/
void pre_processing(char* password, int password_length, int* num_blocks, char** blocks);
void hash_function(int num_blocks, char** blocks, unsigned int* hash);

int main(void){
  /*Introduction*/
  printf("Welcome to the Bitwise Visionary Hash Function Program.\n");
  printf("Please enter your password: ");

  /*User Input*/
  char password[100];
  scanf("%s", password);
  int password_length = strlen(password);

  /*Pre-Processing*/
  int num_blocks;
  char** blocks = malloc(num_blocks * sizeof(char*));
  pre_processing(password, password_length, &num_blocks, blocks);

  /*Hash Function*/
  unsigned int* hash = malloc(HASH_SIZE * sizeof(unsigned int));
  hash_function(num_blocks, blocks, hash);

  /*Output*/
  printf("\nYour password hash is: ");
  for(int i = 0; i < HASH_SIZE; i++){
    printf("%02X", hash[i]);
  }

  /*Cleanup*/
  for(int i = 0; i < num_blocks; i++){
    free(blocks[i]);
  }
  free(blocks);
  free(hash);

  return 0;
}

void pre_processing(char* password, int password_length, int* num_blocks, char** blocks){
  /*Padding*/
  int padding = BLOCK_SIZE - ((password_length + 8) % BLOCK_SIZE);
  if(padding < 1){
    padding += BLOCK_SIZE;
  }
  int total_blocks = (password_length + padding + 8) / BLOCK_SIZE;
  unsigned char pad_char = 0x80;
  unsigned long long* length_bits = (unsigned long long*) &password[password_length];
  *length_bits = 8 * password_length;

  /*Memory Allocation*/
  for(int i = 0; i < total_blocks; i++){
    blocks[i] = malloc(BLOCK_SIZE * sizeof(char));
    memset(blocks[i], 0, BLOCK_SIZE);
  }

  /*Copy Input*/
  int block_num = 0;
  int char_count = 0;
  for(int i = 0; i < password_length; i++){
    blocks[block_num][char_count] = password[i];
    char_count++;
    if(char_count == BLOCK_SIZE){
      block_num++;
      char_count = 0;
    }
  }

  /*Padding*/
  blocks[block_num][char_count] = pad_char;
  memcpy(blocks[total_blocks - 1] + BLOCK_SIZE - 8, length_bits, 8);
  *num_blocks = total_blocks;
}

void hash_function(int num_blocks, char** blocks, unsigned int* hash){
  /*Initial Hash*/
  hash[0] = 0x6a09e667;
  hash[1] = 0xbb67ae85;
  hash[2] = 0x3c6ef372;
  hash[3] = 0xa54ff53a;
  hash[4] = 0x510e527f;
  hash[5] = 0x9b05688c;
  hash[6] = 0x1f83d9ab;
  hash[7] = 0x5be0cd19;

  /*Constants*/
  unsigned int K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
  };

  /*Main Loop*/
  for(int i = 0; i < num_blocks; i++){
    unsigned int W[64];
    for(int t = 0; t < 16; t++){
      W[t] = (unsigned int) blocks[i][4*t] << 24;
      W[t] |= (unsigned int) blocks[i][4*t+1] << 16;
      W[t] |= (unsigned int) blocks[i][4*t+2] << 8;
      W[t] |= (unsigned int) blocks[i][4*t+3];
    }
    for(int t = 16; t < 64; t++){
      W[t] = W[t-16] + ROTR(W[t-15],7) + W[t-7] + ROTR(W[t-2],17);
    }
    unsigned int a = hash[0];
    unsigned int b = hash[1];
    unsigned int c = hash[2];
    unsigned int d = hash[3];
    unsigned int e = hash[4];
    unsigned int f = hash[5];
    unsigned int g = hash[6];
    unsigned int h = hash[7];

    for(int t = 0; t < 64; t++){
      unsigned int T1 = h + (ROTR(e,6) ^ ROTR(e,11) ^ ROTR(e,25)) + ((e & f) ^ ((~e) & g)) + K[t] + W[t];
      unsigned int T2 = (ROTR(a,2) ^ ROTR(a,13) ^ ROTR(a,22)) + ((a & b) ^ (a & c) ^ (b & c));
      h = g;
      g = f;
      f = e;
      e = d + T1;
      d = c;
      c = b;
      b = a;
      a = T1 + T2;
    }
    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
  }
}