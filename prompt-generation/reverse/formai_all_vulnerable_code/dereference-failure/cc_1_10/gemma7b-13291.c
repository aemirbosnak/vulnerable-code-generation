//Gemma-7B DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char **arr = NULL;
    int i, size = 0, word_count = 0;
    char word[20];

    // Allocate memory dynamically
    arr = (char**)malloc(MAX_SIZE * sizeof(char*));

    // Read the text from the user
    printf("Enter text: ");
    getline(arr, MAX_SIZE, stdin);

    // Split the text into words
    char *ptr = arr[0];
    while (ptr)
    {
        // Check if the word is already present
        int flag = 0;
        for (i = 0; i < word_count; i++)
        {
            if (strcmp(ptr, word[i]) == 0)
            {
                flag = 1;
                break;
            }
        }

        // If the word is not present, add it to the list
        if (flag == 0)
        {
            word[word_count] = ptr;
            word_count++;
        }

        // Move to the next word
        ptr = strchr(ptr, ' ') ? strchr(ptr, ' ') : NULL;
    }

    // Print the unique words
    printf("Unique words: ");
    for (i = 0; i < word_count; i++)
    {
        printf("%s ", word[i]);
    }

    // Free the memory
    free(arr);

    return 0;
}