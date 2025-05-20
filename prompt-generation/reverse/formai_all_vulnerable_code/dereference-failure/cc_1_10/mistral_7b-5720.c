//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

struct file_info {
    char name[256];
    off_t size;
    char type[10];
};

int main(void) {
    DIR *dir;
    struct dirent *entry;
    struct file_info files[1024];
    int num_files = 0;

    puts("Welcome, dear user, to the madness of the Disk Space Analyzer 3000!");

    if ((dir = opendir(".")) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (num_files >= 1024) {
                printf("Error: Too many files in this directory!\n");
                goto exit;
            }

            strcpy(files[num_files].name, entry->d_name);

            if (entry->d_type == DT_REG) {
                struct stat info;
                stat(entry->d_name, &info);

                files[num_files].size = info.st_size;

                int i;
                for (i = strlen(entry->d_name) - 1; i >= 0; i--) {
                    if (entry->d_name[i] == '.') {
                        strcpy(files[num_files].type, &entry->d_name[i]);
                        break;
                    }
                }
            }

            num_files++;
        }

        closedir(dir);
    } else {
        perror("Error: ");
        goto exit;
    }

    printf("\n-----------------------------------------------------------\n");
    printf("|                  File Type | Size in bytes |   File Name |\n");
    printf("-----------------------------------------------------------\n");

    int i;
    for (i = 0; i < num_files; i++) {
        printf("|%-14s|%-17llu|%s|\n", files[i].type, files[i].size, files[i].name);
    }

    printf("\n-----------------------------------------------------------\n");
    puts("And now, my dear user, you have the pleasure of knowing what's filling up your precious C: drive!");

exit:
    return 0;
}