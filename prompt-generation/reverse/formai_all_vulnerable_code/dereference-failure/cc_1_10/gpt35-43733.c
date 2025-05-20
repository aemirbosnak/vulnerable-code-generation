//FormAI DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct fileList {
    char** files;
    int count;
};

void* synchronize(void* arg) {
    struct fileList* flist = (struct fileList*) arg;
    char* dest = flist->files[0];

    pthread_mutex_lock(&mutex);

    for (int i = 1; i < flist->count; i++) {
        char* src = flist->files[i];

        pid_t pid = fork();

        if (pid == 0) {
            execlp("cp", "cp", src, dest, NULL);
        } else if (pid > 0) {
            wait(NULL);
        } else {
            perror("fork");
            exit(1);
        }
    }

    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void traverseDirectory(const char* path, char* dest) {
    struct fileList* flist = malloc(sizeof(struct fileList));
    flist->files = malloc(MAX_FILES * sizeof(char*));
    flist->count = 0;

    DIR* dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* entry;
    struct stat info;

    while ((entry = readdir(dir)) != NULL) {
        char* filename = entry->d_name;
        char* filepath = malloc(strlen(path) + strlen(filename) + 2);
        sprintf(filepath, "%s/%s", path, filename);

        if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
            free(filepath);
            continue;
        }

        if (lstat(filepath, &info) < 0) {
            perror("lstat");
            free(filepath);
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            traverseDirectory(filepath, dest);
        } else if (S_ISREG(info.st_mode)) {
            flist->files[flist->count] = malloc(strlen(filepath) + 1);
            strcpy(flist->files[flist->count], filepath);
            flist->count++;
            if (flist->count == MAX_FILES) {
                printf("MAX_FILES reached. Aborting...\n");
                pthread_exit(NULL);
            }
        }

        free(filepath);
    }

    closedir(dir);

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, synchronize, (void*) flist);
    pthread_join(tid, NULL);

    free(flist->files);
    free(flist);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_dir destination_dir\n", argv[0]);
        exit(1);
    }

    char* source = argv[1];
    char* dest = argv[2];

    traverseDirectory(source, dest);

    return 0;
}