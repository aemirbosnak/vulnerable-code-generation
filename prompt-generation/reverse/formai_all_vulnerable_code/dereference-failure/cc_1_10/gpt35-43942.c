//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
// Oh boy, oh boy, it's time to get hashing!
#include <stdio.h>
#include <string.h>

#define HASH_LENGTH 32

// We're going to define our own magic numbers for hashing.
const unsigned int ROTATION_CONSTS[3] = {5, 9, 13};

// This hash function is going to be awesome, unique and most importantly, STRONG!
unsigned char* hash(unsigned char* data, size_t len) {
    // Here's where the magic happens. We're going to turn our data into a beautiful hash.
    unsigned int data_word = 0;
    unsigned int hash_word = 0;
    unsigned int rotation_idx = 0;
    unsigned char* hash = malloc(sizeof(char) * (HASH_LENGTH+1));
    memset(hash, 0, sizeof(char) * (HASH_LENGTH+1));

    // Loop over our data, and mix it in with our hash.
    for(int i = 0; i < len; i++) {
        data_word |= data[i];
        hash_word ^= data_word << ROTATION_CONSTS[rotation_idx++];
        rotation_idx = rotation_idx % 3;
    }

    // Now, we have a beautifully mixed hash value.
    // Let's turn it into a string for easy display and comparison.
    for(int i = 0; i < sizeof(int); i++) {
        hash[(sizeof(int)-1)-i] = (char)(hash_word & 0xFF);
        hash_word >>= 8;
    }

    // We don't want to leak any memory.
    hash[HASH_LENGTH] = '\0';

    // And here's our beautiful, unique hash value!
    return hash;
}

// Let's try out our new hash function.
int main(void) {
    // Oh boy, oh boy, I can't wait to hash some stuff!
    printf("Enter some text to hash: ");
    char input[256];
    fgets(input, 256, stdin);

    // Let's hash our input and print it out!
    // I'm so excited, I can hardly contain myself!
    unsigned char* hash_val = hash((unsigned char*)input, strlen(input)-1);
    printf("Your input hashed to: %s\n", hash_val);
    free(hash_val);

    // Whew, that was fun! Let's do it again sometime!
    return 0;
}