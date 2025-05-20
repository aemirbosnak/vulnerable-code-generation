//Falcon2-11B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server;
    struct hostent *server_addr;

    if ((server_addr = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Hostname not found\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char*)&server.sin_addr.s_addr, server_addr->h_addr, server_addr->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error: Failed to connect");
        exit(1);
    }

    char buf[1024];
    while (1) {
        printf("Enter message: ");
        fgets(buf, sizeof(buf), stdin);

        send(sockfd, buf, strlen(buf), 0);
        if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
            perror("Error: Failed to receive");
            exit(1);
        }

        printf("Received: %s\n", buf);
    }

    close(sockfd);
    return 0;
}