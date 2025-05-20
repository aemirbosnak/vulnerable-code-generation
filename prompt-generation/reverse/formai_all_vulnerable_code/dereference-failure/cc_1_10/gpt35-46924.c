//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char* encode(char*);
int* gen_perm(int);

int main()
{
    char input[1000], *output;
    srand((unsigned int)time(NULL)); // Seed the random number generator

    printf("Enter a string to be encrypted: ");
    fgets(input, sizeof(input), stdin);

    output = encode(input);
    printf("Encrypted string: %s", output);

    free(output);
    return 0;
}

// Encodes a string by shuffling its characters and performing a substitution cipher
char* encode(char* str)
{
    int len = strlen(str);
    int* perm = gen_perm(len); // Generate a random permutation of integers for character shuffling
    char* encoded = (char*)malloc(sizeof(char) * (len + 1));
    int index;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            index = toupper(str[i]) - 'A';
            encoded[i] = (char)((perm[index] + 'A') % 26 + 'A'); // Apply substitution cipher
            if (islower(str[i]))
                encoded[i] = tolower(encoded[i]);
        }
        else
            encoded[i] = str[i];

    }
    encoded[len] = '\0'; // Add null-terminator to end of encoded string
    free(perm);

    return encoded;
}

// Generates a random permutation of integers from 0 to n-1
int* gen_perm(int n)
{
    int* perm = (int*)malloc(sizeof(int) * n);
    int* temp_perm = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        perm[i] = i;
        temp_perm[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int j = rand() % (n - i) + i;
        temp_perm[i] = perm[j];
        perm[j] = perm[i];
    }

    free(temp_perm);
    return perm;
}