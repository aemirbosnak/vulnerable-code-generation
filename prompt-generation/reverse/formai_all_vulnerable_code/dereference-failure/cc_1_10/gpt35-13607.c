//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan(char* filename);
void removeVirus(char* filename);
void printHeader();

int main(int argc, char* argv[])
{
    printHeader();

    int i;
    for (i = 1; i < argc; i++)
    {
        scan(argv[i]);
    }

    printf("Scan complete.\n");
    return 0;
}

int scan(char* filename)
{
    FILE* file;
    file = fopen(filename, "rb");

    if (!file)
    {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(size);

    fread(buffer, sizeof(char), size, file);

    int infected = 0;

    if (strstr(buffer, "virus") != NULL)
    {
        printf("File %s is infected with the virus.\n", filename);

        removeVirus(filename);

        infected = 1;
    }

    fclose(file);
    free(buffer);

    return infected;
}

void removeVirus(char* filename)
{
    FILE* file;
    file = fopen(filename, "r+");

    if (!file)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[1024];
    char c;
    int i, j;

    for (i = 0; (c = fgetc(file)) != EOF; i++)
    {
        buffer[i] = c;

        if (buffer[i] == 'v' && buffer[i + 1] == 'i' && buffer[i + 2] == 'r' && buffer[i + 3] == 'u' && buffer[i + 4] == 's')
        {
            j = i;
            while (buffer[j] != '\0')
            {
                buffer[j] = buffer[j + 5];
                j++;
            }
            break;
        }
    }

    fseek(file, 0, SEEK_SET);
    fputs(buffer, file);

    fclose(file);
}

void printHeader()
{
    printf("************************************\n");
    printf("*         C Antivirus Scanner      *\n");
    printf("*       Powered by AI Technology   *\n");
    printf("************************************\n");
}