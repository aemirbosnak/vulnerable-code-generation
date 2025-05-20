//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(0);
    }

    DIR *dir1, *dir2;
    struct dirent *dp;

    dir1 = opendir(argv[1]);
    dir2 = opendir(argv[2]);

    if (!dir1 || !dir2) {
        printf("Error opening directories.\n");
        exit(1);
    }

    struct stat statbuf1, statbuf2;

    while ((dp = readdir(dir1)) != NULL) {
        char filename[256];
        sprintf(filename, "%s/%s", argv[1], dp->d_name);

        stat(filename, &statbuf1);

        if (S_ISREG(statbuf1.st_mode)) {
            char filename2[256];
            sprintf(filename2, "%s/%s", argv[2], dp->d_name);

            if (stat(filename2, &statbuf2) == -1) {
                printf("%s does not exist in %s\n", dp->d_name, argv[2]);
                continue;
            }

            if (statbuf1.st_size != statbuf2.st_size) {
                printf("%s is different in size between %s and %s\n", dp->d_name, argv[1], argv[2]);
                continue;
            }

            FILE *f1 = fopen(filename, "r");
            FILE *f2 = fopen(filename2, "r");

            char buf1[1024], buf2[1024];

            while (fgets(buf1, sizeof(buf1), f1) != NULL) {
                if (fgets(buf2, sizeof(buf2), f2) == NULL || strcmp(buf1, buf2) != 0) {
                    printf("%s is different in content between %s and %s\n", dp->d_name, argv[1], argv[2]);
                    break;
                }
            }

            fclose(f1);
            fclose(f2);
        }
    }

    closedir(dir1);
    closedir(dir2);

    return 0;
}