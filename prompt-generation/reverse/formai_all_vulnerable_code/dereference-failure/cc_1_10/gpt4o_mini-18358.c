//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_FILES 10
#define BUFFER_SIZE 1024

typedef struct {
    char *source_file;
    char *backup_dir;
    pthread_t thread_id;
    int is_running;
} BackupTask;

BackupTask tasks[MAX_FILES];
int task_count = 0;

void handle_sigint(int sig) {
    printf("\nReceived interrupt. Initiating graceful shutdown of backup tasks...\n");
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].is_running) {
            tasks[i].is_running = 0;
            pthread_cancel(tasks[i].thread_id);
            printf("Backup task for %s has been cancelled.\n", tasks[i].source_file);
        }
    }
    exit(0);
}

void *backup_file(void *arg) {
    BackupTask *task = (BackupTask *)arg;
    task->is_running = 1;

    char buffer[BUFFER_SIZE];
    char dest_file[512];
    snprintf(dest_file, sizeof(dest_file), "%s/%s_backup", task->backup_dir, strrchr(task->source_file, '/') + 1);

    FILE *src = fopen(task->source_file, "rb");
    if (src == NULL) {
        perror("Failed to open source file");
        task->is_running = 0;
        pthread_exit(NULL);
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        perror("Failed to create backup file");
        fclose(src);
        task->is_running = 0;
        pthread_exit(NULL);
    }

    size_t bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0 && task->is_running) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    task->is_running = 0;
    printf("Backup of %s completed successfully.\n", task->source_file);
    pthread_exit(NULL);
}

int add_backup_task(const char *file_path, const char *backup_dir) {
    if (task_count >= MAX_FILES) {
        printf("Maximum number of backup tasks reached!\n");
        return -1;
    }

    tasks[task_count].source_file = strdup(file_path);
    tasks[task_count].backup_dir = strdup(backup_dir);
    pthread_create(&tasks[task_count].thread_id, NULL, backup_file, &tasks[task_count]);
    task_count++;
    return 0;
}

void cleanup_tasks() {
    for (int i = 0; i < task_count; i++) {
        free(tasks[i].source_file);
        free(tasks[i].backup_dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <backup_directory> <file1> [file2] [file3] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    signal(SIGINT, handle_sigint);  // Handle Ctrl+C for graceful shutdown

    const char *backup_dir = argv[1];

    for (int i = 2; i < argc; i++) {
        if (add_backup_task(argv[i], backup_dir) != 0) {
            fprintf(stderr, "Failed to add backup task for %s\n", argv[i]);
        }
    }

    for (int i = 0; i < task_count; i++) {
        if (tasks[i].is_running) {
            pthread_join(tasks[i].thread_id, NULL);
        }
    }

    cleanup_tasks();
    return EXIT_SUCCESS;
}