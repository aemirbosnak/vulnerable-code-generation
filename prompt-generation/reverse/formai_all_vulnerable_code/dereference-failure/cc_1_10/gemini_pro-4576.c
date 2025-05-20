//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convert a string to an array of integers
int *strToIntArray(char *str) {
    int len = strlen(str);
    int *arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr[i] = str[i];
    }
    return arr;
}

// Encrypt an array of integers using a key
int *encryptArray(int *arr, int key) {
    int len = sizeof(arr) / sizeof(arr[0]);
    int *encryptedArr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        encryptedArr[i] = arr[i] ^ key;
    }
    return encryptedArr;
}

// Decrypt an array of integers using a key
int *decryptArray(int *arr, int key) {
    int len = sizeof(arr) / sizeof(arr[0]);
    int *decryptedArr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        decryptedArr[i] = arr[i] ^ key;
    }
    return decryptedArr;
}

// Write an array of integers to a file
void writeArrayToFile(int *arr, char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(arr, sizeof(int), sizeof(arr) / sizeof(arr[0]), file);
    fclose(file);
}

// Read an array of integers from a file
int *readArrayFromFile(char *filename) {
    FILE *file = fopen(filename, "rb");
    int len;
    fread(&len, sizeof(int), 1, file);
    int *arr = malloc(len * sizeof(int));
    fread(arr, sizeof(int), len, file);
    fclose(file);
    return arr;
}

int main() {
    char *filename = "encrypted.bin";
    char *key = "12345";

    // Convert the key to an array of integers
    int *keyArr = strToIntArray(key);

    // Encrypt the string using the key
    char *str = "Hello, world!";
    int *strArr = strToIntArray(str);
    int *encryptedArr = encryptArray(strArr, keyArr);

    // Write the encrypted array to a file
    writeArrayToFile(encryptedArr, filename);

    // Read the encrypted array from the file
    int *decryptedArr = readArrayFromFile(filename);

    // Decrypt the encrypted array using the key
    int *decryptedStrArr = decryptArray(decryptedArr, keyArr);

    // Convert the decrypted array of integers to a string
    char *decryptedStr = malloc((sizeof(decryptedStrArr) / sizeof(decryptedStrArr[0])) + 1);
    for (int i = 0; i < sizeof(decryptedStrArr) / sizeof(decryptedStrArr[0]); i++) {
        decryptedStr[i] = decryptedStrArr[i];
    }
    decryptedStr[sizeof(decryptedStrArr) / sizeof(decryptedStrArr[0])] = '\0';

    // Print the decrypted string
    printf("Decrypted string: %s\n", decryptedStr);

    return 0;
}