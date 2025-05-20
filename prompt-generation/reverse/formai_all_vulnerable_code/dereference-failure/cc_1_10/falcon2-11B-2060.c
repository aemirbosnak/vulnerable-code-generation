//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100
#define MAX_OUTPUT_LENGTH 1000000

void bwt(char* input, char* output, int len);
void encode(char* input, char* output, int len);
void decode(char* input, char* output, int len);

int main()
{
    char input[MAX_LINE_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    printf("Enter a string to encode: ");
    scanf("%[^\n]s", input);

    printf("Encoding...");
    bwt(input, output, strlen(input));
    printf("done\n");

    printf("Decoding...");
    decode(output, output, strlen(output));
    printf("done\n");

    printf("Output: %s\n", output);

    return 0;
}

void bwt(char* input, char* output, int len)
{
    char* row = (char*)malloc(len * sizeof(char));
    int row_len = 0;
    bool is_done = false;

    while (!is_done)
    {
        row[row_len] = '\0';
        row_len = 0;

        for (int i = 0; i < len; i++)
        {
            int j = i;
            while (j < len && row[j]!= '\0')
            {
                j++;
            }
            if (j == len)
            {
                row[row_len] = input[i];
                row_len++;
            }
        }

        if (row_len == len)
        {
            is_done = true;
        }

        int index = 0;
        for (int i = 0; i < len; i++)
        {
            output[index++] = row[i];
        }
    }

    free(row);
}

void encode(char* input, char* output, int len)
{
    char* row = (char*)malloc(len * sizeof(char));
    int row_len = 0;

    for (int i = 0; i < len; i++)
    {
        row[row_len] = input[i];
        row_len++;
    }

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        output[index++] = row[i];
    }

    free(row);
}

void decode(char* input, char* output, int len)
{
    char* row = (char*)malloc(len * sizeof(char));
    int row_len = 0;

    for (int i = 0; i < len; i++)
    {
        row[row_len] = input[i];
        row_len++;
    }

    int index = 0;
    for (int i = 0; i < len; i++)
    {
        output[index++] = row[i];
    }

    free(row);
}