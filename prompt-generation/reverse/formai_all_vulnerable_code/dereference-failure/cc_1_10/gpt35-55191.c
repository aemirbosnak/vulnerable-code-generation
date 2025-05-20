//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define KEY_LEN 16 //length of our key

//function to generate a key 
char *generate_key(){
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; //our character set
    char *key = malloc(KEY_LEN + 1); //allocate space for our key
    int i;
    for(i = 0; i < KEY_LEN; i++){
        key[i] = charset[rand() % strlen(charset)]; //fill our key with random characters from our character set
    }
    key[KEY_LEN] = '\0'; //make sure our key is null terminated
    return key;
}

//function to encrypt plaintext using our key
char *encrypt(char *plaintext, char *key){
    int plaintext_len = strlen(plaintext); //get length of our plaintext
    char *ciphertext = malloc(plaintext_len + 1); //allocate space for our ciphertext
    int i;
    for (i = 0; i < plaintext_len; i++){
        ciphertext[i] = plaintext[i] + key[i % KEY_LEN]; //encrypt our plaintext by adding the key character at the same position
    }
    ciphertext[plaintext_len] = '\0'; //make sure our ciphertext is null terminated
    return ciphertext;
}

//function to decrypt ciphertext using our key
char *decrypt(char *ciphertext, char *key){
    int ciphertext_len = strlen(ciphertext); //get length of our ciphertext
    char *plaintext = malloc(ciphertext_len + 1); //allocate space for our plaintext
    int i;
    for (i = 0; i < ciphertext_len; i++){
        plaintext[i] = ciphertext[i] - key[i % KEY_LEN]; //decrypt our ciphertext by subtracting the key character at the same position
    }
    plaintext[ciphertext_len] = '\0'; //make sure our plaintext is null terminated
    return plaintext;
}

int main(){
    srand(time(NULL)); //seed our random generator
    char *plaintext = "Hello World!"; //our plaintext
    char *key = generate_key(); //generate a key
    char *ciphertext = encrypt(plaintext, key); //encrypt our plaintext using the key
    char *decrypted_plaintext = decrypt(ciphertext, key); //decrypt our ciphertext using the key
    
    printf("Plaintext: %s\n", plaintext); //print our original plaintext
    printf("Key: %s\n", key); //print the key
    printf("Ciphertext: %s\n", ciphertext); //print the ciphertext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext); //print the decrypted plaintext
    
    free(key); //free the memory we allocated for the key
    free(ciphertext); //free the memory we allocated for the ciphertext
    free(decrypted_plaintext); //free the memory we allocated for the decrypted plaintext
    
    return 0;
}