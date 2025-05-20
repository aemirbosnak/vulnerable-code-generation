//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    FILE *file_ptr;
} FILE_HANDLE;

FILE_HANDLE *open_file(char *file_name)
{
    FILE_HANDLE *file_handle = (FILE_HANDLE *)malloc(sizeof(FILE_HANDLE));

    strcpy(file_handle->file_name, file_name);
    file_handle->file_ptr = fopen(file_name, "r");

    if (file_handle->file_ptr == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    return file_handle;
}

void close_file(FILE_HANDLE *file_handle)
{
    fclose(file_handle->file_ptr);
    free(file_handle);
}

char *read_line(FILE_HANDLE *file_handle, char *buffer)
{
    char *line = fgets(buffer, MAX_LINE_LEN, file_handle->file_ptr);

    if (line == NULL) {
        printf("End of file reached\n");
        return NULL;
    }

    int len = strlen(line);
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    return line;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE_HANDLE *file_handle = open_file(argv[1]);

    char buffer[MAX_LINE_LEN];
    char *line = NULL;

    while ((line = read_line(file_handle, buffer))!= NULL) {
        printf("%s", line);
    }

    close_file(file_handle);

    return 0;
}