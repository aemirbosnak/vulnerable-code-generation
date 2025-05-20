//FormAI DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void backup_files(char *dir) {
    // Create backup directory
    char backup_dir[100];
    sprintf(backup_dir, "%s_backup", dir);
    mkdir(backup_dir, 0700);

    // Get list of files in directory
    DIR *d;
    struct dirent *dir_entry;
    d = opendir(dir);
    if (d) {
        while ((dir_entry = readdir(d)) != NULL) {
            // Skip over directories and system files
            if (dir_entry->d_type == DT_DIR) {
                continue;
            }
            if (dir_entry->d_name[0] == '.') {
                continue;
            }

            // Copy file to backup directory
            char src_path[200], dest_path[200];
            sprintf(src_path, "%s/%s", dir, dir_entry->d_name);
            sprintf(dest_path, "%s/%s", backup_dir, dir_entry->d_name);
            FILE *src_file = fopen(src_path, "r");
            FILE *dest_file = fopen(dest_path, "w");
            char buffer[1024];
            size_t read_size;
            while ((read_size = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, read_size, dest_file);
            }
            fclose(src_file);
            fclose(dest_file);
        }
        closedir(d);
    }

    printf("Backup of directory %s complete!\n", dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *dir = argv[1];
    backup_files(dir);

    return 0;
}