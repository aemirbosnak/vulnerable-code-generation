//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>

void print_dir(char *dir)
{
    DIR *d = opendir(dir);
    struct dirent *e;

    if (d == NULL)
        return;

    printf("%s:\n", dir);
    printf("--------------------\n");
    while ((e = readdir(d)) != NULL)
    {
        if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, ".."))
            continue;

        char *path = malloc(strlen(dir) + strlen(e->d_name) + 2);
        sprintf(path, "%s/%s", dir, e->d_name);

        struct stat s;
        if (lstat(path, &s) == -1)
        {
            free(path);
            continue;
        }

        char *perms = malloc(11);
        perms[0] = '-';

        if (s.st_mode & S_IRUSR)
            perms[1] = 'r';
        else
            perms[1] = '-';

        if (s.st_mode & S_IWUSR)
            perms[2] = 'w';
        else
            perms[2] = '-';

        if (s.st_mode & S_IXUSR)
            perms[3] = 'x';
        else
            perms[3] = '-';

        if (s.st_mode & S_IRGRP)
            perms[4] = 'r';
        else
            perms[4] = '-';

        if (s.st_mode & S_IWGRP)
            perms[5] = 'w';
        else
            perms[5] = '-';

        if (s.st_mode & S_IXGRP)
            perms[6] = 'x';
        else
            perms[6] = '-';

        if (s.st_mode & S_IROTH)
            perms[7] = 'r';
        else
            perms[7] = '-';

        if (s.st_mode & S_IWOTH)
            perms[8] = 'w';
        else
            perms[8] = '-';

        if (s.st_mode & S_IXOTH)
            perms[9] = 'x';
        else
            perms[9] = '-';

        perms[10] = '\0';

        struct passwd *pw = getpwuid(s.st_uid);
        struct group *gr = getgrgid(s.st_gid);

        char *time_str = malloc(26);
        strftime(time_str, 26, "%d %b %Y %H:%M", gmtime(&s.st_mtime));

        printf("  %s %d %s %s %ld %s %s\n", perms, s.st_nlink, pw->pw_name, gr->gr_name, s.st_size, time_str, e->d_name);

        free(path);
        free(perms);
        free(time_str);
    }

    closedir(d);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    print_dir(argv[1]);

    return 0;
}