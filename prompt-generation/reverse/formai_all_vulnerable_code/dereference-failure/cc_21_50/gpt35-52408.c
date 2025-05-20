//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024
#define MAX_CLIENTS 50
#define BACKLOG 10

// A structure to hold client information
struct client_info {
    int sock_fd;
    char client_ip[INET_ADDRSTRLEN];
    int client_port;
    struct timeval last_active;
};

int main(int argc, char *argv[])
{
    // Check if server port was provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert port from string to integer
    int port = atoi(argv[1]);

    // Create a TCP socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt() error");
        exit(EXIT_FAILURE);
    }

    // Bind socket to the address and port specified
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, BACKLOG) == -1) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    // Create an array to hold client information
    struct client_info *clients = (struct client_info *)calloc(MAX_CLIENTS, sizeof(struct client_info));
    if (clients == NULL) {
        perror("calloc() error");
        exit(EXIT_FAILURE);
    }

    // Create an array of file descriptors to be monitored by select()
    fd_set read_fds;        // file descriptors ready to be read
    fd_set all_fds;         // all file descriptors
    int max_fd = server_fd; // maximum file descriptor number
    FD_ZERO(&all_fds);
    FD_SET(server_fd, &all_fds);

    // Start monitoring for incoming connections and client activity
    while (1) {
        // Check for activity on monitored file descriptors
        read_fds = all_fds; // copy all file descriptors
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select() error");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connections on server socket
        if (FD_ISSET(server_fd, &read_fds)) {
            // Accept incoming connection
            struct sockaddr_in client_addr = {0};
            socklen_t client_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
            if (client_fd == -1) {
                perror("accept() error");
                continue;
            }

            // Check if maximum number of clients reached
            int i;
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sock_fd == -1) {
                    break;
                }
            }
            if (i == MAX_CLIENTS) {
                fprintf(stderr, "Maximum number of clients reached\n");
                close(client_fd);
                continue;
            }

            // Add new client to client array and all file descriptors
            clients[i].sock_fd = client_fd;
            clients[i].client_port = ntohs(client_addr.sin_port);
            inet_ntop(AF_INET, &(client_addr.sin_addr), clients[i].client_ip, INET_ADDRSTRLEN);
            gettimeofday(&(clients[i].last_active), NULL);
            FD_SET(client_fd, &all_fds);
            if (client_fd > max_fd) {
                max_fd = client_fd;
            }

            // Send welcome message to new client
            char welcome_msg[MAX_MSG_LEN] = {0};
            snprintf(welcome_msg, MAX_MSG_LEN, "Welcome to the server, %s:%d!\n", clients[i].client_ip, clients[i].client_port);
            if (send(client_fd, welcome_msg, strlen(welcome_msg), 0) == -1) {
                perror("send() error");
                exit(EXIT_FAILURE);
            }
        }

        // Handle client activity
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock_fd == -1) {
                continue;
            }
            if (FD_ISSET(clients[i].sock_fd, &read_fds)) {
                // Receive message from client
                char msg[MAX_MSG_LEN] = {0};
                int msg_len = recv(clients[i].sock_fd, msg, MAX_MSG_LEN, 0);
                if (msg_len == -1) {
                    perror("recv() error");
                    exit(EXIT_FAILURE);
                } else if (msg_len == 0) {
                    // Client disconnected
                    printf("%s:%d disconnected\n", clients[i].client_ip, clients[i].client_port);
                    close(clients[i].sock_fd);
                    FD_CLR(clients[i].sock_fd, &all_fds);
                    clients[i].sock_fd = -1;
                } else {
                    // Client sent message
                    gettimeofday(&(clients[i].last_active), NULL);
                    printf("%s:%d: %s", clients[i].client_ip, clients[i].client_port, msg);
                }
            }

            // Check if client has been inactive for a certain amount of time (e.g. 1 minute)
            struct timeval curr_time;
            gettimeofday(&curr_time, NULL);
            int inactive_time = curr_time.tv_sec - clients[i].last_active.tv_sec;
            if (inactive_time >= 60) {
                printf("%s:%d has been inactive for 1 minute. Disconnecting...\n", clients[i].client_ip, clients[i].client_port);
                close(clients[i].sock_fd);
                FD_CLR(clients[i].sock_fd, &all_fds);
                clients[i].sock_fd = -1;
            }
        }
    }

    return 0;
}