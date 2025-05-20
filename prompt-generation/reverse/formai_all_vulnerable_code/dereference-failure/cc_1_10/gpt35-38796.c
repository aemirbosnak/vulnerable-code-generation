//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT 8888
#define MAX_CLIENTS 5
#define BUFF_SIZE 1024

// client structure
typedef struct {
    int socket;
    char ip[INET_ADDRSTRLEN];
    time_t last_active;
} client_t;

// global variables
client_t clients[MAX_CLIENTS];
fd_set read_fds, master_fds;
int max_fd;

// function prototypes
void init_clients();
void add_client(int);
void remove_client(int);

int main() {
    int server_fd, new_socket, opt = 1, activity, i;
    struct sockaddr_in address;

    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        printf("Socket options set failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // server address initialization
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        printf("Socket bind failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // listen for clients
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        printf("Listen failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // initialize clients array
    init_clients();

    // clear sockets list
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    // add server socket to list
    FD_SET(server_fd, &master_fds);
    max_fd = server_fd;
    
    while (1) {
        read_fds = master_fds;
        activity = select(max_fd+1, &read_fds, NULL, NULL, NULL);

        if (activity == -1) {
            printf("Select error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        // new client connection
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&i)) == -1) {
                printf("Accept error: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            // add new client to clients array and sockets list
            add_client(new_socket);

            printf("New client connected: %s\n", inet_ntoa(address.sin_addr));
        }

        // incoming data from clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && FD_ISSET(clients[i].socket, &read_fds)) {
                char buff[BUFF_SIZE] = {0};
                int bytes_read;

                if ((bytes_read = recv(clients[i].socket, buff, BUFF_SIZE, 0)) == 0) {
                    // client disconnected
                    printf("Client disconnected: %s\n", clients[i].ip);
                    remove_client(i);
                } else {
                    // client activity detected
                    clients[i].last_active = time(NULL);
                    printf("Data received from client %s: %s\n", clients[i].ip, buff);
                }
            }
        }

        // check client activity (QoS monitoring)
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket != 0 && (time(NULL) - clients[i].last_active) > 10) {
                // client inactive for more than 10 seconds, remove client
                printf("Client inactive for 10 seconds, disconnecting: %s\n", clients[i].ip);
                remove_client(i);
            }
        }
    }

    return 0;
}

// initialize clients array
void init_clients() {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        clients[i].socket = 0;
        strcpy(clients[i].ip, "");
        clients[i].last_active = 0;
    }
}

// add client to clients array and sockets list
void add_client(int socket) {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == 0) {
            // add new client to clients array
            clients[i].socket = socket;
            strcpy(clients[i].ip, inet_ntoa(((struct sockaddr_in*) &clients[i].ip)->sin_addr));
            clients[i].last_active = time(NULL);

            // add new client socket to sockets list
            FD_SET(socket, &master_fds);

            if (socket > max_fd) {
                max_fd = socket;
            }

            break;
        }
    }
}

// remove client from clients array and sockets list
void remove_client(int index) {
    // close socket
    close(clients[index].socket);

    // remove client from clients array and sockets list
    FD_CLR(clients[index].socket, &master_fds);
    clients[index].socket = 0;
    strcpy(clients[index].ip, "");
    clients[index].last_active = 0;
}