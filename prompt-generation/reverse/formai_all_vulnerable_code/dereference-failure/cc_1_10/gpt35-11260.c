//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define AES_BLOCK_SIZE 16

uint8_t SBOX[256] = {
    /*0x00 to 0x0f*/
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    /*0x10 to 0x1f*/
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    /*0x20 to 0x2f*/
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
    /*0x30 to 0x3f*/
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
    /*0x40 to 0x4f*/
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
    /*0x50 to 0x5f*/
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
    /*0x60 to 0x6f*/
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
    /*0x70 to 0x7f*/
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
    /*0x80 to 0x8f*/
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
    /*0x90 to 0x9f*/
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
    /*0xa0 to 0xaf*/
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
    /*0xb0 to 0xbf*/
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
    /*0xc0 to 0xcf*/
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
    /*0xd0 to 0xdf*/
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
    /*0xe0 to 0xef*/
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
    /*0xf0 to 0xff*/
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16,
};

uint8_t RCON[10] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36
};

uint8_t mult2(uint8_t a) {
    if(a >> 7) {
        a <<= 1;
        a ^= 0x1B;  /* XOR with the polynomial 0x11b */
    } else {
        a <<= 1;
    }
    return a;
}

void shiftrows(uint8_t *block) {
    uint8_t temp;

    /* no shift for row 0 */
    /* shift left for row 1 */
    temp = block[1];
    block[1] = block[5];
    block[5] = block[9];
    block[9] = block[13];
    block[13] = temp;
  
    /* shift left twice for row 2 */
    temp = block[2];
    block[2] = block[10];
    block[10] = temp;
    temp = block[6];
    block[6] = block[14];
    block[14] = temp;
  
    /* shift left three times for row 3 */
    temp = block[15];
    block[15] = block[11];
    block[11] = block[7];
    block[7] = block[3];
    block[3] = temp;
}

void mixcolumns(uint8_t *block) {
    uint8_t i;
    uint8_t a[4];
    uint8_t b[4];
    uint8_t c;
    uint8_t h;

    for(i = 0; i < 4; i++) {
        a[i] = block[i];
        h = block[i] & 0x80;
        b[i] = block[i] << 1;
        if(h == 0x80) {
            b[i] ^= 0x1B;
        }
    }

    block[0] = b[0] ^ mult2(a[1] ^ a[2]) ^ a[3];
    block[1] = b[1] ^ mult2(a[2] ^ a[3]) ^ a[0];
    block[2] = b[2] ^ mult2(a[3] ^ a[0]) ^ a[1];
    block[3] = b[3] ^ mult2(a[0] ^ a[1]) ^ a[2];

    for(i = 4; i < 8; i++) {
        c = block[i + 4];
        a[i - 4] = c;
        h = c & 0x80;
        b[i - 4] = c << 1;
        if(h == 0x80) {
            b[i - 4] ^= 0x1B;
        }
    }
  
    block[4] = b[0] ^ mult2(a[1] ^ a[2]) ^ a[3];
    block[5] = b[1] ^ mult2(a[2] ^ a[3]) ^ a[0];
    block[6] = b[2] ^ mult2(a[3] ^ a[0]) ^ a[1];
    block[7] = b[3] ^ mult2(a[0] ^ a[1]) ^ a[2];

    for(i = 8; i < 12; i++) {
        c = block[i + 4];
        a[i - 8] = c;
        h = c & 0x80;
        b[i - 8] = c << 1;
        if(h == 0x80) {
            b[i - 8] ^= 0x1B;
        }
    }

    block[8] = b[0] ^ mult2(a[1] ^ a[2]) ^ a[3];
    block[9] = b[1] ^ mult2(a[2] ^ a[3]) ^ a[0];
    block[10] = b[2] ^ mult2(a[3] ^ a[0]) ^ a[1];
    block[11] = b[3] ^ mult2(a[0] ^ a[1]) ^ a[2];

    for(i = 12; i < 16; i++) {
        c = block[i + 4];
        a[i - 12] = c;
        h = c & 0x80;
        b[i - 12] = c << 1;
        if(h == 0x80) {
            b[i - 12] ^= 0x1B;
        }
    }
  
    block[12] = b[0] ^ mult2(a[1] ^ a[2]) ^ a[3];
    block[13] = b[1] ^ mult2(a[2] ^ a[3]) ^ a[0];
    block[14] = b[2] ^ mult2(a[3] ^ a[0]) ^ a[1];
    block[15] = b[3] ^ mult2(a[0] ^ a[1]) ^ a[2];
}

