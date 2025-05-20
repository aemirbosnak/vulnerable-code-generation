//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <pthread.h>

#define MAX_THREADS 10
#define QUEUE_SIZE 500

typedef struct {
    char path[1024];
    unsigned long long size;
} file_info_t;

typedef struct {
    file_info_t *files;
    int num_files;
} thread_data_t;

void *analyze_disk_space(void *data) {
    thread_data_t *thread_data = (thread_data_t *) data;
    file_info_t *files = thread_data->files;
    int num_files = thread_data->num_files;

    for (int i = 0; i < num_files; i++) {
        struct statvfs buf;
        if (statvfs(files[i].path, &buf) == 0) {
            files[i].size = (unsigned long long) buf.f_blocks * buf.f_frsize;
        } else {
            files[i].size = 0;
        }
    }

    return NULL;
}

int main() {
    char root_path[1024];
    if (getcwd(root_path, sizeof(root_path))!= NULL) {
        printf("Analyzing disk space for %s\n", root_path);
    } else {
        printf("Error: failed to get current working directory\n");
        return 1;
    }

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(root_path))!= NULL) {
        int num_files = 0;
        file_info_t *files = malloc(sizeof(file_info_t) * MAX_THREADS);

        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                if (num_files >= MAX_THREADS) {
                    printf("Warning: maximum number of threads reached\n");
                    break;
                }

                char path[1024];
                snprintf(path, sizeof(path), "%s/%s", root_path, ent->d_name);
                files[num_files].path[0] = '\0';
                strncat(files[num_files].path, path, sizeof(files[num_files].path) - 1);
                num_files++;
            }
        }

        closedir(dir);

        pthread_t threads[MAX_THREADS];
        thread_data_t thread_data[MAX_THREADS];

        for (int i = 0; i < num_files; i++) {
            thread_data[i].files = files;
            thread_data[i].num_files = 1;
            if (pthread_create(&threads[i], NULL, analyze_disk_space, (void *) &thread_data[i])!= 0) {
                printf("Error: failed to create thread\n");
                return 1;
            }
        }

        for (int i = 0; i < num_files; i++) {
            if (pthread_join(threads[i], NULL)!= 0) {
                printf("Error: failed to join thread\n");
                return 1;
            }
        }

        free(files);
    } else {
        printf("Error: failed to open directory\n");
        return 1;
    }

    return 0;
}