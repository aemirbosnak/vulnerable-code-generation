//FormAI DATASET v1.0 Category: modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1000
#define ENCRYPTED_FILE "encrypted.txt"
#define DECRYPTED_FILE "decrypted.txt"

char message[MAX_LEN];
int key[MAX_LEN];

void encrypt(char *m, int *k) {
    int len = strlen(m);
    for (int i = 0; i < len; i++) {
        k[i] = rand() % 1000; // generate random key value
        m[i] = m[i] + k[i]; // adding key value to ASCII code of character
    }
}

void decrypt(char *m, int *k) {
    int len = strlen(m);
    for (int i = 0; i < len; i++) {
        m[i] = m[i] - k[i]; // subtracting key value from ASCII code of character
    }
}

int main() {
    printf("Enter message to be encrypted: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = 0; // remove newline character from string
    
    srand(time(NULL)); // seed for rand()
    
    encrypt(message, key); // encrypt message using key
    
    FILE *fp = fopen(ENCRYPTED_FILE, "w"); // write encrypted message to file
    fprintf(fp, "%s\n", message);
    for (int i = 0; i < strlen(message); i++) {
        fprintf(fp, "%d ", key[i]);
    }
    fclose(fp);
    
    fp = fopen(ENCRYPTED_FILE, "r"); // read encrypted message from file
    fgets(message, MAX_LEN, fp);
    fclose(fp);
    
    char temp[MAX_LEN];
    strcpy(temp, message); // make a copy of encrypted message
    
    char *token;
    token = strtok(temp, " "); // tokenize key values
    int i = 0;
    while (token != NULL) {
        key[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    decrypt(message, key); // decrypt message using key
    
    fp = fopen(DECRYPTED_FILE, "w"); // write decrypted message to file
    fprintf(fp, "%s\n", message);
    fclose(fp);
    
    return 0;
}