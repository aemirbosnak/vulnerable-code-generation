//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 16

typedef unsigned char byte;
typedef struct hash chunk;

struct hash {
    byte data[HASH_SIZE];
};

chunk md5(byte* message, size_t len);
chunk get_chunk(byte* data, size_t len);
char* hash_to_string(chunk hash);

int main() {
    byte* message = "This is a sample message";
    chunk hash = md5(message, strlen(message));
    char* hash_string = hash_to_string(hash);
    printf("Hash: %s\n", hash_string);
    free(hash_string);
    return 0;
}

chunk md5(byte* message, size_t len) {
    size_t padded_len = len + 64 - (len % 64);
    byte* padded_message = calloc(padded_len, 1);
    memcpy(padded_message, message, len);
    padded_message[len] = 0x80;

    size_t message_len_bits = len * 8;
    memcpy(padded_message + padded_len - 8, &message_len_bits, 4);

    byte* M = padded_message;
    byte* A = (byte*)"\x67\x45\x23\x01";
    byte* B = (byte*)"\xef\xcd\xab\x89";
    byte* C = (byte*)"\x98\xba\xdc\xfe";
    byte* D = (byte*)"\x10\x32\x54\x76";

    for (int i = 0; i < padded_len; i += 64) {
        byte* X = M + i;
        byte AA[4], BB[4], CC[4], DD[4];
        memcpy(AA, A, 4), memcpy(BB, B, 4), memcpy(CC, C, 4), memcpy(DD, D, 4);

        for (int j = 0; j < 64; j++) {
            byte F, g;
            if (j >= 0 && j < 16) {
                F = (B[j & 3] & C[j & 3]) | (~B[j & 3] & D[j & 3]);
                g = j;
            } else if (j >= 16 && j < 32) {
                F = (D[(j + (3 * (j & 1))) & 3] & B[(j + (2 * (j & 1))) & 3]) 
                  | (C[(j + (1 * (j & 1))) & 3] & ~D[(j + (2 * (j & 1))) & 3]);
                g = (5 * j + 1) & 0xf;
            } else if (j >= 32 && j < 48) {
                F = B[(j + (3 * (j & 1))) & 3] ^ C[j & 3] ^ D[(j + (2 * (j & 1))) & 3];
                g = (3 * j + 5) & 0xf;
            } else {
                F = C[(j + (1 * (j & 1))) & 3] ^ (B[(j + (2 * (j & 1))) & 3] | ~D[j & 3]);
                g = (7 * j) & 0xf;
            }

            byte tempD[4];
            memcpy(tempD, D, 4);
            memcpy(D, C, 4), memcpy(C, B, 4), memcpy(B, A, 4);
            A[0] += F, A[0] += X[g], A[0] += (byte)'\x01' + (byte)(j % 4);
            A[1] += (A[0] >> 8), A[0] &= 0xff;
            A[2] += (A[1] >> 8), A[1] &= 0xff;
            A[3] += (A[2] >> 8), A[2] &= 0xff;
            memcpy(A, tempD, 4);
        }

        A[0] += (byte)(X[7] & 0xff);
        A[1] += (byte)((X[7] >> 8) & 0xff);
        A[2] += (byte)((X[7] >> 16) & 0xff);
        A[3] += (byte)(X[7] >> 24);
        B[0] += (byte)(X[6] & 0xff);
        B[1] += (byte)((X[6] >> 8) & 0xff);
        B[2] += (byte)((X[6] >> 16) & 0xff);
        B[3] += (byte)(X[6] >> 24);
        C[0] += (byte)(X[5] & 0xff);
        C[1] += (byte)((X[5] >> 8) & 0xff);
        C[2] += (byte)((X[5] >> 16) & 0xff);
        C[3] += (byte)(X[5] >> 24);
        D[0] += (byte)(X[4] & 0xff);
        D[1] += (byte)((X[4] >> 8) & 0xff);
        D[2] += (byte)((X[4] >> 16) & 0xff);
        D[3] += (byte)(X[4] >> 24);
    }

    chunk result;
    memcpy(result.data, A, 4);
    memcpy(result.data + 4, B, 4);
    memcpy(result.data + 8, C, 4);
    memcpy(result.data + 12, D, 4);
    free(padded_message);
    return result;
}

chunk get_chunk(byte* data, size_t len) {
    chunk result;
    memcpy(result.data, data, len);
    memset(result.data + len, 0, HASH_SIZE - len);
    return result;
}

char* hash_to_string(chunk hash) {
    char* result = calloc((HASH_SIZE * 2) + 1, 1);
    for (int i = 0; i < HASH_SIZE; i++)
        sprintf(result + (i * 2), "%02x", hash.data[i]);
    return result;
}