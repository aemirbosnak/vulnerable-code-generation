//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096
#define MAXSIZE 1024

struct config {
    char address[MAXSIZE];
    int port;
};

struct proxy {
    int client_fd;
    int server_fd;
};

int get_config(const char *file, struct config *config) {
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Cannot open configuration file\n");
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "address") != NULL) {
            sscanf(line, "address=%s", config->address);
        }
        else if (strstr(line, "port") != NULL) {
            sscanf(line, "port=%d", &config->port);
        }
    }

    fclose(fp);

    if (line)
        free(line);

    return 0;
}

int handle_client_request(int client_fd, int server_fd) {
    char message[MAXLINE];
    int message_length;

    if ((message_length = recv(client_fd, message, MAXLINE, 0)) == -1) {
        printf("Error: Failed to Receive Message from Client\n");
        return -1;
    }

    if (send(server_fd, message, message_length, 0) == -1) {
        printf("Error: Failed to Forward Message to Server\n");
        return -1;
    }

    return 0;
}

int handle_server_response(int server_fd, int client_fd) {
    char message[MAXLINE];
    int message_length;

    if ((message_length = recv(server_fd, message, MAXLINE, 0)) == -1) {
        printf("Error: Failed to Receive Message from Server\n");
        return -1;
    }

    if (send(client_fd, message, message_length, 0) == -1) {
        printf("Error: Failed to Forward Message to Client\n");
        return -1;
    }

    return 0;
}

int create_socket(const struct config *config) {
    struct sockaddr_in remote_address;
    struct hostent *remote_host;
    int socket_fd;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Error: Failed to Create Socket\n");
        return -1;
    }

    if (inet_pton(AF_INET, config->address, &remote_address.sin_addr) != 1) {
        remote_host = gethostbyname(config->address);

        if (remote_host == NULL) {
            printf("Error: Failed to Obtain Remote Host Address\n");
            return -1;
        }

        memcpy(&remote_address.sin_addr, remote_host->h_addr, remote_host->h_length);
    }

    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(config->port);

    if (connect(socket_fd, (struct sockaddr *)&remote_address, sizeof(remote_address)) == -1) {
        printf("Error: Failed to Connect to Server\n");
        return -1;
    }

    return socket_fd;
}

struct proxy create_proxy(int client_fd, const struct config *config) {
    struct proxy proxy;
    int server_fd;

    if ((server_fd = create_socket(config)) == -1) {
        proxy.client_fd = -1;
        proxy.server_fd = -1;
        return proxy;
    }

    proxy.client_fd = client_fd;
    proxy.server_fd = server_fd;

    return proxy;
}

int close_proxy(struct proxy *proxy) {
    close(proxy->client_fd);
    close(proxy->server_fd);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <config file>\n", argv[0]);
        return -1;
    }

    struct config config;

    if (get_config(argv[1], &config) == -1) {
        return -1;
    }

    int listen_fd, max_fd;
    fd_set readfds, allfds;
    struct proxy proxies[FD_SETSIZE];

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Failed to Create Socket\n");
        return -1;
    }

    struct sockaddr_in local_address;
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = htonl(INADDR_ANY);
    local_address.sin_port = htons(config.port);

    if (bind(listen_fd, (struct sockaddr *)&local_address, sizeof(local_address)) == -1) {
        printf("Error: Failed to Bind Socket\n");
        return -1;
    }

    if (listen(listen_fd, FD_SETSIZE) == -1) {
        printf("Error: Failed to Listen on Socket\n");
        return -1;
    }

    FD_ZERO(&allfds);
    FD_SET(listen_fd, &allfds);
    max_fd = listen_fd;

    while (1) {
        readfds = allfds;

        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1) {
            printf("Error: Failed to Select File Descriptors\n");
            return -1;
        }

        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &readfds)) {
                if (i == listen_fd) {
                    struct sockaddr_in client_address;
                    int client_fd, address_length;

                    address_length = sizeof(client_address);

                    if ((client_fd = accept(listen_fd, (struct sockaddr *)&client_address, &address_length)) == -1) {
                        printf("Error: Failed to Accept Connection from Client\n");
                    }
                    else {
                        FD_SET(client_fd, &allfds);

                        if (client_fd > max_fd) {
                            max_fd = client_fd;
                        }

                        struct proxy proxy = create_proxy(client_fd, &config);

                        if (proxy.client_fd == -1 || proxy.server_fd == -1) {
                            close_proxy(&proxy);
                            FD_CLR(client_fd, &allfds);
                        }
                        else {
                            proxies[client_fd] = proxy;
                        }
                    }
                }
                else {
                    struct proxy proxy = proxies[i];

                    if (handle_client_request(proxy.client_fd, proxy.server_fd) == -1) {
                        close_proxy(&proxy);
                        FD_CLR(i, &allfds);
                        proxies[i].client_fd = -1;
                        proxies[i].server_fd = -1;
                    }
                    else if (handle_server_response(proxy.server_fd, proxy.client_fd) == -1) {
                        close_proxy(&proxy);
                        FD_CLR(i, &allfds);
                        proxies[i].client_fd = -1;
                        proxies[i].server_fd = -1;
                    }
                }
            }
        }
    }

    return 0;
}