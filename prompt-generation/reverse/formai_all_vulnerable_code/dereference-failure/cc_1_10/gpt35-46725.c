//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//encryption function
char* encrypt(char* plaintext, int key) {
    int length = strlen(plaintext);
    int i;
    srand(time(0));
    //generate random seed for encryption
    int seed = rand()%100;
    //initialize ciphertext array
    char* ciphertext = malloc(length*sizeof(char));
    //encrypt plaintext character by character
    for(i=0;i<length;i++) {
        char ch = plaintext[i];
        //apply key and seed to character
        ch = (ch + key + seed) % 128;
        ciphertext[i] = ch;
        seed = ch + seed;
    }
    //add null terminator at the end of ciphertext
    ciphertext[length] = '\0';
    return ciphertext;
}

//decryption function
char* decrypt(char* ciphertext, int key) {
    int length = strlen(ciphertext);
    int i;
    srand(time(0));
    //generate random seed for decryption
    int seed = rand()%100;
    //initialize plaintext array
    char* plaintext = malloc(length*sizeof(char));
    //decrypt ciphertext character by character
    for(i=0;i<length;i++) {
        char ch = ciphertext[i];
        //reverse key and seed transformation applied during encryption
        ch = (ch - key - seed + 128) % 128;
        plaintext[i] = ch;
        seed = ciphertext[i] + seed;
    }
    //add null terminator at the end of plaintext
    plaintext[length] = '\0';
    return plaintext;
}

int main() {
    char* plaintext = "Hello World!";
    int key = 7;
    char* ciphertext = encrypt(plaintext,key);
    printf("Encrypted Ciphertext: %s\n",ciphertext);
    char* decrypted_plaintext = decrypt(ciphertext,key);
    printf("Decrypted Plaintext: %s\n",decrypted_plaintext);
    return 0;
}