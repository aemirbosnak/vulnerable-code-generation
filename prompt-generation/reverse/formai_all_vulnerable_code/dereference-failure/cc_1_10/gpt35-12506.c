//FormAI DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

// function to check if directory or file exists
int exists(const char *path)
{
    return access(path, F_OK) == 0;
}

// synchronize two directories recursively
void syncDirs(char *dir1, char *dir2)
{
    DIR *dp1, *dp2;
    struct dirent *dir_entry;
    struct stat stat_buf1, stat_buf2;
    char path1[200], path2[200];

    dp1 = opendir(dir1);
    if (!dp1)
    {
        printf("cannot open directory %s\n", dir1);
        exit(1);
    }

    dp2 = opendir(dir2);
    if (!dp2)
    {
        printf("cannot open directory %s\n", dir2);
        exit(1);
    }

    while ((dir_entry = readdir(dp1)) != NULL)
    {
        sprintf(path1, "%s/%s", dir1, dir_entry->d_name);
        if (dir_entry->d_name[0] != '.')
        {
            if (stat(path1, &stat_buf1) == -1)
            {
                printf("error - could not stat %s\n", path1);
                continue;
            }

            sprintf(path2, "%s/%s", dir2, dir_entry->d_name);

            if (stat(path2, &stat_buf2) == -1)
            {
                if (errno != ENOENT)
                {
                    printf("error - could not stat %s\n", path2);
                }
                else
                {
                    printf("creating new file %s\n", path2);
                    FILE *f = fopen(path2, "w");
                    fclose(f);
                }
            }
            else
            {
                if (S_ISDIR(stat_buf1.st_mode))
                {
                    if (!S_ISDIR(stat_buf2.st_mode))
                    {
                        printf("error - %s is a directory but %s is not\n", path1, path2);
                        continue;
                    }

                    syncDirs(path1, path2);
                }
                else
                {
                    if (!S_ISREG(stat_buf1.st_mode))
                    {
                        printf("error - %s is not a regular file\n", path1);
                        continue;
                    }

                    if (!S_ISREG(stat_buf2.st_mode))
                    {
                        printf("removing %s (not a regular file)\n", path2);
                        unlink(path2);
                        printf("creating new file %s\n", path2);
                        FILE *f = fopen(path2, "w");
                        fclose(f);
                    }
                    else
                    {
                        if (stat_buf1.st_size != stat_buf2.st_size)
                        {
                            printf("overwriting %s with %s (file size mismatch)\n", path2, path1);
                            remove(path2);
                            if (exists(path2))
                            {
                                printf("could not remove %s\n", path2);
                                continue;
                            }
                            if (link(path1, path2) == -1)
                            {
                                printf("could not link %s to %s\n", path1, path2);
                            }
                        }
                        else
                        {
                            char buffer1[BUFSIZ], buffer2[BUFSIZ];
                            FILE *f1 = fopen(path1, "r");
                            FILE *f2 = fopen(path2, "r");
                            while (fgets(buffer1, BUFSIZ, f1) != NULL && fgets(buffer2, BUFSIZ, f2) != NULL)
                            {
                                if (strcmp(buffer1, buffer2) != 0)
                                {
                                    printf("overwriting %s with %s (content mismatch)\n", path2, path1);
                                    remove(path2);
                                    if (exists(path2))
                                    {
                                        printf("could not remove %s\n", path2);
                                        break;
                                    }
                                    if (link(path1, path2) == -1)
                                    {
                                        printf("could not link %s to %s\n", path1, path2);
                                    }
                                    break;
                                }
                            }
                            fclose(f1);
                            fclose(f2);
                        }
                    }
                }
            }
        }
    }

    while ((dir_entry = readdir(dp2)) != NULL)
    {
        sprintf(path2, "%s/%s", dir2, dir_entry->d_name);
        if (dir_entry->d_name[0] != '.' && stat(path2, &stat_buf2) == -1)
        {
            sprintf(path1, "%s/%s", dir1, dir_entry->d_name);
            if (stat(path1, &stat_buf1) == -1)
            {
                printf("could not stat %s\n", path1);
            }
            else
            {
                if (S_ISDIR(stat_buf1.st_mode))
                {
                    printf("creating new directory %s\n", path2);
                    mkdir(path2, 0777);
                    syncDirs(path1, path2);
                }
                else if (S_ISREG(stat_buf1.st_mode))
                {
                    printf("creating new file %s\n", path2);
                    FILE *f = fopen(path2, "w");
                    fclose(f);
                }
                else
                {
                    printf("error - %s is not a directory or a regular file\n", path1);
                }
            }
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }

    syncDirs(argv[1], argv[2]);

    return 0;
}