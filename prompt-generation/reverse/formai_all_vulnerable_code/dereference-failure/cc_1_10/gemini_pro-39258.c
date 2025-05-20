//GEMINI-pro DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", host);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: could not connect to server");
        return 1;
    }

    char buffer[256];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter a message to send to the server: ");
        fgets(buffer, sizeof(buffer), stdin);

        int n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("Error: could not send data to server");
            return 1;
        }

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("Error: could not receive data from server");
            return 1;
        }

        printf("Received from server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}