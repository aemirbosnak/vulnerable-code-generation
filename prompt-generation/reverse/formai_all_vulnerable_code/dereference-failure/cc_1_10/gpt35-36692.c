//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

void backup(char source[], char dest[]) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char filename[256];
    sprintf(filename, "%s_backup_%d%02d%02d_%02d%02d%02d.tar.gz", source, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

    char command[512];
    sprintf(command, "tar -czvf %s %s", filename, source);
    system(command);

    char dest_filename[256];
    sprintf(dest_filename, "%s/%s", dest, filename);
    sprintf(command, "cp %s %s", filename, dest_filename);
    system(command);

    sprintf(command, "rm %s", filename);
    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source_dir] [dest_dir]\n", argv[0]);
        return 1;
    }

    DIR *source_dir = opendir(argv[1]);
    if (source_dir == NULL) {
        printf("Error: Failed to open source directory %s\n", argv[1]);
        return 1;
    }

    DIR *dest_dir = opendir(argv[2]);
    if (dest_dir == NULL) {
        printf("Error: Failed to open destination directory %s\n", argv[2]);
        return 1;
    }

    closedir(source_dir);
    closedir(dest_dir);

    backup(argv[1], argv[2]);

    return 0;
}