//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define MAX_ENTRY_COUNT 100
#define MAX_ENTRY_SIZE 1024
#define MAX_FILE_SIZE 1024

#define DIRECTORY_ENTRY 1
#define FILE_ENTRY 2
#define LINK_ENTRY 3

struct direntry {
    char name[MAX_ENTRY_SIZE];
    int type;
    long size;
    struct direntry* next;
};

struct direntry* head = NULL;

void add_directory(char* path) {
    DIR* dir = opendir(path);
    if(dir == NULL) {
        return;
    }

    struct dirent* dir_entry;
    while((dir_entry = readdir(dir))!= NULL) {
        char entry_path[MAX_BUF_SIZE];
        snprintf(entry_path, MAX_BUF_SIZE, "%s/%s", path, dir_entry->d_name);

        struct stat stat_buf;
        stat(entry_path, &stat_buf);

        if(S_ISDIR(stat_buf.st_mode)) {
            add_directory(entry_path);
        } else if(S_ISREG(stat_buf.st_mode)) {
            struct direntry* entry = (struct direntry*) malloc(sizeof(struct direntry));
            strncpy(entry->name, dir_entry->d_name, MAX_ENTRY_SIZE);
            entry->type = FILE_ENTRY;
            entry->size = stat_buf.st_size;
            entry->next = head;
            head = entry;

            if(head->next!= NULL) {
                struct direntry* current = head;
                while(current->next!= NULL) {
                    current = current->next;
                }
                current->next = NULL;
            }
        }
    }

    closedir(dir);
}

int main() {
    srand(time(NULL));

    add_directory("/");

    struct direntry* current = head;
    while(current!= NULL) {
        printf("%s (%ld bytes)\n", current->name, current->size);
        current = current->next;
    }

    return 0;
}