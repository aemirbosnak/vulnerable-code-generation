//FormAI DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char *source_file, const char *destination_file) {
    FILE *source, *destination;
    char ch;

    source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Unable to open file %s\n", source_file);
        return;
    }

    destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Unable to create file %s\n", destination_file);
        fclose(source);
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File synchronized: %s\n", destination_file);

    fclose(source);
    fclose(destination);
}

void copy_directory(const char *source_directory, const char *destination_directory) {
    DIR *dir;
    struct dirent *entry;
    struct stat stat_data_source, stat_data_destination;
    char source_file[1024], destination_file[1024];
    char source_directory_name[1024], destination_directory_name[1024];

    dir = opendir(source_directory);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", source_directory);
        return;
    }

    mkdir(destination_directory, 0777);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;

        sprintf(source_file, "%s/%s", source_directory, entry->d_name);
        sprintf(destination_file, "%s/%s", destination_directory, entry->d_name);

        stat(source_file, &stat_data_source);
        stat(destination_file, &stat_data_destination);

        if (S_ISDIR(stat_data_source.st_mode)) {
            copy_directory(source_file, destination_file);
        } else if (S_ISREG(stat_data_source.st_mode)) {
            if (stat_data_source.st_mtime > stat_data_destination.st_mtime) {
                copy_file(source_file, destination_file);
            }
        }
    }

    printf("Directory synchronized: %s\n", destination_directory);

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    copy_directory(argv[1], argv[2]);

    return 0;
}