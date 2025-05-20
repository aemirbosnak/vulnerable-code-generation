//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16          // Number of bytes in the key
#define BLOCK_SIZE 16        // Number of bytes in each block
#define ROUNDS 10            // Number of rounds in encryption/decryption

unsigned char* key;          // The encryption key
unsigned char s_box[256];    // The S-Box used for encryption/decription
unsigned char r_con[11][4];  // The Round Constant used for key schedule

void key_schedule(unsigned char* round_key, unsigned char round_num)
{
    unsigned char temp[4];
    int i;

    // Rotate the bytes in the last column
    temp[0] = round_key[12];
    temp[1] = round_key[13];
    temp[2] = round_key[14];
    temp[3] = round_key[15];

    round_key[12] = s_box[temp[1]] ^ r_con[round_num][0];
    round_key[13] = s_box[temp[2]] ^ r_con[round_num][1];
    round_key[14] = s_box[temp[3]] ^ r_con[round_num][2];
    round_key[15] = s_box[temp[0]] ^ r_con[round_num][3];

    // XOR the 4-byte block at the current position with the block 4 bytes before it
    for (i = 0; i < 4; i++)
        round_key[i] ^= round_key[i - 4];

    // XOR the 4-byte block at the current position with the 4-byte block 16 bytes before it
    for (i = 4; i < 16; i++)
        round_key[i] ^= round_key[i - 4];
}

void key_expansion(unsigned char* key)
{
    unsigned char temp[4];
    unsigned char round_key[16];
    int i, j;

    // Copy the encryption key into the first round key
    for (i = 0; i < KEY_SIZE; i++)
        round_key[i] = key[i];

    for (i = KEY_SIZE; i < 16 * (ROUNDS + 1); i += KEY_SIZE)
    {
        // Generate the next round key
        for (j = 0; j < 4; j++)
            temp[j] = round_key[j + 12];

        // If the current position is a multiple of the key size, apply the key schedule
        if (i % KEY_SIZE == 0)
            key_schedule(round_key, i / KEY_SIZE);

        // XOR the 4-byte block at the current position with the 4-byte block KEY_SIZE bytes before it
        for (j = 0; j < 4; j++)
            round_key[i + j] = round_key[i - KEY_SIZE + j] ^ temp[j];
    }

    // Copy the resulting round keys into the global key array
    memcpy(key, round_key, 16 * (ROUNDS + 1));
}

void sub_bytes(unsigned char* state)
{
    int i;

    for (i = 0; i < BLOCK_SIZE; i++)
        state[i] = s_box[state[i]];
}

void shift_rows(unsigned char* state)
{
    unsigned char temp[BLOCK_SIZE];
    int i, j;

    // Copy the first row unchanged
    for (i = 0; i < 4; i++)
        temp[i] = state[i];

    // Shift the second row one byte to the left
    temp[4] = state[5];
    temp[5] = state[6];
    temp[6] = state[7];
    temp[7] = state[4];

    // Shift the third row two bytes to the left
    temp[8] = state[10];
    temp[9] = state[11];
    temp[10] = state[8];
    temp[11] = state[9];

    // Shift the fourth row three bytes to the left
    temp[12] = state[15];
    temp[13] = state[12];
    temp[14] = state[13];
    temp[15] = state[14];

    // Copy the resulting state back into the original array
    memcpy(state, temp, BLOCK_SIZE);
}

void mix_columns(unsigned char* state)
{
    unsigned char temp[BLOCK_SIZE];
    int i, j;

    for (i = 0; i < 4; i++)
    {
        temp[4 * i] = state[4 * i] ^ state[4 * i + 1] ^ state[4 * i + 2] ^ state[4 * i + 3];
        temp[4 * i + 1] = state[4 * i] ^ state[4 * i + 1] ^ 0x02 * state[4 * i + 2] ^ 0x03 * state[4 * i + 3];
        temp[4 * i + 2] = state[4 * i] ^ 0x02 * state[4 * i + 1] ^ state[4 * i + 2] ^ 0x02 * state[4 * i + 3];
        temp[4 * i + 3] = state[4 * i] ^ 0x03 * state[4 * i + 1] ^ 0x02 * state[4 * i + 2] ^ state[4 * i + 3];
    }

    memcpy(state, temp, BLOCK_SIZE);
}

