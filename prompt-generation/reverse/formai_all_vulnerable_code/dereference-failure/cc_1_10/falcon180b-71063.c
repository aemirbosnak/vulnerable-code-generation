//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define VIRUS_SIZE 1024
#define VIRUS_NAME "virus.txt"

int is_infected(char *file_content) {
    char virus_content[VIRUS_SIZE];
    FILE *virus_file = fopen(VIRUS_NAME, "r");
    if (virus_file == NULL) {
        printf("Error: Unable to open virus file.\n");
        exit(1);
    }
    fread(virus_content, 1, VIRUS_SIZE, virus_file);
    fclose(virus_file);

    int i = 0;
    while (i < strlen(file_content) && i < strlen(virus_content)) {
        if (tolower(file_content[i])!= tolower(virus_content[i])) {
            break;
        }
        i++;
    }

    if (i == strlen(virus_content)) {
        printf("File is infected with %s.\n", VIRUS_NAME);
        return 1;
    }

    return 0;
}

int scan_file(char *file_name) {
    int file_size;
    char *file_content = NULL;

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s.\n", file_name);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Unable to allocate memory for file content.\n");
        fclose(file);
        return 1;
    }

    fread(file_content, 1, file_size, file);
    file_content[file_size] = '\0';

    int result = is_infected(file_content);

    free(file_content);
    fclose(file);

    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int result = scan_file(file_name);

    if (result == 0) {
        printf("File is clean.\n");
    }

    return result;
}