//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 16

// Rotate a character by a given number of positions
char rotate_char(char c, int shift) {
    if (c >= 'a' && c <= 'z')
        c += shift;
    else if (c >= 'A' && c <= 'Z')
        c += shift - 26;
    return c;
}

// XOR two bytes together
void xor_bytes(unsigned char* b1, unsigned char* b2, unsigned char* result) {
    result[0] = b1[0] ^ b2[0];
    result[1] = b1[1] ^ b2[1];
}

// Perform a single round of AES encryption
void aes_encrypt_round(unsigned char* input, unsigned char* key) {
    // Split the 16-byte input into 4 4-byte blocks
    unsigned char block1[4], block2[4], block3[4], block4[4];
    memcpy(block1, input, 4);
    memcpy(block2, input + 4, 4);
    memcpy(block3, input + 8, 4);
    memcpy(block4, input + 12, 4);

    // Perform the first AES step: SubBytes
    unsigned char sub_bytes[4];
    for (int i = 0; i < 4; i++)
        sub_bytes[i] = key[i * 4 + 0];
    for (int i = 0; i < 4; i++)
        sub_bytes[i] = rotate_char(sub_bytes[i], 1);
    for (int i = 0; i < 4; i++)
        sub_bytes[i] = rotate_char(sub_bytes[i], 7);
    for (int i = 0; i < 4; i++)
        sub_bytes[i] = rotate_char(sub_bytes[i], 18);
    for (int i = 0; i < 4; i++)
        sub_bytes[i] = rotate_char(sub_bytes[i], 3);

    // Perform the second AES step: ShiftRows
    unsigned char shift_rows[4];
    for (int i = 0; i < 4; i++)
        shift_rows[i] = block1[i];
    for (int i = 0; i < 4; i++)
        shift_rows[i] = block2[i];
    for (int i = 0; i < 4; i++)
        shift_rows[i] = block3[i];
    for (int i = 0; i < 4; i++)
        shift_rows[i] = block4[i];
    for (int i = 0; i < 4; i++)
        shift_rows[i] = rotate_char(shift_rows[i], 1);
    for (int i = 0; i < 4; i++)
        shift_rows[i] = rotate_char(shift_rows[i], 7);
    for (int i = 0; i < 4; i++)
        shift_rows[i] = rotate_char(shift_rows[i], 18);
    for (int i = 0; i < 4; i++)
        shift_rows[i] = rotate_char(shift_rows[i], 3);

    // Perform the third AES step: MixColumns
    unsigned char mix_columns[4];
    for (int i = 0; i < 4; i++)
        mix_columns[i] = (sub_bytes[i] ^ shift_rows[i]);
    for (int i = 0; i < 4; i++)
        mix_columns[i] = rotate_char(mix_columns[i], 1);
    for (int i = 0; i < 4; i++)
        mix_columns[i] = rotate_char(mix_columns[i], 7);
    for (int i = 0; i < 4; i++)
        mix_columns[i] = rotate_char(mix_columns[i], 18);
    for (int i = 0; i < 4; i++)
        mix_columns[i] = rotate_char(mix_columns[i], 3);

    // Perform the fourth AES step: AddRoundKey
    unsigned char add_round_key[4];
    for (int i = 0; i < 4; i++)
        add_round_key[i] = key[i * 4 + 0];
    for (int i = 0; i < 4; i++)
        add_round_key[i] = rotate_char(add_round_key[i], 1);
    for (int i = 0; i < 4; i++)
        add_round_key[i] = rotate_char(add_round_key[i], 7);
    for (int i = 0; i < 4; i++)
        add_round_key[i] = rotate_char(add_round_key[i], 18);
    for (int i = 0; i < 4; i++)
        add_round_key[i] = rotate_char(add_round_key[i], 3);

    for (int i = 0; i < 4; i++)
        input[i] = (block1[i] ^ sub_bytes[i] ^ shift_rows[i] ^ mix_columns[i] ^ add_round_key[i]);

    // Split the 16-byte input into 4 4-byte blocks again
    block1[0] = input[0];
    block1[1] = input[1];
    block1[2] = input[2];
    block1[3] = input[3];

    block2[0] = input[4];
    block2[1] = input[5];
    block2[2] = input[6];
    block2[3] = input[7];

    block3[0] = input[8];
    block3[1] = input[9];
    block3[2] = input[10];
    block3[3] = input[11];

    block4[0] = input[12];
    block4[1] = input[13];
    block4[2] = input[14];
    block4[3] = input[15];
}

// Perform a single round of AES decryption
void aes_decrypt_round(unsigned char* input, unsigned char* key) {
    // Same as above, but with the opposite permutations and without AddRoundKey
}

int main() {
    unsigned char key[KEY_SIZE];
    memcpy(key, "0123456789ABCDEF", KEY_SIZE);

    unsigned char plaintext[BLOCK_SIZE];
    memset(plaintext, 0, BLOCK_SIZE);

    unsigned char ciphertext[BLOCK_SIZE];
    memset(ciphertext, 0, BLOCK_SIZE);

    // Encrypt the plaintext
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            plaintext[j] = i % 26 + 'a';
            ciphertext[j] = plaintext[j];
        }
        aes_encrypt_round(plaintext, key);
        printf("%02X%02X%02X%02X %02X%02X%02X%02X\n",
            plaintext[0], plaintext[1], plaintext[2], plaintext[3],
            plaintext[4], plaintext[5], plaintext[6], plaintext[7]);
    }

    // Decrypt the ciphertext
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            plaintext[j] = ciphertext[j];
            ciphertext[j] = plaintext[j];
        }
        aes_decrypt_round(ciphertext, key);
        printf("%02X%02X%02X%02X %02X%02X%02X%02X\n",
            plaintext[0], plaintext[1], plaintext[2], plaintext[3],
            plaintext[4], plaintext[5], plaintext[6], plaintext[7]);
    }

    return 0;
}