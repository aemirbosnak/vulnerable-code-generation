//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10

// Client structure
struct client {
    int sockfd;
    char name[BUF_SIZE];
    char email[BUF_SIZE];
};

// Server structure
struct server {
    int sockfd;
    struct sockaddr_in addr;
    int num_clients;
    struct client clients[MAX_CLIENTS];
};

// Function to create a server
struct server *create_server(int port) {
    struct server *server = malloc(sizeof(struct server));
    if (server == NULL) {
        perror("malloc");
        return NULL;
    }

    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd < 0) {
        perror("socket");
        free(server);
        return NULL;
    }

    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(port);

    if (bind(server->sockfd, (struct sockaddr *)&server->addr, sizeof(server->addr)) < 0) {
        perror("bind");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    if (listen(server->sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server->sockfd);
        free(server);
        return NULL;
    }

    server->num_clients = 0;

    return server;
}

// Function to accept a client connection
int accept_client(struct server *server) {
    int newsockfd;
    struct sockaddr_in cliaddr;
    socklen_t clilen;

    clilen = sizeof(cliaddr);
    newsockfd = accept(server->sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        return -1;
    }

    if (server->num_clients >= MAX_CLIENTS) {
        close(newsockfd);
        return -1;
    }

    struct client *client = &server->clients[server->num_clients++];
    client->sockfd = newsockfd;
    strcpy(client->name, "Anonymous");
    strcpy(client->email, "none");

    return newsockfd;
}

// Function to handle a client
void handle_client(struct server *server, int sockfd) {
    char buf[BUF_SIZE];
    int n;

    while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
        buf[n] = '\0';

        // Parse the command
        char *command = strtok(buf, " ");
        if (strcmp(command, "NAME") == 0) {
            // Set the client's name
            char *name = strtok(NULL, " ");
            if (name != NULL) {
                strcpy(server->clients[sockfd].name, name);
            }
        } else if (strcmp(command, "EMAIL") == 0) {
            // Set the client's email
            char *email = strtok(NULL, " ");
            if (email != NULL) {
                strcpy(server->clients[sockfd].email, email);
            }
        } else if (strcmp(command, "SEND") == 0) {
            // Send a message to another client
            char *recipient = strtok(NULL, " ");
            char *message = strtok(NULL, "\n");
            if (recipient != NULL && message != NULL) {
                int recipient_sockfd = -1;
                for (int i = 0; i < server->num_clients; i++) {
                    if (strcmp(server->clients[i].name, recipient) == 0) {
                        recipient_sockfd = server->clients[i].sockfd;
                        break;
                    }
                }

                if (recipient_sockfd != -1) {
                    sprintf(buf, "%s: %s\n", server->clients[sockfd].name, message);
                    write(recipient_sockfd, buf, strlen(buf));
                }
            }
        } else if (strcmp(command, "QUIT") == 0) {
            // Close the client's connection
            close(sockfd);
            server->num_clients--;
            break;
        }
    }

    if (n < 0) {
        perror("read");
    }
}

// Function to run the server
void run_server(struct server *server) {
    fd_set readfds;

    while (1) {
        // Initialize the file descriptor set
        FD_ZERO(&readfds);
        FD_SET(server->sockfd, &readfds);

        // Add the client sockets to the file descriptor set
        for (int i = 0; i < server->num_clients; i++) {
            FD_SET(server->clients[i].sockfd, &readfds);
        }

        // Wait for activity on any of the sockets
        int maxfd = server->sockfd;
        for (int i = 0; i < server->num_clients; i++) {
            if (server->clients[i].sockfd > maxfd) {
                maxfd = server->clients[i].sockfd;
            }
        }

        int activity = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("select");
            break;
        }

        // Check if there is activity on the server socket
        if (FD_ISSET(server->sockfd, &readfds)) {
            accept_client(server);
        }

        // Check if there is activity on any of the client sockets
        for (int i = 0; i < server->num_clients; i++) {
            if (FD_ISSET(server->clients[i].sockfd, &readfds)) {
                handle_client(server, server->clients[i].sockfd);
            }
        }
    }
}

// Main function
int main(int argc, char **argv) {
    int port;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    port = atoi(argv[1]);

    struct server *server = create_server(port);
    if (server == NULL) {
        return EXIT_FAILURE;
    }

    run_server(server);

    close(server->sockfd);
    free(server);

    return EXIT_SUCCESS;
}