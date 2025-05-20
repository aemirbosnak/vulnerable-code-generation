//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_IP 20
#define MAX_MSG 100

typedef struct network_node {
    char ip[MAX_IP];
    int port;
    struct network_node* next_node;
} NetworkNode;

NetworkNode* head_node = NULL; // Linked list of all nodes in the network

void add_node(char* ip, int port) {
    NetworkNode* new_node = (NetworkNode*) malloc(sizeof(NetworkNode));
    strcpy(new_node->ip, ip);
    new_node->port = port;
    new_node->next_node = NULL;

    if (head_node == NULL) {
        head_node = new_node;
    }
    else {
        NetworkNode* current_node = head_node;
        while (current_node->next_node != NULL) {
            current_node = current_node->next_node;
        }
        current_node->next_node = new_node;
    }
}

void remove_node(char* ip, int port) {
    NetworkNode* current_node = head_node;
    NetworkNode* previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->ip, ip) == 0 && current_node->port == port) {
            if (previous_node == NULL) {
                head_node = current_node->next_node;
            }
            else {
                previous_node->next_node = current_node->next_node;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next_node;
    }
}

void print_nodes() {
    NetworkNode* current_node = head_node;
    printf("Nodes in network:\n");
    while (current_node != NULL) {
        printf("(%s, %d)\n", current_node->ip, current_node->port);
        current_node = current_node->next_node;
    }
}

void error(const char* message) {
    perror(message);
    exit(1);
}

void handle_connection(int socket_fd) {
    char buffer[MAX_MSG];
    memset(buffer, 0, MAX_MSG);
    if (read(socket_fd, buffer, MAX_MSG) < 0) {
        error("Error reading from socket");
    }
    printf("%s\n", buffer);

    char command[MAX_MSG];
    memset(command, 0, MAX_MSG);
    printf("> ");
    fgets(command, MAX_MSG, stdin);

    if (write(socket_fd, command, strlen(command)) < 0) {
        error("Error writing to socket");
    }
}

void connect_to_nodes() {
    NetworkNode* current_node = head_node;
    while (current_node != NULL) {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            error("Error opening socket");
        }
        struct hostent* server = gethostbyname(current_node->ip);
        if (server == NULL) {
            error("Error resolving hostname");
        }
        struct sockaddr_in server_address;
        memset((char*) &server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        bcopy((char*) server->h_addr,
              (char*) &server_address.sin_addr.s_addr,
              server->h_length);
        server_address.sin_port = htons(current_node->port);
        if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            printf("Error connecting to node %s:%d\n", current_node->ip, current_node->port);
            close(socket_fd);
        }
        else {
            printf("Connected to node %s:%d\n", current_node->ip, current_node->port);
            fcntl(socket_fd, F_SETFL, O_NONBLOCK); // Set socket to non-blocking
            handle_connection(socket_fd); // Start handling user input on this socket
        }
        current_node = current_node->next_node;
    }
}

void signal_handler(int sig) {
    printf("Shutting down...\n");
    NetworkNode* current_node = head_node;
    while (current_node != NULL) {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            continue;
        }
        struct hostent* server = gethostbyname(current_node->ip);
        if (server == NULL) {
            close(socket_fd);
            continue;
        }
        struct sockaddr_in server_address;
        memset((char*) &server_address, 0, sizeof(server_address));
        server_address.sin_family = AF_INET;
        bcopy((char*) server->h_addr,
              (char*) &server_address.sin_addr.s_addr,
              server->h_length);
        server_address.sin_port = htons(current_node->port);
        if (connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            close(socket_fd);
            continue;
        }
        write(socket_fd, "exit\n", 5);
        close(socket_fd);
        current_node = current_node->next_node;
    }
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./mapper <port>\n");
        exit(1);
    }
    int server_port = atoi(argv[1]);

    signal(SIGINT, signal_handler);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error("Error opening socket");
    }
    int enable = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        error("Error setting socket options");
    }
    struct sockaddr_in server_address;
    memset((char*) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(server_port);
    if (bind(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }
    listen(socket_fd, 5);
    printf("Listening for incoming connections on port %d...\n", server_port);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_length = sizeof(client_address);
        int client_fd = accept(socket_fd, (struct sockaddr*) &client_address, &client_length);
        if (client_fd < 0) {
            error("Error accepting connection");
        }

        char client_ip[MAX_IP];
        memset(client_ip, 0, MAX_IP);
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, MAX_IP);
        int client_port = ntohs(client_address.sin_port);
        printf("Connection from %s:%d\n", client_ip, client_port);

        add_node(client_ip, client_port); // Add new node to list of nodes in the network
        print_nodes(); // Print current list of nodes in the network

        fcntl(client_fd, F_SETFL, O_NONBLOCK); // Set connection to non-blocking
        handle_connection(client_fd); // Start handling user input on this connection
    }

    return 0;
}