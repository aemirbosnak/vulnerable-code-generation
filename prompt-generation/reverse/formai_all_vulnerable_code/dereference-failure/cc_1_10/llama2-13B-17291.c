//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_STR_LEN 1024

// Structure to hold the message and the receiver's PID
typedef struct {
    char message[MAX_STR_LEN];
    pid_t receiver_pid;
} message_t;

// Function to send a message to a process
void send_message(pid_t sender_pid, pid_t receiver_pid, char* message) {
    // Create a new message struct
    message_t new_message = {
        .message = message,
        .receiver_pid = receiver_pid
    };

    // Encode the message struct into a string
    char* message_str = malloc(sizeof(message_t) * sizeof(char));
    memcpy(message_str, &new_message, sizeof(message_t));

    // Send the message to the receiver process
    write(sender_pid, message_str, sizeof(message_t));

    // Free the message struct
    free(message_str);
}

// Function to receive a message from a process
void receive_message(pid_t receiver_pid) {
    // Create a new message struct
    message_t new_message;

    // Decode the message struct from the string
    char* message_str = malloc(sizeof(message_t) * sizeof(char));
    read(receiver_pid, message_str, sizeof(message_t));
    memcpy(&new_message, message_str, sizeof(message_t));

    // Free the message struct
    free(message_str);

    // Print the received message
    printf("Received message from %d: %s\n", receiver_pid, new_message.message);
}

int main() {
    // Create two processes
    pid_t parent_pid = getpid();
    pid_t child_pid = fork();

    // If the parent process...
    if (parent_pid == 0) {
        // ...send a message to the child process
        send_message(parent_pid, child_pid, "Hello from the parent!");

        // Wait for the child process to finish
        wait(NULL);
    }

    // If the child process...
    else if (child_pid == 0) {
        // ...receive the message from the parent process
        receive_message(child_pid);

        // Print a message to the parent process
        char message[] = "Hello from the child!";
        send_message(child_pid, parent_pid, message);

        // Do some work...
        sleep(5);

        // ...and then send another message to the parent process
        char message2[] = "I'm done!";
        send_message(child_pid, parent_pid, message2);
    }

    return 0;
}