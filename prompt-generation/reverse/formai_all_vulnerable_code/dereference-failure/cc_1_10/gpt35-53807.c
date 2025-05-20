//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t byte;

// The S-box table
byte S[256] = {  // randomly generated values
    196, 221, 15, 37, 80, 130, 72, 79, 189, 5, 156, 25, 162, 224, 21, 151, 
    163, 229, 111, 49, 4, 168, 250, 47, 122, 96, 231, 67, 39, 0, 28, 85, 
    20, 129, 218, 209, 162, 2, 130, 105, 157, 33, 53, 145, 183, 87, 238, 
    117, 241, 39, 244, 124, 119, 168, 215, 27, 236, 212, 171, 147, 105, 
    91, 137, 13, 113, 237, 214, 87, 166, 100, 99, 230, 158, 105, 126, 
    76, 8, 251, 10, 150, 116, 238, 78, 28, 222, 68, 107, 37, 138, 221, 
    72, 146, 225, 203, 67, 27, 10, 110, 233, 51, 185, 131, 181, 16, 141, 
    93, 78, 38, 36, 163, 89, 225, 43, 160, 63, 33, 82, 191, 98, 78, 26, 
    80, 230, 12, 246, 221, 117, 210, 127, 17, 117, 171, 193, 253, 78, 
    80, 135, 123, 183, 101, 153, 244, 77, 179, 180, 64, 102, 4, 154, 
    149, 23, 135, 108, 202, 235, 20, 17, 147, 240, 77, 224, 200, 247, 
    62, 16, 174, 21, 117, 236, 183, 168, 207, 204, 121, 119, 245, 117, 
    205, 20, 170, 179, 134, 31, 8, 15, 110, 76, 78, 188, 51, 61, 204, 
    185, 134, 196, 45, 123, 174, 155, 134, 55, 239, 125, 105, 1, 205, 
    38, 208, 47, 108, 198, 205, 70, 200, 183, 196, 53, 239, 53, 106, 
    44, 181, 56, 172, 5, 211, 4, 203, 6, 34, 55, 24, 64, 147, 46, 51, 
    108, 35, 115, 152, 178, 172, 121, 110, 94, 171, 225, 186, 216, 107
};

// The P-box permutation values
byte P[256] = {  // randomly generated values
    36, 91, 77, 74, 103, 50, 67, 185, 210, 91, 12, 14, 202, 164, 135, 25, 
    98, 230, 16, 72, 70, 25, 177, 43, 81, 95, 118, 60, 103, 17, 222, 19, 
    22, 2, 44, 26, 96, 201, 93, 157, 121, 244, 65, 210, 160, 94, 122, 
    183, 79, 98, 204, 227, 180, 79, 53, 23, 34, 210, 51, 202, 57, 79, 
    169, 165, 34, 138, 25, 206, 241, 41, 73, 101, 15, 77, 174, 81, 7, 
    98, 177, 231, 212, 105, 217, 123, 25, 16, 239, 111, 242, 71, 171, 
    5, 120, 32, 137, 237, 61, 49, 107, 169, 234, 82, 191, 209, 223, 233, 
    175, 34, 145, 218, 12, 2, 93, 35, 230, 57, 97, 38, 103, 130, 116, 
    105, 220, 60, 197, 157, 229, 176, 54, 225, 50, 66, 131, 120, 223, 
    194, 54, 128, 236, 184, 4, 4, 30, 161, 120, 23, 187, 188, 70, 86, 
    85, 3, 42, 23, 177, 200, 133, 224, 218, 103, 34, 133, 250, 207, 
    190, 30, 94, 175, 183, 31, 227, 50, 82, 92, 220, 66, 234, 105, 
    223, 149, 0, 78, 0, 142, 137, 40, 66, 29, 47, 247, 67, 196, 250, 
    178, 16, 3, 189, 213, 125, 206, 78, 5, 153, 176, 44, 47, 92, 126, 
    220, 188, 220, 247, 74, 224, 172, 50, 156, 150, 176, 203, 246, 175, 
    103, 28, 172, 124, 43, 134, 105, 99, 85, 27, 38, 179, 164, 75, 89, 
    230, 31, 196, 45, 145, 214, 62, 16
};

// The calculated parity bit
byte parity(byte b) {
    b ^= b >> 8;  // XOR the 8 bits into the upper 4 bits
    b ^= b >> 4;  // XOR the upper 4 bits into the lower 4 bits
    b ^= b >> 2;  // XOR bits 2 and 3 into the lowest bit
    b ^= b >> 1;  // XOR bits 1 and 4 into the lowest bit
    return b & 1;  // Return only the lowest bit (parity bit)
}

// Encryption function using the S-box and P-box algorithms
void encrypt(byte *data, size_t len, byte *key, size_t key_len) {
    size_t i, j;
    byte t, x, y, z;
    byte key_parity = 0;

    if (key_len == 0) {
        return;  // Cannot encrypt without a key
    }

    // Calculate the parity bit of the key
    for (i = 0; i < key_len; i++) {
        key_parity ^= parity(key[i]);
    }

    // Add the key parity bit to the end of the data
    data[len++] = key_parity;

    // Iterate through the data bytes
    for (i = 0; i < len; i++) {
        x = data[i];
        y = key[i % key_len];
        z = S[(x + y) % 256];
        t = P[i % 256];
        S[x] = S[y];
        S[y] = S[z];
        S[z] = S[t];
        data[i] = z;
    }
}

// Decryption function using the S-box and P-box algorithms
void decrypt(byte *data, size_t len, byte *key, size_t key_len) {
    size_t i, j;
    byte t, x, y, z;
    byte key_parity = 0;

    if (key_len == 0) {
        return;  // Cannot decrypt without a key
    }

    // Calculate the parity bit of the key
    for (i = 0; i < key_len; i++) {
        key_parity ^= parity(key[i]);
    }

    // Verify the key parity bit
    if (key_parity != data[len - 1]) {
        return;  // Incorrect key or corrupted data
    }

    // Iterate through the data bytes
    for (i = len - 1; i > 0; i--) {
        x = data[i];
        y = key[(i - 1) % key_len];
        t = P[(i - 1) % 256];
        z = S[t];
        S[t] = S[z];
        S[z] = S[y];
        S[y] = S[x];
        data[i] = z - y;
    }
    data[0] -= key[0] % 256;  // Final transformation
}

// Test case
int main() {
    byte data[] = { 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde };
    byte key[] = { 0x12, 0x34, 0x56, 0x78 };
    size_t data_len = sizeof(data) / sizeof(byte);
    size_t key_len = sizeof(key) / sizeof(byte);

    // Encrypt the data
    encrypt(data, data_len, key, key_len);

    // Print the encrypted data
    printf("Encrypted data: ");
    for (size_t i = 0; i < data_len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    // Decrypt the data
    decrypt(data, data_len, key, key_len);

    // Print the decrypted data
    printf("Decrypted data: ");
    for (size_t i = 0; i < data_len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");

    return 0;
}