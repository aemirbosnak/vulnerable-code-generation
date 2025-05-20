//FormAI DATASET v1.0 Category: File Backup System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_SIZE 1048576 // 1MB

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    size_t size;
    char *data;
} File;

typedef struct {
    size_t count;
    File *files;
} Backup;

File *read_file(char *filename) {
    File *file = malloc(sizeof(File));
    strncpy(file->filename, filename, MAX_FILENAME_LENGTH);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("error opening file %s\n", filename);
        free(file);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    file->size = ftell(fp);
    rewind(fp);

    if (file->size > MAX_FILE_SIZE) {
        printf("file %s is too large\n", filename);
        free(file);
        fclose(fp);
        return NULL;
    }

    file->data = malloc(file->size);
    fread(file->data, file->size, 1, fp);

    fclose(fp);
    return file;
}

void write_file(char *filename, File *file) {
    FILE *fp = fopen(filename, "wb");
    fwrite(file->data, file->size, 1, fp);
    fclose(fp);
}

void backup_add_file(Backup *backup, File *file) {
    backup->count++;
    backup->files = realloc(backup->files, backup->count * sizeof(File));
    backup->files[backup->count - 1] = *file;
}

void backup_create(char *backup_dir, char *files[], int file_count) {
    Backup backup = {0};

    for (int i = 0; i < file_count; i++) {
        File *file = read_file(files[i]);
        if (file) {
            backup_add_file(&backup, file);
        }
    }

    char backup_filename[MAX_FILENAME_LENGTH];
    snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s/backup.bin", backup_dir);

    FILE *fp = fopen(backup_filename, "wb");
    if (!fp) {
        printf("error opening backup file %s\n", backup_filename);
        for (int i = 0; i < backup.count; i++) {
            free(backup.files[i].data);
        }
        free(backup.files);
        return;
    }

    fwrite(&backup.count, sizeof(size_t), 1, fp);
    for (int i = 0; i < backup.count; i++) {
        fwrite(&backup.files[i].filename, sizeof(char), MAX_FILENAME_LENGTH, fp);
        fwrite(&backup.files[i].size, sizeof(size_t), 1, fp);
        fwrite(backup.files[i].data, sizeof(char), backup.files[i].size, fp);
    }

    fclose(fp);

    for (int i = 0; i < backup.count; i++) {
        free(backup.files[i].data);
    }
    free(backup.files);

    printf("backup created successfully\n");
}

void backup_restore(char *backup_filename, char *output_dir) {
    FILE *fp = fopen(backup_filename, "rb");
    if (!fp) {
        printf("error opening backup file %s\n", backup_filename);
        return;
    }

    size_t count;
    fread(&count, sizeof(size_t), 1, fp);

    Backup backup = {0};
    backup.count = count;
    backup.files = malloc(count * sizeof(File));

    for (int i = 0; i < count; i++) {
        File file = {0};
        fread(&file.filename, sizeof(char), MAX_FILENAME_LENGTH, fp);
        fread(&file.size, sizeof(size_t), 1, fp);
        file.data = malloc(file.size);
        fread(file.data, sizeof(char), file.size, fp);
        backup.files[i] = file;
    }

    fclose(fp);

    for (int i = 0; i < backup.count; i++) {
        char output_filename[MAX_FILENAME_LENGTH];
        snprintf(output_filename, MAX_FILENAME_LENGTH, "%s/%s", output_dir, backup.files[i].filename);
        write_file(output_filename, &backup.files[i]);
    }

    for (int i = 0; i < backup.count; i++) {
        free(backup.files[i].data);
    }
    free(backup.files);

    printf("backup restored successfully\n");
}

int main() {
    char *files[] = {"file1.txt", "file2.txt", "file3.txt"};
    int file_count = 3;
    char *backup_dir = "backup";
    char *output_dir = "restored";

    backup_create(backup_dir, files, file_count);
    backup_restore("backup/backup.bin", output_dir);
    return 0;
}