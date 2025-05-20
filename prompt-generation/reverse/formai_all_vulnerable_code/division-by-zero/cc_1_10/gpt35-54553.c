//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to implement Caesar cipher
char *caesar_cipher(char *plain_text, int key)
{
    int i;
    char *cipher_text = (char *)malloc(strlen(plain_text) + 1);
  
    // Encrypt the plain text using the key
    for (i = 0; i < strlen(plain_text); i++)
    {
        // Check for uppercase letters
        if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
        {
            cipher_text[i] = (char)((int)plain_text[i] + key - 65) % 26 + 65;
        }
        // Check for lowercase letters
        else if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
        {
            cipher_text[i] = (char)((int)plain_text[i] + key - 97) % 26 + 97;
        }
        // If not a letter
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[i] = '\0';
    
    return cipher_text;
}

// Function to implement Vigenere cipher
char *vigenere_cipher(char *plain_text, char *key)
{
    int i, j, k = 0;
    char *cipher_text = (char *)malloc(strlen(plain_text) + 1);
  
    // Encrypt the plain text using the key
    for (i = 0, j = 0; i < strlen(plain_text); i++)
    {
        // Check for uppercase letters
        if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
        {
            cipher_text[i] = (char)(((int)plain_text[i] + (int)key[j] - 2 * 65) % 26) + 65;
            j = (j + 1) % strlen(key);
        }
        // Check for lowercase letters
        else if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
        {
            cipher_text[i] = (char)(((int)plain_text[i] + (int)key[j] - 2 * 97) % 26) + 97;
            j = (j + 1) % strlen(key);
        }
        // If not a letter
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    cipher_text[i] = '\0';
    
    return cipher_text;
}

// Function to implement transposition cipher
char *transposition_cipher(char *plain_text, char *key)
{
    int i, j, k = 0;
    char *cipher_text = (char *)malloc(strlen(plain_text) + 1);
    int key_len = strlen(key);
    int text_len = strlen(plain_text);
    int num_rows = (text_len / key_len) + 1;
    char **matrix = (char **)malloc(num_rows * sizeof(char *));
    for (i = 0; i < num_rows; i++)
    {
        matrix[i] = (char *)malloc(key_len * sizeof(char));
    }
  
    // Fill the matrix with the plain text
    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < key_len; j++)
        {
            if (plain_text[k] != '\0')
            {
                matrix[i][j] = plain_text[k];
                k++;
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }
  
    // Rearrange the columns according to the key
    int *key_index = (int *)malloc(key_len * sizeof(int));
    for (i = 0; i < key_len; i++)
    {
        for (j = 0; j < key_len; j++)
        {
            if (key[j] == i + '1')
            {
                key_index[i] = j;
            }
        }
    }

    // Fill in the cipher text matrix
    k = 0;
    for (i = 0; i < key_len; i++)
    {
        for (j = 0; j < num_rows; j++)
        {
            cipher_text[k] = matrix[j][key_index[i]];
            k++;
        }
    }
    cipher_text[k] = '\0';
  
    return cipher_text;
}

int main()
{
    int choice;
    char plain_text[1000];
    char key[100];
  
    // Get the plain text and key from the user
    printf("Enter the plain text: ");
    fgets(plain_text, sizeof(plain_text), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;  // remove trailing newline character
    
    // Generate a random key if the user did not enter one
    if (strcmp(key, "") == 0)
    {
        srand(time(0));
        for (int i = 0; i < strlen(plain_text); i++)
        {
            key[i] = rand() % 9 + 1 + '0';
        }
        key[strlen(plain_text)] = '\0';
        printf("The generated key is: %s\n", key);
    }
  
    // Get the cipher type from the user
    printf("Choose a cipher type:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    printf("3. Transposition Cipher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
  
    // Encrypt the plain text using the chosen cipher
    char *cipher_text;
    switch (choice)
    {
        case 1:
            printf("Encrypting using Caesar Cipher...\n");
            cipher_text = caesar_cipher(plain_text, atoi(key));
            break;
        case 2:
            printf("Encrypting using Vigenere Cipher...\n");
            cipher_text = vigenere_cipher(plain_text, key);
            break;
        case 3:
            printf("Encrypting using Transposition Cipher...\n");
            cipher_text = transposition_cipher(plain_text, key);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }
  
    // Print the cipher text
    printf("The cipher text is: %s\n", cipher_text);
  
    return 0;
}