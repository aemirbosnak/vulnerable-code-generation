//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void syncDirectory(char *dir1, char *dir2);

int main(int argc, char const *argv[])
{
    if (argc == 3)
    {
        char *dir1 = argv[1];
        char *dir2 = argv[2];

        syncDirectory(dir1, dir2);
    }
    else
    {
        printf("Usage: ./fileSync directory1 directory2\n");
    }

    return 0;
}

void syncDirectory(char *dir1, char *dir2)
{
    DIR *dp1, *dp2;
    struct dirent *entry1, *entry2;

    dp1 = opendir(dir1);

    if (dp1 == NULL)
    {
        printf("Failed to open %s directory\n", dir1);
        return;
    }

    while ((entry1 = readdir(dp1)) != NULL)
    {
        if (strcmp(entry1->d_name, ".") != 0 && strcmp(entry1->d_name, "..") != 0)
        {
            char path1[100];
            char path2[100];
            
            sprintf(path1, "%s/%s", dir1, entry1->d_name);
            sprintf(path2, "%s/%s", dir2, entry1->d_name);

            struct stat stat1, stat2;

            stat(path1, &stat1);

            if (access(path2, F_OK) == 0) // file exists in both directories
            {
                stat(path2, &stat2);
                
                if (stat1.st_mtime > stat2.st_mtime)
                {
                    // file in dir1 is newer, so copy it to dir2
                    FILE *fp1, *fp2;

                    fp1 = fopen(path1, "r");
                    fp2 = fopen(path2, "w");

                    char buf[1024];
                    size_t n;

                    while ((n = fread(buf, 1, sizeof buf, fp1)) > 0)
                        fwrite(buf, 1, n, fp2);

                    fclose(fp1);
                    fclose(fp2);

                    printf("%s synchronized\n", path2);
                }
                else if (stat1.st_mtime < stat2.st_mtime)
                {
                    // file in dir2 is newer, so copy it to dir1
                    FILE *fp1, *fp2;

                    fp1 = fopen(path2, "r");
                    fp2 = fopen(path1, "w");

                    char buf[1024];
                    size_t n;

                    while ((n = fread(buf, 1, sizeof buf, fp1)) > 0)
                        fwrite(buf, 1, n, fp2);

                    fclose(fp1);
                    fclose(fp2);

                    printf("%s synchronized\n", path1);
                }
            }
            else // file only exists in dir1
            {
                FILE *fp1, *fp2;

                fp1 = fopen(path1, "r");
                fp2 = fopen(path2, "w");

                char buf[1024];
                size_t n;

                while ((n = fread(buf, 1, sizeof buf, fp1)) > 0)
                    fwrite(buf, 1, n, fp2);

                fclose(fp1);
                fclose(fp2);

                printf("%s copied to %s\n", path1, path2);
            }
        }
    }

    closedir(dp1);

    dp2 = opendir(dir2);

    if (dp2 == NULL)
    {
        printf("Failed to open %s directory\n", dir2);
        return;
    }

    while ((entry2 = readdir(dp2)) != NULL)
    {
        if (strcmp(entry2->d_name, ".") != 0 && strcmp(entry2->d_name, "..") != 0)
        {
            char path1[100];
            char path2[100];

            sprintf(path1, "%s/%s", dir1, entry2->d_name);
            sprintf(path2, "%s/%s", dir2, entry2->d_name);

            if (access(path1, F_OK) != 0) // file only exists in dir2
            {
                FILE *fp1, *fp2;

                fp1 = fopen(path1, "w");
                fp2 = fopen(path2, "r");

                char buf[1024];
                size_t n;

                while ((n = fread(buf, 1, sizeof buf, fp2)) > 0)
                    fwrite(buf, 1, n, fp1);

                fclose(fp1);
                fclose(fp2);

                printf("%s copied to %s\n", path2, path1);
            }
        }
    }

    closedir(dp2);
}