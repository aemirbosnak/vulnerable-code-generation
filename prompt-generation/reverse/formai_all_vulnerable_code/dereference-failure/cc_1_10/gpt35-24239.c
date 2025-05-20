//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define WATERMARK_SIZE 32

// Function to print binary representation of a character
void print_binary(char c)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (c >> i) & 1);
    }
}

// Function to generate a random watermark
char* generate_watermark()
{
    char* watermark = (char*)malloc(WATERMARK_SIZE + 1);
    for (int i = 0; i < WATERMARK_SIZE; i++)
    {
        watermark[i] = rand() % 2 ? '1' : '0';
    }
    watermark[WATERMARK_SIZE] = '\0';
    return watermark;
}

// Function to embed the watermark in the message
void embed_watermark(char* message, char* watermark)
{
    int message_length = strlen(message);
    int watermark_length = strlen(watermark);
    if (message_length < watermark_length + 8)
    {
        printf("Cannot embed watermark in the message\n");
        return;
    }
    int watermark_index = 0;
    int no_of_bits_embedded = 0;
    for (int i = 0; i < message_length; i++)
    {
        if (i % 8 == 0 && watermark_index < watermark_length)
        {
            message[i] = watermark[watermark_index++];
            no_of_bits_embedded++;
        }
        else if (no_of_bits_embedded >= WATERMARK_SIZE)
        {
            break;
        }
    }
}

// Function to extract the watermark from the message
void extract_watermark(char* message)
{
    int message_length = strlen(message);
    char* watermark = (char*)malloc(WATERMARK_SIZE + 1);
    int watermark_index = 0;
    for (int i = 0; i < message_length; i++)
    {
        if (i % 8 == 0 && watermark_index < WATERMARK_SIZE)
        {
            watermark[watermark_index++] = message[i];
        }
        else if (watermark_index >= WATERMARK_SIZE)
        {
            break;
        }
    }
    printf("Extracted watermark: %s\n", watermark);
    free(watermark);
}

int main()
{
    char message[MAX_INPUT_SIZE];
    char* watermark = generate_watermark();

    printf("Enter the message: ");
    fgets(message, MAX_INPUT_SIZE, stdin);

    embed_watermark(message, watermark);

    printf("Embedded watermark: %s\n", watermark);
    printf("Embedded message: %s\n", message);

    extract_watermark(message);

    free(watermark);
    return 0;
}