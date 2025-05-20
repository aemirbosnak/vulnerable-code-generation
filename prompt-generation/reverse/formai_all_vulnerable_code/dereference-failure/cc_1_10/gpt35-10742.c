//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./pop3client [server IP] [port number]\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Read welcome message from server
    char buffer[MAXSIZE];
    if (read(sockfd, buffer, MAXSIZE) < 0) {
        perror("Error reading server response");
        return 1;
    }
    printf("%s", buffer);

    // Send user credentials
    char username[MAXSIZE], password[MAXSIZE];
    printf("Username: ");
    fgets(username, MAXSIZE, stdin);
    printf("Password: ");
    fgets(password, MAXSIZE, stdin);

    char auth_buffer[MAXSIZE];
    snprintf(auth_buffer, MAXSIZE, "USER %sPASS %s", username, password);
    if (send(sockfd, auth_buffer, strlen(auth_buffer), 0) < 0) {
        perror("Error sending user credentials");
        return 1;
    }

    // Read server response
    if (read(sockfd, buffer, MAXSIZE) < 0) {
        perror("Error reading server response");
        return 1;
    }
    printf("%s\n", buffer);

    // Close connection
    if (send(sockfd, "QUIT", 4, 0) < 0) {
        perror("Error sending QUIT message");
    }
    close(sockfd);

    return 0;
}