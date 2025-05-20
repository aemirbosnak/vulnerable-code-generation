//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define NUM_THREADS 4

typedef struct {
    char *filename;
    FILE *file;
    int filesize;
} file_t;

void *scan_file(void *arg) {
    file_t *file = (file_t *) arg;
    unsigned char buffer[4096];
    int match_count = 0;

    fseek(file->file, 0, SEEK_SET);
    while (fread(buffer, 1, sizeof(buffer), file->file) > 0) {
        for (int i = 0; i < sizeof(buffer) - 4; i++) {
            if (memcmp(buffer + i, "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*", 44) == 0) {
                match_count++;
                break;
            }
        }
    }

    if (match_count > 0) {
        printf("Virus found in %s\n", file->filename);
    }

    fclose(file->file);
    free(file);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    file_t files[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        files[i].filename = (char *) malloc(1024);
        files[i].file = fopen("test.txt", "rb");
        files[i].filesize = fseek(files[i].file, 0, SEEK_END);

        if (files[i].filesize > MAX_FILE_SIZE) {
            fclose(files[i].file);
            free(files[i].filename);
            continue;
        }

        pthread_create(&threads[i], NULL, scan_file, (void *) &files[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}