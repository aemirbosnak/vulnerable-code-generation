//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 8080

void *sendData(void *arg) {
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in servaddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);

    connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    while (1) {
        printf("Enter data to send: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n == -1) {
            perror("Error writing to socket");
            exit(1);
        }
    }
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, sendData, NULL);
    pthread_join(thread, NULL);

    return 0;
}