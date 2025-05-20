//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define DEFAULT_PORT 80
#define DEFAULT_HOST "google.com"
#define DEFAULT_TIMEOUT 10

int main(int argc, char *argv[]) {
    int sockfd, n, len;
    char buffer[1024];
    struct sockaddr_in servaddr;
    struct hostent *host;
    struct timeval start, end;
    double time_taken;

    if (argc < 2) {
        printf("Usage: %s <host> [<port>] [<timeout>]\n", argv[0]);
        return 1;
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(argc > 2 ? atoi(argv[2]) : DEFAULT_PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    gettimeofday(&start, NULL);

    len = strlen("HEAD / HTTP/1.1\r\nHost: google.com\r\n\r\n");
    if (send(sockfd, "HEAD / HTTP/1.1\r\nHost: google.com\r\n\r\n", len, 0) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Do nothing with the received data
    }

    if (n == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    gettimeofday(&end, NULL);

    time_taken = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Speed: %.2f Mbps\n", (double)len / time_taken / 1024.0 * 8.0);

    close(sockfd);

    return 0;
}