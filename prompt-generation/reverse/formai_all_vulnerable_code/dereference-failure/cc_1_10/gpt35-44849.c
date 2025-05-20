//FormAI DATASET v1.0 Category: File Synchronizer ; Style: secure
/*
	A secure C file synchronizer program using MD5 hash checker for file integrity
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <openssl/md5.h>
#include <pthread.h>

const char *source_dir = "/path/to/source/directory/";
const char *dest_dir = "/path/to/destination/directory/";

// function to calculate MD5 hash of given file
int get_md5(char *filename, unsigned char *hash) {
    FILE *fp;
    int bytes;
    unsigned char data[1024];
    MD5_CTX mdcontext;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    MD5_Init(&mdcontext);
    while ((bytes = fread(data, 1, 1024, fp)) != 0) {
        MD5_Update(&mdcontext, data, bytes);
    }
    MD5_Final(hash, &mdcontext);

    fclose(fp);

    return 0;
}

// function to synchronize two files by copying the source file to destination file
int sync_file(char *src, char *dest) {
    int ch;
    FILE *src_fp, *dest_fp;

    src_fp = fopen(src, "r");
    dest_fp = fopen(dest, "w");

    if (src_fp == NULL || dest_fp == NULL) {
        return -1;
    }

    while ((ch = fgetc(src_fp)) != EOF) {
        fputc(ch, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);

    return 0;
}

// thread function to synchronize all files in a directory
void *sync_dir(void *arg) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char src_path[1024], dest_path[1024];
    unsigned char src_hash[MD5_DIGEST_LENGTH], dest_hash[MD5_DIGEST_LENGTH];

    // get directory path from argument
    char *dir_path = (char *) arg;

    dir = opendir(dir_path);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", dir_path);
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // construct source and destination file paths
            sprintf(src_path, "%s/%s", dir_path, entry->d_name);
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

            if (lstat(src_path, &file_stat) == -1) {
                printf("Unable to retrieve file information for %s\n", src_path);
                continue;
            }

            if (S_ISDIR(file_stat.st_mode)) {
                // recursively sync subdirectory
                sync_dir(src_path);
            } else if (S_ISREG(file_stat.st_mode)) {
                // check if destination file exists and is up-to-date
                if (access(dest_path, F_OK) != -1) {
                    get_md5(src_path, src_hash);
                    get_md5(dest_path, dest_hash);

                    if (memcmp(src_hash, dest_hash, sizeof(src_hash)) == 0) {
                        // files are already in sync
                        continue;
                    }
                }

                // sync source file to destination file
                if (sync_file(src_path, dest_path) == 0) {
                    printf("Synchronized %s\n", dest_path);
                } else {
                    printf("Failed to synchronize %s\n", dest_path);
                }
            }
        }
    }

    closedir(dir);

    return NULL;
}

int main() {
    pthread_t thread;

    // create destination directory if it doesn't already exist
    mkdir(dest_dir, 0777);

    // synchronize source and destination directories
    pthread_create(&thread, NULL, sync_dir, (void *) source_dir);
    pthread_join(thread, NULL);

    return 0;
}