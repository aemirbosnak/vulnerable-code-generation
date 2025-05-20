//FormAI DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10
#define MAX_USERNAME_LENGTH 20
#define BUFFER_SIZE 100

typedef struct {
    int sockfd;
    char username[MAX_USERNAME_LENGTH];
    struct sockaddr_in address;
    socklen_t addr_len;
} client_info;

client_info client_list[MAX_CONNECTIONS];
pthread_t tids[MAX_CONNECTIONS];
pthread_mutex_t mutex;

void *server_thread(void *arg);
void send_to_all(char *message, int sender_sockfd);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind socket to port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_addr_len = sizeof(client_address);
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create new thread to handle client
        pthread_t tid;
        client_info *client = malloc(sizeof(client_info));
        client->sockfd = client_sockfd;
        client->address = client_address;
        client->addr_len = client_addr_len;
        pthread_create(&tid, NULL, &server_thread, client);

        // Store client information and thread ID
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (client_list[i].sockfd == 0) {
                client_list[i] = *client;
                tids[i] = tid;
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
    }

    // Close socket
    close(sockfd);

    return 0;
}

void *server_thread(void *arg) {
    client_info *client = (client_info *) arg;

    // Make user enter their name
    char name_prompt[BUFFER_SIZE] = "Enter your name: ";
    if (write(client->sockfd, name_prompt, strlen(name_prompt)) < 0) {
        perror("Error writing to socket");
        return NULL;
    }

    char username[MAX_USERNAME_LENGTH];
    memset(username, 0, MAX_USERNAME_LENGTH);
    if (read(client->sockfd, username, MAX_USERNAME_LENGTH) < 0) {
        perror("Error reading from socket");
        return NULL;
    }
    strncpy(client->username, username, MAX_USERNAME_LENGTH);

    printf("New client connected from %s:%d (username=%s)\n", 
            inet_ntoa(client->address.sin_addr), 
            ntohs(client->address.sin_port), 
            client->username);

    // Send welcome message
    char welcome_message[BUFFER_SIZE];
    sprintf(welcome_message, "Welcome %s!\n", client->username);
    send_to_all(welcome_message, client->sockfd);

    // Echo messages
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int nbytes = read(client->sockfd, buffer, BUFFER_SIZE);
        if (nbytes < 0) {
            perror("Error reading from socket");
            break;
        }
        if (nbytes == 0) {
            printf("Disconnected from %s:%d (username=%s)\n", 
                    inet_ntoa(client->address.sin_addr), 
                    ntohs(client->address.sin_port), 
                    client->username);
            break;
        }
        char message[BUFFER_SIZE];
        sprintf(message, "[%s] %s", client->username, buffer);
        send_to_all(message, client->sockfd);
    }

    // Close socket and thread
    close(client->sockfd);
    free(client);
    pthread_exit(0);
}

void send_to_all(char *message, int sender_sockfd) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (client_list[i].sockfd != 0 && client_list[i].sockfd != sender_sockfd) {
            write(client_list[i].sockfd, message, strlen(message));
        }
    }
    pthread_mutex_unlock(&mutex);
}