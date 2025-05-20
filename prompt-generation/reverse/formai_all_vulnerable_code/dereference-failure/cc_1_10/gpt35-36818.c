//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// SHA512 Constants
const uint64_t K[] = { 0x428A2F98D728AE22, 0x7137449123EF65CD, 0xB5C0FBCFEC4D3B2F, 0xE9B5DBA58189DBBC, 
                      0x3956C25BF348B538, 0x59F111F1B605D019, 0x923F82A4AF194F9B, 0xAB1C5ED5DA6D8118, 
                      0xD807AA98A3030242, 0x12835B0145706FBE, 0x243185BE4EE4B28C, 0x550C7DC3D5FFB4E2, 
                      0x72BE5D74F27B896F, 0x80DEB1FE3B1696B1, 0x9BDC06A725C71235, 0xC19BF174CF692694, 
                      0xE49B69C19EF14AD2, 0xEFBE4786384F25E3, 0x0FC19DC68B8CD5B5, 0x240CA1CC77AC9C65, 
                      0x2DE92C6F592B0275, 0x4A7484AA6EA6E483, 0x5CB0A9DCBD41FBD4, 0x76F988DA831153B5, 
                      0x983E5152EE66DFAB, 0xA831C66D2DB43210, 0xB00327C898FB213F, 0xBF597FC7BEEF0EE4, 
                      0xC6E00BF33DA88FC2, 0xD5A79147930AA725, 0x06CA6351E003826F, 0x142929670A0E6E70, 
                      0x27B70A8546D22FFC, 0x2E1B21385C26C926, 0x4D2C6DFC5AC42AED, 0x53380D139D95B3DF, 
                      0x650A73548BAF63DE, 0x766A0ABB3C77B2A8, 0x81C2C92E47EDAEE6, 0x92722C851482353B, 
                      0xA2BFE8A14CF10364, 0xA81A664BBC423001, 0xC24B8B70D0F89791, 0xC76C51A30654BE30, 
                      0xD192E819D6EF5218, 0xD69906245565A910, 0xF40E35855771202A, 0x106AA07032BBD1B8, 
                      0x19A4C116B8D2D0C8, 0x1E376C085141AB53, 0x2748774CDF8EEB99, 0x34B0BCB5E19B48A8, 
                      0x391C0CB3C5C95A63, 0x4ED8AA4AE3418ACB, 0x5B9CCA4F7763E373, 0x682E6FF3D6B2B8A3, 
                      0x748F82EE5DEFB2FC, 0x78A5636F43172F60, 0x84C87814A1F0AB72, 0x8CC702081A6439EC, 
                      0x90BEFFFA23631E28, 0xA4506CEBDE82BDE9, 0xBEF9A3F7B2C67915, 0xC67178F2E372532B, 
                      0xCA273ECEEA26619C, 0xD186B8C721C0C207, 0xEADA7DD6CDE0EB1E, 0xF57D4F7FEE6ED178, 
                      0x06F067AA72176FBA, 0x0A637DC5A2C898A6, 0x113F9804BEF90DAE, 0x1B710B35131C471B, 
                      0x28DB77F523047D84, 0x32CAAB7B40C72493, 0x3C9EBE0A15C9BEBC, 0x431D67C49C100D4C, 
                      0x4CC5D4BECB3E42B6, 0x597F299CFC657E2A, 0x5FCB6FAB3AD6FAEC, 0x6C44198C4A475817 };

// SHA512 Initial Hash Value
const uint64_t H[] = { 0x6A09E667F3BCC908, 0xBB67AE8584CAA73B, 0x3C6EF372FE94F82B, 0xA54FF53A5F1D36F1,
                      0x510E527FADE682D1, 0x9B05688C2B3E6C1F, 0x1F83D9ABFB41BD6B, 0x5BE0CD19137E2179 };

// Right Rotate
#define RO(x, n) ((x >> n) | (x << (64 - n)))

// Ch
#define CH(x, y, z) ((x & y) ^ (~x & z))

// Maj
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

// Sigma0
#define SG0(x) (RO(x, 28) ^ RO(x, 34) ^ RO(x, 39))

// Sigma1
#define SG1(x) (RO(x, 14) ^ RO(x, 18) ^ RO(x, 41))

// sigma0
#define sg0(x) (RO(x, 1) ^ RO(x, 8) ^ (x >> 7))

