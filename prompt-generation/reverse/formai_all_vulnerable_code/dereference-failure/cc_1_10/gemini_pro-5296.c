//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void printUsage() {
    printf("\nUsage: ./internet-speed-test [server address]\n\n");
}

int main(int argc, char **argv) {
    struct hostent *host;
    struct sockaddr_in server;
    int sockfd;
    char buf[BUFSIZE];
    char *serverAddress = "google.com";

    if (argc > 2) {
        printUsage();
        return EXIT_FAILURE;
    } else if (argc == 2) {
        serverAddress = argv[1];
    }

    host = gethostbyname(serverAddress);
    if (host == NULL) {
        printf("Invalid server address '%s'\n", serverAddress);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    struct timeval start;
    gettimeofday(&start, NULL);

    write(sockfd, "GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n"));

    int bytesRead = 0;
    while ((bytesRead = read(sockfd, buf, BUFSIZE)) > 0) {
        // Do nothing
    }

    struct timeval end;
    gettimeofday(&end, NULL);

    double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    close(sockfd);

    if (bytesRead == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    double speed = bytesRead / 1024.0 / 1024.0 / elapsedTime;

    printf("\nInternet speed: %.2f Mbps\n\n", speed);

    return EXIT_SUCCESS;
}