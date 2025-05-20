//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_info {
    char name[256];
    char size[32];
    char last_modified[32];
} file_info;

int main() {
    char file_name[256];
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = (char*)malloc(file_size + 1);
    fread(buffer, file_size, 1, fp);
    fclose(fp);
    fp = fopen(file_name, "r+");
    if (fp == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer, file_size, 1, fp);
    fclose(fp);
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Failed to open file for reading\n");
        return 1;
    }
    fseek(fp, 0, SEEK_SET);
    char *buffer_copy = (char*)malloc(file_size + 1);
    fread(buffer_copy, file_size, 1, fp);
    fclose(fp);
    fp = fopen(file_name, "w+");
    if (fp == NULL) {
        printf("Failed to open file for writing\n");
        return 1;
    }
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer_copy, file_size, 1, fp);
    fclose(fp);
    return 0;
}