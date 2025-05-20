//FormAI DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <openssl/md5.h>

#define MAX_PATH_LEN 256
#define MAX_FILENAME_LEN 64
#define MD5_DIGEST_LEN 16

void print_error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

void calc_file_md5(char* path, unsigned char* md5) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        print_error("Could not open file");
    }

    MD5_CTX md5ctx;
    MD5_Init(&md5ctx);

    char buffer[1024];
    size_t nbytes;

    while ((nbytes = fread(buffer, 1, 1024, file)) != 0) {
        MD5_Update(&md5ctx, buffer, nbytes);
    }

    MD5_Final(md5, &md5ctx);

    fclose(file);
}

void sync_dir(char* dir1, char* dir2) {
    // Open directories
    DIR* d1 = opendir(dir1);
    DIR* d2 = opendir(dir2);
    if (d1 == NULL || d2 == NULL) {
        print_error("Could not open directory");
    }

    // Iterate over dir1 and sync files
    struct dirent* ent;
    while ((ent = readdir(d1)) != NULL) {
        // Ignore hidden files
        if (ent->d_name[0] == '.') {
            continue;
        }

        // File path
        char path1[MAX_PATH_LEN];
        snprintf(path1, MAX_PATH_LEN, "%s/%s", dir1, ent->d_name);
        char path2[MAX_PATH_LEN];
        snprintf(path2, MAX_PATH_LEN, "%s/%s", dir2, ent->d_name);

        // Check if file exists in dir2
        struct dirent* ent2;
        int exists = 0;
        while ((ent2 = readdir(d2)) != NULL) {
            if (strcmp(ent->d_name, ent2->d_name) == 0) {
                exists = 1;
                break;
            }
        }
        rewinddir(d2);

        if (exists) {
            // File exists in both directories, compare hash
            unsigned char md5_1[MD5_DIGEST_LEN];
            unsigned char md5_2[MD5_DIGEST_LEN];
            calc_file_md5(path1, md5_1);
            calc_file_md5(path2, md5_2);
            if (memcmp(md5_1, md5_2, MD5_DIGEST_LEN) != 0) {
                // Files differ, synchronize
                printf("Synchronizing %s\n", ent->d_name);
                FILE* file1 = fopen(path1, "rb");
                FILE* file2 = fopen(path2, "wb");
                if (file1 == NULL || file2 == NULL) {
                    print_error("Could not open file");
                }
                char buffer[1024];
                size_t nbytes;

                while ((nbytes = fread(buffer, 1, 1024, file1)) != 0) {
                    fwrite(buffer, 1, nbytes, file2);
                }

                fclose(file1);
                fclose(file2);
            }
        } else {
            // File only exists in dir1, copy over to dir2
            printf("Copying %s\n", ent->d_name);
            FILE* file1 = fopen(path1, "rb");
            FILE* file2 = fopen(path2, "wb");
            if (file1 == NULL || file2 == NULL) {
                print_error("Could not open file");
            }
            char buffer[1024];
            size_t nbytes;

            while ((nbytes = fread(buffer, 1, 1024, file1)) != 0) {
                fwrite(buffer, 1, nbytes, file2);
            }

            fclose(file1);
            fclose(file2);
        }
    }

    // Close directories
    closedir(d1);
    closedir(d2);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }

    sync_dir(argv[1], argv[2]);

    return 0;
}