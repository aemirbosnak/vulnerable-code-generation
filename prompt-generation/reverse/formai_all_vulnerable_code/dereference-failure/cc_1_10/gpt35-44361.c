//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <openssl/md5.h>

#define CHUNK_SIZE 1024
#define MAX_THREADS 4

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct file_data {
    char *filename;
    unsigned char hash[MD5_DIGEST_LENGTH];
} file_data;

void *scan_file(void *data) {
    file_data *file = (file_data *) data;

    unsigned char buf[CHUNK_SIZE];
    FILE *fp = fopen(file->filename, "rb");
    MD5_CTX mdContext;

    if (fp == NULL) {
        perror(file->filename);
        pthread_exit(NULL);
    }

    MD5_Init(&mdContext);

    int bytesRead = 0;
    while ((bytesRead = fread(buf, 1, CHUNK_SIZE, fp)) != 0) {
        MD5_Update(&mdContext, buf, bytesRead);
    }

    MD5_Final(file->hash, &mdContext);
    fclose(fp);

    return NULL;
}

void print_md5(unsigned char hash[]) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    char *scan_path = "/home/user/Desktop"; //scan folder path
    DIR *dir = opendir(scan_path);

    if (dir == NULL) {
        perror(scan_path);
        return 1;
    }

    file_data files[10000];
    int file_count = 0;

    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL && file_count < 10000) {
        if (dp->d_type == DT_REG) {
            char *fullpath = malloc(strlen(scan_path) + strlen(dp->d_name) + 2);
            sprintf(fullpath, "%s/%s", scan_path, dp->d_name);
            files[file_count].filename = fullpath;

            file_count++;
        }
    }
    closedir(dir);

    int num_threads = MAX_THREADS > file_count ? file_count : MAX_THREADS;
    pthread_t threads[num_threads];

    int chunk_size = file_count / num_threads;
    int start_index = 0;
    int end_index = chunk_size;

    for (int i = 0; i < num_threads; i++) {
        if (i == num_threads - 1) {
            end_index = file_count;
        }

        for (int j = start_index; j < end_index; j++) {
            pthread_create(&threads[i], NULL, scan_file, (void *) &files[j]);
        }

        start_index = end_index;
        end_index += chunk_size;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < file_count; i++) {
        printf("%s - ", files[i].filename);
        print_md5(files[i].hash);
        free(files[i].filename);
    }

    return 0;
}