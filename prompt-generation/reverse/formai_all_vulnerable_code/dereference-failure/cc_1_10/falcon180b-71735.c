//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1024*1024) //1MB
#define MAX_VIRUS_NAME_LENGTH 80
#define MAX_VIRUS_SIZE 1000
#define MAX_VIRUS_COUNT 50

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIZE];
    int size;
} virus;

virus viruses[MAX_VIRUS_COUNT];
int num_viruses;

void scan_file(const char* filename) {
    FILE* fp;
    long file_size;
    char buffer[MAX_FILE_SIZE];
    int i;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (max size is 1MB)\n", filename);
        fclose(fp);
        return;
    }

    rewind(fp);
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    for (i = 0; i < num_viruses; i++) {
        int j;
        for (j = 0; j < viruses[i].size; j++) {
            if (buffer[j]!= viruses[i].signature[j]) {
                break;
            }
        }
        if (j == viruses[i].size) {
            printf("Virus found: %s\n", viruses[i].name);
        }
    }
}

void load_viruses() {
    FILE* fp;
    char line[MAX_VIRUS_NAME_LENGTH + MAX_VIRUS_SIZE + 2];
    int i;

    fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open viruses.txt\n");
        exit(1);
    }

    num_viruses = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* virus_name = strtok(line, ":");
        char* virus_signature = strtok(NULL, ":");
        int virus_size = strlen(virus_signature);

        if (num_viruses >= MAX_VIRUS_COUNT) {
            printf("Error: Too many viruses in viruses.txt\n");
            exit(1);
        }

        strncpy(viruses[num_viruses].name, virus_name, MAX_VIRUS_NAME_LENGTH - 1);
        strncpy(viruses[num_viruses].signature, virus_signature, MAX_VIRUS_SIZE - 1);
        viruses[num_viruses].size = virus_size;
        num_viruses++;
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s file1 [file2...]\n", argv[0]);
        return 1;
    }

    load_viruses();

    for (int i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }

    return 0;
}