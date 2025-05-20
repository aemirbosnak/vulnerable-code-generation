//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt text using a simple substitution cipher
char* encrypt(char* text, int shift)
{
    char* result = (char*) malloc(sizeof(char) * (strlen(text) + 1));
    
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            result[i] = (((text[i] - 'A') + shift) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            result[i] = (((text[i] - 'a') + shift) % 26) + 'a';
        }
        else
        {
            result[i] = text[i];
        }
    }
    
    result[i] = '\0';
    return result;
}

// Main function
int main()
{
    char text[100];
    int shift;
    
    printf("Enter text to encrypt: ");
    fgets(text, 100, stdin);
    
    printf("Enter shift value: ");
    scanf("%d", &shift);
    
    char* encrypted = encrypt(text, shift);
    
    printf("\nOriginal Text: %s", text);
    printf("Encrypted Text: %s", encrypted);
    
    free(encrypted);
    
    return 0;
}