//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: could not resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: could not connect to server");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFERSIZE];
    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send request");
        exit(EXIT_FAILURE);
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFERSIZE, 0)) > 0) {
        gettimeofday(&end, NULL);
    }

    if (bytes_received == -1) {
        perror("Error: could not receive response");
        exit(EXIT_FAILURE);
    }

    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Response time: %.2f ms\n", elapsed_time);

    close(sockfd);

    return EXIT_SUCCESS;
}