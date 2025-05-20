//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_FILE_SIZE (1024 * 1024 * 5) // 5 MB

struct file_info {
    char *filename;
    int filesize;
};

int is_infected(const char *filename) {
    FILE *fp;
    char buffer[1024];
    int len;
    const char *virus_signature = "This file is infected with a virus!";

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    while ((len = fread(buffer, 1, 1024, fp)) > 0) {
        buffer[len] = '\0';
        if (strstr(buffer, virus_signature)) {
            printf("File %s is infected with a virus!\n", filename);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void scan_directory(const char *path) {
    DIR *dp;
    struct dirent *dirp;
    dp = opendir(path);
    if (dp == NULL) {
        printf("Error opening directory %s\n", path);
        return;
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_REG) {
            char filename[1024];
            snprintf(filename, 1024, "%s/%s", path, dirp->d_name);
            if (is_infected(filename)) {
                printf("Infected file found: %s\n", filename);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}