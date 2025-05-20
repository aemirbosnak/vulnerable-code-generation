//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    struct timeval start, end;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }

    gettimeofday(&start, NULL);
    for (int i = 0; i < 10; i++) {
        memset(buf, 0, BUFSIZE);
        strcpy(buf, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
        n = write(sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("Error: could not write to server");
            exit(1);
        }

        memset(buf, 0, BUFSIZE);
        n = read(sockfd, buf, BUFSIZE);
        if (n < 0) {
            perror("Error: could not read from server");
            exit(1);
        }
    }
    gettimeofday(&end, NULL);

    long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    double speed = (10 * BUFSIZE * 8) / (elapsed / 1000000.0);

    printf("Speed: %.2f Mbps\n", speed);
    close(sockfd);

    return 0;
}