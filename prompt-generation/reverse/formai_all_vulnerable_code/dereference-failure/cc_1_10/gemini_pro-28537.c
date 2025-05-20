//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define POP3_PORT 110

void usage(char *program) {
    printf("Usage: %s <hostname> <username> <password>\n", program);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Get the IP address of the POP3 server.
    struct hostent *hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    char *ip = inet_ntoa(*((struct in_addr *)hostinfo->h_addr));

    // Create a TCP socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the POP3 server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        exit(EXIT_FAILURE);
    }

    // Receive the welcome message from the server.
    char buf[1024];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: could not receive welcome message");
        exit(EXIT_FAILURE);
    }
    printf("Welcome message: %s\n", buf);

    // Send the USER command to the server.
    sprintf(buf, "USER %s\n", username);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: could not send USER command");
        exit(EXIT_FAILURE);
    }
    printf("Sent USER command: %s\n", buf);

    // Receive the USER response from the server.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: could not receive USER response");
        exit(EXIT_FAILURE);
    }
    printf("Received USER response: %s\n", buf);

    // Send the PASS command to the server.
    sprintf(buf, "PASS %s\n", password);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: could not send PASS command");
        exit(EXIT_FAILURE);
    }
    printf("Sent PASS command: %s\n", buf);

    // Receive the PASS response from the server.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("Error: could not receive PASS response");
        exit(EXIT_FAILURE);
    }
    printf("Received PASS response: %s\n", buf);

    // Send the LIST command to the server.
    sprintf(buf, "LIST\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: could not send LIST command");
        exit(EXIT_FAILURE);
    }
    printf("Sent LIST command: %s\n", buf);

    // Receive the LIST response from the server.
    int num_messages = 0;
    while (1) {
        n = recv(sockfd, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("Error: could not receive LIST response");
            exit(EXIT_FAILURE);
        }
        if (strncmp(buf, ".\n", 2) == 0) {
            break;
        }
        num_messages++;
        printf("Received message %d: %s\n", num_messages, buf);
    }

    // Send the QUIT command to the server.
    sprintf(buf, "QUIT\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("Error: could not send QUIT command");
        exit(EXIT_FAILURE);
    }
    printf("Sent QUIT command: %s\n", buf);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}