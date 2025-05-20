//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt given string using Caesar cipher
char* caesarCipher(char* originalText, int key)
{
    int n = strlen(originalText);
    char* result = (char *) malloc(n+1 *sizeof(char));

    // Iterate over each character in the original string
    for(int i=0; i<n; i++)
    {
        // If the character is an alphabet
        if(isalpha(originalText[i]))
        {
            // Calculate the new character by shifting it by given key
            char newChar = originalText[i] + key;
            
            // Wrap around the alphabet if new character is beyond Z/z
            if(isupper(originalText[i]) && newChar > 'Z')
                newChar = newChar - 'Z' + 'A' - 1;
            else if(islower(originalText[i]) && newChar > 'z')
                newChar = newChar - 'z' + 'a' - 1;
            
            // Add the new character to the result string
            result[i] = newChar;
        }
        else
        {
            // Add the non-alphabetic character as is
            result[i] = originalText[i];
        }
    }
    
    // Add the null character to terminate the result string
    result[n] = '\0';
    
    return result;
}

int main()
{
    // Input string
    char* originalText = "Hello World!";
    
    // Encryption key
    int key = 5;

    // Encrypt the given string using Caesar cipher
    char* encryptedText = caesarCipher(originalText, key);
    
    // Print the encrypted string and the key
    printf("Original Text: %s\n", originalText);
    printf("Key: %d\n", key);
    printf("Encrypted Text: %s\n", encryptedText);
    
    // Free the memory
    free(encryptedText);

    return 0;
}