//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 1024

typedef struct {
    char *file_name;
    char *file_path;
} File;

void read_files(char *directory_path, char *source_file_name, char *destination_file_name) {
    DIR *dir;
    struct dirent *ent;
    FILE *fp_source, *fp_destination;
    char ch;
    int file_size = 0;

    dir = opendir(directory_path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                File file;
                strcpy(file.file_name, ent->d_name);
                strcpy(file.file_path, directory_path);
                strcat(file.file_path, "/");
                strcat(file.file_path, ent->d_name);

                fp_source = fopen(file.file_path, "r");

                if (fp_source!= NULL) {
                    while ((ch = fgetc(fp_source))!= EOF) {
                        file_size++;
                    }
                    fclose(fp_source);

                    fp_destination = fopen(destination_file_name, "a+");

                    if (fp_destination!= NULL) {
                        fprintf(fp_destination, "File Name: %s\nFile Size: %d bytes\n\n", file.file_name, file_size);
                        fclose(fp_destination);
                    }
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program <source_file_name> <destination_file_name> <directory_path>\n");
        exit(1);
    }

    char *source_file_name = argv[1];
    char *destination_file_name = argv[2];
    char *directory_path = argv[3];

    read_files(directory_path, source_file_name, destination_file_name);

    return 0;
}