//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16

// Function to perform XOR operation on two strings
char* perform_xor(char* a, char* b){
    char* result = malloc(BLOCK_SIZE+1);
    for(int i=0;i<BLOCK_SIZE;i++){
        result[i] = a[i] ^ b[i];
    }
    result[BLOCK_SIZE] = '\0';
    return result;
}

// Function to perform encryption of a block
char* encrypt_block(char* plaintext, char* key){
    char* ciphertext = malloc(BLOCK_SIZE+1);
    char* v = malloc(BLOCK_SIZE+1);
    char* tmp;
    memset(v, 0, BLOCK_SIZE+1);

    // Perform encryption using CBC mode
    for(int i=0;i<BLOCK_SIZE;i++){
        tmp = perform_xor(&plaintext[i],&v[i]);
        tmp = perform_xor(tmp,key);
        memcpy(&ciphertext[i],tmp,1);
        memcpy(&v[i],tmp,1);
        free(tmp);
    }

    ciphertext[BLOCK_SIZE] = '\0';
    free(v);
    return ciphertext;
}

// Function to perform encryption of a message using given key
char* encrypt(char* plaintext, char* key){
    int len = strlen(plaintext);
    char* ciphertext = malloc(len+1);
    char* block = malloc(BLOCK_SIZE+1);
    char* tmp;

    // Pad the message with zeros if its length is not multiple of block size
    int num_blocks = len/BLOCK_SIZE + ((len%BLOCK_SIZE)?1:0);
    int pad_len = num_blocks * BLOCK_SIZE;

    while(len < pad_len){
        plaintext[len] = '\0';
        len++;
    }

    // Perform encryption of each block using encrypt_block function
    for(int i=0;i<num_blocks;i++){
        memcpy(block,&plaintext[i*BLOCK_SIZE],BLOCK_SIZE);
        tmp = encrypt_block(block,key);
        memcpy(&ciphertext[i*BLOCK_SIZE],tmp,BLOCK_SIZE);
        free(tmp);
    }

    ciphertext[pad_len] = '\0';
    free(block);
    return ciphertext;
}

int main(){
    char plaintext[] = "Hello, World!";
    char key[] = "secretkey";
    char* ciphertext = encrypt(plaintext,key);

    printf("Plaintext : %s\n",plaintext);
    printf("Key : %s\n",key);
    printf("Ciphertext : %s\n",ciphertext);

    return 0;
}