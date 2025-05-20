//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LEN 1024
#define MAX_SIGNATURE_LEN 64
#define MAX_FILE_SIZE (5 * 1024 * 1024) // 5MB

char virus_signatures[][MAX_SIGNATURE_LEN] = {
    "virus_signature_1",
    "virus_signature_2",
    "virus_signature_3",
    // add more signatures here
};

int is_virus_signature(char* bytes) {
    for (int i = 0; i < sizeof(virus_signatures) / MAX_SIGNATURE_LEN; i++) {
        if (strstr(bytes, virus_signatures[i])) {
            return 1;
        }
    }

    return 0;
}

int scan_file(char* file_path) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        return 1;
    }

    char bytes[MAX_FILE_SIZE];
    size_t num_bytes = fread(bytes, sizeof(char), MAX_FILE_SIZE, file);
    bytes[num_bytes] = '\0';
    fclose(file);

    if (is_virus_signature(bytes)) {
        printf("%s contains a virus signature!\n", file_path);
    } else {
        printf("%s is clean.\n", file_path);
    }

    return 0;
}

int scan_directory(char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[MAX_PATH_LEN];
        snprintf(file_path, MAX_PATH_LEN, "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            scan_directory(file_path);
        } else if (entry->d_type == DT_REG) {
            scan_file(file_path);
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    printf("Scanning directory %s...\n", argv[1]);
    scan_directory(argv[1]);
    printf("Done.\n");

    return 0;
}