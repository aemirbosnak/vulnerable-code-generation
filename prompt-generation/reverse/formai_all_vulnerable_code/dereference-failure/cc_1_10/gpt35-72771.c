//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void hideData(char *imgFileName, char *textFileName, char *outputFileName);
void extractData(char *imgFileName, char *outputFileName);

int main()
{
    int choice;
    char inputFileName[MAX_LEN], outputFileName[MAX_LEN];

    printf("Welcome to Image Steganography!\n");

    do
    {
        printf("\nPlease choose an option:\n");
        printf("1. Hide data inside an image\n");
        printf("2. Extract data from an image\n");
        printf("3. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char textFileName[MAX_LEN];
                printf("\nEnter the name of the image file: ");
                scanf("%s", inputFileName);
                printf("\nEnter the name of the text file: ");
                scanf("%s", textFileName);
                printf("\nEnter the name of the output file (must be a PNG file): ");
                scanf("%s", outputFileName);
                hideData(inputFileName, textFileName, outputFileName);
                printf("\nData successfully hidden inside the image!\n");
                break;
            }
            case 2:
            {
                printf("\nEnter the name of the image file: ");
                scanf("%s", inputFileName);
                printf("\nEnter the name of the output file (must be a TXT file): ");
                scanf("%s", outputFileName);
                extractData(inputFileName, outputFileName);
                printf("\nData successfully extracted from the image!\n");
                break;
            }
            case 3:
            default:
            {
                printf("\nGoodbye!\n");
                exit(0);
            }
        }
    } while (choice != 3);

    return 0;
}

void hideData(char *imgFileName, char *textFileName, char *outputFileName)
{
    FILE *imgFile, *textFile;
    imgFile = fopen(imgFileName, "rb");
    textFile = fopen(textFileName, "r");
    if (imgFile == NULL || textFile == NULL)
    {
        printf("\nError opening input files!\n");
        exit(1);
    }

    FILE *outputFile;
    int c, count = 0;
    unsigned char ch[4] = {0};
    outputFile = fopen(outputFileName, "wb");
    while ((c = fgetc(imgFile)) != EOF)
    {
        if (count < 54) //header of BMP image file ends at byte 53
            fputc(c, outputFile);
        else
        {
            if (!feof(textFile))
            {
                int data = fgetc(textFile);
                ch[count % 4] = data;
                if (count % 4 == 3)
                {
                    fputc(c & 0xFC | ((ch[0] & 0x03) << 6), outputFile); //modify the 2 least significant bits of c with bits 0 and 1 of ch[0]
                    fputc(c & 0xFC | ((ch[1] & 0x03) << 4), outputFile); //modify the 2 least significant bits of c with bits 0 and 1 of ch[1]
                    fputc(c & 0xFC | ((ch[2] & 0x03) << 2), outputFile); //modify the 2 least significant bits of c with bits 0 and 1 of ch[2]
                    fputc(c & 0xFC | ((ch[3] & 0x03)), outputFile);       //modify the 2 least significant bits of c with bits 0 and 1 of ch[3]
                }
                count++;
            }
            else
                fputc(c, outputFile);
        }
    }
    fclose(imgFile);
    fclose(textFile);
    fclose(outputFile);
}

void extractData(char *imgFileName, char *outputFileName)
{
    FILE *imgFile;
    imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL)
    {
        printf("\nError opening input file!\n");
        exit(1);
    }

    FILE *outputFile;
    int count = 0;
    unsigned char ch[4] = {0};
    outputFile = fopen(outputFileName, "w");
    while (!feof(imgFile))
    {
        int c = fgetc(imgFile);
        if (count < 54)
        {
            count++;
            continue;
        }
        else
        {
            ch[count % 4] = c & 0x03; //get the 2 least significant bits of c and store them in ch[count%4]
            if (count % 4 == 3)
                fprintf(outputFile, "%c%c%c%c", ch[0], ch[1], ch[2], ch[3]);
            count++;
        }
    }
    fclose(imgFile);
    fclose(outputFile);
}