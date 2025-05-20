//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void sync_folder(const char *from_dir, const char *to_dir) {
    DIR *dir1 = opendir(from_dir);
    DIR *dir2 = opendir(to_dir);

    struct dirent *entry1 = NULL;
    struct dirent *entry2 = NULL;
    struct stat st1, st2;

    char path1[1024], path2[1024];

    while ((entry1 = readdir(dir1)) != NULL) {
        if (entry1->d_name[0] == '.') {
            continue; // ignore hidden files
        }
        snprintf(path1, sizeof(path1), "%s/%s", from_dir, entry1->d_name);
        snprintf(path2, sizeof(path2), "%s/%s", to_dir, entry1->d_name);

        lstat(path1, &st1);
        if (S_ISDIR(st1.st_mode)) {
            mkdir(path2, 0700); // create directory if not exists
            sync_folder(path1, path2); // synchronize subdirectories
        } else {
            lstat(path2, &st2);
            if (st1.st_mtime > st2.st_mtime) { // if modification time is greater, copy the file
                printf("%s -> %s\n", path1, path2);
                FILE *fp1 = fopen(path1, "r");
                FILE *fp2 = fopen(path2, "w");
                char c;
                while ((c = fgetc(fp1)) != EOF)
                    fputc(c, fp2);
                fclose(fp1);
                fclose(fp2);
            }
        }
    }
    closedir(dir1);
    closedir(dir2);
}

int main() {
    const char *from_dir = "/home/user/Documents";
    const char *to_dir = "/mnt/usb/Documents";
    printf("Synchronizing Folders...\n");
    sync_folder(from_dir, to_dir);
    printf("Synchronization Completed!\n");
    return 0;
}