//FormAI DATASET v1.0 Category: File Synchronizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1024

void synchronize_files(char* filename1, char* filename2);
int compare_files(char file1_data[], char file2_data[]);
void write_to_file(char filename[], char data[]);

int main()
{
    char file1[MAX_FILE_SIZE], file2[MAX_FILE_SIZE];
    char file1_name[MAX_FILE_NAME], file2_name[MAX_FILE_NAME];
    printf("Enter the first file name: ");
    scanf("%s", file1_name);
    printf("Enter the second file name: ");
    scanf("%s", file2_name);

    synchronize_files(file1_name, file2_name);
    return 0;
}

void synchronize_files(char* filename1, char* filename2)
{
    FILE * file1, * file2;
    char file1_data[MAX_FILE_SIZE], file2_data[MAX_FILE_SIZE];
    int file1_size = 0, file2_size = 0;

    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

    if (file1 == NULL)
    {
        printf("Unable to open %s\n", filename1);
        return;
    }

    if (file2 == NULL)
    {
        printf("Unable to open %s\n", filename2);
        return;
    }

    fseek(file1, 0, SEEK_END);
    file1_size = ftell(file1);

    fseek(file2, 0, SEEK_END);
    file2_size = ftell(file2);

    rewind(file1);
    rewind(file2);

    fgets(file1_data, file1_size + 1, file1);
    fgets(file2_data, file2_size + 1, file2);

    int result = compare_files(file1_data, file2_data);

    if (result == 0)
    {
        printf("%s and %s are already synchronized.", filename1, filename2);
        return;
    }

    if (result == -1)
    {
        write_to_file(filename1, file2_data);
        printf("%s is now synchronized with %s.", filename1, filename2);
        return;
    }

    if (result == 1)
    {
        write_to_file(filename2, file1_data);
        printf("%s is now synchronized with %s.", filename2, filename1);
        return;
    }

    fclose(file1);
    fclose(file2);
}

int compare_files(char file1_data[], char file2_data[])
{
    if (strcmp(file1_data, file2_data) == 0)
    {
        return 0;
    }
    else if (strcmp(file1_data, file2_data) < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void write_to_file(char filename[], char data[])
{
    FILE * file = fopen(filename, "w");
    fputs(data, file);
    fclose(file);
}