//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    struct timeval start, end;
    struct hostent *server;
    struct sockaddr_in addr;
    int sockfd, n;
    char *filename = "test.txt";

    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, server->h_addr, server->h_length);
    addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting");
        return 1;
    }

    gettimeofday(&start, NULL);

    n = send(sockfd, filename, strlen(filename), 0);
    if (n < 0) {
        perror("Error sending filename");
        return 1;
    }

    gettimeofday(&end, NULL);

    long duration = (end.tv_sec - start.tv_sec) * 1000000LL + end.tv_usec - start.tv_usec;

    double speed = (double)n / duration * 8 / 1000000;
    printf("Download speed: %.2f Mbps\n", speed);

    close(sockfd);
    return 0;
}