//FormAI DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char source_file[100], destination_file[100];
    int choice;

    printf("Welcome to the C Image Editor!\n");
    printf("What would you like to do?\n");
    printf("1. Convert image to grayscale\n");
    printf("2. Invert image colors\n");
    printf("3. Flip image horizontally\n");
    printf("4. Flip image vertically\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the source file name: ");
    scanf("%s", source_file);

    FILE *fp1 = fopen(source_file, "rb");
    if (fp1 == NULL)
    {
        printf("ERROR: Invalid file name!");
        exit(1);
    }

    printf("\nEnter the destination file name: ");
    scanf("%s", destination_file);

    FILE *fp2 = fopen(destination_file, "wb");
    if (fp2 == NULL)
    {
        printf("ERROR: Unable to create file!");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp1);
    fwrite(header, sizeof(unsigned char), 54, fp2);

    switch (choice)
    {
        case 1:
        {
            printf("\nConverting image to grayscale...\n");

            unsigned char buffer[3];
            int padding = 0;
            if ((header[18]*header[24])%4 != 0)
                padding = 4 - ((header[18]*header[24])%4);

            for(int i=0; i<header[18]; i++)
            {
                for(int j=0; j<header[24]; j++)
                {
                    fread(buffer, sizeof(unsigned char), 3, fp1);

                    int grayscale = 0;
                    grayscale += (int) buffer[0]*0.3;
                    grayscale += (int) buffer[1]*0.59;
                    grayscale += (int) buffer[2]*0.11;

                    buffer[0] = (unsigned char) grayscale;
                    buffer[1] = (unsigned char) grayscale;
                    buffer[2] = (unsigned char) grayscale;

                    fwrite(buffer, sizeof(unsigned char), 3, fp2);
                }
                fseek(fp1, padding, SEEK_CUR);
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash;
                    fread(&trash, sizeof(unsigned char), 1, fp1);
                }
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash = 0x00;
                    fwrite(&trash, sizeof(unsigned char), 1, fp2);
                }
            }
            printf("\nGrayscale conversion successful!\n");
            break;
        }

        case 2:
        {
            printf("\nInverting image colors...\n");

            unsigned char buffer[3];
            int padding = 0;
            if ((header[18]*header[24])%4 != 0)
                padding = 4 - ((header[18]*header[24])%4);

            for(int i=0; i<header[18]; i++)
            {
                for(int j=0; j<header[24]; j++)
                {
                    fread(buffer, sizeof(unsigned char), 3, fp1);

                    buffer[0] = 255 - buffer[0];
                    buffer[1] = 255 - buffer[1];
                    buffer[2] = 255 - buffer[2];

                    fwrite(buffer, sizeof(unsigned char), 3, fp2);
                }
                fseek(fp1, padding, SEEK_CUR);
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash;
                    fread(&trash, sizeof(unsigned char), 1, fp1);
                }
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash = 0x00;
                    fwrite(&trash, sizeof(unsigned char), 1, fp2);
                }
            }
            printf("\nInversion successful!\n");
            break;
        }

        case 3:
        {
            printf("\nFlipping image horizontally...\n");

            unsigned char buffer[3];
            int padding = 0;
            if ((header[18]*header[24])%4 != 0)
                padding = 4 - ((header[18]*header[24])%4);

            for(int i=0; i<header[18]; i++)
            {
                for(int j=header[24]-1; j>=0; j--)
                {
                    fread(buffer, sizeof(unsigned char), 3, fp1);
                    fwrite(buffer, sizeof(unsigned char), 3, fp2);
                }
                fseek(fp1, padding, SEEK_CUR);
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash;
                    fread(&trash, sizeof(unsigned char), 1, fp1);
                }
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash = 0x00;
                    fwrite(&trash, sizeof(unsigned char), 1, fp2);
                }
            }
            printf("\nHorizontal flip successful!\n");
            break;
        }

        case 4:
        {
            printf("\nFlipping image vertically...\n");

            unsigned char buffer[header[24]*3];
            int padding = 0;
            if ((header[18]*header[24])%4 != 0)
                padding = 4 - ((header[18]*header[24])%4);

            for(int i=header[18]-1; i>=0; i--)
            {
                fread(buffer, sizeof(unsigned char), 3*header[24], fp1);
                fwrite(buffer, sizeof(unsigned char), 3*header[24], fp2);

                fseek(fp1, padding, SEEK_CUR);
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash;
                    fread(&trash, sizeof(unsigned char), 1, fp1);
                }
                for(int k=0; k<padding; k++)
                {
                    unsigned char trash = 0x00;
                    fwrite(&trash, sizeof(unsigned char), 1, fp2);
                }
            }
            printf("\nVertical flip successful!\n");
            break;
        }

        default:
            printf("\nInvalid choice, please enter a number between 1 and 4!\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}