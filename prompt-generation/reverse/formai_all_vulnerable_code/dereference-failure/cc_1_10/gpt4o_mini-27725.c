//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <openssl/md5.h>

#define MAX_PATH_LENGTH 256
#define HASH_LENGTH 32

void calculate_md5(const char *filename, unsigned char *result) {
    MD5_CTX md5_ctx;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    MD5_Init(&md5_ctx);
    unsigned char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) != 0) {
        MD5_Update(&md5_ctx, buffer, bytesRead);
    }

    MD5_Final(result, &md5_ctx);
    fclose(file);
}

void print_hash(unsigned char *hash, char *output) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&output[i*2], "%02x", hash[i]);
    }
    output[HASH_LENGTH - 1] = '\0'; // Null terminate the string
}

int file_exists(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

void sync_files(const char *src, const char *dst) {
    DIR *dir = opendir(src);
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char src_file[MAX_PATH_LENGTH];
        char dst_file[MAX_PATH_LENGTH];
        snprintf(src_file, sizeof(src_file), "%s/%s", src, entry->d_name);
        snprintf(dst_file, sizeof(dst_file), "%s/%s", dst, entry->d_name);

        if (file_exists(dst_file)) {
            // File exists in both directories, check the hash
            unsigned char src_hash[MD5_DIGEST_LENGTH], dst_hash[MD5_DIGEST_LENGTH];
            calculate_md5(src_file, src_hash);
            calculate_md5(dst_file, dst_hash);

            if (memcmp(src_hash, dst_hash, MD5_DIGEST_LENGTH) != 0) {
                // File exists but is different; copy the source file to destination
                printf("Updating file: %s\n", dst_file);
                rename(src_file, dst_file);
            }
        } else {
            // File does not exist in destination; copy it over
            printf("Copying new file: %s to %s\n", src_file, dst_file);
            rename(src_file, dst_file);
        }
    }
    closedir(dir);

    // Log files in destination that are not in source
    dir = opendir(dst);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        
        char src_file[MAX_PATH_LENGTH];
        snprintf(src_file, sizeof(src_file), "%s/%s", src, entry->d_name);

        if (!file_exists(src_file)) {
            // File exists in destination but not in source
            printf("File not found in source: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}