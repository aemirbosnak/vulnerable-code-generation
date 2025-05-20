//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main(int argc, char *argv[])
{
    char input[MAX_LEN];
    char output[MAX_LEN];
    int i, j, length;
    int decimal = 0;
    int binary[MAX_LEN];
    int binary_len = 0;
    int temp;

    // Check if the user entered a string
    if (argc!= 2)
    {
        printf("Invalid input. Please enter a string.\n");
        return 1;
    }

    // Get the input string
    strcpy(input, argv[1]);

    // Remove any leading or trailing white spaces
    input[strcspn(input, "\n")] = '\0';

    // Get the length of the input string
    length = strlen(input);

    // Check if the input string is empty
    if (length == 0)
    {
        printf("Empty input.\n");
        return 1;
    }

    // Convert the input string to binary
    for (i = 0; i < length; i++)
    {
        if (isdigit(input[i]))
        {
            decimal = decimal * 10 + input[i] - '0';
        }
        else
        {
            printf("Invalid character found: %c\n", input[i]);
            return 1;
        }
    }

    // Convert the decimal number to binary
    while (decimal > 0)
    {
        temp = decimal % 2;
        binary[binary_len++] = temp;
        decimal /= 2;
    }

    // Reverse the binary array
    for (i = 0, j = binary_len - 1; i < j; i++, j--)
    {
        temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }

    // Convert the binary array to a string
    strcpy(output, "Binary representation: ");
    for (i = 0; i < binary_len; i++)
    {
        sprintf(output + strlen(output), "%d", binary[i]);
    }

    // Print the result
    printf("%s\n", output);

    return 0;
}