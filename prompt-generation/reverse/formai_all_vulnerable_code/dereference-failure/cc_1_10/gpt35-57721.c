//FormAI DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1000

void encypt(char *filename, int key);

int main(int argc, char **argv)
{
    if (argc != 3) 
    {
        printf("Invalid arguments - please provide a file name and an integer key\n");
        return 1;
    }

    char *filename = argv[1];
    int key = atoi(argv[2]);

    if (key == 0) 
    {
        printf("Invalid encryption key - please provide a non-zero integer key\n");
        return 1;
    }

    encypt(filename, key);

    return 0;
}

void encypt(char *filename, int key)
{
    FILE *fptr;
    char line[MAX_LENGTH];
    char encrypted_line[MAX_LENGTH];
    int line_length, i;

    fptr = fopen(filename, "r");
    if (fptr == NULL) 
    {
        printf("Error opening file\n");
        return;
    }

    while (fgets(line, MAX_LENGTH, fptr) != NULL) 
    {
        line_length = strlen(line);
        for (i = 0; i < line_length; i++)
        {
            encrypted_line[i] = fmod((line[i] + key), 256);
        }

        printf("%s", encrypted_line);
    }

    fclose(fptr);
}