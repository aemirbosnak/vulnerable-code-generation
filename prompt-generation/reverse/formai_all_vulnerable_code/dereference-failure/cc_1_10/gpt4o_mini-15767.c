//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define BACKUP_DIR "backups/"
#define BUFFER_SIZE 1024

typedef struct {
    char *filepath;
    char *backupfile;
} BackupTask;

void *backup_file(void *arg) {
    BackupTask *task = (BackupTask *)arg;
    FILE *src = fopen(task->filepath, "rb");
    if (!src) {
        perror("Source file open error");
        free(task);
        pthread_exit(NULL);
    }

    FILE *dst = fopen(task->backupfile, "wb");
    if (!dst) {
        perror("Destination file open error");
        fclose(src);
        free(task);
        pthread_exit(NULL);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytesRead, dst);
    }

    fclose(src);
    fclose(dst);
    printf("Backup of %s completed as %s\n", task->filepath, task->backupfile);
    free(task);
    pthread_exit(NULL);
}

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    create_backup_directory();

    pthread_t threads[MAX_FILES];
    int thread_count = 0;

    for (int i = 1; i < argc && thread_count < MAX_FILES; i++) {
        BackupTask *task = malloc(sizeof(BackupTask));
        task->filepath = argv[i];
        
        char *filename = strrchr(argv[i], '/');
        filename = filename ? filename + 1 : argv[i]; // Extract filename from path
        asprintf(&task->backupfile, "%s%s_%ld.bak", BACKUP_DIR, filename, time(NULL)); // Unique backup filename

        if (pthread_create(&threads[thread_count], NULL, backup_file, task) != 0) {
            perror("Failed to create thread");
            free(task->backupfile);
            free(task);
            continue;
        }
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All backup operations completed.\n");
    return 0;
}