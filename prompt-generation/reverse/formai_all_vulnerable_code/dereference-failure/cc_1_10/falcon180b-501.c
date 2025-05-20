//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_DIR_SIZE 100
#define MAX_FILE_SIZE 100

typedef struct {
    char dir[MAX_DIR_SIZE];
    char file[MAX_FILE_SIZE];
    time_t timestamp;
} BackupFile;

void backup_file(char* source_file, char* dest_file) {
    FILE* source = fopen(source_file, "rb");
    FILE* dest = fopen(dest_file, "wb");

    if (!source ||!dest) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(source);
    fclose(dest);
}

int compare_timestamps(const void* a, const void* b) {
    const BackupFile* file1 = (const BackupFile*)a;
    const BackupFile* file2 = (const BackupFile*)b;

    return difftime(file2->timestamp, file1->timestamp);
}

void backup_directory(char* source_dir, char* dest_dir) {
    DIR* dir = opendir(source_dir);

    if (!dir) {
        printf("Error opening directory.\n");
        exit(1);
    }

    struct dirent* ent;
    BackupFile files[100];
    int num_files = 0;

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG || ent->d_type == DT_LNK) {
            BackupFile file;
            strcpy(file.dir, source_dir);
            strcat(file.dir, "/");
            strcat(file.dir, ent->d_name);

            strcpy(file.file, ent->d_name);
            struct stat st;
            stat(file.dir, &st);
            file.timestamp = st.st_mtime;

            files[num_files++] = file;
        }
    }

    closedir(dir);

    qsort(files, num_files, sizeof(BackupFile), compare_timestamps);

    for (int i = 0; i < num_files; i++) {
        char dest_file[MAX_FILE_SIZE];
        sprintf(dest_file, "%s/%s", dest_dir, files[i].file);

        char dest_dir_path[MAX_DIR_SIZE];
        strcpy(dest_dir_path, dest_dir);
        strcat(dest_dir_path, "/");

        if (mkdir(dest_dir_path, 0755)!= 0) {
            printf("Error creating directory.\n");
            exit(1);
        }

        backup_file(files[i].dir, dest_file);
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage:./backup source_dir dest_dir\n");
        exit(1);
    }

    backup_directory(argv[1], argv[2]);

    printf("Backup complete!\n");

    return 0;
}