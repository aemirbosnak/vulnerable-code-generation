//FormAI DATASET v1.0 Category: File handling ; Style: Ada Lovelace
/*
Title: Ada Lovelace File Handling Example Program
Author: [Your Name]
Date: [Date]

Description: This program reads from and writes to a text file
in order to perform basic file operations like appending and
reading lines.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp; //file pointer
    char ch, fileName[20];
    char data[1000];
    int choice;

    printf("Enter filename: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "a+"); //opening file in append mode

    if (fp == NULL) //error handling
    {
        printf("File does not exist!!");
        exit(0);
    }

    printf("\nMenu: \n");
    printf("1. Append text.\n");
    printf("2. Read file.\n");
    printf("3. Exit.\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%s", data);
                fprintf(fp, "%s\n", data); //writing to file
                printf("Data appended successfully!\n");
                break;

            case 2:
                printf("\nContents of the file are: \n");
                while ((ch = fgetc(fp)) != EOF) //reading from file
                    printf("%c", ch);
                break;

            case 3:
                printf("\nExiting program!\n");
                exit(0);

            default:
                printf("\nInvalid choice.\n");
        }
    }

    fclose(fp); //closing file

    return 0;
}