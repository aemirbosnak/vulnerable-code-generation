//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <sys/resource.h>

#define MAX_PACKETS 1000
#define SLEEP_TIME 1

int main(int argc, char *argv[]) {
    int sockfd, bytes_recv, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_PACKETS];
    struct timeval tv;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: %s is an invalid hostname\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting to server\n");
        exit(1);
    }

    while (1) {
        tv.tv_sec = SLEEP_TIME;
        tv.tv_usec = 0;

        bytes_recv = recv(sockfd, buffer, MAX_PACKETS, 0);
        if (bytes_recv < 0) {
            fprintf(stderr, "ERROR receiving data\n");
            exit(1);
        }

        printf("Received: %s\n", buffer);
        fflush(stdout);

        sleep(1);
    }

    close(sockfd);
    return 0;
}