//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    struct dirent *de;
    DIR *dir;
    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Failed to open source directory\n");
        return 1;
    }

    struct dirent *dest_de;
    DIR *dest_dir;
    dest_dir = opendir(argv[2]);
    if (dest_dir == NULL) {
        printf("Failed to open destination directory\n");
        return 1;
    }

    while ((de = readdir(dir))!= NULL) {
        char source_path[256];
        char dest_path[256];
        strcpy(source_path, argv[1]);
        strcat(source_path, "/");
        strcat(source_path, de->d_name);

        strcpy(dest_path, argv[2]);
        strcat(dest_path, "/");
        strcat(dest_path, de->d_name);

        FILE *source_file = fopen(source_path, "r");
        FILE *dest_file = fopen(dest_path, "w");
        if (source_file!= NULL && dest_file!= NULL) {
            fseek(source_file, 0, SEEK_END);
            long source_size = ftell(source_file);
            fseek(source_file, 0, SEEK_SET);

            fseek(dest_file, 0, SEEK_END);
            long dest_size = ftell(dest_file);
            fseek(dest_file, 0, SEEK_SET);

            if (dest_size > source_size) {
                printf("Destination file '%s' is larger than source file '%s'\n", dest_path, source_path);
                fclose(source_file);
                fclose(dest_file);
                continue;
            }

            fseek(dest_file, 0, SEEK_SET);
            if (fwrite(fread(source_file, 1, source_size, source_file), 1, source_size, dest_file)!= source_size) {
                printf("Failed to write to destination file '%s'\n", dest_path);
                fclose(source_file);
                fclose(dest_file);
                continue;
            }

            fclose(source_file);
            fclose(dest_file);
        } else {
            printf("Failed to open source or destination file '%s'\n", source_path);
            continue;
        }

        printf("Synced %s to %s\n", source_path, dest_path);
    }

    closedir(dir);
    closedir(dest_dir);

    return 0;
}