//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    int is_updated;
} file_info;

file_info files[MAX_FILES];
int num_files = 0;

void *monitor_thread(void *arg) {
    while (1) {
        for (int i = 0; i < num_files; i++) {
            if (files[i].is_updated) {
                printf("File %s has been updated.\n", files[i].filename);
                files[i].is_updated = 0;
            }
        }
        sleep(1);
    }
    return NULL;
}

void add_file(char *filename) {
    if (num_files >= MAX_FILES) {
        printf("Cannot add more files.\n");
        return;
    }
    strcpy(files[num_files].filename, filename);
    files[num_files++].is_updated = 0;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_thread, NULL);

    while (1) {
        printf("Enter filename to add: ");
        scanf("%s", files[num_files-1].filename);
        add_file(files[num_files-1].filename);
    }

    return 0;
}