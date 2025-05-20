//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int sync_files(char *source_path, char *dest_path) {
    DIR *source_dir, *dest_dir;
    struct dirent *ent;
    char source_file[BUF_SIZE], dest_file[BUF_SIZE];
    FILE *fp_src, *fp_dest;

    source_dir = opendir(source_path);
    if (source_dir == NULL) {
        printf("Error opening source directory: %s\n", strerror(errno));
        return 1;
    }

    dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        printf("Error opening destination directory: %s\n", strerror(errno));
        closedir(source_dir);
        return 1;
    }

    while ((ent = readdir(source_dir))!= NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        strcpy(source_file, source_path);
        strcat(source_file, "/");
        strcat(source_file, ent->d_name);

        strcpy(dest_file, dest_path);
        strcat(dest_file, "/");
        strcat(dest_file, ent->d_name);

        fp_src = fopen(source_file, "r");
        if (fp_src == NULL) {
            printf("Error opening source file: %s\n", strerror(errno));
            closedir(source_dir);
            closedir(dest_dir);
            return 1;
        }

        fp_dest = fopen(dest_file, "w");
        if (fp_dest == NULL) {
            printf("Error opening destination file: %s\n", strerror(errno));
            fclose(fp_src);
            closedir(source_dir);
            closedir(dest_dir);
            return 1;
        }

        while (fgets(source_file, BUF_SIZE, fp_src)!= NULL) {
            fputs(source_file, fp_dest);
        }

        fclose(fp_src);
        fclose(fp_dest);
    }

    closedir(source_dir);
    closedir(dest_dir);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}