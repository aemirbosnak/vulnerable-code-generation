//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define SIGNATURE_SIZE 16
#define MAX_VIRUSES 100

typedef struct {
    char name[50];
    unsigned char signature[SIGNATURE_SIZE];
} Virus;

void load_viruses(Virus *viruses, int *count) {
    FILE *file = fopen("viruses.dat", "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open viruses.dat\n");
        exit(1);
    }

    fread(count, sizeof(int), 1, file);
    fread(viruses, sizeof(Virus), *count, file);
    fclose(file);
}

int is_infected(const char *file_path, Virus *viruses, int virus_count) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", file_path);
        return 0;
    }

    unsigned char buffer[SIGNATURE_SIZE];
    fread(buffer, sizeof(unsigned char), SIGNATURE_SIZE, file);
    fclose(file);

    for (int i = 0; i < virus_count; i++) {
        if (memcmp(buffer, viruses[i].signature, SIGNATURE_SIZE) == 0) {
            return i; // Return index of infected virus
        }
    }
    return -1; // Not infected
}

void scan_file(const char *file_path, Virus *viruses, int virus_count) {
    int virus_index = is_infected(file_path, viruses, virus_count);
    if (virus_index != -1) {
        printf("Infected: %s with virus: %s\n", file_path, viruses[virus_index].name);
    }
}

void scan_directory(const char *dir_path, Virus *viruses, int virus_count) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    if (!dir) {
        fprintf(stderr, "Error: Could not open directory %s\n", dir_path);
        return;
    }

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                scan_directory(full_path, viruses, virus_count);
            } else if (entry->d_type == DT_REG) {
                scan_file(full_path, viruses, virus_count);
            }
        }
    }
    closedir(dir);
}

void print_help() {
    printf("Cyberpunk Antivirus Scanner - Version 2077\n");
    printf("Usage: ./cyber_scan <directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_help();
        return 1;
    }

    Virus viruses[MAX_VIRUSES];
    int virus_count = 0;

    load_viruses(viruses, &virus_count);
    printf("Loaded %d virus signatures.\n", virus_count);

    char *directory = argv[1];
    scan_directory(directory, viruses, virus_count);

    printf("Scanning completed. Stay cyber safe!\n");
    return 0;
}