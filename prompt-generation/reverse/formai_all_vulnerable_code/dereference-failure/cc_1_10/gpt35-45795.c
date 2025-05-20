//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(char *path1, char *path2);

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: %s <path1> <path2>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    printf("Files synchronized successfully!\n");

    return 0;
}


void sync_files(char *path1, char *path2) {
    struct dirent *dp1, *dp2;
    DIR *dir1, *dir2;
    struct stat st1, st2;

    /* Open input and output directories */
    dir1 = opendir(path1);
    dir2 = opendir(path2);

    /* Error handling */
    if(!dir2) {
        mkdir(path2, 0755);
        dir2 = opendir(path2);
    }

    /* Sync files from path1 to path2 */
    while((dp1 = readdir(dir1)) != NULL) {
        char *file1, *file2;
        size_t len1, len2;

        /* Ignore files beginning with '.' */
        if(dp1->d_name[0] == '.') continue;

        /* Create full paths for file in path1 and path2 */
        len1 = strlen(path1) + strlen(dp1->d_name) + 2;
        len2 = strlen(path2) + strlen(dp1->d_name) + 2;

        file1 = malloc(len1);
        file2 = malloc(len2);

        snprintf(file1, len1, "%s/%s", path1, dp1->d_name);
        snprintf(file2, len2, "%s/%s", path2, dp1->d_name);

        /* Get metadata for files in both paths */
        stat(file1, &st1);
        stat(file2, &st2);

        /* If file doesn't exist in path2, copy it over */
        if(!S_ISREG(st2.st_mode)) {
            FILE *in, *out;
            int ch;

            in = fopen(file1, "rb");
            out = fopen(file2, "wb");

            while((ch = fgetc(in)) != EOF) {
                fputc(ch, out);
            }

            fclose(in);
            fclose(out);
        } else {
            /* If file already exists in path2, check modification times */
            if(st1.st_mtime > st2.st_mtime) {
                FILE *in, *out;
                int ch;

                in = fopen(file1, "rb");
                out = fopen(file2, "wb");

                while((ch = fgetc(in)) != EOF) {
                    fputc(ch, out);
                }

                fclose(in);
                fclose(out);
            }
        }

        free(file1);
        free(file2);
    }

    /* Sync files from path2 to path1 */
    while((dp2 = readdir(dir2)) != NULL) {
        char *file1, *file2;
        size_t len1, len2;

        /* Ignore files beginning with '.' */
        if(dp2->d_name[0] == '.') continue;

        /* Create full paths for file in path1 and path2 */
        len1 = strlen(path1) + strlen(dp2->d_name) + 2;
        len2 = strlen(path2) + strlen(dp2->d_name) + 2;

        file1 = malloc(len1);
        file2 = malloc(len2);

        snprintf(file1, len1, "%s/%s", path1, dp2->d_name);
        snprintf(file2, len2, "%s/%s", path2, dp2->d_name);

        /* Get metadata for files in both paths */
        stat(file1, &st1);
        stat(file2, &st2);

        /* If file doesn't exist in path1, copy it over */
        if(!S_ISREG(st1.st_mode)) {
            FILE *in, *out;
            int ch;

            in = fopen(file2, "rb");
            out = fopen(file1, "wb");

            while((ch = fgetc(in)) != EOF) {
                fputc(ch, out);
            }

            fclose(in);
            fclose(out);
        }

        free(file1);
        free(file2);
    }

    closedir(dir1);
    closedir(dir2);
}