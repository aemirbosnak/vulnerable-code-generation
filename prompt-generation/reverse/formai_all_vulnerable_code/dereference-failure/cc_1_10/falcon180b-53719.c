//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <ftw.h>

#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char source[MAX_FILE_NAME_LENGTH];
    char destination[MAX_FILE_NAME_LENGTH];
    int is_file;
} FileSyncData;

int sync_file(const char *path, const struct stat *sb, int typeflag, struct FTW *ftwbuf) {
    if (typeflag == FTW_F) {
        FileSyncData *data = (FileSyncData *) ftwbuf;
        char dest_file_path[MAX_FILE_NAME_LENGTH];
        sprintf(dest_file_path, "%s/%s", data->destination, data->source);
        if (sb->st_mode & S_IFREG) {
            if (sb->st_size!= 0) {
                FILE *src_file = fopen(path, "rb");
                FILE *dest_file = fopen(dest_file_path, "wb");
                if (src_file && dest_file) {
                    char buffer[1024];
                    int bytes_read;
                    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, sizeof(char), bytes_read, dest_file);
                    }
                    fclose(src_file);
                    fclose(dest_file);
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <source_directory> <destination_directory> <is_file>\n", argv[0]);
        exit(1);
    }
    char source_dir[MAX_FILE_NAME_LENGTH];
    char dest_dir[MAX_FILE_NAME_LENGTH];
    strcpy(source_dir, argv[1]);
    strcpy(dest_dir, argv[2]);
    FileSyncData data;
    strcpy(data.source, argv[3]);
    strcpy(data.destination, argv[4]);
    data.is_file = 1;
    nftw(source_dir, sync_file, 20, 0);
    return 0;
}