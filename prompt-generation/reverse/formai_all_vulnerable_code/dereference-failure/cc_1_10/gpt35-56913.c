//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_MSG_LEN 100 //max message length
#define KEY_LEN 10 //key length
#define MAX_RAND 127 //max value for random number generator

char* encrypt(char* msg, char* key) {
    int len = strlen(msg);
    char* encrypted = (char*)malloc(sizeof(char) * len);

    for(int i=0; i<len; i++) {
        encrypted[i] = msg[i] ^ key[i%KEY_LEN]; //XOR operation
    }

    encrypted[len] = '\0'; //set the last character as null terminator

    return encrypted;
}

int main() {
    char msg[MAX_MSG_LEN], key[KEY_LEN], *encrypted;
    int rand_num;
    time_t t; //for random number generation using system time

    srand((unsigned) time(&t)); //seed the random number generator with system time

    printf("Enter the message to be encrypted: ");
    fgets(msg, MAX_MSG_LEN, stdin); //read the message from user

    for(int i=0; i<KEY_LEN; i++) {
        rand_num = rand() % MAX_RAND; //generate a random number within the range of MAX_RAND
        key[i] = (char)rand_num; //convert the random number to a character and assign it to key
    }

    encrypted = encrypt(msg, key); //encrypt the message using the key

    printf("The encrypted message is: %s\n", encrypted);
    printf("The key used for encryption is: ");

    for(int i=0; i<KEY_LEN; i++) {
        printf("%d ", (int)key[i]); //convert the key characters back to their ASCII values and print them
    }

    free(encrypted); //free the memory allocated for encrypted message

    return 0;
}