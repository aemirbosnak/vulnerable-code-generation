//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 1024

typedef struct {
    char name[MAX_PATH];
    long size;
} File;

void add_file(File *files, int count, const char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                snprintf(files[count].name, MAX_PATH, "%s/%s", path, ent->d_name);
                files[count].size = 0;
                if (ent->d_type == DT_DIR) {
                    add_file(files, count + 1, files[count].name);
                } else {
                    FILE *fp;
                    fp = fopen(files[count].name, "rb");
                    if (fp!= NULL) {
                        fseek(fp, 0, SEEK_END);
                        files[count].size = ftell(fp);
                        fclose(fp);
                    }
                }
                count++;
            }
        }
        closedir(dir);
    }
}

void print_files(File *files, int count) {
    for (int i = 0; i < count; i++) {
        printf("%-40s %10ld\n", files[i].name, files[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    File files[1000];
    int count = 0;

    add_file(files, count, argv[1]);

    printf("Directory: %s\n", argv[1]);
    printf("Total files: %d\n", count);
    printf("Name\t\tSize\n");
    print_files(files, count);

    return 0;
}