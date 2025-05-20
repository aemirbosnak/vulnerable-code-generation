//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_THREADS 10

struct file_data {
    char filename[100];
    int filesize;
    int thread_id;
};

void *extract_metadata(void *arg) {
    struct file_data *data = (struct file_data *) arg;
    FILE *fp;
    char buffer[1024];

    fp = fopen(data->filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", data->filename);
        exit(1);
    }

    while (fgets(buffer, 1024, fp)!= NULL) {
        // Extract metadata from the file and store it in a data structure
        // For example, you can extract the file creation date, author, title, etc.
    }

    fclose(fp);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    struct file_data files[MAX_FILES];
    int num_files = 0;
    int i, j;

    for (i = 1; i < argc; i++) {
        strcpy(files[num_files].filename, argv[i]);
        files[num_files].filesize = 0;
        files[num_files].thread_id = -1;
        num_files++;
    }

    for (i = 0; i < num_files; i++) {
        for (j = 0; j < MAX_THREADS; j++) {
            if (files[i].thread_id == -1) {
                files[i].thread_id = j;
                pthread_create(&threads[j], NULL, extract_metadata, (void *) &files[i]);
                break;
            }
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}