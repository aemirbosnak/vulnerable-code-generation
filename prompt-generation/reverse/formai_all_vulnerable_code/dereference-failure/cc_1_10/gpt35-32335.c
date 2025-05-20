//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HTTP_REQUEST_SIZE 2048
#define MAX_HOSTNAME_SIZE 256
#define MAX_PATH_SIZE 1024
#define MAX_RESPONSE_SIZE 8192

int http_get(char *hostname, char *path)
{
    int sock;
    struct sockaddr_in server;
    char request[MAX_HTTP_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    struct hostent *he;
    
    if ((he = gethostbyname(hostname)) == NULL)
    {
        perror("gethostbyname");
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server.sin_zero), 0, 8);

    if (connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
    {
        perror("connect");
        return 1;
    }

    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    if (send(sock, request, strlen(request), 0) == -1)
    {
        perror("send");
        return 1;
    }

    int total_bytes_read = 0;
    while (1)
    {
        int num_bytes_read = recv(sock, response + total_bytes_read, MAX_RESPONSE_SIZE - total_bytes_read, 0);
        if (num_bytes_read == -1)
        {
            perror("recv");
            return 1;
        }
        else if (num_bytes_read == 0)
        {
            break;
        }
        else
        {
            total_bytes_read += num_bytes_read;
            if (total_bytes_read >= MAX_RESPONSE_SIZE)
            {
                fprintf(stderr, "Response too large\n");
                return 1;
            }
        }
    }

    response[total_bytes_read] = '\0';
    printf("%s\n", response);

    close(sock);
    return 0;
}

int main()
{
    char hostname[MAX_HOSTNAME_SIZE];
    char path[MAX_PATH_SIZE];

    printf("Enter hostname: ");
    if (fgets(hostname, MAX_HOSTNAME_SIZE, stdin) == NULL)
    {
        perror("fgets");
        return 1;
    }
    strtok(hostname, "\r\n");

    printf("Enter path: ");
    if (fgets(path, MAX_PATH_SIZE, stdin) == NULL)
    {
        perror("fgets");
        return 1;
    }
    strtok(path, "\r\n");

    if (http_get(hostname, path) == 1)
    {
        fprintf(stderr, "Error retrieving data from host\n");
        return 1;
    }

    return 0;
}