//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(1);
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&address.sin_addr.s_addr, server->h_length);
    address.sin_port = htons(atoi(argv[2]));

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket creation failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error: connection failed");
        exit(1);
    }

    char message[256];
    if (argc == 4 && strcmp(argv[3], "-s") == 0) {
        printf("Server: ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);
    } else {
        printf("Client: ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);
        int n = recv(sockfd, message, sizeof(message), 0);
        if (n > 0) {
            printf("Server: %s\n", message);
        } else if (n == 0) {
            printf("Server: Connection closed\n");
        } else {
            perror("Error: receive failed");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}