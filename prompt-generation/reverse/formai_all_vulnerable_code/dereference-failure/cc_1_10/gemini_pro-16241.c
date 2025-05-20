//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

// Function to receive a line of text from the server.
char *recv_line(int sockfd) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = recv(sockfd, line + len, 1, 0)) > 0) {
        len += nread;
        if (line[len - 1] == '\n') {
            break;
        }

        line = realloc(line, len + 1);
        if (line == NULL) {
            perror("realloc");
            return NULL;
        }
    }

    if (nread == 0) {
        return NULL;
    }

    line[len] = '\0';
    return line;
}

// Function to send a command to the server.
int send_command(int sockfd, char *command) {
    int n;

    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

// Function to retrieve the email messages from the server.
int retrieve_messages(int sockfd) {
    char *line;
    int msg_count = 0;

    while ((line = recv_line(sockfd)) != NULL) {
        if (strncmp(line, "+OK", 3) == 0) {
            msg_count++;
        } else {
            printf("%s", line);
        }

        free(line);
    }

    return msg_count;
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char *host;
    char *user;
    char *pass;
    int msg_count;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <user> <pass>\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    user = argv[2];
    pass = argv[3];

    // Create a socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address.
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message from the server.
    char *line = recv_line(sockfd);
    if (line == NULL) {
        perror("recv_line");
        return EXIT_FAILURE;
    }

    printf("%s", line);
    free(line);

    // Send the USER command to the server.
    if (send_command(sockfd, "USER ") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    if (send_command(sockfd, user) < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    if (send_command(sockfd, "\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    line = recv_line(sockfd);
    if (line == NULL) {
        perror("recv_line");
        return EXIT_FAILURE;
    }

    printf("%s", line);
    free(line);

    // Send the PASS command to the server.
    if (send_command(sockfd, "PASS ") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    if (send_command(sockfd, pass) < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    if (send_command(sockfd, "\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    line = recv_line(sockfd);
    if (line == NULL) {
        perror("recv_line");
        return EXIT_FAILURE;
    }

    printf("%s", line);
    free(line);

    // Send the STAT command to the server.
    if (send_command(sockfd, "STAT\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    line = recv_line(sockfd);
    if (line == NULL) {
        perror("recv_line");
        return EXIT_FAILURE;
    }

    printf("%s", line);
    free(line);

    // Send the LIST command to the server.
    if (send_command(sockfd, "LIST\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    line = recv_line(sockfd);
    if (line == NULL) {
        perror("recv_line");
        return EXIT_FAILURE;
    }

    printf("%s", line);
    free(line);

    // Send the RETR command to the server.
    if (send_command(sockfd, "RETR 1\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Receive the response from the server.
    msg_count = retrieve_messages(sockfd);

    // Send the QUIT command to the server.
    if (send_command(sockfd, "QUIT\n") < 0) {
        perror("send_command");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}