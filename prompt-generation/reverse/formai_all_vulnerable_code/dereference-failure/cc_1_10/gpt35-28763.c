//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_THREAD 5 // maximum number of threads that can run simultaneously

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // to lock threads while using shared variables
pthread_cond_t done = PTHREAD_COND_INITIALIZER; // to signal when threads have finished execution

typedef struct {
    char path[MAX_PATH];
    long long size;
} file_info;

typedef struct {
    int num_files;
    file_info *files;
} thread_args;

void* analyze_directory(void *arg) {
    thread_args *args = (thread_args*) arg;
    file_info *files = args->files;
    int num_files = args->num_files;

    for (int i = 0; i < num_files; i++) {
        struct stat st;
        if (stat(files[i].path, &st) < 0) {
            perror(files[i].path);
            continue;
        }

        if (S_ISREG(st.st_mode)) { // regular file
            files[i].size = st.st_size;
        } else if (S_ISDIR(st.st_mode)) { // directory
            DIR *dir = opendir(files[i].path);
            if (dir == NULL) {
                perror(files[i].path);
                continue;
            }

            int count = 0;
            file_info *new_files = NULL;
            char path[MAX_PATH];
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                    continue;

                snprintf(path, MAX_PATH, "%s/%s", files[i].path, entry->d_name);

                if (count == 0) {
                    new_files = (file_info*) malloc(sizeof(file_info));
                } else {
                    new_files = (file_info*) realloc(new_files, (count + 1) * sizeof(file_info));
                }

                if (new_files == NULL) {
                    fprintf(stderr, "Out of memory.\n");
                    break;
                }

                strcpy(new_files[count].path, path);
                new_files[count].size = 0;
                count++;
            }

            closedir(dir);

            if (count > 0) {
                thread_args *new_args = (thread_args*) malloc(sizeof(thread_args));
                new_args->num_files = count;
                new_args->files = new_files;

                pthread_mutex_lock(&mutex);
                while (count >= num_files - i) {
                    pthread_cond_wait(&done, &mutex);
                }
                pthread_mutex_unlock(&mutex);

                pthread_t tid;
                pthread_create(&tid, NULL, analyze_directory, new_args);
            }
        }
    }

    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&done);
    pthread_mutex_unlock(&mutex);

    free(arg);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    file_info initial_file = { .path = argv[1], .size = 0 };
    thread_args *args = (thread_args*) malloc(sizeof(thread_args));
    args->num_files = 1;
    args->files = &initial_file;

    pthread_t tid;
    pthread_create(&tid, NULL, analyze_directory, args);

    pthread_join(tid, NULL);

    long long total_size = 0;
    for (int i = 0; i < args->num_files; i++) {
        total_size += args->files[i].size;
    }
    printf("Total size of %d files: %lld bytes\n", args->num_files, total_size);

    return 0;
}