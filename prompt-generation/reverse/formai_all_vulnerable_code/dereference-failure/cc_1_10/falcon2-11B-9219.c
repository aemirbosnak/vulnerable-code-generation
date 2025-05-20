//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to compare two strings
int compareStrings(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2)
        return 0;

    while (len1--)
    {
        if (str1[len1]!= str2[len1])
            return 0;
    }

    return 1;
}

// Function to read a file and return its content as a string
char* readFile(const char* filename)
{
    FILE* file = fopen(filename, "rb");

    if (file == NULL)
        return NULL;

    char* content = (char*)malloc(sizeof(char) * (1000 * 1024)); // Maximum size of file content = 1MB
    fread(content, 1, 1000 * 1024, file);
    fclose(file);

    return content;
}

// Function to write a string to a file
void writeFile(const char* filename, char* content)
{
    FILE* file = fopen(filename, "wb");

    if (file == NULL)
        return;

    fwrite(content, 1, strlen(content), file);
    fclose(file);
}

int main()
{
    // Read contents of file1 and file2
    char* content1 = readFile("file1.txt");
    char* content2 = readFile("file2.txt");

    if (content1 == NULL || content2 == NULL)
    {
        printf("Error reading file.\n");
        return 1;
    }

    // Compare sizes of files
    int size1 = strlen(content1);
    int size2 = strlen(content2);

    if (size1!= size2)
    {
        printf("Files have different sizes.\n");
        free(content1);
        free(content2);
        return 1;
    }

    // Compare contents of files
    if (compareStrings(content1, content2))
    {
        printf("Files are synchronized.\n");
        free(content1);
        free(content2);
        return 0;
    }

    printf("Files are not synchronized.\n");
    free(content1);
    free(content2);
    return 1;
}