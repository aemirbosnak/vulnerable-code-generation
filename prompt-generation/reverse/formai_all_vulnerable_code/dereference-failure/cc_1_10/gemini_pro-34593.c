//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>

#define POP3_PORT 110
#define MAX_LINE 1024

void handle_sigint(int sig) {
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to POP3 server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error connecting to POP3 server");
        exit(1);
    }

    // Set socket to non-blocking mode
    int flags = fcntl(sockfd, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(sockfd, F_SETFL, flags);

    // Register signal handler for SIGINT
    signal(SIGINT, handle_sigint);

    // Send USER command
    char buf[MAX_LINE];
    sprintf(buf, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending USER command");
        exit(1);
    }

    // Receive response
    int bytes_received = recv(sockfd, buf, MAX_LINE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response to USER command");
        exit(1);
    } else if (bytes_received == 0) {
        fprintf(stderr, "Connection closed by server\n");
        exit(1);
    } else if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error response to USER command: %s\n", buf);
        exit(1);
    }

    // Send PASS command
    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending PASS command");
        exit(1);
    }

    // Receive response
    bytes_received = recv(sockfd, buf, MAX_LINE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response to PASS command");
        exit(1);
    } else if (bytes_received == 0) {
        fprintf(stderr, "Connection closed by server\n");
        exit(1);
    } else if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error response to PASS command: %s\n", buf);
        exit(1);
    }

    // Send LIST command
    sprintf(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending LIST command");
        exit(1);
    }

    // Receive response
    while (1) {
        bytes_received = recv(sockfd, buf, MAX_LINE, 0);
        if (bytes_received == -1) {
            perror("Error receiving response to LIST command");
            exit(1);
        } else if (bytes_received == 0) {
            fprintf(stderr, "Connection closed by server\n");
            exit(1);
        } else if (strncmp(buf, ".", 1) == 0) {
            break;
        } else {
            printf("%s", buf);
        }
    }

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}