//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 1000
#define MAX_FILE_NAME_LENGTH 50

struct File {
    char name[MAX_FILE_NAME_LENGTH];
    time_t modified_time;
};

void add_file(struct File *files, int *num_files, char *filename) {
    strcpy(files[*num_files].name, filename);
    files[*num_files].modified_time = time(NULL);
    (*num_files)++;
}

int compare_files(const void *a, const void *b) {
    struct File *file_a = (struct File *)a;
    struct File *file_b = (struct File *)b;

    if (file_a->modified_time > file_b->modified_time) {
        return -1;
    } else if (file_a->modified_time < file_b->modified_time) {
        return 1;
    } else {
        return 0;
    }
}

void backup_files(struct File *files, int num_files, char *backup_path) {
    qsort(files, num_files, sizeof(struct File), compare_files);

    FILE *backup_file = fopen(backup_path, "w");

    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }

    for (int i = 0; i < num_files; i++) {
        fprintf(backup_file, "%s %ld\n", files[i].name, files[i].modified_time);
    }

    fclose(backup_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <backup_path> <file1> [<file2>...]\n", argv[0]);
        exit(1);
    }

    char backup_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_path, argv[1]);

    struct File files[MAX_FILES];
    int num_files = 0;

    add_file(files, &num_files, argv[2]);

    for (int i = 3; i < argc; i++) {
        add_file(files, &num_files, argv[i]);
    }

    backup_files(files, num_files, backup_path);

    printf("Backup completed successfully.\n");

    return 0;
}