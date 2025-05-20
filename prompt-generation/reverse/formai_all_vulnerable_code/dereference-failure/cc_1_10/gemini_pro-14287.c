//GEMINI-pro DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(void) {
    // Get the current working directory.
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    // Open the current working directory as a directory stream.
    DIR *dir = opendir(cwd);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Iterate over the files in the current working directory.
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Get the file's attributes.
        struct stat file_attrs;
        if (lstat(entry->d_name, &file_attrs) == -1) {
            perror("lstat");
            continue;
        }

        // Get the file's owner and group.
        struct passwd *owner = getpwuid(file_attrs.st_uid);
        struct group *group = getgrgid(file_attrs.st_gid);

        // Print the file's attributes.
        printf("%s %ld %s %s %ld %s\n", entry->d_name, file_attrs.st_ino,
               owner->pw_name, group->gr_name, file_attrs.st_size,
               ctime(&file_attrs.st_ctime));
    }

    // Close the directory stream.
    closedir(dir);

    return EXIT_SUCCESS;
}