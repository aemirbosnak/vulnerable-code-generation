//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_PRODUCER "/tmp/fifo_producer"
#define FIFO_CONSUMER "/tmp/fifo_consumer"
#define BUFFER_SIZE 256

void create_fifo(const char *fifo_path) {
    if (mkfifo(fifo_path, 0666) == -1 && errno != EEXIST) {
        perror("Failed to create FIFO");
        exit(EXIT_FAILURE);
    }
}

void producer() {
    int fd;
    char input[BUFFER_SIZE];

    if ((fd = open(FIFO_PRODUCER, O_WRONLY)) == -1) {
        perror("Producer: Failed to open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Producer: Enter message (type 'exit' to quit): ");
        fgets(input, BUFFER_SIZE, stdin);
        
        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (write(fd, input, strlen(input) + 1) == -1) {
            perror("Producer: Failed to write to FIFO");
            break;
        }

        printf("Producer: Sent '%s'\n", input);
    }
    
    close(fd);
}

void consumer() {
    int fd;
    char buffer[BUFFER_SIZE];

    if ((fd = open(FIFO_CONSUMER, O_RDONLY)) == -1) {
        perror("Consumer: Failed to open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    while (1) {
        ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
        
        if (bytes_read == -1) {
            perror("Consumer: Failed to read from FIFO");
            break;
        } else if (bytes_read == 0) {
            printf("Consumer: No more data. Exiting...\n");
            break;
        }

        printf("Consumer: Received '%s'\n", buffer);
    }

    close(fd);
}

int main() {
    create_fifo(FIFO_PRODUCER);
    create_fifo(FIFO_CONSUMER);

    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process - Consumer
        consumer();
    } else {
        // Parent process - Producer
        producer();
        // Wait for child process to finish
        wait(NULL);
    }

    // Clean up FIFOs
    unlink(FIFO_PRODUCER);
    unlink(FIFO_CONSUMER);

    return 0;
}