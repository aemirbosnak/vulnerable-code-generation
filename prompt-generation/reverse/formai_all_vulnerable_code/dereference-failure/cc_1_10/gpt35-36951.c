//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 255
#define VIRUS_SIGNATURE "5649525553" // "VIRUS" in hexadecimal

typedef struct {
    char filename[MAX_FILENAME_LEN + 1];
    int is_infected;
} file_t;

void scan_file(file_t *file);
void detect_virus(char *contents, int *is_infected);
void clean_infected_files(file_t *files, int num_files);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename1> <filename2> ... <filenameN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_files = argc - 1;
    file_t *files = malloc(num_files * sizeof(file_t));
    if (!files) {
        printf("Error: could not allocate memory for file list\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < num_files; i++) {
        strncpy(files[i].filename, argv[i + 1], MAX_FILENAME_LEN);
        files[i].filename[MAX_FILENAME_LEN] = '\0';
        files[i].is_infected = 0;

        scan_file(&files[i]);

        if (files[i].is_infected) {
            printf("Warning: file %s is infected with virus\n", files[i].filename);
        }
    }

    clean_infected_files(files, num_files);
    free(files);

    return EXIT_SUCCESS;
}

void scan_file(file_t *file) {
    FILE *f = fopen(file->filename, "rb");
    if (!f) {
        printf("Error: could not open file %s\n", file->filename);
        return;
    }

    fseek(f, 0L, SEEK_END);
    long filesize = ftell(f);
    rewind(f);

    char *contents = malloc((size_t)filesize);
    if (!contents) {
        printf("Error: could not allocate memory for file contents of %s\n", file->filename);
        fclose(f);
        return;
    }

    fread(contents, 1, (size_t)filesize, f);
    fclose(f);

    detect_virus(contents, &file->is_infected);
    free(contents);
}

void detect_virus(char *contents, int *is_infected) {
    int i;
    for (i = 0; contents[i] != '\0'; i++) {
        if (contents[i] == VIRUS_SIGNATURE[0]) {
            int j;
            for (j = 0; VIRUS_SIGNATURE[j] != '\0'; j++) {
                if (contents[i + j] != VIRUS_SIGNATURE[j]) {
                    break;
                }
            }
            if (VIRUS_SIGNATURE[j] == '\0') {
                *is_infected = 1;
                return;
            }
        }
    }
}

void clean_infected_files(file_t *files, int num_files) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (files[i].is_infected) {
            char *cmd = malloc(sizeof(char) * (strlen(files[i].filename) + 7));
            // The command '[rm ' + MAX_FILENAME_LEN + 1 + ']'
            if (!cmd) {
                printf("Error: could not allocate memory for cleaning command\n");
                continue;
            }
            sprintf(cmd, "rm %s", files[i].filename);
            system(cmd);
            printf("%s has been cleaned\n", files[i].filename);
            free(cmd);
        }
    }
}