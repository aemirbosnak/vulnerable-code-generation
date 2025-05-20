//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_VIRUS_SIGNATURES 1000
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_VIRUS_SIGNATURE_LENGTH 1000
#define MAX_SCANNED_FILE_SIZE 1048576

typedef struct virus {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURE_LENGTH];
    int signature_length;
} virus_t;

typedef struct virus_db {
    virus_t viruses[MAX_VIRUS_SIGNATURES];
    int size;
} virus_db_t;

char* read_file(char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    if (file_size > MAX_SCANNED_FILE_SIZE) {
        printf("File size too big\n");
        exit(1);
    }

    char* buffer = malloc(file_size);
    fread(buffer, file_size, 1, file);
    fclose(file);

    return buffer;
}

void scan_file(char* file_name, virus_db_t virus_db) {
    char* buffer = read_file(file_name);

    for (int i = 0; i < virus_db.size; i++) {
        virus_t virus = virus_db.viruses[i];
        int found = 0;

        for (int j = 0; j < MAX_SCANNED_FILE_SIZE - virus.signature_length; j++) {
            if (memcmp(buffer + j, virus.signature, virus.signature_length) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Virus detected! File: %s\tVirus: %s\n", file_name, virus.name);
            break;
        }
    }

    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    virus_db_t virus_db;
    virus_db.size = 0;

    virus_t virus1 = {"Virus 1", "ababab", 6};
    virus_db.viruses[virus_db.size++] = virus1;

    virus_t virus2 = {"Virus 2", "cdcdcd", 6};
    virus_db.viruses[virus_db.size++] = virus2;

    virus_t virus3 = {"Virus 3", "1234567890", 10};
    virus_db.viruses[virus_db.size++] = virus3;

    virus_t virus4 = {"Virus 4", "qwertyuiop", 10};
    virus_db.viruses[virus_db.size++] = virus4;

    virus_t virus5 = {"Virus 5", "asdfghjkl", 9};
    virus_db.viruses[virus_db.size++] = virus5;

    scan_file(argv[1], virus_db);

    return 0;
}