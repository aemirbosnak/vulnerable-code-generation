//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_MESSAGE_LENGTH 10240

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <recipient> [<sender>]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command-line arguments.
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *recipient = argv[3];
    char *sender = argc >= 5 ? argv[4] : NULL;

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve hostname.
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, sizeof(server_addr.sin_addr));
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read greeting response from the server.
    char buffer[MAX_LINE_LENGTH];
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send HELO command.
    snprintf(buffer, MAX_LINE_LENGTH, "HELO %s\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read HELO response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send MAIL FROM command.
    snprintf(buffer, MAX_LINE_LENGTH, "MAIL FROM:<%s>\r\n", sender ? sender : "anonymous");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read MAIL FROM response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send RCPT TO command.
    snprintf(buffer, MAX_LINE_LENGTH, "RCPT TO:<%s>\r\n", recipient);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read RCPT TO response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send DATA command.
    if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read DATA response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send the message body.
    char message[MAX_MESSAGE_LENGTH];
    memset(message, 0, sizeof(message));
    printf("Enter the message body (end with a single period on a line by itself):\n");
    while (1) {
        fgets(buffer, MAX_LINE_LENGTH, stdin);
        if (buffer[0] == '.' && buffer[1] == '\r' && buffer[2] == '\n') {
            break;
        }
        strcat(message, buffer);
    }
    snprintf(buffer, MAX_LINE_LENGTH, "%s\r\n.", message);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Send QUIT command.
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read QUIT response from the server.
    if (recv(sockfd, buffer, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("Server: %s\n", buffer);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}