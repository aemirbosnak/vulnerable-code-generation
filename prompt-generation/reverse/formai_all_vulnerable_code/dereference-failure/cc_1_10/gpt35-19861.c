//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUM 1000

void generateKey(int *key) {
    srand(time(NULL));
    
    for (int i = 0; i < 26; i++) {
        key[i] = (rand() % MAX_NUM) + 1;
    }
}

void encrypt(char *input, char *output, int *key) {
    int len = strlen(input);
    
    for (int i = 0; i < len; i++) {
        int index = (int)input[i] - 97;
        int value = key[index];
        
        sprintf(&output[i], "%d", value);
    }
}

void decrypt(char *input, char *output, int *key) {
    int len = strlen(input);
    
    for (int i = 0; i < len; i += 3) {
        char str[4] = "";
        
        strncat(&str[0], &input[i], 3);
        
        int value = atoi(str);
        int index = 0;
        
        for (int j = 0; j < 26; j++) {
            if (key[j] == value) {
                index = j;
                break;
            }
        }
        
        sprintf(&output[i / 3], "%c", index + 97);
    }
}

int main() {
    int key[26];
    generateKey(key);
    
    char *message = "this is a secret message";
    char encrypted[1024] = "";
    encrypt(message, encrypted, key);
    
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", encrypted);
    
    char decrypted[1024] = "";
    decrypt(encrypted, decrypted, key);
    
    printf("Decrypted Message: %s\n", decrypted);
    
    return 0;
}