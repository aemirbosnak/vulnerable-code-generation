//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_MESSAGE 128
#define FIFO_NAME "kingdom_fifo"

void knight_on_guard() {
    int fd;
    char message[MAX_MESSAGE];

    // Open the named pipe for writing
    fd = open(FIFO_NAME, O_WRONLY);
    
    if (fd == -1) {
        perror("Knight Guard: Unable to open FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Crafting the message
    snprintf(message, MAX_MESSAGE, "Hear ye! A dragon has been sighted near the western woods!");

    // Sending the message to the kingdom
    write(fd, message, strlen(message) + 1);
    printf("Knight Guard: Sent message to the questing knight.\n");

    // Close the named pipe
    close(fd);
}

void knight_on_quest() {
    int fd;
    char message[MAX_MESSAGE];

    // Create the named pipe (FIFO)
    mkfifo(FIFO_NAME, 0666);

    // Open the named pipe for reading
    fd = open(FIFO_NAME, O_RDONLY);
    
    if (fd == -1) {
        perror("Knight Quest: Unable to open FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read the message from the named pipe
    read(fd, message, MAX_MESSAGE);
    printf("Knight Quest: Received message - '%s'\n", message);

    // Close the named pipe
    close(fd);

    // Clean up the FIFO after use
    unlink(FIFO_NAME);
}

int main() {
    // Forking two knights
    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork knights");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // This process will be the knight on quest
        knight_on_quest();
    } else {
        // This process will be the knight on guard
        sleep(1); // Ensure guard sends message after questing knight is ready
        knight_on_guard();
    }

    return 0;
}