//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>

#define BUF_SIZE 4096

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <listen-port> <target-hostname>:<target-port>\n", argv[0]);
        exit(1);
    }

    int listen_port = atoi(argv[1]);
    char target_hostname[256], target_port[6];
    int ret = sscanf(argv[2], "%255[^:]:%5s", target_hostname, target_port);
    if (ret != 2)
    {
        printf("Invalid target address format: %s\n", argv[2]);
        exit(1);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *result;
    ret = getaddrinfo(target_hostname, target_port, &hints, &result);
    if (ret != 0)
    {
        printf("Failed to resolve target address: %s\n", gai_strerror(ret));
        exit(1);
    }

    int target_sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (target_sock < 0)
    {
        printf("Failed to create target socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = connect(target_sock, result->ai_addr, result->ai_addrlen);
    if (ret < 0)
    {
        printf("Failed to connect to target: %s\n", strerror(errno));
        exit(1);
    }

    int listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listen_sock < 0)
    {
        printf("Failed to create listen socket: %s\n", strerror(errno));
        exit(1);
    }

    int yes = 1;
    ret = setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    if (ret < 0)
    {
        printf("Failed to set socket option: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);

    ret = bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(listen_addr));
    if (ret < 0)
    {
        printf("Failed to bind listen socket: %s\n", strerror(errno));
        exit(1);
    }

    ret = listen(listen_sock, SOMAXCONN);
    if (ret < 0)
    {
        printf("Failed to listen on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Listening on port %d and forwarding to %s:%s\n", listen_port, target_hostname, target_port);

    char buf[BUF_SIZE];
    fd_set reads;
    while (1)
    {
        FD_ZERO(&reads);
        FD_SET(listen_sock, &reads);
        FD_SET(target_sock, &reads);

        int nfds = (listen_sock > target_sock ? listen_sock : target_sock) + 1;
        ret = select(nfds, &reads, NULL, NULL, NULL);
        if (ret < 0)
        {
            printf("Select failed: %s\n", strerror(errno));
            break;
        }

        if (FD_ISSET(listen_sock, &reads))
        {
            int client_sock = accept(listen_sock, NULL, NULL);
            if (client_sock < 0)
            {
                printf("Failed to accept client connection: %s\n", strerror(errno));
                break;
            }

            printf("Accepted client connection\n");

            while (1)
            {
                ret = recv(client_sock, buf, sizeof(buf), 0);
                if (ret <= 0)
                {
                    printf("Closing client connection\n");
                    close(client_sock);
                    break;
                }

                ret = send(target_sock, buf, ret, 0);
                if (ret <= 0)
                {
                    printf("Closing target connection\n");
                    close(target_sock);
                    break;
                }
            }
        }

        if (FD_ISSET(target_sock, &reads))
        {
            ret = recv(target_sock, buf, sizeof(buf), 0);
            if (ret <= 0)
            {
                printf("Closing target connection\n");
                close(target_sock);
                break;
            }

            ret = send(listen_sock, buf, ret, 0);
            if (ret <= 0)
            {
                printf("Closing client connection\n");
                close(listen_sock);
                break;
            }
        }
    }

    close(listen_sock);
    close(target_sock);

    return 0;
}