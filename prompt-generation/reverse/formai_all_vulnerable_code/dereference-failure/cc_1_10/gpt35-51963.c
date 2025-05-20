//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE], server_reply[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host as %s\n", argv[1]);
        return 1;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("ftp> ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE - 1, stdin);

        if (strcmp("quit\n", buffer) == 0) {
            printf("Quitting...\n");
            break;
        }

        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            perror("Error writing to server");
            return 1;
        }

        printf("Sent: %s\n", buffer);

        if (read(sockfd, server_reply, BUFFER_SIZE) < 0) {
            perror("Error reading from server");
            return 1;
        }

        printf("Received: %s\n", server_reply);
    }

    close(sockfd);
    printf("Connection closed\n");

    return 0;
}