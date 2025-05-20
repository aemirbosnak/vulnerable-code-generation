//FormAI DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define BACKUP_FOLDER "backup"

void backup(char* filename);
void backup_dir(char* dir);

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: backup FILE/DIR [...]\n");
        return 1;
    }

    // create backup folder if it doesn't exist
    mkdir(BACKUP_FOLDER, 0777);

    for (int i = 1; i < argc; i++) {
        char* path = argv[i];
        struct stat st;

        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            backup_dir(path);
        } else {
            backup(path);
        }
    }

    return 0;
}

void backup(char* filename) {
    char backup_filename[256];

    // generate backup filename with timestamp
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    strftime(backup_filename, 256, "%Y%m%d%H%M%S_", tm);
    strcat(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // open source and destination files
    FILE* src_file = fopen(filename, "rb");
    FILE* dst_file = fopen(backup_filename, "wb");

    if (src_file == NULL || dst_file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // copy contents of source file to destination file
    unsigned char buffer[1024];
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, n, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    printf("Backed up %s to %s\n", filename, backup_filename);
}

void backup_dir(char* dir) {
    DIR* dp = opendir(dir);

    if (dp == NULL) {
        printf("Error: Unable to open directory %s\n", dir);
        return;
    }

    struct dirent* ep;
    char path[256];

    while ((ep = readdir(dp)) != NULL) {
        // ignore . and .. directories
        if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0) {
            continue;
        }

        // create full path
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, ep->d_name);

        struct stat st;

        if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
            // backup sub-directory recursively
            backup_dir(path);
        } else {
            // backup file
            backup(path);
        }
    }

    closedir(dp);
}