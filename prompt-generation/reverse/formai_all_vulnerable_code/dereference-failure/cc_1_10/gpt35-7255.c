//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* This program allows users to hide a romantic message inside a picture file using steganography.
   While encoding the message, the program adds a slight color deviation in the image.
   The message can be decoded using the same program later on. */

int main()
{
    int temp, i = 0, j = 0, x = 0, y = 0;
    char message[200], fileName[20], newFileName[20], ch, c;
    FILE *fptr, *fptr1, *fptr2;

    printf("Enter name of input file:");
    scanf("%s", fileName);

    fptr = fopen(fileName, "rb"); // open the file in binary mode
    if(fptr == NULL)
    {
        printf("Error! File not found.");
        exit(1);
    }

    printf("Enter the message you want to hide:");
    scanf("%s", message);

    temp = strlen(message);
    printf("Size of message: %d\n", temp);

    fptr1 = fopen("steganography.txt", "w"); // create a text file to save the message
    if(fptr1 == NULL)
    {
        printf("Error! Could not create file.");
        exit(1);
    }

    fptr2 = fopen("RomeoandJuliet.pgm", "wb"); // create a new binary file to save the modified picture
    if(fptr2 == NULL)
    {
        printf("Error! Could not create file.");
        exit(1);
    }

    while((ch = fgetc(fptr)) != EOF)
    {
        if(ch == '\n' || ch == '\r' || ch == ' ') // skip the header part of the image
        {
            fprintf(fptr2, "%c", ch);
        }
        else
        {
            if(i < temp)
            {
                fprintf(fptr1, "%c", message[i]); // save the message to the text file
                c = message[i];
            }
            else
            {
                c = ch;
            }

            fprintf(fptr2, "%c", c + 5*sin(i*j+i*x+y)); // add a small deviation to the pixel value
            i++;
            j++;
            x++;
            y++;
        }
    }

    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);

    printf("Message successfully hidden in image file!\n");

    return 0;
}