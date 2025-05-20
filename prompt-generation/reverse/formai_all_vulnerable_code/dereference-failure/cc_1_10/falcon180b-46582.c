//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 1000

typedef struct {
    char name[1024];
    time_t modified_time;
} file_t;

void backup_files(char *backup_dir, char *source_dir, int num_files) {
    DIR *dir;
    struct dirent *ent;
    char path[1024];
    file_t files[MAX_FILES];
    int i = 0;

    dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error: could not open directory '%s'\n", source_dir);
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (i >= num_files) {
            printf("Error: too many files to backup\n");
            exit(1);
        }

        strcpy(path, source_dir);
        strcat(path, "/");
        strcat(path, ent->d_name);

        struct stat st;
        if (stat(path, &st)!= 0) {
            printf("Error: could not stat file '%s'\n", path);
            exit(1);
        }

        strcpy(files[i].name, ent->d_name);
        files[i].modified_time = st.st_mtime;
        i++;
    }

    closedir(dir);

    for (int j = 0; j < i; j++) {
        char dest_path[1024];
        sprintf(dest_path, "%s/%s", backup_dir, files[j].name);

        FILE *src_file = fopen(source_dir, "rb");
        if (src_file == NULL) {
            printf("Error: could not open source file '%s'\n", source_dir);
            exit(1);
        }

        FILE *dest_file = fopen(dest_path, "wb");
        if (dest_file == NULL) {
            printf("Error: could not open destination file '%s'\n", dest_path);
            exit(1);
        }

        char buffer[BUFFER_SIZE];
        while (fread(buffer, 1, BUFFER_SIZE, src_file) > 0) {
            fwrite(buffer, 1, BUFFER_SIZE, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <backup_dir> <source_dir> <num_files>\n", argv[0]);
        exit(1);
    }

    backup_files(argv[1], argv[2], atoi(argv[3]));

    return 0;
}