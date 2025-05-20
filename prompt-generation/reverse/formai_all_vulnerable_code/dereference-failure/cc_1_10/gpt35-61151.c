//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <openssl/md5.h>
#include <dirent.h>

#define MAX_PATH_SIZE 1024
#define BUF_SIZE 8192

int md5_file(char *path, char *md5);
int file_exists(char *path);
int copy_file(char *src, char *dst);

int main(int argc, char *argv[])
{
    char source_dir[MAX_PATH_SIZE];
    char dest_dir[MAX_PATH_SIZE];
    char md5[MD5_DIGEST_LENGTH * 2 + 1];
    struct dirent *entry;
    DIR *dir;

    // Prompt for source directory
    printf("Enter path to source directory: ");
    fgets(source_dir, MAX_PATH_SIZE, stdin);
    source_dir[strcspn(source_dir, "\n")] = '\0';

    // Prompt for destination directory
    printf("Enter path to destination directory: ");
    fgets(dest_dir, MAX_PATH_SIZE, stdin);
    dest_dir[strcspn(dest_dir, "\n")] = '\0';

    // Open source directory
    if ((dir = opendir(source_dir)) == NULL) {
        fprintf(stderr, "Failed to open source directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Iterate over files in source directory
    while ((entry = readdir(dir)) != NULL) {
        char src_path[MAX_PATH_SIZE];
        char dst_path[MAX_PATH_SIZE];

        // Ignore '.' and '..' files
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct source and destination paths
        snprintf(src_path, MAX_PATH_SIZE, "%s/%s", source_dir, entry->d_name);
        snprintf(dst_path, MAX_PATH_SIZE, "%s/%s", dest_dir, entry->d_name);

        // Check if file already exists in destination directory
        if (file_exists(dst_path)) {
            // Check if MD5 hashes match
            if (md5_file(src_path, md5) == 0 && md5_file(dst_path, md5) == 0) {
                printf("[SKIPPING] %s (already exists)\n", entry->d_name);
                continue;
            }
        }

        // Copy file to destination directory
        if (copy_file(src_path, dst_path) != 0) {
            fprintf(stderr, "Failed to copy file: %s\n", entry->d_name);
            continue;
        }

        printf("[COPYING ] %s\n", entry->d_name);
    }

    closedir(dir);
    exit(EXIT_SUCCESS);
}

/* Calculate the MD5 hash of a file */
int md5_file(char *path, char *md5)
{
    int i;
    unsigned char buf[BUF_SIZE];
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5_CTX ctx;
    struct stat st;
    FILE *f;

    // Open file for reading
    if ((f = fopen(path, "r")) == NULL) {
        return -1;
    }

    // Get file size
    if (fstat(fileno(f), &st) == -1) {
        return -1;
    }

    // Initialize MD5 context
    MD5_Init(&ctx);

    // Calculate MD5 hash
    while (!feof(f)) {
        size_t len = fread(buf, 1, BUF_SIZE, f);
        MD5_Update(&ctx, buf, len);
    }

    MD5_Final(hash, &ctx);

    // Convert hash to string
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&md5[i*2], "%02x", (unsigned int)hash[i]);
    }

    fclose(f);

    return 0;
}

/* Check if a file exists */
int file_exists(char *path)
{
    struct stat st;
    return stat(path, &st) == 0;
}

/* Copy a file from src to dst */
int copy_file(char *src, char *dst)
{
    char buf[BUF_SIZE];
    size_t nread;
    FILE *src_file, *dst_file;

    if ((src_file = fopen(src, "r")) == NULL) {
        return -1;
    }

    if ((dst_file = fopen(dst, "w")) == NULL) {
        return -1;
    }

    while ((nread = fread(buf, 1, sizeof buf, src_file)) > 0)
        fwrite(buf, 1, nread, dst_file);

    fclose(src_file);
    fclose(dst_file);

    return 0;
}