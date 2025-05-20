//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Structure to store candidate information
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Structure to store client information
typedef struct client {
    int sockfd;
    char name[50];
    int voted;
} client;

// Array of candidates
candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0}
};

// Array of clients
client clients[100];
int num_clients = 0;

// Mutex to protect shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client requests
void *handle_client(void *arg) {
    // Get the client socket
    int sockfd = *((int *)arg);
    free(arg);

    // Get the client's name
    char name[50];
    recv(sockfd, name, sizeof(name), 0);

    // Add the client to the array of clients
    pthread_mutex_lock(&mutex);
    clients[num_clients].sockfd = sockfd;
    strcpy(clients[num_clients].name, name);
    clients[num_clients].voted = 0;
    num_clients++;
    pthread_mutex_unlock(&mutex);

    // Send the list of candidates to the client
    char buffer[1024];
    int i;
    for (i = 0; i < 3; i++) {
        sprintf(buffer, "%d. %s\n", i + 1, candidates[i].name);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    // Receive the client's vote
    int vote;
    recv(sockfd, &vote, sizeof(vote), 0);

    // Update the vote count for the selected candidate
    pthread_mutex_lock(&mutex);
    candidates[vote - 1].votes++;
    pthread_mutex_unlock(&mutex);

    // Send a confirmation message to the client
    send(sockfd, "Your vote has been recorded.", 29, 0);

    // Close the client socket
    close(sockfd);

    return NULL;
}

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 10) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept connections and handle them in a separate thread
    while (1) {
        // Accept a connection
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create a thread to handle the client
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = newsockfd;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("Error creating thread");
            close(newsockfd);
            continue;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}