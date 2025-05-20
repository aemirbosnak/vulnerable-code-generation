//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <openssl/md5.h>

void calculate_md5(const char *filename, unsigned char *md5sum) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    
    unsigned char data[1024];
    size_t bytesRead;
    while ((bytesRead = fread(data, 1, sizeof(data), file)) != 0) {
        MD5_Update(&md5Context, data, bytesRead);
    }
    
    MD5_Final(md5sum, &md5Context);
    fclose(file);
}

void sync_file(const char *source, const char *dest) {
    unsigned char source_md5[MD5_DIGEST_LENGTH];
    unsigned char dest_md5[MD5_DIGEST_LENGTH];

    calculate_md5(source, source_md5);
    calculate_md5(dest, dest_md5);

    if (memcmp(source_md5, dest_md5, MD5_DIGEST_LENGTH) != 0) {
        printf("Copying %s to %s\n", source, dest);
        FILE *srcFile = fopen(source, "rb");
        FILE *destFile = fopen(dest, "wb");

        if (!srcFile || !destFile) {
            perror("Failed to open files");
            return;
        }

        char buffer[1024];
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) != 0) {
            fwrite(buffer, 1, bytesRead, destFile);
        }
        fclose(srcFile);
        fclose(destFile);
    } else {
        printf("No changes: %s is up-to-date.\n", source);
    }
}

void sync_directory(const char *sourceDir, const char *destDir) {
    DIR *dir = opendir(sourceDir);
    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files
        char sourcePath[1024];
        snprintf(sourcePath, sizeof(sourcePath), "%s/%s", sourceDir, entry->d_name);
        
        char destPath[1024];
        snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);
        
        struct stat buffer;

        if (stat(sourcePath, &buffer) == 0 && S_ISREG(buffer.st_mode)) {
            sync_file(sourcePath, destPath);
        } else if (stat(sourcePath, &buffer) == 0 && S_ISDIR(buffer.st_mode)) {
            mkdir(destPath, 0755);
            sync_directory(sourcePath, destPath);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sync_directory(argv[1], argv[2]);
    return EXIT_SUCCESS;
}