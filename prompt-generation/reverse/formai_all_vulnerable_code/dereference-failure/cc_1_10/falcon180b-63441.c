//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000
#define NUM_OF_CHARS 10

int main()
{
    char input[MAX_LINE_LENGTH];
    char binary_output[NUM_OF_CHARS];
    char *binary_ptr = binary_output;
    int num_of_chars = 0;
    int i = 0;
    int j = 0;

    printf("Welcome to the post-apocalyptic world of binary conversion!\n");

    printf("Enter a string to convert to binary: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    printf("The binary representation of the input string is:\n");

    for (i = 0; input[i]!= '\0'; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            binary_ptr[j++] = input[i] - '0';
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            binary_ptr[j++] = input[i] - 'A' + 10;
        }
        else if (input[i] >= 'a' && input[i] <= 'f')
        {
            binary_ptr[j++] = input[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid character encountered.\n");
            exit(1);
        }
    }

    printf("Binary representation: ");

    for (i = 0; i < j; i++)
    {
        printf("%d", binary_ptr[i]);
    }

    printf("\n");

    return 0;
}