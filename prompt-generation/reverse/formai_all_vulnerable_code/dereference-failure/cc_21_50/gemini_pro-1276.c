//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *path = argv[2];

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send the USER command
    char user_cmd[BUFFER_SIZE];
    snprintf(user_cmd, BUFFER_SIZE, "USER anonymous\r\n");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
        perror("Error sending USER command");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    char response[BUFFER_SIZE];
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(response, "331", 3) != 0) {
        fprintf(stderr, "Error: %s\n", response);
        exit(EXIT_FAILURE);
    }

    // Send the PASS command
    char pass_cmd[BUFFER_SIZE];
    snprintf(pass_cmd, BUFFER_SIZE, "PASS anonymous@\r\n");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
        perror("Error sending PASS command");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(response, "230", 3) != 0) {
        fprintf(stderr, "Error: %s\n", response);
        exit(EXIT_FAILURE);
    }

    // Send the TYPE command
    char type_cmd[BUFFER_SIZE];
    snprintf(type_cmd, BUFFER_SIZE, "TYPE I\r\n");
    if (send(sockfd, type_cmd, strlen(type_cmd), 0) == -1) {
        perror("Error sending TYPE command");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(response, "200", 3) != 0) {
        fprintf(stderr, "Error: %s\n", response);
        exit(EXIT_FAILURE);
    }

    // Send the RETR command
    char retr_cmd[BUFFER_SIZE];
    snprintf(retr_cmd, BUFFER_SIZE, "RETR %s\r\n", path);
    if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) == -1) {
        perror("Error sending RETR command");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Check the response code
    if (strncmp(response, "150", 3) != 0) {
        fprintf(stderr, "Error: %s\n", response);
        exit(EXIT_FAILURE);
    }

    // Receive the file data
    FILE *fp = fopen(path, "w");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (1) {
        char buf[BUFFER_SIZE];
        int bytes_received = recv(sockfd, buf, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving file data");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            break;
        }

        fwrite(buf, 1, bytes_received, fp);
    }

    fclose(fp);

    // Send the QUIT command
    char quit_cmd[BUFFER_SIZE];
    snprintf(quit_cmd, BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return 0;
}