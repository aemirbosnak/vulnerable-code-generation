//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st {
    long int my_msg_type;
    char some_text[BUFSIZ];
};

int main(void) {
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    char buffer[BUFSIZ];

    // Get the message queue id for the "my_queue" queue.
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        return EXIT_FAILURE;
    }

    // Main loop
    while(running) {
        // Get some text from the user.
        printf("Enter some text: ");
        fgets(buffer, BUFSIZ, stdin);
        printf("User entered: ");
        puts(buffer);

        // Put the text into the message structure.
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);

        // Send the message to the "my_queue" queue.
        if (msgsnd(msgid, (void*)&some_data, strlen(some_data.some_text) + 1, 0) == -1) {
            fprintf(stderr, "msgsnd failed with error: %d\n", errno);
            return EXIT_FAILURE;
        }

        // Check if the user entered the word "exit".
        if (strcmp(buffer, "exit\n") == 0) {
            running = 0;
        }
    }

    // Delete the message queue.
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed with error: %d\n", errno);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}