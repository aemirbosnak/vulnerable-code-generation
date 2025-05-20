//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>

#define BUFFSIZE 4096

void handle_sigterm(int sig) {
    printf("Caught SIGTERM signal, exiting gracefully...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, valread;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFSIZE];
    int port;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    signal(SIGTERM, handle_sigterm);

    while (1) {
        valread = read(sockfd, buffer, BUFFSIZE);
        if (valread > 0) {
            printf("Received: %s\n", buffer);
        } else if (valread == 0) {
            printf("Disconnected from server\n");
            exit(1);
        } else {
            perror("ERROR reading from socket");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}