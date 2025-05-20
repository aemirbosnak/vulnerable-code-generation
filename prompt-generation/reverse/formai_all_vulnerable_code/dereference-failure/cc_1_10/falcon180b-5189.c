//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr, "No such host: %s\n", SERVER_IP);
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive data from server
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        // Print received data
        printf("Received data: %s\n", buffer);

        // Send data to server
        sprintf(buffer, "QoS monitor: %d", rand() % 10);
        ret = send(sockfd, buffer, strlen(buffer), 0);
        if (ret == -1) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
    return 0;
}