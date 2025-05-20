//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pthread.h>

// File synchronization structure
typedef struct {
    char *filename;
    time_t last_modified;
    size_t size;
} FileInfo;

// Queue for file synchronization
typedef struct {
    FileInfo *items;
    int front, rear, count;
    size_t capacity;
} Queue;

// Create a new queue
Queue *createQueue(size_t capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (FileInfo *)malloc(sizeof(FileInfo) * capacity);
    queue->front = queue->rear = queue->count = 0;
    queue->capacity = capacity;
    return queue;
}

// Check if the queue is full
int isFull(Queue *queue) {
    return (queue->count == queue->capacity);
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return (queue->count == 0);
}

// Add an item to the queue
void enqueue(Queue *queue, FileInfo *item) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    queue->items[queue->rear] = *item;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->count++;
}

// Remove an item from the queue
FileInfo *dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    FileInfo *item = &queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
    return item;
}

// Get the size of the queue
size_t size(Queue *queue) {
    return queue->count;
}

// Print the queue
void printQueue(Queue *queue) {
    for (int i = 0; i < queue->count; i++) {
        FileInfo *item = &queue->items[i];
        printf("%s (%ld bytes, %s)\n", item->filename, item->size, ctime(&item->last_modified));
    }
}

// Free the queue
void freeQueue(Queue *queue) {
    free(queue->items);
    free(queue);
}

// Get file information
FileInfo *getFileInfo(const char *filename) {
    struct stat statbuf;
    if (stat(filename, &statbuf) < 0) {
        return NULL;
    }
    FileInfo *fileinfo = (FileInfo *)malloc(sizeof(FileInfo));
    fileinfo->filename = strdup(filename);
    fileinfo->last_modified = statbuf.st_mtime;
    fileinfo->size = statbuf.st_size;
    return fileinfo;
}

// Compare two files
int compareFiles(FileInfo *file1, FileInfo *file2) {
    return (strcmp(file1->filename, file2->filename) == 0);
}

// Find a file in the queue
int findFileInQueue(Queue *queue, FileInfo *file) {
    for (int i = 0; i < queue->count; i++) {
        FileInfo *item = &queue->items[i];
        if (compareFiles(item, file)) {
            return i;
        }
    }
    return -1;
}

// Synchronize two directories
void syncDirs(const char *dir1, const char *dir2) {
    // Create queues for each directory
    Queue *queue1 = createQueue(100);
    Queue *queue2 = createQueue(100);

    // Get a list of files in each directory
    DIR *dp1 = opendir(dir1);
    DIR *dp2 = opendir(dir2);
    if (dp1 == NULL || dp2 == NULL) {
        perror("Error opening directory");
        return;
    }
    struct dirent *entry1, *entry2;
    while ((entry1 = readdir(dp1)) != NULL) {
        if (strcmp(entry1->d_name, ".") == 0 || strcmp(entry1->d_name, "..") == 0) {
            continue;
        }
        FileInfo *file1 = getFileInfo(entry1->d_name);
        enqueue(queue1, file1);
    }
    while ((entry2 = readdir(dp2)) != NULL) {
        if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }
        FileInfo *file2 = getFileInfo(entry2->d_name);
        enqueue(queue2, file2);
    }
    closedir(dp1);
    closedir(dp2);

    // Compare the files in the queues
    while (!isEmpty(queue1) && !isEmpty(queue2)) {
        FileInfo *file1 = dequeue(queue1);
        FileInfo *file2 = dequeue(queue2);
        int index2 = findFileInQueue(queue2, file1);
        if (index2 == -1) {
            // File1 does not exist in dir2, so copy it
            printf("Copying %s to %s\n", file1->filename, dir2);
            // ...
        } else {
            FileInfo *file2_copy = &queue2->items[index2];
            if (file1->last_modified > file2_copy->last_modified) {
                // File1 is newer than file2, so update file2
                printf("Updating %s in %s\n", file1->filename, dir2);
                // ...
            } else if (file1->last_modified < file2_copy->last_modified) {
                // File2 is newer than file1, so update file1
                printf("Updating %s in %s\n", file1->filename, dir1);
                // ...
            }
            // Remove file2 from queue2
            queue2->count--;
            for (int i = index2; i < queue2->count; i++) {
                queue2->items[i] = queue2->items[i + 1];
            }
        }
        // Free file1
        free(file1->filename);
        free(file1);
    }

    // Copy any remaining files from queue1 to dir2
    while (!isEmpty(queue1)) {
        FileInfo *file1 = dequeue(queue1);
        printf("Copying %s to %s\n", file1->filename, dir2);
        // ...
        // Free file1
        free(file1->filename);
        free(file1);
    }

    // Copy any remaining files from queue2 to dir1
    while (!isEmpty(queue2)) {
        FileInfo *file2 = dequeue(queue2);
        printf("Copying %s to %s\n", file2->filename, dir1);
        // ...
        // Free file2
        free(file2->filename);
        free(file2);
    }

    // Free the queues
    freeQueue(queue1);
    freeQueue(queue2);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    syncDirs(argv[1], argv[2]);

    return 0;
}