//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024 // Maximum size of email messages.

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s server port user\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *port = argv[2];
    char *user = argv[3];

    int sockfd, error;
    struct addrinfo *ai, hint;

    memset(&hint, 0, sizeof(hint));
    hint.ai_family = AF_UNSPEC;
    hint.ai_socktype = SOCK_STREAM;

    if ((error = getaddrinfo(server, port, &hint, &ai)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        exit(EXIT_FAILURE);
    }

    // Find the first address that works.
    for (struct addrinfo *p = ai; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    freeaddrinfo(ai);

    if (sockfd == -1) {
        fprintf(stderr, "Failed to connect to %s:%s\n", server, port);
        exit(EXIT_FAILURE);
    }

    // Receive the banner message from the server.
    char buffer[BUFFER_SIZE];
    ssize_t n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send our login information to the server.
    char login_command[BUFFER_SIZE];
    snprintf(login_command, BUFFER_SIZE, "LOGIN %s\n", user);
    if (send(sockfd, login_command, strlen(login_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to our login command.
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the SELECT command to choose the INBOX mailbox.
    const char *select_command = "SELECT INBOX\n";
    if (send(sockfd, select_command, strlen(select_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to our SELECT command.
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the FETCH command to get a list of message IDs.
    const char *fetch_command = "FETCH 1:* (UID)\n";
    if (send(sockfd, fetch_command, strlen(fetch_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to our FETCH command.
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';

    // Parse the message IDs from the response.
    char *id_lines = strstr(buffer, "UID");
    if (id_lines == NULL) {
        fprintf(stderr, "Failed to parse message IDs.\n");
        exit(EXIT_FAILURE);
    }

    // Convert the message IDs to integers.
    int num_ids = 0;
    int *ids = malloc(100 * sizeof(int));
    char *token = strtok(id_lines, " ");
    while (token != NULL) {
        int id = atoi(token);
        if (id > 0) {
            ids[num_ids++] = id;
        }
        token = strtok(NULL, " ");
    }

    if (num_ids == 0) {
        fprintf(stderr, "No message IDs found.\n");
        exit(EXIT_FAILURE);
    }

    // Loop through each message and retrieve its contents.
    for (int i = 0; i < num_ids; i++) {
        int id = ids[i];

        // Send the FETCH command to get the message contents.
        char fetch_command[BUFFER_SIZE];
        snprintf(fetch_command, BUFFER_SIZE, "FETCH %d BODY[]\n", id);
        if (send(sockfd, fetch_command, strlen(fetch_command), 0) == -1) {
            perror("send");
            continue;
        }

        // Receive the response to our FETCH command.
        n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (n < 0) {
            perror("recv");
            continue;
        }
        buffer[n] = '\0';

        // Find the start and end of the email message within the response.
        char *start = strstr(buffer, "{");
        char *end = strstr(start, ")\r\n");
        if (start == NULL || end == NULL) {
            fprintf(stderr, "Failed to parse email message.\n");
            continue;
        }

        // Extract the size of the email message.
        int message_size = atoi(start + 1);
        if (message_size < 0) {
            fprintf(stderr, "Invalid email message size.\n");
            continue;
        }

        // Read the body of the email message.
        int bytes_read = 0;
        char message[BUFFER_SIZE];
        while (bytes_read < message_size) {
            n = recv(sockfd, message + bytes_read, BUFFER_SIZE - bytes_read - 1, 0);
            if (n < 0) {
                perror("recv");
                break;
            }
            bytes_read += n;
        }
        message[bytes_read] = '\0';

        // Print the contents of the email message.
        printf("%s", message);
    }

    // Clean up and exit.
    free(ids);
    close(sockfd);
    exit(EXIT_SUCCESS);
}