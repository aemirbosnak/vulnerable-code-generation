//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 100
#define MAX_FILES 100

typedef struct {
    char source[MAX_PATH_LENGTH];
    char destination[MAX_PATH_LENGTH];
    int num_files;
    char files[MAX_FILES][MAX_PATH_LENGTH];
} sync_info;

void copy_file(char *from, char *to) {
    FILE *source = fopen(from, "rb");
    FILE *dest = fopen(to, "wb");
    if (!source || !dest) {
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(source, 0, SEEK_END);
    size_t file_size = ftell(source);
    rewind(source);

    char *buffer = (char*)malloc(file_size);

    fread(buffer, 1, file_size, source);
    fwrite(buffer, 1, file_size, dest);

    fclose(source);
    fclose(dest);
}

void *sync_thread(void *arg) {
    sync_info *si = (sync_info*)arg;

    for (int i = 0; i < si->num_files; i++) {
        char src[MAX_PATH_LENGTH];
        char dst[MAX_PATH_LENGTH];
        snprintf(src, sizeof(src), "%s/%s", si->source, si->files[i]);
        snprintf(dst, sizeof(dst), "%s/%s", si->destination, si->files[i]);
        copy_file(src, dst);
    }

    pthread_exit(NULL);
}

void synchronize(char *source, char *destination) {
    struct dirent *de;
    DIR *dr = opendir(source);
    sync_info si = { 0 };

    if (dr == NULL) {
        printf("Could not open directory: %s\n", source);
        exit(1);
    }

    si.num_files = 0;

    while ((de = readdir(dr)) != NULL && si.num_files < MAX_FILES) {
        if (de->d_name[0] == '.') continue;
        snprintf(si.files[si.num_files], sizeof(si.files[si.num_files]), "%s", de->d_name);
        si.num_files++;
    }

    closedir(dr);

    snprintf(si.source, sizeof(si.source), "%s", source);
    snprintf(si.destination, sizeof(si.destination), "%s", destination);

    pthread_t thread;
    pthread_create(&thread, NULL, sync_thread, (void*)&si);
    pthread_join(thread, NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(1);
    }

    synchronize(argv[1], argv[2]);

    printf("Synchronization complete!\n");

    return 0;
}