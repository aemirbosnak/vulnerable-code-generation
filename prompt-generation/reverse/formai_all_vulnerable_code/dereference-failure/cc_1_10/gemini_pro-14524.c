//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct file_node {
    char *name;
    struct file_node *parent;
    struct file_node *next;
    struct file_node *prev;
    long long size;
} file_node;

typedef struct file_queue {
    file_node *head;
    file_node *tail;
} file_queue;

void init_file_queue(file_queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue_file(file_queue *queue, file_node *file) {
    if (queue->head == NULL) {
        queue->head = file;
        queue->tail = file;
    } else {
        queue->tail->next = file;
        file->prev = queue->tail;
        queue->tail = file;
    }
}

file_node *dequeue_file(file_queue *queue) {
    if (queue->head == NULL) {
        return NULL;
    } else {
        file_node *file = queue->head;
        queue->head = queue->head->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        } else {
            queue->head->prev = NULL;
        }
        return file;
    }
}

void free_file_node(file_node *file) {
    if (file->name != NULL) {
        free(file->name);
    }
    free(file);
}

void free_file_queue(file_queue *queue) {
    while (queue->head != NULL) {
        file_node *file = dequeue_file(queue);
        free_file_node(file);
    }
}

int compare_file_nodes(const void *a, const void *b) {
    const file_node *file_a = (const file_node *)a;
    const file_node *file_b = (const file_node *)b;
    return (file_b->size - file_a->size);
}

void analyze_directory(const char *path, file_queue *queue) {
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
        char *file_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, entry->d_name);
        file_node *file = malloc(sizeof(file_node));
        file->name = file_path;
        file->parent = NULL;
        file->next = NULL;
        file->prev = NULL;
        struct stat statbuf;
        if (lstat(file_path, &statbuf) == -1) {
            perror("lstat");
            free_file_node(file);
            continue;
        }
        file->size = statbuf.st_size;
        enqueue_file(queue, file);
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(file_path, queue);
        }
    }
    closedir(dir);
}

void print_file_queue(file_queue *queue) {
    file_node *file = queue->head;
    while (file != NULL) {
        printf("%lld %s\n", file->size, file->name);
        file = file->next;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    file_queue queue;
    init_file_queue(&queue);
    analyze_directory(argv[1], &queue);
    file_node *files[queue.head->next == NULL ? 1 : queue.head->next->size];
    int i = 0;
    file_node *file = queue.head;
    while (file != NULL) {
        files[i] = file;
        i++;
        file = file->next;
    }
    qsort(files, i, sizeof(file_node *), compare_file_nodes);
    for (int j = 0; j < i; j++) {
        printf("%lld %s\n", files[j]->size, files[j]->name);
    }
    free_file_queue(&queue);
    return 0;
}