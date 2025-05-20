//FormAI DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Declaration of variables and file pointers
    char filename[20];
    char message[100];
    int choice;
    FILE *fp;

    printf("\nSurvival Tip: Always have a backup plan, including backup files\n");

    //Creating a new apocalyptic file or opening existing one
    printf("\nWhat is the name of your apocalyptic file? ");
    scanf("%s", filename);
    fp = fopen(filename, "a+");

    //Displaying file content and selecting options
    while (1)
    {
        printf("\nWhat do you want to do?\n1. Write a new message\n2. Read the file\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter your message (max 100 characters):\n");
            getchar(); //To read the '\n' character before fgets
            fgets(message, 100, stdin);
            fprintf(fp, "%s\n", message);
            printf("\nMessage successfully saved!\n");
            break;

        case 2:
            printf("\nMessages in your apocalyptic file:\n");
            rewind(fp); //To go back to the beginning of the file
            char temp[100];
            while (fgets(temp, 100, fp) != NULL)
            {
                printf("%s", temp);
            }
            printf("\n");
            break;

        case 3:
            printf("\nBefore you go, remember to always stay alert and stay alive\n");
            fclose(fp); //To close the file
            exit(0);

        default:
            printf("\nInvalid option! Try again\n");
        }
    }

    return 0;
}