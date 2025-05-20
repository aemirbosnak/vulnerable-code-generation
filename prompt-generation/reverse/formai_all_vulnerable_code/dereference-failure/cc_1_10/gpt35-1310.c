//FormAI DATASET v1.0 Category: Data recovery tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recover(char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* data = malloc(sizeof(char) * (size + 1));
    if (data == NULL)
    {
        printf("Error allocating memory.\n");
        return;
    }

    fread(data, sizeof(char), size, file);

    fclose(file);

    int i = 0;
    while (i < size)
    {
        if (data[i] == 'd' || data[i] == 'a' || data[i] == 't' || data[i] == 'e')
        {
            printf("%c", data[i] - 23);
        }
        else if (data[i] >= 'b' && data[i] <= 'z')
        {
            printf("%c", data[i] - 1);
        }
        else if (data[i] >= 'A' && data[i] <= 'Z')
        {
            printf("%c", data[i] + 32);
        }
        else if (data[i] >= '0' && data[i] <= '9')
        {
            printf("%c", data[i] + 5);
        }
        else
        {
            printf("%c", data[i]);
        }
        i++;
    }

    free(data);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    printf("Welcome to the mind-bending data recovery tool!\n");

    int confirm;
    printf("Are you sure you want to recover data from %s? (1 for yes, 0 for no): ", argv[1]);
    scanf("%d", &confirm);

    if (confirm == 1)
    {
        recover(argv[1]);
    }
    else
    {
        printf("Aborting data recovery.\n");
    }

    return 0;
}