void addroundkey(uint8_t *block, uint8_t *key) {
    int i;
    for(i = 0; i < AES_BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

void subbytes(uint8_t *block) {
    uint8_t i;
    for(i = 0; i < AES_BLOCK_SIZE; i++) {
        block[i] = SBOX[block[i]];
    }
}

void keyexpansion(uint8_t *key, uint8_t *w) {
    uint8_t temp[4];
    uint8_t i;
    uint8_t k;
    uint8_t len = 16;
    int j;

    for(i = 0; i < len; i++) {
        w[i] = key[i];
    }

    k = 16;
    i = 1;
    while(k < 176) {
        /* copy the previous 4 bytes to temp */
        memcpy(temp, &w[k - 4], 4);

        /* perform the core key schedule operations */
        if(k % len == 0) {
            /* rotate the 4 bytes in temp */
            j = 0;
            temp[j] = SBOX[temp[1]];
            temp[j+1] = SBOX[temp[2]];
            temp[j+2] = SBOX[temp[3]];
            temp[j+3] = SBOX[temp[0]];

            /* XOR the RCON value */
            temp[0] ^= RCON[i-1];

            i++;
        }
        else if((len > 24) && (k % len == 16)) {
            /* only apply the SBOX to the first byte */
            temp[0] = SBOX[temp[0]];
            temp[1] = SBOX[temp[1]];
            temp[2] = SBOX[temp[2]];
            temp[3] = SBOX[temp[3]];
        }

        /* XOR temp with the 4-byte block n bytes before it */
        temp[0] ^= w[k - len];
        temp[1] ^= w[k + 1 - len];
        temp[2] ^= w[k + 2 - len];
        temp[3] ^= w[k + 3 - len];

        /* copy the generated bytes into the key schedule */
        memcpy(&w[k], temp, 4);

        k += 4;
    }
}

int main(void) {
    uint8_t key[16] = { 0x2b, 0x7e, 0x15, 0x16,
                        0x28, 0xae, 0xd2, 0xa6,
                        0xab, 0xf7, 0x15, 0x88,
                        0x09, 0xcf, 0x4f, 0x3c };
    uint8_t plaintext[16] = { 0x32, 0x43, 0xf6, 0xa8,
                              0x88, 0x5a, 0x30, 0x8d,
                              0x31, 0x31, 0x98, 0xa2,
                              0xe0, 0x37, 0x07, 0x34 };
    uint8_t key_schedule[176];

    keyexpansion(key, key_schedule);

    printf("Plaintext: ");

    int i;
    for(i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x ", plaintext[i]);
    }

    printf("\n\n");

    addroundkey(plaintext, key_schedule);

    printf("After initial AddRoundKey: ");

    for(i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x ", plaintext[i]);
    }

    printf("\n\n");

    int r;
    for(r = 1; r < 10; r++) {
        subbytes(plaintext);
        shiftrows(plaintext);
        mixcolumns(plaintext);
        addroundkey(plaintext, &key_schedule[r * AES_BLOCK_SIZE]);

        printf("After round %d: ", r);

        for(i = 0; i < AES_BLOCK_SIZE; i++) {
            printf("%02x ", plaintext[i]);
        }

        printf("\n\n");
    }

    subbytes(plaintext);
    shiftrows(plaintext);
    addroundkey(plaintext, &key_schedule[10 * AES_BLOCK_SIZE]);

    printf("After final round: ");

    for(i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x ", plaintext[i]);
    }

    printf("\n\n");

    return 0;
}