//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress given string
void compress(char *str)
{
    int count = 1;
    char* temp = (char*) malloc(sizeof(char) * (strlen(str) + 1));
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == str[i + 1])
        {
            count++;
        }
        else
        {
            temp[index] = str[i];
            index++;
            char countStr[10];
            sprintf(countStr, "%d", count);
            for (int j = 0; countStr[j] != '\0'; j++)
            {
                temp[index] = countStr[j];
                index++;
            }
            count = 1;
        }
    }

    temp[index] = '\0';
    strcpy(str, temp);
    free(temp);
}

int main()
{
    char str[100];
    printf("Enter string to compress: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character from fgets
    
    printf("Original string: %s\n", str);
    compress(str);
    printf("Compressed string: %s\n", str);

    return 0;
}