//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
    int sockfd, valread;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    struct timeval start, end;
    double elapsed_time;
    char buffer[BUFSIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    gettimeofday(&start, NULL);

    while (1) {
        valread = read(sockfd, buffer, BUFSIZE);
        if (valread < 0) {
            perror("ERROR reading from socket");
            exit(1);
        } else if (valread == 0) {
            printf("Connection closed by peer\n");
            break;
        }

        gettimeofday(&end, NULL);
        elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        printf("Received %d bytes in %f seconds\n", valread, elapsed_time / 1000000.0);
    }

    close(sockfd);
    return 0;
}