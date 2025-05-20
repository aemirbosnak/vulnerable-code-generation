//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

// Maximum number of threads
#define MAX_THREADS 10

// Structure to store file information
typedef struct file_info {
    char *path;
    char *name;
    size_t size;
    time_t mtime;
} file_info;

// Queue to store file information
typedef struct file_queue {
    file_info *files;
    int count;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} file_queue;

// Create a new file queue
file_queue *file_queue_create() {
    file_queue *queue = malloc(sizeof(file_queue));
    queue->files = NULL;
    queue->count = 0;
    pthread_mutex_init(&queue->lock, NULL);
    pthread_cond_init(&queue->cond, NULL);
    return queue;
}

// Destroy a file queue
void file_queue_destroy(file_queue *queue) {
    if (queue->files != NULL) {
        for (int i = 0; i < queue->count; i++) {
            free(queue->files[i].path);
            free(queue->files[i].name);
        }
        free(queue->files);
    }
    pthread_mutex_destroy(&queue->lock);
    pthread_cond_destroy(&queue->cond);
    free(queue);
}

// Push a file into the queue
void file_queue_push(file_queue *queue, file_info file) {
    pthread_mutex_lock(&queue->lock);
    queue->files = realloc(queue->files, (queue->count + 1) * sizeof(file_info));
    queue->files[queue->count] = file;
    queue->count++;
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->lock);
}

// Pop a file from the queue
file_info file_queue_pop(file_queue *queue) {
    pthread_mutex_lock(&queue->lock);
    while (queue->count == 0) {
        pthread_cond_wait(&queue->cond, &queue->lock);
    }
    file_info file = queue->files[queue->count - 1];
    queue->count--;
    pthread_mutex_unlock(&queue->lock);
    return file;
}

// Scan a directory for files and add them to the queue
void scan_directory(const char *path, file_queue *queue) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char *filepath = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(filepath, "%s/%s", path, entry->d_name);
        struct stat statbuf;
        if (stat(filepath, &statbuf) == -1) {
            perror("stat");
            free(filepath);
            continue;
        }
        file_info file;
        file.path = filepath;
        file.name = entry->d_name;
        file.size = statbuf.st_size;
        file.mtime = statbuf.st_mtime;
        file_queue_push(queue, file);
    }
    closedir(dir);
}

// Copy a file to the backup directory
void copy_file(const char *path, const char *backup_path) {
    FILE *src = fopen(path, "rb");
    if (src == NULL) {
        perror("fopen");
        return;
    }
    FILE *dest = fopen(backup_path, "wb");
    if (dest == NULL) {
        perror("fopen");
        fclose(src);
        return;
    }
    char buffer[4096];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }
    fclose(src);
    fclose(dest);
}

// Backup a file
void backup_file(file_info file) {
    char *backup_path = malloc(strlen(file.path) + strlen(".backup") + 1);
    sprintf(backup_path, "%s.backup", file.path);
    copy_file(file.path, backup_path);
    free(backup_path);
}

// Thread function to backup files
void *backup_thread(void *arg) {
    file_queue *queue = (file_queue *)arg;
    while (1) {
        file_info file = file_queue_pop(queue);
        if (strcmp(file.name, "STOP") == 0) {
            break;
        }
        backup_file(file);
        free(file.path);
        free(file.name);
    }
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <path> <backup_path>\n", argv[0]);
        return 1;
    }
    const char *path = argv[1];
    const char *backup_path = argv[2];
    file_queue *queue = file_queue_create();
    scan_directory(path, queue);
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, backup_thread, queue);
    }
    file_info stop;
    stop.path = "STOP";
    stop.name = "STOP";
    for (int i = 0; i < MAX_THREADS; i++) {
        file_queue_push(queue, stop);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    file_queue_destroy(queue);
    return 0;
}