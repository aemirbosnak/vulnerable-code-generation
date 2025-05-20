//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10MB

typedef enum {
    VIRUS_FOUND,
    NO_VIRUS,
    FILE_ERROR
} scan_result;

void print_usage(char *prog_name) {
    printf("Usage: %s <filename>\n", prog_name);
}

scan_result scan_file(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    scan_result result = NO_VIRUS;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return FILE_ERROR;
    }

    while ((read = getline(&line, &len, fp))!= -1) {
        if (strstr(line, "virus")!= NULL) {
            printf("Virus found in file '%s'\n", filename);
            result = VIRUS_FOUND;
            break;
        }
    }

    free(line);
    fclose(fp);

    return result;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    scan_result result = scan_file(argv[1]);

    if (result == VIRUS_FOUND) {
        printf("File '%s' contains a virus!\n", argv[1]);
    } else if (result == NO_VIRUS) {
        printf("File '%s' is clean.\n", argv[1]);
    }

    return 0;
}