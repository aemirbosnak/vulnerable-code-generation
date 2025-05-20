//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int server_socket_fd, client_socket_fd, proxy_socket_fd;
struct sockaddr_in server_addr, client_addr, proxy_addr;
socklen_t addr_len;

void *handle_client(void *args)
{
    int *client_fd = (int *)args;
    char recv_buf[1024], send_buf[1024];
    int recv_len, send_len;

    while (1)
    {
        recv_len = recv(*client_fd, recv_buf, sizeof(recv_buf), 0);
        if (recv_len <= 0)
        {
            close(*client_fd);
            pthread_detach(pthread_self());
        }

        send(proxy_socket_fd, recv_buf, recv_len, 0);
    }
}

void *handle_proxy(void *args)
{
    char recv_buf[1024], send_buf[1024];
    int recv_len, send_len;

    while (1)
    {
        recv_len = recv(proxy_socket_fd, recv_buf, sizeof(recv_buf), 0);
        if (recv_len <= 0)
        {
            close(proxy_socket_fd);
            close(client_socket_fd);
            pthread_detach(pthread_self());
        }

        send(client_socket_fd, recv_buf, recv_len, 0);
    }
}

int main(int argc, char **argv)
{
    if (argc != 5)
    {
        printf("Usage: %s <server_ip> <server_port> <proxy_ip> <proxy_port>\n", argv[0]);
        return -1;
    }

    int server_port = atoi(argv[2]);
    int proxy_port = atoi(argv[4]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(server_port);

    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = 0;

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = inet_addr(argv[3]);
    proxy_addr.sin_port = htons(proxy_port);

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    proxy_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    bind(client_socket_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));

    connect(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    connect(proxy_socket_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));

    pthread_t client_thread, proxy_thread;
    pthread_create(&client_thread, NULL, handle_client, &client_socket_fd);
    pthread_create(&proxy_thread, NULL, handle_proxy, NULL);

    pthread_join(client_thread, NULL);
    pthread_join(proxy_thread, NULL);

    close(server_socket_fd);
    close(client_socket_fd);
    close(proxy_socket_fd);

    return 0;
}