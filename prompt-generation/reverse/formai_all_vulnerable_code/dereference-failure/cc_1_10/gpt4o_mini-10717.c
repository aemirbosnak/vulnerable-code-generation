//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH 1024
#define HASH_TABLE_SIZE 1000
#define FILE_SIGNATURE_SIZE 128
#define MAX_FILE_SIZE 1048576  // 1 MB max file size for scanning
#define SLEEP_DURATION 5000000  // 5 seconds in microseconds

typedef struct FileSignature {
    char name[FILE_SIGNATURE_SIZE];
    unsigned long checksum;
} FileSignature;

// Sample virus signatures
FileSignature virus_signatures[] = {
    {"EICAR", 0x27509D8E},
    {"DummyVirus1", 0xABCD1234},
    {"FakeMalware", 0xBEAFCAFE},
};

size_t num_signatures = sizeof(virus_signatures) / sizeof(FileSignature);

unsigned long simple_hash(const char *data, size_t len) {
    unsigned long hash = 5381;
    int c;
    while ((c = *data++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

int is_virus(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("File open error");
        return 0;
    }
    
    unsigned char *buffer = (unsigned char *)malloc(MAX_FILE_SIZE);
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    if (bytes_read == 0) {
        free(buffer);
        return 0;
    }

    unsigned long checksum = simple_hash((const char *)buffer, bytes_read);
    free(buffer);

    for (size_t i = 0; i < num_signatures; i++) {
        if (virus_signatures[i].checksum == checksum) {
            printf("Virus detected: %s in file %s\n", virus_signatures[i].name, file_path);
            return 1;  // Virus found
        }
    }

    return 0;  // No virus
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char file_path[MAX_PATH];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

            if (entry->d_type == DT_DIR) {
                scan_directory(file_path);  // Recursive scan for directories
            } else if (entry->d_type == DT_REG) {
                is_virus(file_path);  // Check if the file is a virus
            }
        }
    }

    closedir(dp);
}

void print_intro() {
    printf("*************************\n");
    printf("*     Simple Antivirus    *\n");
    printf("*     Version 1.0        *\n");
    printf("*************************\n");
    printf("Scanning for viruses...\n");
}

void wait_before_next_scan() {
    printf("Waiting before next scan...\n");
    usleep(SLEEP_DURATION);  // Sleep for a duration before scanning again
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_intro();
    
    while (1) {
        scan_directory(argv[1]);
        wait_before_next_scan();
    }

    return EXIT_SUCCESS;
}