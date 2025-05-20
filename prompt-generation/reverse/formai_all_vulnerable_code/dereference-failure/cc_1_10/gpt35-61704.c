//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void read_message(char *message)
{
    printf("Enter the message to be watermarked: ");
    fgets(message, MAX_SIZE, stdin);
}

void print_message(char *message)
{
    printf("The message is: %s\n", message);
}

void generate_watermark(char *watermark)
{
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        int random_number = rand() % 10;
        watermark[i] = (char)(random_number + '0');
    }
    watermark[6] = '\0';
}

void print_watermark(char *watermark)
{
    printf("The watermark is: %s\n", watermark);
}

void embed_watermark(char *message, char *watermark)
{
    int watermark_length = strlen(watermark);
    for (int i = 0; i < watermark_length; i++)
    {
        int position = 2 * (i + 1);
        message[position] = watermark[i];
    }
}

void extract_watermark(char *message, char *extracted_watermark)
{
    int watermark_length = strlen(extracted_watermark);
    for (int i = 0; i < watermark_length; i++)
    {
        int position = 2 * (i + 1);
        extracted_watermark[i] = message[position];
    }
    extracted_watermark[watermark_length] = '\0';
}

int main()
{
    char message[MAX_SIZE];
    char watermark[MAX_SIZE];
    char extracted_watermark[MAX_SIZE];

    read_message(message);
    print_message(message);

    generate_watermark(watermark);
    print_watermark(watermark);

    embed_watermark(message, watermark);
    print_message(message);

    extract_watermark(message, extracted_watermark);
    print_watermark(extracted_watermark);

    return 0;
}