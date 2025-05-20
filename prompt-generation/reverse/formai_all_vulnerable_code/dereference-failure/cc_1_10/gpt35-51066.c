//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_SIZE 1024

int check_file(char *filename) {
    FILE *fp;
    int ch, count = 0;
    fp = fopen(filename, "r");
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == 'v' || ch == 'i' || ch == 'r' || ch == 'u' || ch == 's')
            count++;
    }
    fclose(fp);
    if (count >= 5)
        return 1;
    else
        return 0;
}

int search_files(char *path) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;
    char file_path[MAX_SIZE];
    dir = opendir(path);
    if (dir != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                sprintf(file_path, "%s/%s", path, ent->d_name);
                if (check_file(file_path)) {
                    printf("Found virus: %s\n", file_path);
                    count++;
                }
            }
            else if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                sprintf(file_path, "%s/%s", path, ent->d_name);
                count += search_files(file_path);
            }
        }
        closedir(dir);
    }
    else {
        perror("Could not open directory");
        return -1;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./scan [directory path]\n");
        return -1;
    }
    char *path = argv[1];
    printf("Scanning directory %s...\n", path);
    int count = search_files(path);
    if (count > 0)
        printf("Found %d viruses!\n", count);
    else
        printf("No viruses found!\n");
    return 0;
}