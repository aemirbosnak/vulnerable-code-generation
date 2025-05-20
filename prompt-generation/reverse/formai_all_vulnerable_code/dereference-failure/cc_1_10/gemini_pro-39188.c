//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_THREADS 4
#define SIGNATURE_SIZE 16

typedef struct {
    char *buffer;
    size_t size;
    int fd;
    bool infected;
} file_info;

typedef struct {
    file_info *files;
    size_t num_files;
    sem_t sem;
} thread_data;

static char *signatures[] = {
    "4D5A90000300000004000000FFFF0000B8000000000000004000000000000000",
    "4D5A90000300000004000000FFFF0000B8000000000000004000000000000000",
    "4D5A90000300000004000000FFFF0000B8000000000000004000000000000000",
    "4D5A90000300000004000000FFFF0000B8000000000000004000000000000000",
    "4D5A90000300000004000000FFFF0000B8000000000000004000000000000000"
};

static const size_t num_signatures = sizeof(signatures) / sizeof(signatures[0]);

static void *scan_file(void *arg) {
    thread_data *data = (thread_data *)arg;
    for (size_t i = 0; i < data->num_files; i++) {
        file_info *file = &data->files[i];
        for (size_t j = 0; j < num_signatures; j++) {
            if (memcmp(file->buffer, signatures[j], SIGNATURE_SIZE) == 0) {
                file->infected = true;
                break;
            }
        }
        sem_post(&data->sem);
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <files>\n", argv[0]);
        return 1;
    }

    size_t num_files = argc - 1;
    file_info *files = malloc(sizeof(file_info) * num_files);
    if (!files) {
        perror("malloc");
        return 1;
    }

    for (size_t i = 0; i < num_files; i++) {
        files[i].fd = open(argv[i + 1], O_RDONLY);
        if (files[i].fd == -1) {
            perror("open");
            return 1;
        }

        struct stat st;
        if (fstat(files[i].fd, &st) == -1) {
            perror("fstat");
            return 1;
        }

        files[i].size = st.st_size;
        files[i].buffer = mmap(NULL, files[i].size, PROT_READ, MAP_PRIVATE, files[i].fd, 0);
        if (files[i].buffer == MAP_FAILED) {
            perror("mmap");
            return 1;
        }
    }

    thread_data data;
    data.files = files;
    data.num_files = num_files;
    sem_init(&data.sem, 0, 0);

    pthread_t threads[MAX_THREADS];
    for (size_t i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, scan_file, &data) != 0) {
            perror("pthread_create");
            return 1;
        }
    }

    for (size_t i = 0; i < num_files; i++) {
        sem_wait(&data.sem);
        if (files[i].infected) {
            printf("%s is infected\n", argv[i + 1]);
        } else {
            printf("%s is clean\n", argv[i + 1]);
        }
    }

    for (size_t i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&data.sem);

    for (size_t i = 0; i < num_files; i++) {
        munmap(files[i].buffer, files[i].size);
        close(files[i].fd);
    }

    free(files);

    return 0;
}