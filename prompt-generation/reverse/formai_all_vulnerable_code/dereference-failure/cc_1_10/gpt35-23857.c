//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct virus_signature {  // Structure to store virus signature
    char name[30];
    unsigned char hex_signature[20];
};

char* scan_file(FILE *file, char* filename, struct virus_signature* signatures, int num_signatures) {
    unsigned char buffer[1024];
    unsigned char file_signature[20] = {0};

    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            for (int j = 0; j < num_signatures; j++) {
                memcpy(file_signature, &buffer[i], 20);
                if (memcmp(file_signature, signatures[j].hex_signature, 20) == 0) {
                    printf("%s is infected with %s\n", filename, signatures[j].name);
                    return signatures[j].name;
                }
            }
        }
    }
    return NULL;
}

int scan_dir(char* path, struct virus_signature* signatures, int num_signatures) {
    int num_infected_files = 0;

    DIR* dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        printf("Could not open directory %s\n", path);
        return -1;
    }

    chdir(path);
    while ((entry = readdir(dir)) != NULL) {
        struct stat statbuf;
        if (stat(entry->d_name, &statbuf) == -1) {
            printf("Could not get file information for %s\n", entry->d_name);
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
                continue;
            }
            num_infected_files += scan_dir(entry->d_name, signatures, num_signatures);
        } else {
            FILE* file = fopen(entry->d_name, "rb");
            if (file == NULL) {
                printf("Could not open file %s\n", entry->d_name);
                continue;
            }

            if (scan_file(file, entry->d_name, signatures, num_signatures) != NULL) {
                num_infected_files++;
            }

            fclose(file);
        }
    }

    chdir("..");
    closedir(dir);
    return num_infected_files;
}

int main() {
    struct virus_signature signatures[] = {  // Example virus signatures
        {"Virus1", {0x33, 0xCB, 0x89, 0x9E, 0x1E, 0xAC, 0xA1, 0x5C, 0xEE, 0x27, 0x69, 0x92, 0x5A, 0x3E, 0x7C, 0x77, 0xF0, 0x12, 0x32, 0xE9}},
        {"Virus2", {0xCA, 0xD5, 0x3D, 0x3B, 0x7D, 0xFA, 0xC7, 0x05, 0xA5, 0x57, 0x86, 0x64, 0x5D, 0x9A, 0x54, 0x2B, 0x27, 0x0F, 0xCC, 0x47}}
    };

    char* path = "/home/user/Documents";
    int num_signatures = sizeof(signatures) / sizeof(struct virus_signature);

    printf("Scanning directory %s...\n", path);
    int num_infected_files = scan_dir(path, signatures, num_signatures);
    if (num_infected_files == 0) {
        printf("No infected files found.\n");
    } else {
        printf("Found %d infected files.\n", num_infected_files);
    }

    return 0;
}