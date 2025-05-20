//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define BACKUP_DIR "backup"

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <backup_directory>\n", argv[0]);
        return 1;
    }

    char *backup_dir = argv[1];

    if (mkdir(backup_dir, 0755) < 0) {
        perror("Failed to create backup directory");
        return 1;
    }

    DIR *dir = opendir(".");
    struct dirent *entry;

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_name[0] == '.')
            continue;

        char file_name[1024];
        strcpy(file_name, "./");
        strcat(file_name, entry->d_name);

        char backup_file_name[1024];
        strcpy(backup_file_name, backup_dir);
        strcat(backup_file_name, "/");
        strcat(backup_file_name, entry->d_name);

        FILE *src_file = fopen(file_name, "r");
        FILE *dst_file = fopen(backup_file_name, "w");

        if (!src_file ||!dst_file) {
            printf("Failed to open files %s and %s\n", file_name, backup_file_name);
            continue;
        }

        char buffer[4096];
        while (fread(buffer, 1, sizeof(buffer), src_file)) {
            fwrite(buffer, 1, sizeof(buffer), dst_file);
        }

        fclose(src_file);
        fclose(dst_file);
    }

    closedir(dir);

    return 0;
}