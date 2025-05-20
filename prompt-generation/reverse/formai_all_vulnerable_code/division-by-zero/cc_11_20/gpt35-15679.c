//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    char original_message[MAX_SIZE];
    printf("Enter the original message: ");
    fgets(original_message, sizeof(original_message), stdin);

    char watermark[MAX_SIZE];
    printf("Enter the watermark: ");
    fgets(watermark, sizeof(watermark), stdin);

    int watermark_length = strlen(watermark);

    // Add the watermark to the original message
    char watermarked_message[MAX_SIZE];
    int i, j;
    for (i = 0, j = 0; original_message[i] != '\0'; i++)
    {
        if (original_message[i] == '\n')
        {
            watermarked_message[j++] = '\n';
        }
        else
        {
            if (j < MAX_SIZE - 1)
            {
                watermarked_message[j++] = original_message[i];
            }
            else
            {
                break;
            }
        }

        if (i % 2 == 0 && j < MAX_SIZE - 1)
        {
            watermarked_message[j++] = watermark[i / 2 % watermark_length];
        }
        else if (i % 2 == 1 && j < MAX_SIZE - 1)
        {
            watermarked_message[j++] = watermark[(watermark_length - 1 - i / 2) % watermark_length];
        }
        else
        {
            break;
        }
    }

    printf("Watermarked message: %s\n", watermarked_message);

    // Remove the watermark from the watermarked message
    char extracted_message[MAX_SIZE];
    for (i = 0, j = 0; watermarked_message[i] != '\0'; i++)
    {
        if (watermarked_message[i] == '\n')
        {
            extracted_message[j++] = '\n';
        }
        else if ((i % 2 == 0 && watermarked_message[i] == watermark[i / 2 % watermark_length]) ||
                 (i % 2 == 1 && watermarked_message[i] == watermark[(watermark_length - 1 - i / 2) % watermark_length]))
        {
            // Do nothing
        }
        else
        {
            if (j < MAX_SIZE - 1)
            {
                extracted_message[j++] = watermarked_message[i];
            }
            else
            {
                break;
            }
        }
    }

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}