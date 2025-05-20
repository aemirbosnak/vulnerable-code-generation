//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define ENCRYPTION_KEY 5
#define FILE_NAME_SIZE 256

typedef struct {
    char *file_name;
    int encrypt;
} task_t;

void *process_file(void *arg) {
    task_t *task = (task_t *)arg;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    int input_fd = open(task->file_name, O_RDONLY);
    if (input_fd < 0) {
        perror("Error opening input file");
        return NULL;
    }

    char output_file_name[FILE_NAME_SIZE];
    if (task->encrypt) {
        snprintf(output_file_name, FILE_NAME_SIZE, "%s.enc", task->file_name);
    } else {
        snprintf(output_file_name, FILE_NAME_SIZE, "%s.dec", task->file_name);
    }

    int output_fd = open(output_file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (output_fd < 0) {
        perror("Error opening output file");
        close(input_fd);
        return NULL;
    }

    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            // Simple XOR encryption/decryption
            buffer[i] ^= ENCRYPTION_KEY;
        }
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to output file");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading input file");
    }

    close(input_fd);
    close(output_fd);
    printf("%s completed\n", task->encrypt ? "Encryption" : "Decryption");

    return NULL;
}

void encrypt_file(const char *file_name) {
    task_t *task = malloc(sizeof(task_t));
    task->file_name = (char *)file_name;
    task->encrypt = 1;

    pthread_t thread;
    pthread_create(&thread, NULL, process_file, task);
    pthread_detach(thread);
}

void decrypt_file(const char *file_name) {
    task_t *task = malloc(sizeof(task_t));
    task->file_name = (char *)file_name;
    task->encrypt = 0;

    pthread_t thread;
    pthread_create(&thread, NULL, process_file, task);
    pthread_detach(thread);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    // Sleep to allow time for async operation to complete
    // In a real application, we should have better synchronization
    printf("Processing, please wait...\n");
    sleep(2); // Wait for threads to process
    printf("Done!\n");

    return EXIT_SUCCESS;
}