void add_round_key(unsigned char* state, unsigned char* round_key)
{
    int i;

    for (i = 0; i < BLOCK_SIZE; i++)
        state[i] ^= round_key[i];
}

void encrypt(unsigned char* plaintext, unsigned char* ciphertext)
{
    unsigned char state[BLOCK_SIZE];
    unsigned char round_key[16];
    int i;

    // Copy the plaintext into the state array
    memcpy(state, plaintext, BLOCK_SIZE);

    // Add the first round key
    memcpy(round_key, key, 16);
    add_round_key(state, round_key);

    // Perform the remaining rounds
    for (i = 1; i < ROUNDS; i++)
    {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        memcpy(round_key, key + 16 * i, 16);
        add_round_key(state, round_key);
    }

    // Perform the final round
    sub_bytes(state);
    shift_rows(state);
    memcpy(round_key, key + 16 * ROUNDS, 16);
    add_round_key(state, round_key);

    // Copy the resulting ciphertext back into the original array
    memcpy(ciphertext, state, BLOCK_SIZE);
}

void init_s_box()
{
    int i;

    for (i = 0; i < 256; i++)
        s_box[i] = i;

    // Apply the S-Box permutation
    int j = 0;
    for (i = 0; i < 256; i++)
    {
        j = (j + s_box[i] + key[i % KEY_SIZE]) % 256;

        unsigned char temp = s_box[i];
        s_box[i] = s_box[j];
        s_box[j] = temp;
    }
}

void init_r_con()
{
    int i, j;
    unsigned char temp[4];

    // Set the first column to 1
    r_con[0][0] = 0x01;
    r_con[0][1] = 0x00;
    r_con[0][2] = 0x00;
    r_con[0][3] = 0x00;

    // Generate the remaining columns using an XOR operation
    for (i = 1; i < 11; i++)
    {
        for (j = 0; j < 4; j++)
            temp[j] = r_con[i - 1][j];

        // Rotate the bytes in the column
        unsigned char t = temp[0];
        temp[0] = temp[1];
        temp[1] = temp[2];
        temp[2] = temp[3];
        temp[3] = t;

        // Apply the S-Box permutation to each byte in the column
        temp[0] = s_box[temp[0]];
        temp[1] = s_box[temp[1]];
        temp[2] = s_box[temp[2]];
        temp[3] = s_box[temp[3]];

        // XOR the first byte with the current round constant
        temp[0] ^= r_con[i][0];

        memcpy(r_con[i], temp, 4);
    }
}

int main()
{
    // Generate a random encryption key
    key = malloc(KEY_SIZE);
    srand(time(NULL));
    int i;
    for (i = 0; i < KEY_SIZE; i++)
        key[i] = rand() % 256;

    // Initialize the S-Box and Round Constant arrays
    init_s_box();
    init_r_con();

    // Generate the round keys
    unsigned char* round_keys = malloc(16 * (ROUNDS + 1));
    key_expansion(round_keys);

    // Test the encryption algorithm
    unsigned char plaintext[] = { 0x01, 0x23, 0x45, 0x67,
                                  0x89, 0xAB, 0xCD, 0xEF,
                                  0xFE, 0xDC, 0xBA, 0x98,
                                  0x76, 0x54, 0x32, 0x10 };
    unsigned char ciphertext[BLOCK_SIZE];
    encrypt(plaintext, ciphertext);

    // Print the results
    printf("Encryption key:\n");
    for (i = 0; i < KEY_SIZE; i++)
        printf("%02X ", key[i]);

    printf("\n\nRound keys:\n");
    for (i = 0; i < 16 * (ROUNDS + 1); i++)
    {
        printf("%02X ", round_keys[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    printf("\nPlaintext:\n");
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        printf("%02X ", plaintext[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }

    printf("\nCiphertext:\n");
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        printf("%02X ", ciphertext[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }

    // Clean up
    free(key);
    free(round_keys);

    return 0;
}