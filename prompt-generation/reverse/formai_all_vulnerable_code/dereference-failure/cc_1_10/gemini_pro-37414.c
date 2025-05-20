//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    char *path;
    int fd;
    off_t size;
} file_info;

typedef struct {
    file_info *files;
    int num_files;
    pthread_mutex_t lock;
    pthread_cond_t cv;
} file_synchronizer;

void file_synchronizer_init(file_synchronizer *fs, int num_files) {
    fs->files = malloc(sizeof(file_info) * num_files);
    fs->num_files = num_files;
    pthread_mutex_init(&fs->lock, NULL);
    pthread_cond_init(&fs->cv, NULL);
}

void file_synchronizer_destroy(file_synchronizer *fs) {
    free(fs->files);
    pthread_mutex_destroy(&fs->lock);
    pthread_cond_destroy(&fs->cv);
}

int file_synchronizer_add_file(file_synchronizer *fs, char *path) {
    int fd;

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    pthread_mutex_lock(&fs->lock);
    fs->files[fs->num_files].path = strdup(path);
    fs->files[fs->num_files].fd = fd;
    fs->files[fs->num_files].size = lseek(fd, 0, SEEK_END);
    fs->num_files++;
    pthread_mutex_unlock(&fs->lock);

    return 0;
}

void file_synchronizer_remove_file(file_synchronizer *fs, char *path) {
    int i;

    pthread_mutex_lock(&fs->lock);
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].path, path) == 0) {
            close(fs->files[i].fd);
            free(fs->files[i].path);
            fs->num_files--;
            memmove(&fs->files[i], &fs->files[i + 1], sizeof(file_info) * (fs->num_files - i));
            break;
        }
    }
    pthread_mutex_unlock(&fs->lock);
}

void file_synchronizer_wait_for_all(file_synchronizer *fs) {
    pthread_mutex_lock(&fs->lock);
    while (fs->num_files > 0) {
        pthread_cond_wait(&fs->cv, &fs->lock);
    }
    pthread_mutex_unlock(&fs->lock);
}

void file_synchronizer_signal_one(file_synchronizer *fs) {
    pthread_mutex_lock(&fs->lock);
    pthread_cond_signal(&fs->cv);
    pthread_mutex_unlock(&fs->lock);
}

void *file_synchronizer_thread(void *arg) {
    file_synchronizer *fs = (file_synchronizer *)arg;
    int i;

    while (1) {
        file_info *file;

        pthread_mutex_lock(&fs->lock);
        if (fs->num_files == 0) {
            pthread_mutex_unlock(&fs->lock);
            break;
        }
        file = &fs->files[0];
        pthread_mutex_unlock(&fs->lock);

        // Do something with the file
        printf("File: %s, Size: %ld\n", file->path, file->size);

        pthread_mutex_lock(&fs->lock);
        file_synchronizer_remove_file(fs, file->path);
        file_synchronizer_signal_one(fs);
        pthread_mutex_unlock(&fs->lock);
    }

    return NULL;
}

int main(int argc, char **argv) {
    file_synchronizer fs;
    pthread_t tid;
    int i;

    file_synchronizer_init(&fs, argc - 1);
    for (i = 1; i < argc; i++) {
        file_synchronizer_add_file(&fs, argv[i]);
    }

    pthread_create(&tid, NULL, file_synchronizer_thread, &fs);

    file_synchronizer_wait_for_all(&fs);

    pthread_join(tid, NULL);

    file_synchronizer_destroy(&fs);

    return 0;
}