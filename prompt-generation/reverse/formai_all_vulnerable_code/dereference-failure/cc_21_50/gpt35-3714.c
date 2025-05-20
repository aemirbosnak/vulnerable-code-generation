//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in proxy_addr = {0};
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[1]));
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(proxy_fd, 10) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        int client_fd = accept(proxy_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE] = {0};
        if (recv(client_fd, buffer, BUFFER_SIZE, MSG_PEEK) < 0) {
            perror("recv");
            close(client_fd);
            continue;
        }

        char *method = strtok(buffer, " ");
        char *url = strtok(NULL, " ");

        if (strncmp(method, "CONNECT", 7) == 0) {
            // HTTPS request
            char *hostname = strtok(url, ":");
            char *port_str = strtok(NULL, ":");
            int port = atoi(port_str);

            struct hostent *server = gethostbyname(hostname);
            if (server == NULL) {
                perror("gethostbyname");
                close(client_fd);
                continue;
            }

            int server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd < 0) {
                perror("socket");
                close(client_fd);
                continue;
            }

            struct sockaddr_in server_addr = {0};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(port);
            memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

            if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
                perror("connect");
                close(client_fd);
                close(server_fd);
                continue;
            }

            char success[] = "HTTP/1.1 200 Connection established\r\n\r\n";
            if (send(client_fd, success, strlen(success), 0) < 0) {
                perror("send");
                close(client_fd);
                close(server_fd);
                continue;
            }

            fd_set descriptor_set;
            FD_ZERO(&descriptor_set);
            FD_SET(client_fd, &descriptor_set);
            FD_SET(server_fd, &descriptor_set);

            while (1) {
                if (select(FD_SETSIZE, &descriptor_set, NULL, NULL, NULL) < 0) {
                    perror("select");
                    break;
                }

                if (FD_ISSET(client_fd, &descriptor_set)) {
                    int bytes_read = recv(client_fd, buffer, BUFFER_SIZE, 0);
                    if (bytes_read < 0) {
                        perror("recv");
                        break;
                    } else if (bytes_read == 0) {
                        break;
                    }

                    if (send(server_fd, buffer, bytes_read, 0) < 0) {
                        perror("send");
                        break;
                    }
                }

                if (FD_ISSET(server_fd, &descriptor_set)) {
                    int bytes_read = recv(server_fd, buffer, BUFFER_SIZE, 0);
                    if (bytes_read < 0) {
                        perror("recv");
                        break;
                    } else if (bytes_read == 0) {
                        break;
                    }

                    if (send(client_fd, buffer, bytes_read, 0) < 0) {
                        perror("send");
                        break;
                    }
                }
            }

            close(server_fd);
        } else {
            // HTTP request
            char *hostname = strstr(url, "//");
            if (hostname == NULL) {
                hostname = url;
            } else {
                hostname += 2;
            }

            char *path = strchr(hostname, '/');
            if (path == NULL) {
                path = "/";
            } else {
                *path = '\0';
                path++;
            }

            struct hostent *server = gethostbyname(hostname);
            if (server == NULL) {
                perror("gethostbyname");
                close(client_fd);
                continue;
            }

            int server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd < 0) {
                perror("socket");
                close(client_fd);
                continue;
            }

            struct sockaddr_in server_addr = {0};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(80);
            memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

            if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
                perror("connect");
                close(client_fd);
                close(server_fd);
                continue;
            }

            snprintf(buffer, BUFFER_SIZE, "%s %s HTTP/1.1\r\n", method, path);

            while (1) {
                int bytes_read = recv(client_fd, buffer + strlen(buffer), BUFFER_SIZE - strlen(buffer), 0);
                if (bytes_read < 0) {
                    perror("recv");
                    close(client_fd);
                    close(server_fd);
                    break;
                } else if (bytes_read == 0) {
                    break;
                }

                if (send(server_fd, buffer + strlen(buffer) - bytes_read, bytes_read, 0) < 0) {
                    perror("send");
                    close(client_fd);
                    close(server_fd);
                    break;
                }

                if (strstr(buffer, "\r\n\r\n") != NULL) {
                    break;
                }
            }

            while (1) {
                int bytes_read = recv(server_fd, buffer, BUFFER_SIZE, 0);
                if (bytes_read < 0) {
                    perror("recv");
                    close(client_fd);
                    close(server_fd);
                    break;
                } else if (bytes_read == 0) {
                    break;
                }

                if (send(client_fd, buffer, bytes_read, 0) < 0) {
                    perror("send");
                    close(client_fd);
                    close(server_fd);
                    break;
                }
            }

            close(server_fd);
        }

        close(client_fd);
    }

    return EXIT_SUCCESS;
}