// sigma1
#define sg1(x) (RO(x, 19) ^ RO(x, 61) ^ (x >> 6))

// Big Endian to Little Endian Conversion
static void BEtoLE (uint64_t *W, int n)
{
    int i;
    uint8_t j;
    union {
        uint64_t w;
        uint8_t c[8];
    } conv;
    for (i = 0; i < n; i++) {
        conv.w = W[i];
        for (j = 0; j < 8; j++) W[i] = (W[i] << 8) + conv.c[j];
    }
}

// SHA512 Compression Function
static uint64_t *SHA512_cps (uint8_t *M, uint64_t *H)
{
    int i, j;
    uint64_t W[80], a, b, c, d, e, f, g, h, T1, T2;
    uint64_t *H_new = (uint64_t *) malloc(8 * sizeof(uint64_t));

    // Initialize Hash Values a, b, c, d, e, f, g, h with the previous hash value 
    a = H[0]; b = H[1]; c = H[2]; d = H[3]; e = H[4]; f = H[5]; g = H[6]; h = H[7];

    // Prepare the message schedule W
    for (i = 0; i < 16; i++) W[i] = ((uint64_t) M[i*8] << 56) + ((uint64_t) M[i*8+1] << 48) 
                                     + ((uint64_t) M[i*8+2] << 40) + ((uint64_t) M[i*8+3] << 32) 
                                     + ((uint64_t) M[i*8+4] << 24) + ((uint64_t) M[i*8+5] << 16) 
                                     + ((uint64_t) M[i*8+6] << 8) + ((uint64_t) M[i*8+7]);
    for (i = 16; i < 80; i++) W[i] = sg1(W[i-2]) + W[i-7] + sg0(W[i-15]) + W[i-16];

    // Initialize working variables T1 and T2
    for (i = 0; i < 80; i++) {
        T1 = h + SG1(e) + CH(e, f, g) + K[i] + W[i];
        T2 = SG0(a) + MAJ(a, b, c);
        h = g; g = f; f = e; e = d + T1; d = c; c = b; b = a; a = T1 + T2;
    }

    // Compute the intermediate hash value by adding the previous hash value
    // to the temporary hash value
    H_new[0] = a + H[0];
    H_new[1] = b + H[1];
    H_new[2] = c + H[2];
    H_new[3] = d + H[3];
    H_new[4] = e + H[4];
    H_new[5] = f + H[5];
    H_new[6] = g + H[6];
    H_new[7] = h + H[7];

    return H_new;
}

// SHA512 Padding
static uint8_t *SHA512_padding (uint8_t *M, uint64_t len, uint64_t *n)
{
    uint64_t bit_len = len * 8;
    uint8_t *M_padded = (uint8_t *) malloc((len + 128) * sizeof(uint8_t));

    // Copy the message M into a new buffer
    memcpy(M_padded, M, len);

    // Padding the message M
    M_padded[len] = 0x80;
    if ((len % 128) < 112) {
        memset(M_padded+len+1, 0, 112 - len%128 - 1);
    } else {
        memset(M_padded+len+1, 0, 128+112 - len%128 - 1);
    }
    for (int i = 0; i < 8; i++) {
        M_padded[len+128-1-i] = bit_len >> (8 * i);
    }

    *n = (len + 128) / 128;

    return M_padded;
}

// SHA512 Hash
void SHA512_hash (uint8_t *M, uint64_t len, uint64_t *H)
{
    uint64_t n, i;
    uint8_t *M_padded = SHA512_padding(M, len, &n);

    // Process each block of padded message
    for (i = 0; i < n; i++) {
        BEtoLE((uint64_t *)(M_padded + i*128), 16);
        H = SHA512_cps(M_padded + i*128, H);
    }

    free(M_padded);
}

int main()
{
    // Input Message
    char *msg = "This is a sample message to test SHA-512 Algorithm.";

    // Get the length of input message
    uint64_t len = strlen(msg);

    // Hash the message
    uint64_t *H = (uint64_t *) malloc(8 * sizeof(uint64_t));
    memcpy(H, H, 8 * sizeof(uint64_t));
    SHA512_hash((uint8_t *) msg, len, H);

    // Output the hash value
    printf("Message: %s\n", msg);
    printf("\nHash Value (in hex):\n");
    for (int i = 0; i < 8; i++) printf("%016lx", H[i]);
    printf("\n");

    free(H);

    return 0;
}