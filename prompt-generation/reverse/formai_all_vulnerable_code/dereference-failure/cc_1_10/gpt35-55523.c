//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#define BUFF_SIZE 1024

void handle_request(int conn_fd);

int main(int argc, char **argv)
{
    int sockfd, conn_fd, port_number;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "Error: Can't open socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_number);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        fprintf(stderr, "Error: Can't bind socket\n");
        exit(1);
    }

    if (listen(sockfd, 1024) < 0)
    {
        fprintf(stderr, "Error: Can't listen on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", port_number);

    while (1)
    {
        conn_fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (conn_fd < 0)
        {
            fprintf(stderr, "Error: Can't accept client connection\n");
            exit(1);
        }
        handle_request(conn_fd);
        close(conn_fd);
    }

    close(sockfd);
    return 0;
}

void handle_request(int conn_fd)
{
    char buffer[BUFF_SIZE];
    int n, file_fd, buflen;
    char *fstr;
    static char* extensions [] = {"jpg", "jpeg", "png", "gif", "bmp", "ico", "html", "htm", "css", "js"};

    n = read(conn_fd, buffer, BUFF_SIZE - 1);
    buffer[n] = '\0';

    printf("%s", buffer);

    if (n < 0)
    {
        fprintf(stderr, "Error: Can't read request from socket\n");
        exit(1);
    }
    else if (n == 0)
    {
        return;
    }
    else
    {
        if (strncmp(buffer, "GET ", 4) && strncmp(buffer, "get ", 4))
        {
            fprintf(stderr, "Error: Only GET requests are supported\n");
            exit(1);
        }
        for (int i = 4; i < BUFF_SIZE; i++)
        {
            if (buffer[i] == ' ')
            {
                buffer[i] = '\0';
                break;
            }
        }
        if (!strcmp(&buffer[0], "GET /\0"))
        {
            strcpy(buffer, "GET /index.html");
        }

        buflen = strlen(buffer);
        fstr = (char *)0;

        for (int i = 0; extensions[i]; i++)
        {
            int len = strlen(extensions[i]);
            if (!strncmp(&buffer[buflen - len], extensions[i], len))
            {
                fstr = extensions[i];
                break;
            }
        }

        if (fstr)
        {
            file_fd = open(&buffer[5], O_RDONLY);
            if (file_fd != -1)
            {
                send(conn_fd, "HTTP/1.1 200 OK\r\n", 17, 0);
                send(conn_fd, "Server: SimpleWebServer\r\n\r\n", 28, 0);
                while ((n = read(file_fd, buffer, BUFF_SIZE)) > 0)
                {
                    send(conn_fd, buffer, n, 0);
                }
            }
        }
        else
        {
            send(conn_fd, "HTTP/1.1 404 Not Found\r\n", 24, 0);
            send(conn_fd, "Server: SimpleWebServer\r\n\r\n", 28, 0);
            send(conn_fd, "<html><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL was not found on this server.</p><hr><address>SimpleWebServer 1.0</address></body></html>\r\n", 165, 0);
        }
    }
}