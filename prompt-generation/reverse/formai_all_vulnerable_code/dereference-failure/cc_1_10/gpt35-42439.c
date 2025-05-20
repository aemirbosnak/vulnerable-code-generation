//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// add your virus signatures here
const char *virus_signatures[] = {
    "rm -rf /",
    "chmod 777 *",
    "dd if=/dev/random of=/dev/sda",
    "mkfs.ext3 /dev/sda"
};

int check_file_virus(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    // read file content into buffer
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(file_size);
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // check for virus signatures
    for (int i = 0; i < sizeof(virus_signatures)/sizeof(char *); i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            free(buffer);
            return 1;
        }
    }

    free(buffer);
    return 0;
}

int check_directory_virus(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        return 0;
    }

    int virus_detected = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // ignore subdirectories
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                continue;
            }
        } else {
            char filepath[1024];
            sprintf(filepath, "%s/%s", dirname, entry->d_name);
            if (check_file_virus(filepath)) {
                printf("Virus detected in file: %s\n", filepath);
                virus_detected = 1;
            }
        }
    }

    closedir(dir);

    return virus_detected;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 0;
    }

    char *dirname = argv[1];
    int virus_detected = check_directory_virus(dirname);

    if (virus_detected) {
        printf("Virus detected in directory: %s\n", dirname);
    } else {
        printf("No virus detected in directory: %s\n", dirname);
    }

    return 0;
}