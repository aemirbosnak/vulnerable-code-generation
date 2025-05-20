//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"
#define TIME_OUT 5

int main(int argc, char *argv[])
{
    int sockfd, bytes_read;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int start_time, end_time, elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL)
    {
        printf("Error: Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: Could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    start_time = time(NULL);
    bytes_read = 0;
    while ((bytes_read < BUFFER_SIZE) && (difftime(time(NULL), start_time) < TIME_OUT))
    {
        bytes_read += recv(sockfd, buffer + bytes_read, BUFFER_SIZE - bytes_read, 0);
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)bytes_read / elapsed_time;

    printf("Internet Speed Test\n");
    printf("Server: %s\n", SERVER_ADDRESS);
    printf("Port: %d\n", SERVER_PORT);
    printf("Elapsed Time: %d seconds\n", (int)elapsed_time);
    printf("Download Speed: %.2f Mbps\n", speed / (1024 * 1024));

    close(sockfd);
    return 0;
}