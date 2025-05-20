//FormAI DATASET v1.0 Category: File Backup System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define MAX_BUF_SZ 4096
#define MAX_FILE_SZ 100

void backup_file(char* filename, char* source_path, char* dest_path) {

    char curr_time[MAX_BUF_SZ];
    time_t now = time(NULL);
    strftime(curr_time, sizeof(curr_time), "%Y-%m-%d_%H:%M:%S", localtime(&now));

    char source_file_path[MAX_BUF_SZ];
    char dest_file_path[MAX_BUF_SZ];
    sprintf(source_file_path, "%s%s", source_path, filename);
    sprintf(dest_file_path, "%s%s_%s", dest_path, filename, curr_time);

    FILE *source, *dest;
    source = fopen(source_file_path, "rb");
    if (source == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return;
    }

    dest = fopen(dest_file_path, "wb");
    if (dest == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        fclose(source);
        return;
    }

    size_t n; char buffer[MAX_BUF_SZ];
    while ((n = fread(buffer, 1, sizeof(buffer), source)) > 0)
        fwrite(buffer, 1, n, dest);

    if (ferror(source))
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));

    if (ferror(dest))
        fprintf(stderr, "Error writing file: %s\n", strerror(errno));

    fclose(source);
    fclose(dest);
}

void backup_dir(char* source_path, char* dest_path) {

    DIR* dirp = opendir(source_path);
    if (dirp == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", strerror(errno));
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) { // regular file
            int len = strlen(entry->d_name);
            if (entry->d_name[len-1] == '~') continue; // skip vim backup files
            if (len > MAX_FILE_SZ) continue; // skip files with too long names
            backup_file(entry->d_name, source_path, dest_path);
        }
    }

    closedir(dirp);
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: %s <source_path> <dest_path>\n", argv[0]);
        return 1;
    }

    char* source_path = argv[1];
    char* dest_path = argv[2];

    backup_dir(source_path, dest_path);

    return 0;
}