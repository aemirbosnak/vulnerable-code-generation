//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *filename;
    char *data;
    int checksum;
} file_t;

int calculate_checksum(char *data) {
    int checksum = 0;
    int i;
    for (i = 0; i < strlen(data); i++) {
        checksum += tolower(data[i]) - 'a' + 1;
    }
    return checksum % 26 + 'a';
}

void write_file(file_t *file) {
    FILE *outfile;
    outfile = fopen(file->filename, "w");
    if (outfile == NULL) {
        printf("Error: could not open file %s for writing.\n", file->filename);
        exit(1);
    }
    fprintf(outfile, "Filename: %s\n", file->filename);
    fprintf(outfile, "Data: %s\n", file->data);
    fprintf(outfile, "Checksum: %c\n", file->checksum);
    fclose(outfile);
}

int main() {
    char input[MAX_LINE_LENGTH];
    char filename[MAX_FILE_NAME_LENGTH];
    char data[MAX_LINE_LENGTH];
    int checksum;
    int i;
    int j;
    file_t file;

    printf("Enter the filename (without extension): ");
    fgets(filename, MAX_FILE_NAME_LENGTH, stdin);
    filename[strcspn(filename, "\r\n")] = '\0';

    printf("Enter the data: ");
    fgets(data, MAX_LINE_LENGTH, stdin);
    data[strcspn(data, "\r\n")] = '\0';

    file.filename = malloc(strlen(filename) + 5);
    strcpy(file.filename, filename);
    strcat(file.filename, ".txt");

    file.data = malloc(strlen(data) + 1);
    strcpy(file.data, data);

    checksum = calculate_checksum(data);

    file.checksum = checksum;

    printf("Filename: %s\n", file.filename);
    printf("Data: %s\n", file.data);
    printf("Checksum: %c\n", file.checksum);

    write_file(&file);

    return 0;
}