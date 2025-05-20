//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char *hostname = "www.example.com";
    int port = 80;
    int timeout = 5;
    int interval = 1;
    int max_attempts = timeout * interval;
    int attempts = 0;
    time_t start_time, end_time;

    printf("Starting ping test to %s:%d\n", hostname, port);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1)
    {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    start_time = time(NULL);
    while (attempts < max_attempts)
    {
        send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);
        attempts++;

        ret = recv(sockfd, NULL, 0, MSG_PEEK);
        if (ret == -1)
        {
            printf("Error receiving data: %s\n", strerror(errno));
            exit(1);
        }
        else if (ret == 0)
        {
            printf("Server not responding\n");
            exit(1);
        }
        else
        {
            printf("Response received\n");
        }

        end_time = time(NULL);
        if (end_time - start_time >= timeout)
        {
            printf("Timeout exceeded\n");
            exit(1);
        }

        usleep(interval * 1000);
    }

    close(sockfd);
    printf("Ping test completed successfully\n");

    return 0;
}