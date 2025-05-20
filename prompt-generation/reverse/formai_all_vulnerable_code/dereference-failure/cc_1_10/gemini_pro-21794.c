//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define POP3_PORT 110
#define MAX_BUFFER 1024

struct client_data {
    int sockfd;
    char *username;
    char *password;
    int num_messages;
    char **messages;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *)arg;

    // Receive the welcome message
    char buffer[MAX_BUFFER];
    recv(client->sockfd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    // Send the username
    sprintf(buffer, "USER %s\r\n", client->username);
    send(client->sockfd, buffer, strlen(buffer), 0);
    recv(client->sockfd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    // Send the password
    sprintf(buffer, "PASS %s\r\n", client->password);
    send(client->sockfd, buffer, strlen(buffer), 0);
    recv(client->sockfd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    // Get the number of messages
    sprintf(buffer, "STAT\r\n");
    send(client->sockfd, buffer, strlen(buffer), 0);
    recv(client->sockfd, buffer, MAX_BUFFER, 0);
    sscanf(buffer, "+OK %d %d\r\n", &client->num_messages, &client->messages);

    // Retrieve the messages
    for (int i = 1; i <= client->num_messages; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        send(client->sockfd, buffer, strlen(buffer), 0);
        recv(client->sockfd, buffer, MAX_BUFFER, 0);
        printf("%s\n", buffer);
    }

    // Quit
    send(client->sockfd, "QUIT\r\n", 6, 0);
    recv(client->sockfd, buffer, MAX_BUFFER, 0);
    printf("%s\n", buffer);

    // Close the socket
    close(client->sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <username> <password> <server>\n", argv[0]);
        return 1;
    }

    // Get the server address
    struct hostent *server = gethostbyname(argv[3]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[3]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *(struct in_addr *)server->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        return 1;
    }

    // Create a client data structure
    struct client_data client;
    client.sockfd = sockfd;
    client.username = argv[1];
    client.password = argv[2];

    // Create a thread to handle the client
    pthread_t thread;
    if (pthread_create(&thread, NULL, handle_client, &client) != 0) {
        perror("Error: could not create thread");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}