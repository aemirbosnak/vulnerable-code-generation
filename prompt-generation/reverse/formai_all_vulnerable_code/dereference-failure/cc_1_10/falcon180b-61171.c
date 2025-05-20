//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define ROUNDS 100

struct block{
    unsigned char data[BLOCK_SIZE];
};

struct key{
    unsigned char data[KEY_SIZE];
};

void encrypt(struct block *plaintext, struct key *key){
    unsigned char temp[BLOCK_SIZE];
    int i,j;
    for(i=0;i<ROUNDS;i++){
        for(j=0;j<BLOCK_SIZE;j++){
            temp[j] = plaintext->data[j] ^ key->data[i*BLOCK_SIZE+j];
        }
        memcpy(plaintext->data,temp,BLOCK_SIZE);
    }
}

void decrypt(struct block *ciphertext, struct key *key){
    unsigned char temp[BLOCK_SIZE];
    int i,j;
    for(i=0;i<ROUNDS;i++){
        for(j=0;j<BLOCK_SIZE;j++){
            temp[j] = ciphertext->data[j] ^ key->data[i*BLOCK_SIZE+j];
        }
        memcpy(ciphertext->data,temp,BLOCK_SIZE);
    }
}

int main(){
    struct block plaintext,ciphertext;
    struct key key;
    int i;
    char *message = "Hello World! ";
    unsigned char *p = (unsigned char *)message;
    for(i=0;i<strlen(message);i++){
        plaintext.data[i] = *p++;
    }
    for(i=0;i<KEY_SIZE;i++){
        key.data[i] = rand()%256;
    }
    encrypt(&plaintext,&key);
    printf("Encrypted Message: ");
    for(i=0;i<BLOCK_SIZE;i++){
        printf("%d ",plaintext.data[i]);
    }
    printf("\n");
    decrypt(&plaintext,&key);
    printf("Decrypted Message: ");
    for(i=0;i<BLOCK_SIZE;i++){
        printf("%c ",plaintext.data[i]);
    }
    printf("\n");
    return 0;
}