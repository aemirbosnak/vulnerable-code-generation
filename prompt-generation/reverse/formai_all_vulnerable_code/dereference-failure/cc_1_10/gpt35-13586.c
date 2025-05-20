//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

void error_handler(char *message); // function to handle errors
void proxy(int client_sock, char *server_ip, int server_port); // function to handle proxy requests

int main(int argc, char **argv)
{
    // check if enough arguments have been passed
    if(argc != 3)
    {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    // get server ip and port from command line arguments
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // create a socket for listening to client requests
    int listen_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_sock == -1)
        error_handler("Error: Failed to create listening socket.");

    // set up server socket address and bind the socket to it
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(8080);

    if(bind(listen_sock, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) == -1)
        error_handler("Error: Failed to bind listening socket to address.");

    // start listening for client requests
    if(listen(listen_sock, 10) == -1)
        error_handler("Error: Failed to start listening for client requests.");

    // accept client requests and fork a process to handle them
    while(1)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_len);

        if(client_sock == -1)
            error_handler("Error: Failed to accept client request.");

        pid_t pid = fork();

        if(pid == -1)
            error_handler("Error: Failed to fork.");

        if(pid == 0)
        {
            // proxy the request from the client
            close(listen_sock);
            proxy(client_sock, server_ip, server_port);
            close(client_sock);
            exit(0);
        }
        else
        {
            // close the client socket since it is being handled by the child process
            close(client_sock);
        }   
    }

    close(listen_sock);
    return 0;
}

void error_handler(char *message)
{
    perror(message);
    exit(1);
}

void proxy(int client_sock, char *server_ip, int server_port)
{
    // create a socket for communicating with the server
    int server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_sock == -1)
        error_handler("Error: Failed to create server socket.");

    // connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if(connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handler("Error: Failed to connect to server.");

    // forward the request from the client to the server
    char buf[BUF_SIZE];
    int bytes_read = recv(client_sock, buf, BUF_SIZE, 0);

    while(bytes_read > 0)
    {
        send(server_sock, buf, bytes_read, 0);
        bytes_read = recv(client_sock, buf, BUF_SIZE, 0);
    }

    // forward the response from the server to the client
    bytes_read = recv(server_sock, buf, BUF_SIZE, 0);

    while(bytes_read > 0)
    {
        send(client_sock, buf, bytes_read, 0);
        bytes_read = recv(server_sock, buf, BUF_SIZE, 0);
    }

    close(server_sock);
}