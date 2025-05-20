//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define BACKUP_DIR "/backup"
#define MAX_FILE_SIZE (10 * 1024 * 1024) // 10 MB

typedef struct {
    char *filename;
    time_t mtime;
    size_t size;
} FileInfo;

int compare_file_info(const void *a, const void *b) {
    const FileInfo *file_a = (const FileInfo *)a;
    const FileInfo *file_b = (const FileInfo *)b;

    if (file_a->mtime > file_b->mtime) {
        return -1;
    } else if (file_a->mtime < file_b->mtime) {
        return 1;
    } else {
        return 0;
    }
}

void backup_file(const char *src_file, const char *dest_file) {
    FILE *src_fp = fopen(src_file, "rb");
    FILE *dest_fp = fopen(dest_file, "wb");

    if (src_fp == NULL || dest_fp == NULL) {
        fprintf(stderr, "Error: failed to open file.\n");
        exit(1);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);
}

int main() {
    char src_file[1024];
    char dest_file[1024];

    snprintf(src_file, sizeof(src_file), "%s/%s", BACKUP_DIR, "file.txt");
    snprintf(dest_file, sizeof(dest_file), "%s/%s.%ld", BACKUP_DIR, "file", time(NULL));

    backup_file("file.txt", dest_file);

    return 0;
}