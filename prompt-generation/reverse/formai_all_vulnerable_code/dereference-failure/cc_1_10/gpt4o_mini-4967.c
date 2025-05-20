//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256
#define SIGNATURE_SIZE 16
#define MAX_SIGNATURES 10
#define MAX_FILES 100

static const char *signatures[MAX_SIGNATURES] = {
    "malware_signature_1",
    "malware_signature_2",
    "malware_signature_3",
    "malware_signature_4",
    "malware_signature_5"
};

struct FileData {
    char path[MAX_PATH];
    int is_infected;
};

void scan_file(const char *filename, struct FileData *file_data) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    unsigned char buffer[1024];
    size_t bytes_read;
    file_data->is_infected = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < MAX_SIGNATURES; i++) {
            if (strstr((char *)buffer, signatures[i]) != NULL) {
                file_data->is_infected = 1;
                printf("Infected file found: %s with signature: %s\n", filename, signatures[i]);
                break;
            }
        }
    }

    fclose(file);
}

void scan_directory(const char *dir_path) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    struct FileData files[MAX_FILES];
    int file_count = 0;

    if (dp == NULL) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            if (file_count < MAX_FILES) {
                snprintf(files[file_count].path, MAX_PATH, "%s/%s", dir_path, entry->d_name);
                scan_file(files[file_count].path, &files[file_count]);
                file_count++;
            } else {
                printf("Maximum file limit reached. Skipping further files.\n");
                break;
            }
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);
    return EXIT_SUCCESS;
}