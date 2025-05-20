//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

#define BUFFER_SIZE 255

char *http_request = "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n";

/* Function that creates a HTTP request and sends it to the server using a socket. */
int http_get_request(const char *url, const char *host, char **response)
{
    struct addrinfo hints, *res;
    char request[BUFFER_SIZE];
    int socket_fd, request_len, total_len, bytes_sent, bytes_received;
    char buffer[BUFFER_SIZE], *tmp;

    /* Create the address structure */
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, "80", &hints, &res) != 0)
    {
        perror("getaddrinfo");
        return -1;
    }

    /* Create the socket */
    socket_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    if (socket_fd == -1)
    {
        perror("socket");
        return -1;
    }

    /* Connect to the server */
    if (connect(socket_fd, res->ai_addr, res->ai_addrlen) == -1)
    {
        perror("connect");
        return -1;
    }

    /* Build the HTTP request */
    request_len = snprintf(request, BUFFER_SIZE, http_request, url, host);

    /* Send the HTTP request */
    total_len = 0;

    while (total_len < request_len)
    {
        bytes_sent = send(socket_fd, request + total_len, request_len - total_len, 0);

        if (bytes_sent == -1)
        {
            perror("send");
            close(socket_fd);
            return -1;
        }

        total_len += bytes_sent;
    }

    /* Receive the HTTP response */
    *response = NULL;
    total_len = 0;

    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0)) > 0)
    {
        buffer[bytes_received] = '\0';

        if (*response == NULL)
        {
            *response = strdup(buffer);
        }
        else
        {
            tmp = realloc(*response, total_len + strlen(buffer) + 1);

            if (tmp == NULL)
            {
                perror("realloc");
                free(*response);
                close(socket_fd);
                return -1;
            }

            *response = tmp;
            strcat(*response, buffer);
        }

        total_len += bytes_received;
    }

    if (bytes_received == -1)
    {
        perror("recv");
        close(socket_fd);
        return -1;
    }

    /* Close the socket */
    close(socket_fd);

    return 1;
}

int main()
{
    char *response = NULL;
    int status = http_get_request("/", "www.google.com", &response);

    if (status == -1)
    {
        printf("Error performing HTTP request.\n");
        return -1;
    }

    printf("%s\n", response);

    free(response);

    return 0;
}