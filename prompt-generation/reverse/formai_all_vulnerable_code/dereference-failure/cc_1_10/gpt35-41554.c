//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

/* Struct to hold file information */
typedef struct {
    char *filename; /* name of the file */
    char *path; /* location on disk */
    time_t modified; /* last modified time */
    size_t size; /* size of file in bytes */
} file_t;

/* Function to get file information */
void get_file_info(char *filename, file_t *file) {
    struct stat info;

    /* Get file information */
    stat(filename, &info);

    /* Fill in file struct */
    file->filename = filename;
    file->path = realpath(filename, NULL);
    file->modified = info.st_mtime;
    file->size = info.st_size;
}

int main(int argc, char **argv) {
    char *source_dir, *backup_dir;
    int max_backups;
    DIR *dir;
    struct dirent *ent;
    time_t cur_time;
    file_t *files;
    int num_files = 0;
    int i, j;
    char date_str[20];
    char time_str[20];

    /* Check arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: backup <source_dir> <backup_dir> <max_backups>\n");
        exit(EXIT_FAILURE);
    }

    /* Parse arguments */
    source_dir = argv[1];
    backup_dir = argv[2];
    max_backups = atoi(argv[3]);

    /* Open source directory */
    dir = opendir(source_dir);

    if (dir == NULL) {
        fprintf(stderr, "Error: Failed to open directory %s\n", source_dir);
        exit(EXIT_FAILURE);
    }

    /* Count number of files */
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            num_files++;
        }
    }

    /* Allocate memory for files */
    files = (file_t*)malloc(num_files * sizeof(file_t));

    /* Reset directory pointer */
    rewinddir(dir);

    /* Fill in file information */
    i = 0;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            get_file_info(ent->d_name, &files[i]);
            i++;
        }
    }

    /* Close directory */
    closedir(dir);

    /* Sort files by date modified */
    for (i = 0; i < num_files; i++) {
        for (j = 0; j < num_files - 1; j++) {
            if (files[j].modified < files[j+1].modified) {
                file_t temp = files[j];
                files[j] = files[j+1];
                files[j+1] = temp;
            }
        }
    }

    /* Rename oldest backup */
    cur_time = time(NULL);
    strftime(date_str, sizeof(date_str), "%Y%m%d", localtime(&cur_time));
    strftime(time_str, sizeof(time_str), "%H%M%S", localtime(&cur_time));

    char old_filename[256];
    snprintf(old_filename, sizeof(old_filename), "%s/%s_%s_%s.tar.gz", backup_dir, source_dir, files[num_files-1].filename, date_str);
    char new_filename[256];
    snprintf(new_filename, sizeof(new_filename), "%s/%s_%s_%s.tar.gz", backup_dir, source_dir, date_str, time_str);
    printf("Renaming %s to %s...\n", old_filename, new_filename);
    rename(old_filename, new_filename);

    /* Create new backup */
    char tar_cmd[512];
    snprintf(tar_cmd, sizeof(tar_cmd), "tar -czf %s/%s_%s_%s.tar.gz %s", backup_dir, source_dir, files[0].filename, date_str, source_dir);
    printf("Creating backup: %s\n", tar_cmd);
    system(tar_cmd);

    /* Check if max backups exceeded */
    if (num_files + 1 > max_backups) {
        /* Delete oldest backup */
        char rm_cmd[256];
        snprintf(rm_cmd, sizeof(rm_cmd), "rm %s/%s_%s_%s.tar.gz", backup_dir, source_dir, files[num_files-1].filename, date_str);
        printf("Deleting backup: %s\n", rm_cmd);
        system(rm_cmd);
    }

    /* Free memory */
    for (i = 0; i < num_files; i++) {
        free(files[i].path);
    }
    free(files);

    return 0;
}