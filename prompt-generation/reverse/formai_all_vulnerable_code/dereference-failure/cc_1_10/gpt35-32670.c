//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character array to binary string 
void charToBinary(char* input, int len, char* output)
{
    int i, j;
    for(i=0; i<len; i++)
    {
        // convert each character to its binary equivalent
        for(j=0; j<8; j++)
        {
            output[(i*8)+j] = ((input[i] >> (7-j)) & 1) + '0';
        }
    }
    output[len*8] = '\0';
}

// Function to convert binary string to character array
void binaryToChar(char* input, int len, char* output)
{
    int i, j;
    for(i=0; i<len/8; i++)
    {
        // convert 8-bit binary string to its corresponding character
        for(j=0; j<8; j++)
        {
            output[i] |= (input[(i*8)+j]-'0') << (7-j);
        }
    }
    output[len/8] = '\0';
}

// Function to perform XOR operation between two strings of same length
void xor(char* str1, char* str2, int len, char* output)
{
    int i;
    for(i=0; i<len; i++)
    {
        output[i] = ((str1[i]-'0') ^ (str2[i]-'0')) + '0';
    }
    output[len] = '\0';
}

// Function to generate random binary string of given length
void generateKey(char* key, int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        key[i] = rand()%2+'0';
    }
    key[len] = '\0';
}

// Function to perform encryption operation
void encrypt(char* message, char* key, int len, char* output)
{
    char binaryMsg[len*8+1], binaryKey[len*8+1], binaryXOR[len*8+1], binaryEnc[len*8+1];
    charToBinary(message, len, binaryMsg);
    charToBinary(key, len, binaryKey);
    xor(binaryMsg, binaryKey, len*8, binaryXOR);
    charToBinary(binaryXOR, len*8, binaryEnc);
    strcpy(output, binaryEnc);
}

// Function to perform decryption operation
void decrypt(char* cipher, char* key, int len, char* output)
{
    char binaryCipher[len*8+1], binaryKey[len*8+1], binaryXOR[len*8+1], binaryDec[len*8+1];
    binaryCipher[len*8+1] = '\0';
    charToBinary(cipher, len, binaryCipher);
    charToBinary(key, len, binaryKey);
    xor(binaryCipher, binaryKey, len*8, binaryXOR);
    binaryToChar(binaryXOR, len*8, binaryDec);
    strcpy(output, binaryDec);
}

int main()
{
    int len = 5;
    char message[] = {'H', 'e', 'l', 'l', 'o'};
    char key[len+1];
    char cipher[len*8+1];
    char decryptedMsg[len+1];
    generateKey(key, len);
    printf("Original Message: %s\n", message);
    printf("Encryption Key : %s\n", key);
    encrypt(message, key, len, cipher);
    printf("Encrypted Text : %s\n", cipher);
    decrypt(cipher, key, len, decryptedMsg);
    printf("Decrypted Text : %s\n", decryptedMsg);
    return 0;
}