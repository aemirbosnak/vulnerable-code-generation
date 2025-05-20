//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;
    FILE *fp;
    char line[MAX_LINE];
    char *filename = "process_list.txt";
    char *mode = "r+";
    int count = 0;

    if (argc!= 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(1);
    }

    if ((dir = opendir(argv[1])) == NULL) {
        printf("Cannot open directory %s\n", argv[1]);
        exit(1);
    }

    if ((fp = fopen(filename, mode)) == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            if (count == 0) {
                fprintf(fp, "Process ID\tProcess Name\n");
            }
            snprintf(line, MAX_LINE, "%d\t%s\n", ent->d_ino, ent->d_name);
            fputs(line, fp);
            count++;
        }
    }

    fclose(fp);
    closedir(dir);

    printf("Process list saved to %s\n", filename);

    return 0;
}