//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned long data[8];
    struct node* next;
} node;

unsigned long h0 = 0x6a09e667;
unsigned long h1 = 0xbb67ae85;
unsigned long h2 = 0x3c6ef372;
unsigned long h3 = 0xa54ff53a;
unsigned long h4 = 0x510e527f;
unsigned long h5 = 0x9b05688c;
unsigned long h6 = 0x1f83d9ab;
unsigned long h7 = 0x5be0cd19;

unsigned long k[80];

node* root = NULL;
node* tail = NULL;

void add_to_list(unsigned long data[8]) {
    if (root == NULL) {
        root = (node*) malloc(sizeof(node));
        memcpy(root->data, data, sizeof(root->data));
        root->next = NULL;
        tail = root;
    } else {
        tail->next = (node*) malloc(sizeof(node));
        memcpy(tail->next->data, data, sizeof(tail->next->data));
        tail->next->next = NULL;
        tail = tail->next;
    }
}

int main() {

    char message[100];
    printf("Enter the message to be hashed: ");
    scanf("%[^\n]", message);

    int len = strlen(message);

    // Step 1 - Padding the message
    int padding_bytes = ((len + 8) * 8 % 512 > 0) ? 512 - ((len + 8) * 8 % 512) : 0;
    unsigned char *padded_message = (unsigned char*) calloc(len + padding_bytes + 8, sizeof(unsigned char));
    memcpy(padded_message, message, len);

    // Adding 1 bit
    padded_message[len] = 0x80;

    // Adding length
    unsigned long long bit_len = len * 8;
    memcpy(padded_message + len + padding_bytes, &bit_len, sizeof(unsigned long long));

    len += padding_bytes + 8;

    // Step 2 - Breaking the message into 512-bit chunks
    int num_chunks = len / 64;
    unsigned long chunks[num_chunks][16];
    int i, j;
    for (i = 0; i < num_chunks; i++) {
        for (j = 0; j < 16; j++) {
            int index = i * 64 + j * 4;
            chunks[i][j] = (unsigned long) ((padded_message[index] << 24) | (padded_message[index + 1] << 16)
                                            | (padded_message[index + 2] << 8) | padded_message[index + 3]);
        }
    }

    // Step 3 - Initializing constants
    int t;
    for (t = 0; t <= 79; t++) {
        int j;
        unsigned long temp = 0;
        for (j = 0; j < 32; j++) {
            temp |= (unsigned long) rand() & 1;
            temp <<= 1;
        }
        k[t] = temp;
    }

    // Step 4 - Processing each chunk
    int chunk;
    for (chunk = 0; chunk < num_chunks; chunk++) {
        unsigned long a = h0;
        unsigned long b = h1;
        unsigned long c = h2;
        unsigned long d = h3;
        unsigned long e = h4;
        unsigned long f = h5;
        unsigned long g = h6;
        unsigned long h = h7;

        for (t = 0; t <= 79; t++) {
            unsigned long temp1 = (((a << 5) | (a >> 27)) + e + k[t] + chunks[chunk][t % 16]);
            unsigned long temp2 = ((b << 30) | (b >> 2)) ^ ((b << 25) | (b >> 7)) ^ ((b << 20) | (b >> 12));
            unsigned long temp3 = ((c << 30) | (c >> 2)) ^ ((c << 19) | (c >> 13)) ^ ((c << 10) | (c >> 22));
            unsigned long temp4 = ((d << 30) | (d >> 2)) ^ ((d << 19) | (d >> 13)) ^ ((d << 10) | (d >> 22));
            unsigned long temp5 = h + temp1 + temp2 + temp3 + temp4;
            h = g;
            g = f;
            f = e;
            e = d + temp5;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2 + temp3 + temp4;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;

        unsigned long hash[8] = {h0, h1, h2, h3, h4, h5, h6, h7};
        add_to_list(hash);
    }

    // Step 5 - Outputting the hash
    node* current = root;
    while (current != NULL) {
        int i;
        for (i = 0; i < 8; i++) {
            printf("%08lx", current->data[i]);
        }
        current = current->next;
    }

    return 0;
}