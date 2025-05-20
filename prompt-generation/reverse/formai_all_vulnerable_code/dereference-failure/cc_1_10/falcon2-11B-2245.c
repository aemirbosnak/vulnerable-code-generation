//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to read a line from the ebook file
char* read_line(FILE* file)
{
    char buffer[100];
    char* line = NULL;

    if (fgets(buffer, 100, file) == NULL)
        return NULL;

    // Remove the trailing newline character
    line = strchr(buffer, '\n');
    if (line!= NULL)
        *line = '\0';

    return line;
}

// Function to read the ebook file
void read_ebook(FILE* file)
{
    char* line = NULL;
    while ((line = read_line(file))!= NULL)
    {
        printf("%s\n", line);
        free(line);
    }
}

// Function to search for a word in the ebook
void search(FILE* file, char* word)
{
    char* line = NULL;
    int count = 0;

    while ((line = read_line(file))!= NULL)
    {
        if (strstr(line, word)!= NULL)
            count++;
        free(line);
    }

    printf("Word '%s' occurs %d times in the ebook.\n", word, count);
}

int main()
{
    FILE* file = fopen("ebook.txt", "r");
    if (file == NULL)
    {
        printf("Error opening the ebook file.\n");
        return 1;
    }

    read_ebook(file);
    fclose(file);

    char word[100];
    printf("Enter a word to search for: ");
    scanf("%s", word);
    search(file, word);

    return 0;
}