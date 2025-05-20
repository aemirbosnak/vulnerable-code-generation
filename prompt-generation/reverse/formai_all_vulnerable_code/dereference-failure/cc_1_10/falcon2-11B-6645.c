//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd, valread;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int num = rand() % 100;
        sprintf(buffer, "Number: %d\n", num);
        valread = write(sockfd, buffer, strlen(buffer));
        if (valread < 0) {
            perror("Error writing to socket");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
    return 0;
}