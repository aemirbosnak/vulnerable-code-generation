//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_PATH 256

typedef struct {
    char *name;
    int length;
} virus;

virus viruses[] = {
    { "WannaCry", 9 },
    { "Locky", 6 },
    { "Petya", 6 },
    { "MyDoom", 7 },
    { "ILOVEYOU", 9 }
};

int num_viruses = sizeof(viruses) / sizeof(viruses[0]);

void scan_file(char *file_path) {
    FILE *fp;
    char buffer[MAX_VIRUS_LENGTH];
    int buffer_index = 0;

    fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", file_path);
        exit(1);
    }

    while (fread(buffer + buffer_index, 1, MAX_VIRUS_LENGTH - buffer_index, fp) > 0) {
        buffer_index += fread(buffer + buffer_index, 1, MAX_VIRUS_LENGTH - buffer_index, fp);
        if (buffer_index >= MAX_VIRUS_LENGTH) {
            buffer_index = 0;
        }
    }

    for (int i = 0; i < num_viruses; i++) {
        virus *v = &viruses[i];
        int virus_length = strlen(v->name);

        while (buffer_index + virus_length <= MAX_VIRUS_LENGTH) {
            int j;
            for (j = 0; j < virus_length; j++) {
                if (tolower(buffer[buffer_index + j])!= tolower(v->name[j])) {
                    break;
                }
            }

            if (j == virus_length) {
                printf("Virus found: %s\n", v->name);
                exit(1);
            }

            buffer_index++;
        }
    }

    fclose(fp);
    printf("File '%s' is clean.\n", file_path);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(1);
    }

    char file_path[MAX_FILE_PATH];
    strcpy(file_path, argv[1]);

    scan_file(file_path);

    return 0;
}