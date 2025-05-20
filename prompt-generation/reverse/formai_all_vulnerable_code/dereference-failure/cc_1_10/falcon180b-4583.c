//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_VIRUS_NAME_LENGTH 64
#define MAX_VIRUS_SIGNATURE_LENGTH 256
#define MAX_VIRUS_COUNT 100

struct virus {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURE_LENGTH];
};

struct virus virus_list[MAX_VIRUS_COUNT];
int virus_count = 0;

void load_virus_list() {
    FILE *fp;
    char filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_FILE_NAME_LENGTH];
    int i = 0;

    sprintf(filename, "virus_list.txt");
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: virus list file not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_FILE_NAME_LENGTH, fp)!= NULL) {
        strtok(line, ":");
        strcpy(virus_list[i].name, strtok(NULL, ":"));
        strcpy(virus_list[i].signature, strtok(NULL, ":"));
        i++;
    }

    fclose(fp);
    virus_count = i;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[1024];
    int file_size = 0;
    int i;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: file not found.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        for (i = 0; i < virus_count; i++) {
            if (strstr(buffer, virus_list[i].signature)!= NULL) {
                printf("Virus found: %s\n", virus_list[i].name);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

void scan_directory(char *dir_path) {
    DIR *dp;
    struct dirent *dir;

    dp = opendir(dir_path);

    if (dp == NULL) {
        printf("Error: directory not found.\n");
        return;
    }

    while ((dir = readdir(dp))!= NULL) {
        if (dir->d_type == DT_REG) {
            char file_path[MAX_FILE_NAME_LENGTH];

            sprintf(file_path, "%s/%s", dir_path, dir->d_name);
            scan_file(file_path);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    load_virus_list();

    if (argc < 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}