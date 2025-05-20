//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s host\n", argv[0]);
        return 1;
    }

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[MAX_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        int client_fd;

        client_fd = accept(sockfd, NULL, NULL);
        if (client_fd < 0) {
            perror("ERROR on accept");
            continue;
        }

        printf("Got a connection from: %s\n", inet_ntoa(serv_addr.sin_addr));
        bzero(buffer, MAX_SIZE);
        n = read(client_fd, buffer, MAX_SIZE);

        if (n < 0) {
            perror("ERROR reading from client");
            close(client_fd);
            continue;
        }

        printf("Message from client: %s\n", buffer);

        bzero(buffer, MAX_SIZE);
        sprintf(buffer, "Thank you for your message!");
        n = write(client_fd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to client");
            close(client_fd);
            continue;
        }

        printf("Message sent to client: %s\n", buffer);

        close(client_fd);
    }

    return 0;
}