//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define PORT 8080

struct timeval start, end;
int sockfd, n;
char buf[BUFSIZE];

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Could not resolve hostname: %s\n", argv[1]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        return 1;
    }

    gettimeofday(&start, NULL);

    while ((n = read(sockfd, buf, BUFSIZE)) > 0)
    {
        write(STDOUT_FILENO, buf, n);
    }
    if (n < 0)
    {
        perror("Error reading from server");
        return 1;
    }

    gettimeofday(&end, NULL);

    long long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    long long total_bytes = n;
    double kbps = (total_bytes * 8 * 1000) / (elapsed_time / 1000.0);

    printf("\nTotal bytes transferred: %lld\n", total_bytes);
    printf("Elapsed time: %lld microseconds\n", elapsed_time);
    printf("Bandwidth: %.2f Kbps\n", kbps);

    close(sockfd);
    return 0;
}