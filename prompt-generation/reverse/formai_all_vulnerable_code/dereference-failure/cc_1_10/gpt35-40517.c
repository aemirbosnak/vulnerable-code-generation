//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/signal.h>
#include <sys/types.h>

#define MAX_PENDING_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

volatile bool stop_server = false;

void signal_handler(int sig_num) {
    if(sig_num == SIGINT) {
        stop_server = true;
    }
}

int make_non_blocking(int socket_fd) {
    int flags = fcntl(socket_fd, F_GETFL, 0);
    if(flags == -1) {
        return -1;
    } 
    if(fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        return -1;
    }
    return 0;
}

int create_tcp_listener(const char* port) {
    struct addrinfo hints, *servinfo, *p;
    int status, listener;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if((status = getaddrinfo(NULL, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    for(p = servinfo; p != NULL; p = p->ai_next) {
        if((listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if(bind(listener, p->ai_addr, p->ai_addrlen) == -1) {
            close(listener);
            continue;
        }
        break;
    }

    if(p == NULL) {
        fprintf(stderr, "Failed to bind!\n");
        exit(EXIT_FAILURE);
    }

    if(listen(listener, MAX_PENDING_CONNECTIONS) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);
    return listener;
}

typedef struct {
    int fd;
    bool reading;
    int bytes_read;
    char buffer[MAX_BUFFER_SIZE];
} client_connexion_t;

client_connexion_t* create_client_connexion(int client_fd) {
    client_connexion_t* client_connexion = (client_connexion_t*) malloc(sizeof(client_connexion_t));
    client_connexion->fd = client_fd;
    client_connexion->reading = true;
    client_connexion->bytes_read = 0;
    memset(&client_connexion->buffer, 0, MAX_BUFFER_SIZE);

    return client_connexion;
}

void destroy_client_connexion(client_connexion_t* client_connexion) {
    close(client_connexion->fd);
    free(client_connexion);
}

void read_data_from_client(client_connexion_t* client_connexion) {
    int bytes_read;
    bytes_read = recv(client_connexion->fd, client_connexion->buffer + client_connexion->bytes_read, MAX_BUFFER_SIZE - client_connexion->bytes_read, 0);

    if (bytes_read == -1) {
        if (errno != EAGAIN) {
            perror("recv failed");
            client_connexion->reading = false;
        }
    } else if (bytes_read == 0) {
        client_connexion->reading = false;
    } else {
        client_connexion->bytes_read += bytes_read;

        // Do some processing on the data
        printf("Received from client: \"%s\"\n", client_connexion->buffer);

        // Clear the buffer for the next read
        memset(&client_connexion->buffer, 0, MAX_BUFFER_SIZE);

        // Set to reading to true to read data from the client again
        client_connexion->reading = true;
    }
}

void write_data_to_client(client_connexion_t* client_connexion) {
    int bytes_sent = send(client_connexion->fd, "ACK", 3, 0);

    if (bytes_sent <= 0) {
        if (errno != EAGAIN) {
            perror("send failed");
            client_connexion->reading = false;
        }
    } else {
        client_connexion->bytes_read = 0;
        client_connexion->reading = true;
    }
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sigaction action;
    action.sa_handler = signal_handler;

    sigaction(SIGINT, &action, NULL);

    int listener = create_tcp_listener(argv[1]);
    make_non_blocking(listener);

    printf("Server is listening on port %s\n", argv[1]);

    fd_set read_set;
    fd_set write_set;
    FD_ZERO(&read_set);
    FD_SET(listener, &read_set);

    while(!stop_server) {
        int num_ready_fds = select(FD_SETSIZE, &read_set, &write_set, NULL, NULL);

        if(num_ready_fds <= 0) {
            continue;
        }

        for(int fd = 0; fd < FD_SETSIZE; fd++) {
            if(stop_server) {
                break;
            }

            if(FD_ISSET(fd, &read_set)) {
                // New connection
                if(fd == listener) {
                    struct sockaddr_storage client_addr;
                    socklen_t addr_len = sizeof client_addr;

                    int client_fd = accept(listener, (struct sockaddr*) &client_addr, &addr_len);

                    if(client_fd == -1) {
                        perror("accept failed");
                    } else {
                        printf("New client connected to the server\n");
                        make_non_blocking(client_fd);
                        FD_SET(client_fd, &read_set);

                        client_connexion_t* client_connexion = create_client_connexion(client_fd);
                        FD_SET(client_connexion->fd, &write_set);
                    }
                } else {
                    client_connexion_t* client_connexion = (client_connexion_t*) malloc(sizeof(client_connexion_t));
                    client_connexion->fd = fd;
                    read_data_from_client(client_connexion);

                    if(client_connexion->reading) {
                        FD_SET(client_connexion->fd, &write_set);
                    } else {
                        FD_CLR(client_connexion->fd, &read_set);
                        destroy_client_connexion(client_connexion);
                    }
                }
            } else if (FD_ISSET(fd, &write_set)) {
                client_connexion_t* client_connexion = (client_connexion_t*) malloc(sizeof(client_connexion_t));
                client_connexion->fd = fd;
                write_data_to_client(client_connexion);

                if(client_connexion->reading) {
                    FD_SET(client_connexion->fd, &read_set);
                } else {
                    FD_CLR(client_connexion->fd, &write_set);
                    destroy_client_connexion(client_connexion);
                }
            }
        }
    }

    printf("Server shutting down ...\n");

    close(listener);
    exit(EXIT_SUCCESS);
}