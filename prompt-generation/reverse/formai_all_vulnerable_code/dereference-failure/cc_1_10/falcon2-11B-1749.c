//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Define a structure for storing client information
struct client_info {
    int sockfd;
    char client_name[100];
    char ip[100];
};

// Function to create a client socket
int create_client_socket(struct client_info *client) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket creation failed");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    strcpy(client->client_name, "Alice");
    strcpy(client->ip, "127.0.0.1");

    return sockfd;
}

// Function to send a message to the server
void send_message(struct client_info *client, char *message) {
    int num_sent;

    num_sent = send(client->sockfd, message, strlen(message), 0);

    if (num_sent < 0) {
        perror("send failed");
    } else {
        printf("Message sent successfully\n");
    }
}

// Function to receive a message from the server
char *receive_message(struct client_info *client) {
    char *message = (char *)malloc(1000 * sizeof(char));
    int num_received;

    num_received = recv(client->sockfd, message, 1000, 0);

    if (num_received < 0) {
        perror("receive failed");
        return NULL;
    } else {
        printf("Message received successfully: %s\n", message);
        return message;
    }
}

// Main function
int main() {
    struct client_info client;
    char *message;

    if (create_client_socket(&client) < 0) {
        return -1;
    }

    message = receive_message(&client);

    while (message!= NULL) {
        send_message(&client, "Hello from Alice");
        message = receive_message(&client);
    }

    return 0;
}