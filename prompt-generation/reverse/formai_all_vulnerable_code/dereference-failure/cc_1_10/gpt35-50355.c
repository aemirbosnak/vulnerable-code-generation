//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if(server == NULL) {
        perror("Error: no such host");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server -> h_addr, server -> h_length);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("Enter command: ");
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 1024, stdin);

        if(strcmp(buffer, "exit\n") == 0) {
            break;
        }

        if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending command");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, sizeof(buffer));

        if(recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
            perror("Error receiving response");
            exit(EXIT_FAILURE);
        }

        printf("Response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}