//Falcon2-11B DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from the file
char* readLine(FILE* file)
{
    char buffer[1000];
    char* line = NULL;
    size_t len = 0;
    size_t read = 0;

    while ((read = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        len += read;
        if (buffer[read - 1] == '\n')
        {
            line = (char*)malloc(len + 1);
            strncpy(line, buffer, len);
            line[len] = '\0';
            break;
        }
    }

    if (line)
    {
        line[len] = '\0';
        return line;
    }

    return NULL;
}

int main()
{
    FILE* file = fopen("test.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    char* line = readLine(file);

    if (line!= NULL)
    {
        printf("%s", line);
        free(line);
    }

    fclose(file);

    return 0;
}