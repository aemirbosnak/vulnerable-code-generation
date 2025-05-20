//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) < 0) {
        error("Error parsing IP Address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    int n;
    while (1) {
        printf("Enter command: ");
        memset(buffer, 0, BUFFER_SIZE);

        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "QUIT", 4) == 0) {
            write(sockfd, buffer, strlen(buffer));
            break;
        }

        write(sockfd, buffer, strlen(buffer));

        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            error("Error reading from server");
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}