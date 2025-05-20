//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

// Recursively read a line from the given file pointer
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        // Remove trailing newline
        if (line[nread - 1] == '\n') {
            line[nread - 1] = '\0';
        }

        // Return the line
        return line;
    }

    // EOF reached
    return NULL;
}

// Recursively send a message to the given socket
void send_message(int sock, char *message) {
    size_t len = strlen(message);
    int sent;

    while (len > 0) {
        sent = send(sock, message, len, 0);
        if (sent < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        message += sent;
        len -= sent;
    }
}

// Recursively receive a message from the given socket
char *receive_message(int sock) {
    char *message = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = recv(sock, message, len, 0)) > 0) {
        // Reallocate the buffer if necessary
        if (nread + len >= len) {
            len *= 2;
            message = realloc(message, len);
            if (message == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        // Append the received data to the message
        memcpy(message + len, message, nread);
        len += nread;
    }

    // Return the message
    return message;
}

// Recursively handle the given client socket
void handle_client(int sock) {
    char *line;

    // Read a line from the client
    line = read_line(fdopen(sock, "r"));
    if (line == NULL) {
        perror("read_line");
        exit(EXIT_FAILURE);
    }

    // Process the line
    if (strcmp(line, "QUIT") == 0) {
        // Client wants to quit
        send_message(sock, "Goodbye!\n");
        close(sock);
        return;
    } else {
        // Echo the line back to the client
        send_message(sock, line);
        send_message(sock, "\n");
    }

    // Free the line
    free(line);

    // Recurse to handle the next line
    handle_client(sock);
}

int main() {
    int sock, newsock;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t clientaddrlen;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        clientaddrlen = sizeof(clientaddr);
        newsock = accept(sock, (struct sockaddr *) &clientaddr, &clientaddrlen);
        if (newsock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Handle the client in a recursive function
        handle_client(newsock);
    }

    // Close the socket
    close(sock);

    return 0;
}