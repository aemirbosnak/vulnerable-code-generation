//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 256

typedef struct file_info {
    char name[MAX_PATH];
    int size;
    time_t mtime;
    struct file_info* next;
} file_info;

void print_file_info(file_info* f) {
    printf("%s, size=%d, mtime=%ld\n", f->name, f->size, f->mtime);
}

int main() {
    DIR* dirp;
    struct dirent* dp;
    struct stat st;
    file_info* head = NULL;
    file_info* tail = NULL;
    file_info* current = NULL;

    if ((dirp = opendir(".")) == NULL) {
        perror("opendir");
        return 1;
    }

    while ((dp = readdir(dirp))!= NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue;

        if (stat(dp->d_name, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                char file_name[MAX_PATH];
                sprintf(file_name, "%s/%s", ".", dp->d_name);

                if ((current = (file_info*)malloc(sizeof(file_info))) == NULL) {
                    perror("malloc");
                    return 1;
                }
                strcpy(current->name, dp->d_name);
                current->size = st.st_size;
                current->mtime = st.st_mtime;
                current->next = NULL;

                if (head == NULL)
                    head = current;
                else
                    tail->next = current;

                tail = current;
            }
        }
    }
    closedir(dirp);

    if (head == NULL) {
        printf("No files found\n");
        return 0;
    }

    current = head;
    while (current!= NULL) {
        print_file_info(current);
        current = current->next;
    }

    return 0;
}