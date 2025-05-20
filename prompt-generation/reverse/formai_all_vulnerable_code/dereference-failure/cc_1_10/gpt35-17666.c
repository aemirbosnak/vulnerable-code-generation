//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    char* key;
    int* values;
    int length;
} Map;

Map* createMap(char* key, int* values, int length){
    Map* map = malloc(sizeof(Map));
    map->key = key;
    map->values = values;
    map->length = length;
    return map;
}

void destroyMap(Map* map){
    free(map->key);
    free(map->values);
    free(map);
}

Map* createFrequencyTable(char* message){
    int messageLen = strlen(message);
    char* key = malloc(sizeof(char) * (messageLen+1));
    int* values = calloc(sizeof(int), 26);
    
    int ki = 0;
    for(int i = 0; i < messageLen; i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            key[ki] = message[i];
            values[message[i] - 'A']++;
            ki++;
        } else if(message[i] >= 'a' && message[i] <= 'z'){
            key[ki] = message[i] - 32;
            values[message[i] - 'a']++;
            ki++;
        }
    }
    
    Map* freqTable = createMap(key, values, 26);
    return freqTable;
}

double* getFrequencyValues(Map* map){
    double* freqValues = calloc(sizeof(double), 26);
    for(int i = 0; i < 26; i++){
        freqValues[i] = (double)map->values[i] / (double)map->length;
    }
    return freqValues;
}

char* encrypt(char* message, int key){
    int messageLen = strlen(message);
    char* ciphertext = malloc(sizeof(char) * (messageLen+1));
    
    for(int i = 0; i < messageLen; i++){
        if(message[i] >= 'A' && message[i] <= 'Z'){
            ciphertext[i] = ((message[i] - 'A' + key) % 26) + 'A';
        } else if(message[i] >= 'a' && message[i] <= 'z'){
            ciphertext[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else {
            ciphertext[i] = message[i];
        }
    }
    ciphertext[messageLen] = '\0';
    
    return ciphertext;
}

char* decrypt(char* ciphertext, int key){
    int messageLen = strlen(ciphertext);
    char* message = malloc(sizeof(char) * (messageLen+1));
    
    for(int i = 0; i < messageLen; i++){
        if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'){
            message[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z'){
            message[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        } else {
            message[i] = ciphertext[i];
        }
    }
    message[messageLen] = '\0';
    
    return message;
}

int findKey(Map* freqTable, double* stdFrequencyValues){
    double minDiff = INFINITY;
    int key = 0;
    
    for(int i = 0; i < 26; i++){
        double* freqValues = getFrequencyValues(freqTable);
        double diff = 0;
        for(int j = 0; j < 26; j++){
            diff += pow(freqValues[j] - stdFrequencyValues[j], 2.0);
        }
        if(diff < minDiff){
            minDiff = diff;
            key = i;
        }
        free(freqValues);
    }
    
    return key;
}

int main(){
    char* message = "Hello World";
    printf("Message: %s\n", message);
    
    // Encryption
    int key = 7;
    char* ciphertext = encrypt(message, key);
    printf("Ciphertext: %s\n", ciphertext);
    
    // Decryption
    char* decryptedMessage = decrypt(ciphertext, key);
    printf("Decrypted Message: %s\n", decryptedMessage);

    // Frequency Analysis Attack
    char* ciphertext2 = "Jxuuh Rduur";
    Map* freqTable = createFrequencyTable(ciphertext2);
    double stdFrequencyValues[26] = {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0402, 0.0241, 0.0675, 0.0751, 0.0193, 0.001, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0008};
    int foundKey = findKey(freqTable, stdFrequencyValues);
    printf("Found Key: %d\n", foundKey);
    
    destroyMap(freqTable);
    free(ciphertext);
    free(decryptedMessage);
    
    return 0;
}