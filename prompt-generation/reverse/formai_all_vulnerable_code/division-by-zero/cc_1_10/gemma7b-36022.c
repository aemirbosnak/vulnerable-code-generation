//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i = 0, j = 0, count = 0, previousChar = -1, previousCount = 0;
    char compressedBuffer[MAX_BUFFER_SIZE];

    printf("Enter text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Iterate over the input text and perform compression
    for (i = 0; buffer[i] != '\0'; i++)
    {
        // Count consecutive occurrences of the current character
        if (buffer[i] == previousChar)
        {
            previousCount++;
        }
        else
        {
            if (previousChar != -1)
            {
                // Write the previous character and its count
                compressedBuffer[j++] = previousChar;
                compressedBuffer[j++] = previousCount;
            }
            previousChar = buffer[i];
            previousCount = 1;
        }

        // Increment the total count of characters
        count++;
    }

    // Write the remaining character and its count
    if (previousChar != -1)
    {
        compressedBuffer[j++] = previousChar;
        compressedBuffer[j++] = previousCount;
    }

    // Calculate the compression ratio
    int ratio = (count - j) * 100 / count;

    // Print the compressed text
    printf("Compressed text: ");
    for (i = 0; compressedBuffer[i] != '\0'; i++)
    {
        printf("%c", compressedBuffer[i]);
    }

    // Print the compression ratio
    printf("\nCompression ratio: %.2f%%", ratio);

    return 0;
}