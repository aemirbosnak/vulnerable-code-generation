//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 512
#define MAX_FILENAME_SIZE 256

typedef struct {
    char name[MAX_FILENAME_SIZE];
    off_t size;
    mode_t mode;
} FileInfo;

int get_file_list(const char *dir_path, FileInfo **file_list, int *list_size)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return errno;
    }

    struct dirent *entry;
    FileInfo *file_info;
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            num_files++;
        }
    }

    *file_list = (FileInfo*)malloc(sizeof(FileInfo) * num_files);
    file_info = *file_list;
    memset(file_info, 0, sizeof(FileInfo) * num_files);
    *list_size = num_files;

    rewinddir(dir);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG || entry->d_type == DT_LNK) {
            snprintf(file_info->name, MAX_FILENAME_SIZE, "%s/%s", dir_path, entry->d_name);
            struct stat st_buf;
            if (lstat(file_info->name, &st_buf) != 0) {
                fprintf(stderr, "Error getting stat for %s: %s\n", file_info->name, strerror(errno));
            }
            file_info->size = st_buf.st_size;
            file_info->mode = st_buf.st_mode;
            file_info++;
        }
    }

    closedir(dir);

    return 0;
}

char* read_file(const char* file_path) 
{
    FILE *fp = fopen(file_path, "r");
    char *buffer;
    size_t buffer_size = 0;

    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    buffer_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*)malloc(buffer_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(fp);
        return NULL;
    }

    memset(buffer, 0, buffer_size + 1);
    if (fread(buffer, 1, buffer_size, fp) != buffer_size) {
        perror("Error reading file");
        free(buffer);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return buffer;
}

void* extract_metadata(void* file_path_ptr)
{
    char* file_path = (char*)file_path_ptr;
    char* file_contents = read_file(file_path);
    if (file_contents == NULL) {
        return NULL;
    }

    char* metadata = strstr(file_contents, "METADATA=");
    if (metadata != NULL) {
        metadata += strlen("METADATA=");
        printf("%s: %s\n", file_path, metadata);
    }

    free(file_contents);
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return -1;
    }

    FileInfo *file_list;
    int list_size;

    if (get_file_list(argv[1], &file_list, &list_size) != 0) {
        perror("Error getting file list");
        return -1;
    }

    pthread_t threads[list_size];
    int i, rc;
    for (i = 0; i < list_size; i++) {
        rc = pthread_create(&threads[i], NULL, extract_metadata, (void*)file_list[i].name);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread for %s: %s\n", file_list[i].name, strerror(rc));
        }
    }

    for (i = 0; i < list_size; i++) {
        pthread_join(threads[i], NULL);
    }

    free(file_list);
    return 0;
}