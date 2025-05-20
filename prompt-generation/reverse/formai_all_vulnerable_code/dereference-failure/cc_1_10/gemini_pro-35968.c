//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Define the maximum number of threads to use.
#define MAX_THREADS 4

// Define the size of each file buffer.
#define BUFFER_SIZE 1024

// Define the number of files to backup.
#define NUM_FILES 10

// Define the array of file names to backup.
char *file_names[] = {
    "file1.txt",
    "file2.txt",
    "file3.txt",
    "file4.txt",
    "file5.txt",
    "file6.txt",
    "file7.txt",
    "file8.txt",
    "file9.txt",
    "file10.txt"
};

// Define the mutex to protect the shared data.
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the condition variable to signal when a thread is finished.
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Define the array of thread IDs.
pthread_t thread_ids[MAX_THREADS];

// Define the array of file pointers.
FILE *file_ptrs[NUM_FILES];

// Define the array of file sizes.
long file_sizes[NUM_FILES];

// Define the total number of bytes backed up.
long total_bytes = 0;

// Define the backup directory.
char *backup_dir = "backup";

// Function to copy a file from one location to another.
void copy_file(char *src_file, char *dest_file) {
    // Open the source file.
    FILE *src_ptr = fopen(src_file, "rb");
    if (src_ptr == NULL) {
        perror("fopen");
        exit(1);
    }

    // Open the destination file.
    FILE *dest_ptr = fopen(dest_file, "wb");
    if (dest_ptr == NULL) {
        perror("fopen");
        exit(1);
    }

    // Copy the file data from the source file to the destination file.
    char buffer[BUFFER_SIZE];
    while (1) {
        // Read a block of data from the source file.
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, src_ptr);
        if (bytes_read == 0) {
            break;
        }

        // Write the block of data to the destination file.
        size_t bytes_written = fwrite(buffer, 1, bytes_read, dest_ptr);
        if (bytes_written != bytes_read) {
            perror("fwrite");
            exit(1);
        }
    }

    // Close the source file.
    fclose(src_ptr);

    // Close the destination file.
    fclose(dest_ptr);
}

// Function to create a backup of a file.
void *backup_file(void *arg) {
    // Get the file name.
    char *file_name = (char *)arg;

    // Create the backup directory if it doesn't exist.
    struct stat st;
    if (stat(backup_dir, &st) != 0) {
        mkdir(backup_dir, 0755);
    }

    // Get the file size.
    struct stat file_stat;
    if (stat(file_name, &file_stat) != 0) {
        perror("stat");
        exit(1);
    }

    // Open the file.
    FILE *file_ptr = fopen(file_name, "rb");
    if (file_ptr == NULL) {
        perror("fopen");
        exit(1);
    }

    // Create the backup file.
    char backup_file[256];
    snprintf(backup_file, 256, "%s/%s", backup_dir, file_name);
    FILE *backup_ptr = fopen(backup_file, "wb");
    if (backup_ptr == NULL) {
        perror("fopen");
        exit(1);
    }

    // Copy the file data from the file to the backup file.
    char buffer[BUFFER_SIZE];
    while (1) {
        // Read a block of data from the file.
        size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file_ptr);
        if (bytes_read == 0) {
            break;
        }

        // Write the block of data to the backup file.
        size_t bytes_written = fwrite(buffer, 1, bytes_read, backup_ptr);
        if (bytes_written != bytes_read) {
            perror("fwrite");
            exit(1);
        }
    }

    // Update the shared data.
    pthread_mutex_lock(&mutex);
    total_bytes += file_stat.st_size;
    pthread_mutex_unlock(&mutex);

    // Close the file.
    fclose(file_ptr);

    // Close the backup file.
    fclose(backup_ptr);

    // Signal that the thread is finished.
    pthread_cond_signal(&cond);

    return NULL;
}

int main() {
    // Create the threads.
    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&thread_ids[i], NULL, backup_file, file_names[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for the threads to finish.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    // Print the total number of bytes backed up.
    printf("Total bytes backed up: %ld\n", total_bytes);

    return 0;
}