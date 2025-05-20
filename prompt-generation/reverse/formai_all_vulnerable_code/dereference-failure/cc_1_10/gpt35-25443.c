//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function for synchronizing files
void sync_files(char* src_path, char* tgt_path) {
    DIR* src_dir = opendir(src_path);
    DIR* tgt_dir = opendir(tgt_path);

    // check if directories exist
    if (src_dir == NULL || tgt_dir == NULL) {
        printf("Could not open directory!\n");
        return;
    }

    struct dirent* sd;
    struct dirent* td;
    struct stat src_st;
    struct stat tgt_st;

    while ((sd = readdir(src_dir)) != NULL) {
        char src_file[255];
        char tgt_file[255];
        sprintf(src_file, "%s/%s", src_path, sd->d_name);

        if (stat(src_file, &src_st) == -1) {
            printf("Error reading source file stats!\n");
            return;
        }

        // check if file is a directory or a regular file
        if (S_ISDIR(src_st.st_mode)) {
            // recursively synchronize directories
            if (strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0) {
                sprintf(tgt_file, "%s/%s", tgt_path, sd->d_name);
                if (stat(tgt_file, &tgt_st) != -1 && S_ISDIR(tgt_st.st_mode)) {
                    sync_files(src_file, tgt_file);
                } else {
                    mkdir(tgt_file, 0777);
                    sync_files(src_file, tgt_file);
                }
            }
        } else {
            td = readdir(tgt_dir);
            while (td != NULL) {
                sprintf(tgt_file, "%s/%s", tgt_path, td->d_name);
                if (stat(tgt_file, &tgt_st) != -1 && !S_ISDIR(tgt_st.st_mode)) {
                    if (strcmp(sd->d_name, td->d_name) == 0) {
                        // check if files are the same
                        if (src_st.st_mtime > tgt_st.st_mtime) {
                            printf("Synchronizing %s to %s\n", src_file, tgt_file);
                            FILE* src = fopen(src_file, "rb");
                            FILE* tgt = fopen(tgt_file, "wb");
                            char c;
                            while ((c = fgetc(src)) != EOF) {
                                fputc(c, tgt);
                            }
                            fclose(src);
                            fclose(tgt);
                        }
                    }
                }
                td = readdir(tgt_dir);
            }

            // if file does not exist in target directory
            sprintf(tgt_file, "%s/%s", tgt_path, sd->d_name);
            if (stat(tgt_file, &tgt_st) == -1) {
                printf("Copying %s to %s\n", src_file, tgt_file);
                FILE* src = fopen(src_file, "rb");
                FILE* tgt = fopen(tgt_file, "wb");
                char c;
                while ((c = fgetc(src)) != EOF) {
                    fputc(c, tgt);
                }
                fclose(src);
                fclose(tgt);
            }
        }

        rewinddir(tgt_dir);
    }

    closedir(src_dir);
    closedir(tgt_dir);
}

int main() {
    char src_path[255] = "/home/user/Documents";
    char tgt_path[255] = "/media/usb/Documents";

    printf("Synchronizing files from %s to %s\n", src_path, tgt_path);
    sync_files(src_path, tgt_path);

    return 0;
}