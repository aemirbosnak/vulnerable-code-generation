//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

// A simple struct to represent a node in the network
typedef struct node {
    char *ip;
    int port;
    struct node *next;
} node;

// This function prints the contents of a node
void print_node(node *n) {
    printf("Node: %s:%d\n", n->ip, n->port);
}

// This function adds a node to the list of nodes
void add_node(node **head, char *ip, int port) {
    node *new_node = malloc(sizeof(node));
    new_node->ip = malloc(strlen(ip) + 1);
    strcpy(new_node->ip, ip);
    new_node->port = port;
    new_node->next = *head;
    *head = new_node;
}

// This function removes a node from the list of nodes
void remove_node(node **head, char *ip, int port) {
    node *current = *head;
    node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->ip, ip) == 0 && current->port == port) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->ip);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// This function creates a socket and connects to a given IP address and port
int connect_to_server(char *ip, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// This function sends a message to a given socket
void send_message(int sockfd, char *message) {
    int len = strlen(message);
    if (send(sockfd, message, len, 0) == -1) {
        perror("send");
        exit(1);
    }
}

// This function receives a message from a given socket
char *receive_message(int sockfd) {
    char buffer[1024];
    int len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (len == -1) {
        perror("recv");
        exit(1);
    }
    buffer[len] = '\0';
    return strdup(buffer);
}

// This function closes a given socket
void close_socket(int sockfd) {
    close(sockfd);
}

// This function is the main function of the program
int main(int argc, char **argv) {
    // Check if the user provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    // Get the IP address and port from the command line arguments
    char *ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket and connect to the server
    int sockfd = connect_to_server(ip, port);

    // Send a message to the server
    send_message(sockfd, "Hello world!\n");

    // Receive a message from the server
    char *message = receive_message(sockfd);

    // Print the message to the console
    printf("%s", message);

    // Close the socket
    close_socket(sockfd);

    return 0;
}