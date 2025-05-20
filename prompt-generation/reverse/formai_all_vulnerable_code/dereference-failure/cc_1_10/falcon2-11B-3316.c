//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LEN 1000

int main()
{
    char book[MAX_LEN];
    char word[MAX_LEN];
    char buffer[MAX_LEN];
    int page = 1;
    bool done = false;
    bool exit = false;
    int i, j;
    
    printf("Welcome to the C Ebook reader!\n");
    
    while (!exit)
    {
        printf("\nPlease enter the name of the book you want to read: ");
        fgets(book, MAX_LEN, stdin);
        book[strcspn(book, "\n")] = '\0';
        
        if (strcmp(book, "quit") == 0)
        {
            exit = true;
            printf("\nGoodbye!\n");
        }
        else
        {
            FILE *fp;
            char* filename = malloc(strlen(book) + 1);
            strcpy(filename, book);
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                printf("Error opening file: %s\n", filename);
                exit = true;
            }
            else
            {
                while (!done)
                {
                    printf("\nPage %d:\n", page);
                    fgets(buffer, MAX_LEN, fp);
                    buffer[strcspn(buffer, "\n")] = '\0';
                    word[0] = '\0';
                    for (i = 0; i < strlen(buffer); i++)
                    {
                        if (isalpha(buffer[i]))
                        {
                            word[i] = buffer[i];
                        }
                    }
                    if (strcmp(word, "THE END") == 0)
                    {
                        done = true;
                    }
                    else
                    {
                        printf("%s", word);
                        page++;
                    }
                }
                free(filename);
                fclose(fp);
            }
        }
    }
    
    return 0;
}