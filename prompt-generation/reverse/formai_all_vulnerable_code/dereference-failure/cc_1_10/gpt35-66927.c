//FormAI DATASET v1.0 Category: Data recovery tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_SIZE 50
#define ERROR -1
#define SUCCESS 0

int main() {
    char file_name[FILENAME_SIZE];
    printf("Enter the name of the file you want to recover: \n");
    scanf("%s", file_name);

    FILE *fp = fopen(file_name, "rb");

    if (fp == NULL) {
        printf("Error opening file!");
        return ERROR;
    }

    fseek(fp, 0, SEEK_END);
    long long file_size = ftell(fp);
    rewind(fp);

    char *data = (char*) malloc(sizeof(char) * file_size);
    if (data == NULL) {
        printf("Memory allocation error!");
        fclose(fp);
        return ERROR;
    }

    size_t read_size = fread(data, sizeof(char), file_size, fp);
    if (read_size != file_size) {
        printf("Reading file error!");
        fclose(fp);
        return ERROR;
    }

    fclose(fp);

    char new_filename[FILENAME_SIZE];
    printf("Enter the name of the new file to store recovered data: \n");
    scanf("%s", new_filename);

    FILE *new_fp = fopen(new_filename, "wb");

    if (new_fp == NULL) {
        printf("Error opening new file!");
        free(data);
        return ERROR;
    }

    size_t write_size = fwrite(data, sizeof(char), file_size, new_fp);
    if (write_size != file_size) {
        printf("Writing file error!");
        free(data);
        fclose(new_fp);
        return ERROR;
    }

    free(data);
    fclose(new_fp);
    printf("File recovery successful!");
    return SUCCESS;
}