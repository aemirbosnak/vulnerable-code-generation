//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

typedef struct {
    char *src_path;
    char *dest_path;
} SyncPair;

void sync_files(SyncPair *pairs, int num_pairs) {
    for (int i = 0; i < num_pairs; i++) {
        char src_buf[BUF_SIZE];
        char dest_buf[BUF_SIZE];
        FILE *src_file = fopen(pairs[i].src_path, "rb");
        FILE *dest_file = fopen(pairs[i].dest_path, "wb");

        if (src_file == NULL || dest_file == NULL) {
            printf("Error: Failed to open file(s)\n");
            exit(1);
        }

        while (fread(src_buf, 1, BUF_SIZE, src_file) > 0) {
            fwrite(src_buf, 1, BUF_SIZE, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }

    char src_dir[1024];
    char dest_dir[1024];
    strcpy(src_dir, argv[1]);
    strcpy(dest_dir, argv[2]);

    DIR *src_dir_ptr = opendir(src_dir);
    if (src_dir_ptr == NULL) {
        printf("Error: Failed to open source directory\n");
        return 1;
    }

    int num_pairs = 0;
    SyncPair pairs[100];

    struct dirent *src_dirent;
    while ((src_dirent = readdir(src_dir_ptr))!= NULL) {
        char path[1024];
        sprintf(path, "%s/%s", src_dir, src_dirent->d_name);

        struct stat src_stat;
        if (stat(path, &src_stat)!= 0) {
            printf("Error: Failed to stat source file\n");
            closedir(src_dir_ptr);
            return 1;
        }

        if (src_stat.st_mode & S_IFDIR) {
            continue;
        }

        char dest_path[1024];
        sprintf(dest_path, "%s/%s", dest_dir, src_dirent->d_name);

        if (mkdir(dest_path, 0777)!= 0 && errno!= EEXIST) {
            printf("Error: Failed to create destination directory\n");
            closedir(src_dir_ptr);
            return 1;
        }

        pairs[num_pairs].src_path = path;
        pairs[num_pairs].dest_path = dest_path;
        num_pairs++;

        if (num_pairs >= 100) {
            break;
        }
    }

    closedir(src_dir_ptr);

    sync_files(pairs, num_pairs);

    return 0;
}