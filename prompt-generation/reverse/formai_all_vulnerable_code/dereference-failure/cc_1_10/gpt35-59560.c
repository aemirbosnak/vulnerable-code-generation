//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 65536

void handle_client(int client_fd, struct sockaddr_in client_addr) {
    char buffer[BUFFER_SIZE], url[BUFFER_SIZE], method[BUFFER_SIZE];
    int n;
    bzero(buffer, BUFFER_SIZE);
    n = read(client_fd, buffer, BUFFER_SIZE - 1);
    if (n <= 0) {
        printf("Fail to receive request from client!\n");
        exit(1);
    }
    sscanf(buffer, "%s %s", method, url);
    if (strcasecmp(method, "CONNECT") == 0) {
        // CONNECT method, use SSL port
        char *host = strtok(url, ":");
        char *port_str = strtok(NULL, ":");
        int port = atoi(port_str);
        printf("HTTPS tunnel to %s %d\n", host, port);
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        struct hostent *server = gethostbyname(host);
        if (server == NULL) {
            printf("Fail to get server by name!\n");
            exit(1);
        }
        struct sockaddr_in server_addr;
        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);        
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

        if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Fail to connect to server!\n");
            exit(1);
        }

        char *ok_reply = "HTTP/1.0 200 Connection established\r\nProxy-agent: simple-http-proxy\r\n\r\n";
        write(client_fd, ok_reply, strlen(ok_reply));
      
        fd_set fd_in;
        int maxfd = (client_fd > server_fd) ? client_fd : server_fd;
        while (1) {
            FD_ZERO(&fd_in);
            FD_SET(client_fd, &fd_in);
            FD_SET(server_fd, &fd_in);
            select(maxfd + 1, &fd_in, NULL, NULL, NULL);
            if (FD_ISSET(client_fd, &fd_in)) {
                bzero(buffer, BUFFER_SIZE);
                n = read(client_fd, buffer, BUFFER_SIZE - 1);
                if (n <= 0) {
                    printf("Fail to receive request from client!\n");
                    exit(1);
                }
                write(server_fd, buffer, n);
            }
            if (FD_ISSET(server_fd, &fd_in)) {
                bzero(buffer, BUFFER_SIZE);
                n = read(server_fd, buffer, BUFFER_SIZE - 1);
                if (n <= 0) {
                    printf("Fail to receive response from server!\n");
                    exit(1);
                }
                write(client_fd, buffer, n);
            }
        }

    } else {
        // non-CONNECT method, use port 80
        printf("%s\n", buffer);
        char *host = strtok(url, "/");
        char *path = strtok(NULL, "/");
        int server_fd = socket(AF_INET, SOCK_STREAM, 0);
        struct hostent *server = gethostbyname(host);
        if (server == NULL) {
            printf("Fail to get server by name!\n");
            exit(1);
        }
        struct sockaddr_in server_addr;
        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);        
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
        if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Fail to connect to server!\n");
            exit(1);
        }

        write(server_fd, buffer, strlen(buffer));
      
        bzero(buffer, BUFFER_SIZE);
        int len = 0;
        while (1) {
            n = read(server_fd, buffer + len, BUFFER_SIZE - len - 1);
            if (n <= 0) {
                break;
            }
            len += n;
            if (len >= BUFFER_SIZE - 1) {
                break;
            }
        }
        if (len == 0) {
            printf("Fail to receive response from server!\n");
            exit(1);
        }
        write(client_fd, buffer, len);
    }
    close(client_fd);
    printf("Connection to client closed!\n");
}

void start_server(int port) {
    int server_fd, client_fd;
    socklen_t client_len;
    struct sockaddr_in server_addr, client_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Fail to create socket!\n");
        exit(1);
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Fail to bind socket!\n");
        exit(1);
    }

    if (listen(server_fd, 10) < 0) {
        printf("Fail to listen on socket!\n");
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);        
        if (client_fd < 0) {
            printf("Fail to accept client!\n");
            continue;
        }
        handle_client(client_fd, client_addr);
    }
}

int main(int argc, char *argv[]) {
    int port = 8888;
    if (argc > 1) {
        port = atoi(argv[1]);
        if (port <= 0) {
            printf("Invalid port number!\n");
            exit(1);
        }
    }
    start_server(port);
    return 0;
}