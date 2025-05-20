//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define DEFAULT_BACKUP_DIR "/backup"
#define MAX_FILE_PATH_LEN 1024

typedef struct backup_file {
    char *path;
    time_t timestamp;
} backup_file;

int compare_backup_files(const void *a, const void *b) {
    const backup_file *file1 = (const backup_file *)a;
    const backup_file *file2 = (const backup_file *)b;

    return (int)(file1->timestamp - file2->timestamp);
}

int main(int argc, char *argv[]) {
    char *source_dir;
    char *backup_dir;
    DIR *src_dir;
    struct dirent *src_file;
    struct stat src_stat;
    backup_file *backup_files;
    int num_backup_files;
    int i;

    // Parse command line arguments.
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    source_dir = argv[1];

    // Get the backup directory.
    backup_dir = getenv("BACKUP_DIR");
    if (backup_dir == NULL) {
        backup_dir = DEFAULT_BACKUP_DIR;
    }

    // Open the source directory.
    src_dir = opendir(source_dir);
    if (src_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Get the number of files in the source directory.
    num_backup_files = 0;
    while ((src_file = readdir(src_dir)) != NULL) {
        if (strcmp(src_file->d_name, ".") == 0 || strcmp(src_file->d_name, "..") == 0) {
            continue;
        }

        num_backup_files++;
    }

    // Allocate memory for the backup files.
    backup_files = (backup_file *)malloc(sizeof(backup_file) * num_backup_files);
    if (backup_files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Rewind the directory stream.
    rewinddir(src_dir);

    // Get the files in the source directory.
    i = 0;
    while ((src_file = readdir(src_dir)) != NULL) {
        if (strcmp(src_file->d_name, ".") == 0 || strcmp(src_file->d_name, "..") == 0) {
            continue;
        }

        // Get the file's path.
        snprintf(backup_files[i].path, MAX_FILE_PATH_LEN, "%s/%s", source_dir, src_file->d_name);

        // Get the file's timestamp.
        stat(backup_files[i].path, &src_stat);
        backup_files[i].timestamp = src_stat.st_mtime;

        i++;
    }

    // Close the source directory.
    closedir(src_dir);

    // Sort the backup files by timestamp.
    qsort(backup_files, num_backup_files, sizeof(backup_file), compare_backup_files);

    // Delete old backup files.
    for (i = 0; i < num_backup_files - 10; i++) {
        remove(backup_files[i].path);
    }

    // Free the memory for the backup files.
    free(backup_files);

    return EXIT_SUCCESS;
}