//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

/* Function to compress a string */
char *compress(char *message)
{
    int len = strlen(message);
    char *compressed = (char *)malloc(sizeof(char) * MAX_LEN);
    int count = 1, index = 0;

    for (int i = 0; i < len; i++)
    {
        if (message[i] == message[i + 1] && i + 1 < len)
        {
            count++;
        }
        else
        {
            compressed[index++] = message[i];
            char buffer[MAX_LEN];
            sprintf(buffer, "%d", count);
            if (count > 1)
            {
                for (int j = 0; j < strlen(buffer); j++)
                {
                    compressed[index++] = buffer[j];
                }
            }
            count = 1;
        }
    }
    compressed[index] = '\0';
    return compressed;
}

/* Function to decompress a string */
char *decompress(char *message)
{
    int len = strlen(message);
    char *decompressed = (char *)malloc(sizeof(char) * MAX_LEN);
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        char c = message[i];
        int count = 0;
        while (message[i + 1] >= '0' && message[i + 1] <= '9' && i + 1 < len)
        {
            count = count * 10 + (message[i + 1] - '0');
            i++;
        }
        for (int j = 0; j < count; j++)
        {
            decompressed[index++] = c;
        }
        if (count == 0)
        {
            decompressed[index++] = c;
        }
    }
    decompressed[index] = '\0';
    return decompressed;
}

int main()
{
    char message[MAX_LEN];
    char choice;

    do
    {
        printf("Enter a string to compress (Max Length : %d) : ", MAX_LEN);
        fgets(message, MAX_LEN, stdin);
        message[strcspn(message, "\n")] = 0;
        char *compressed = compress(message);
        printf("\nCompressed message : %s\n", compressed);

        char *decompressed = decompress(compressed);
        printf("Decompressed message : %s\n", decompressed);

        printf("\nDo you want to continue? (y/n) : ");
        scanf("%c", &choice);
        getchar();
    } while (choice == 'y' || choice == 'Y');
    return 0;
}