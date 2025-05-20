//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[100];
    char checksum[100];
} FileInfo;

void read_file(char *filename, char *buffer) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File %s is too large (max size is %d bytes)\n", filename, MAX_FILE_SIZE);
        exit(1);
    }

    buffer[0] = '\0';
    char c;
    while ((c = fgetc(file))!= EOF) {
        strcat(buffer, &c);
    }

    fclose(file);
}

void calculate_checksum(char *buffer, char *checksum) {
    int sum = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        sum += buffer[i];
    }
    sprintf(checksum, "%d", sum % 256);
}

void write_checksum(FileInfo *file_info) {
    FILE *file = fopen(file_info->filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing\n", file_info->filename);
        exit(1);
    }

    fprintf(file, "%s", file_info->checksum);

    fclose(file);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    char buffer[MAX_FILE_SIZE];
    read_file(filename, buffer);

    char checksum[100];
    calculate_checksum(buffer, checksum);

    FileInfo file_info;
    strcpy(file_info.filename, filename);
    strcpy(file_info.checksum, checksum);

    write_checksum(&file_info);

    printf("Checksum calculated and written to file.\n");

    return 0;
}