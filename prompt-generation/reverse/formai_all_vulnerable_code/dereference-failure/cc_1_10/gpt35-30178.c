//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void backup_dir(char *src, char *dst) {
    struct dirent *dir;
    DIR *dirp;
    struct stat file_info;
    char src_path[2000], dst_path[2000];
    sprintf(src_path, "%s/", src);
    sprintf(dst_path, "%s/", dst);

    if ((dirp = opendir(src_path)) == NULL) {
        printf("Failed to open directory!\n");
        return;
    }

    while ((dir = readdir(dirp)) != NULL) {
        char *filename = dir->d_name;
        char src_file[2000], dst_file[2000];
        sprintf(src_file, "%s/%s", src_path, filename);
        sprintf(dst_file, "%s/%s", dst_path, filename);

        if (filename[0] == '.') continue; // Skip hidden files

        if (lstat(src_file, &file_info) == -1) {
            printf("Failed to get file info for %s\n", filename);
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            mkdir(dst_file, 0777);
            backup_dir(src_file, dst_file);
        } else {
            FILE *src_fp, *dst_fp;
            if ((src_fp = fopen(src_file, "rb")) == NULL) {
                printf("Failed to open %s for reading!\n", src_file);
                continue;
            }
            if ((dst_fp = fopen(dst_file, "wb")) == NULL) {
                printf("Failed to open %s for writing!\n", dst_file);
                continue;
            }

            char buffer[1024];
            int num_bytes_read = 0;
            while ((num_bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_fp)) > 0) {
                fwrite(buffer, sizeof(char), num_bytes_read, dst_fp);
            }

            fclose(src_fp);
            fclose(dst_fp);
        }
    }

    closedir(dirp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <backup_directory>\n", argv[0]);
        return -1;
    }

    backup_dir(argv[1], argv[2]);

    return 0;
}