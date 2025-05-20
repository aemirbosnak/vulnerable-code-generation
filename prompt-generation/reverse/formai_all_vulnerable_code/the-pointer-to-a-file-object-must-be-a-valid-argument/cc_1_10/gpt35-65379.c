//FormAI DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
    char ebook[MAX_SIZE];
    char book_text[MAX_SIZE];
    FILE *fp;
    int choice;

    printf("Welcome to the C Ebook Reader!");
    printf("\nEnter the name of the ebook you want to read: ");
    fgets(ebook, MAX_SIZE, stdin);
    ebook[strcspn(ebook, "\n")] = 0; //removing newline character from input

    fp = fopen(ebook, "r");

    if (fp == NULL)
    {
        printf("\nError! File not found.");
        exit(1);
    }

    printf("\nPlease wait while the ebook loads...");

    while (!feof(fp))
    {
        fgets(book_text, MAX_SIZE, fp);
        printf("%s", book_text);
    }

    fclose(fp);

    printf("\n\nWould you like to:\n1. Search for a keyword\n2. Exit the program\n\nEnter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        char keyword[MAX_SIZE];
        printf("\nEnter the keyword you want to search for: ");
        scanf("%s", keyword);

        fp = fopen(ebook, "r");

        printf("\nResults for the keyword '%s'...\n", keyword);

        while (!feof(fp))
        {
            fgets(book_text, MAX_SIZE, fp);
            if (strstr(book_text, keyword) != NULL)
            {
                printf("%s", book_text);
            }
        }

        fclose(fp);

        printf("\n\nThank you for using our Ebook Reader! Happy Reading!");
    }

    else if(choice == 2)
    {
        printf("\n\nThank you for using our Ebook Reader! Happy Reading!");
    }

    else
    {
        printf("\n\nError! Invalid choice.");
        exit(1);
    }

    return 0;
}