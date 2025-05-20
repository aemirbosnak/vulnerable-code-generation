//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

// Define the virus signature
char virus_signature[] = "7369646520656666696369656e74207465787420766563746f72";

// Helper function to read file content and return it as a string
char* read_file_content(const char* file_path) {
    FILE* fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("Error: Failed to read %s. %s\n", file_path, strerror(errno));
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        fclose(fp);
        return NULL;
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);
    buffer[file_size] = '\0';

    return buffer;
}

// Helper function to convert hex string to byte array
void hex_string_to_byte_array(char* hex_string, unsigned char* byte_array, size_t byte_array_len) {
    size_t hex_len = strlen(hex_string);
    size_t byte_array_pos = 0;

    for (size_t i = 0; i < hex_len; i += 2) {
        if (byte_array_pos >= byte_array_len) {
            return;
        }

        char hex_byte[3] = { hex_string[i], hex_string[i + 1], '\0' };
        byte_array[byte_array_pos++] = strtol(hex_byte, NULL, 16);
    }
}

// Helper function to check if a file is infected with the virus
int is_file_infected(const char* file_path) {
    char* file_content = read_file_content(file_path);
    if (file_content == NULL) {
        return 0;
    }

    size_t file_content_len = strlen(file_content);
    size_t signature_len = strlen(virus_signature) / 2;
    unsigned char signature[signature_len];
    hex_string_to_byte_array(virus_signature, signature, signature_len);

    for (size_t i = 0; i < file_content_len - signature_len; i++) {
        int is_match = 1;
        for (size_t j = 0; j < signature_len; j++) {
            if (file_content[i + j] != signature[j]) {
                is_match = 0;
                break;
            }
        }
        if (is_match) {
            free(file_content);
            return 1;
        }
    }

    free(file_content);
    return 0;
}

// Helper function to scan a given directory and all its sub-directories for infected files
void scan_directory(const char* dir_path) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Error: Failed to open directory %s. %s\n", dir_path, strerror(errno));
        return;
    }

    struct dirent* dirent;
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
            continue;
        }

        char file_path[1024];
        sprintf(file_path, "%s/%s", dir_path, dirent->d_name);

        if (dirent->d_type == DT_DIR) {
            scan_directory(file_path);
        } else if (dirent->d_type == DT_REG) {
            if (is_file_infected(file_path)) {
                printf("%s is infected!\n", file_path);
            } else {
                printf("%s is clean\n", file_path);
            }
        } else {
            printf("%s is not a regular file. Skipping...\n", file_path);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory-to-scan>\n", argv[0]);
        return 0;
    }

    const char* dir_path = argv[1];
    printf("Scanning %s...\n", dir_path);
    scan_directory(dir_path);
    printf("Done.\n");

    return 0;
}