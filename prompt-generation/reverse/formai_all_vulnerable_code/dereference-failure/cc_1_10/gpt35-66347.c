//FormAI DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 30
#define SECRET_MSG_SIZE 100

void hideMsgInImage(char *imgName, char *secretMsg);
void extractMsgFromImage(char *imgName);

int main()
{
    char imgName[FILE_NAME_SIZE];
    char secretMsg[SECRET_MSG_SIZE];

    printf("Enter the name of the image file to hide message: ");
    fgets(imgName, FILE_NAME_SIZE, stdin);
    imgName[strcspn(imgName, "\n")] = 0; // remove newline character

    printf("Enter the secret message: ");
    fgets(secretMsg, SECRET_MSG_SIZE, stdin);
    secretMsg[strcspn(secretMsg, "\n")] = 0; // remove newline character

    hideMsgInImage(imgName, secretMsg);
    printf("Message successfully hidden in the image!\n");

    printf("Enter the name of the image file to extract message: ");
    fgets(imgName, FILE_NAME_SIZE, stdin);
    imgName[strcspn(imgName, "\n")] = 0; // remove newline character

    extractMsgFromImage(imgName);

    return 0;
}

void hideMsgInImage(char *imgName, char *secretMsg)
{
    FILE *imgFile = fopen(imgName, "rb+");
    if (imgFile == NULL)
    {
        printf("Error: Could not open image file!\n");
        exit(1);
    }

    fseek(imgFile, 0, SEEK_END);
    long fileSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    int secretMsgLength = strlen(secretMsg);
    if (secretMsgLength * 8 >= fileSize)
    {
        printf("Error: Message is too long to hide in the image file!\n");
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, imgFile); // copy BMP header to memory

    for (int i = 0; i < secretMsgLength; i++) // loop through each character of message
    {
        char currChar = secretMsg[i];
        for (int j = 0; j < 8; j++) // loop through each bit of character
        {
            int bit = (currChar >> j) & 1; // get jth bit of character
            int offset = 54 + (i * 8) + j; // calculate the bit position in the image file
            fseek(imgFile, offset, SEEK_SET); // move file pointer to the bit position
            int byte = fgetc(imgFile);
            byte &= ~1; // clear the last bit
            byte |= bit; // set the last bit to the bit of the message character
            fseek(imgFile, offset, SEEK_SET); // move file pointer to the bit position
            fputc(byte, imgFile);
        }
    }

    fclose(imgFile);
}

void extractMsgFromImage(char *imgName)
{
    FILE *imgFile = fopen(imgName, "rb");
    if (imgFile == NULL)
    {
        printf("Error: Could not open image file!\n");
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, imgFile); // copy BMP header to memory

    int bitsRead = 0;
    char currChar = 0;
    while (bitsRead < SECRET_MSG_SIZE * 8) // loop until all bits of secret message are extracted
    {
        int offset = 54 + bitsRead; // calculate the bit position in the image file
        fseek(imgFile, offset, SEEK_SET); // move file pointer to the bit position
        int byte = fgetc(imgFile);
        int bit = byte & 1; // get the last bit of the byte
        currChar |= bit << (bitsRead % 8); // set the bit in the current character
        bitsRead++;

        if (bitsRead % 8 == 0) // if current character is complete
        {
            if (currChar == '\0') // if end-of-string character is encountered
            {
                break; // stop extracting bits from image
            }
            printf("%c", currChar); // print the current character
            currChar = 0; // clear the current character for the next 8 bits
        }
    }

    printf("\n");

    fclose(imgFile);
}