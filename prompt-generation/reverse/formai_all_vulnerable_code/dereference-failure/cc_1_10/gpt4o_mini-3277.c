//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define BUFFER_SIZE 4096

typedef struct {
    char *name;
    unsigned char *signature;
    size_t sig_length;
} MaliciousFile;

MaliciousFile known_vulnerabilities[] = {
    {"Virus1", (unsigned char[]){0x90, 0x90, 0x90, 0xEB}, 4},
    {"Trojan2", (unsigned char[]){0xDE, 0xAD, 0xBE, 0xEF}, 4},
};

const size_t num_known_vltns = sizeof(known_vulnerabilities) / sizeof(MaliciousFile);

void scan_file(const char *filepath);
int contains_signature(const unsigned char *buffer, size_t length, MaliciousFile mal_file);

void scan_directory(const char *directory_path) {
    DIR *d;
    struct dirent *dir;
    char full_path[MAX_PATH];

    if ((d = opendir(directory_path)) == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
            snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, dir->d_name);
            struct stat path_stat;
            stat(full_path, &path_stat);
            if (S_ISDIR(path_stat.st_mode)) {
                scan_directory(full_path);
            } else if (S_ISREG(path_stat.st_mode)) {
                scan_file(full_path);
            }
        }
    }
    closedir(d);
}

void scan_file(const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < num_known_vltns; i++) {
            if (contains_signature(buffer, bytes_read, known_vulnerabilities[i])) {
                printf("Malicious signature detected in file: %s | Type: %s\n", filepath, known_vulnerabilities[i].name);
            }
        }
    }

    fclose(file);
}

int contains_signature(const unsigned char *buffer, size_t length, MaliciousFile mal_file) {
    for (size_t i = 0; i <= length - mal_file.sig_length; i++) {
        if (memcmp(buffer + i, mal_file.signature, mal_file.sig_length) == 0) {
            return 1; // signature found
        }
    }
    return 0; // signature not found
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    scan_directory(argv[1]);

    return EXIT_SUCCESS;
}