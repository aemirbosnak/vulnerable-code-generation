//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define FILENAME_SIZE 256
#define MESSAGE_SIZE 1024

int readFile(char* filename, char** buffer, long* length);
int writeFile(char* filename, char* data, long length);
void embedMessage(char* cover, char* message, char* stego, long messageLength);
void extractMessage(char* stego, char** message, long* messageLength);

int main()
{
    // Variable Declaration
    char coverFilename[FILENAME_SIZE];
    char messageFilename[FILENAME_SIZE];
    char stegoFilename[FILENAME_SIZE];
    char* cover = NULL;
    char* message = NULL;
    char* stego = NULL;
    long coverLength, messageLength, stegoLength;
    int choice;

    // User Input
    printf("=============================\n");
    printf("          STEGANOGRAPHY\n");
    printf("=============================\n");
    printf("Enter Cover File Name: ");
    scanf("%s", coverFilename);
    printf("Enter Message File Name: ");
    scanf("%s", messageFilename);
    printf("Enter Stego File Name: ");
    scanf("%s", stegoFilename);

    // Read Files
    if (!readFile(coverFilename, &cover, &coverLength))
    {
        printf("Error Reading Cover File!\n");
        return -1;
    }

    if (!readFile(messageFilename, &message, &messageLength))
    {
        printf("Error Reading Message File!\n");
        return -1;
    }

    // Embed or Extract
    printf("\nSelect an Option:\n");
    printf("1. Embed Message\n");
    printf("2. Extract Message\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        embedMessage(cover, message, stego, messageLength);

        if (!writeFile(stegoFilename, stego, coverLength))
        {
            printf("Error Writing Stego File!\n");
            return -1;
        }

        printf("Message Embedded Successfully!\n");
    }
    else if (choice == 2)
    {
        if (!readFile(stegoFilename, &stego, &stegoLength))
        {
            printf("Error Reading Stego File!\n");
            return -1;
        }

        extractMessage(stego, &message, &messageLength);

        if (!writeFile(messageFilename, message, messageLength))
        {
            printf("Error Writing Extracted Message!\n");
            return -1;
        }

        printf("Message Extracted Successfully!\n");
    }
    else
    {
        printf("Invalid Choice!\n");
    }

    // Free Allocated Memory
    free(cover);
    free(message);
    free(stego);

    return 0;
}

int readFile(char* filename, char** buffer, long* length)
{
    FILE* file = NULL;
    size_t result;

    file = fopen(filename, "rb");

    if (file == NULL)
    {
        return FALSE;
    }

    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    rewind(file);

    *buffer = (char*) malloc(sizeof(char) * (*length));

    result = fread(*buffer, 1, (*length), file);

    fclose(file);

    if (*length != result)
    {
        return FALSE;
    }

    return TRUE;
}

int writeFile(char* filename, char* data, long length)
{
    FILE* file = NULL;
    size_t result;

    file = fopen(filename, "wb");

    if (file == NULL)
    {
        return FALSE;
    }

    result = fwrite(data, 1, length, file);

    fclose(file);

    if (length != result)
    {
        return FALSE;
    }

    return TRUE;
}

void embedMessage(char* cover, char* message, char* stego, long messageLength)
{
    int i, j;

    // Copy Cover to Stego
    memcpy(stego, cover, messageLength);

    // Embed Message
    srand(time(NULL));

    for (i = 0; i < messageLength; i++)
    {
        j = rand() % 8;

        if ((message[i] >> j) & 1)
        {
            stego[i] |= 1;
        }
        else
        {
            stego[i] &= ~1;
        }
    }
}

void extractMessage(char* stego, char** message, long* messageLength)
{
    int i, j;
    char bit;

    // Allocate Memory
    *message = (char*) malloc(sizeof(char) * (*messageLength));

    // Extract Message
    srand(time(NULL));

    for (i = 0; i < *messageLength; i++)
    {
        (*message)[i] = 0;

        for (j = 0; j < 8; j++)
        {
            bit = (stego[i] >> j) & 1;
            (*message)[i] |= (bit << (rand() % 8));
        }
    }
}