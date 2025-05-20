//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

// Structure to store the candidate details
typedef struct {
    int id;
    char name[100];
    int votes;
} Candidate;

// Function to create a new candidate
Candidate* createCandidate(int id, char* name) {
    Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
    candidate->id = id;
    strcpy(candidate->name, name);
    candidate->votes = 0;
    return candidate;
}

// Function to print the candidate details
void printCandidate(Candidate* candidate) {
    printf("Candidate ID: %d\n", candidate->id);
    printf("Candidate Name: %s\n", candidate->name);
    printf("Candidate Votes: %d\n\n", candidate->votes);
}

// Function to handle the client connection
void handleClient(int client_socket, Candidate** candidates, int num_candidates) {
    // Receive the candidate ID from the client
    int candidate_id;
    recv(client_socket, &candidate_id, sizeof(int), 0);
    
    // Increment the vote count for the selected candidate
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i]->id == candidate_id) {
            candidates[i]->votes++;
            break;
        }
    }
    
    // Send a confirmation message to the client
    char message[] = "Vote recorded successfully.";
    send(client_socket, message, strlen(message), 0);
    
    // Close the client socket
    close(client_socket);
}

int main() {
    // Create the candidate list
    Candidate* candidates[] = {
        createCandidate(1, "John Smith"),
        createCandidate(2, "Jane Doe"),
        createCandidate(3, "Michael Jones")
    };
    int num_candidates = sizeof(candidates) / sizeof(Candidate*);
    
    // Create the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return EXIT_FAILURE;
    }
    
    // Bind the server socket to the specified port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        return EXIT_FAILURE;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for incoming connections");
        return EXIT_FAILURE;
    }
    
    printf("Electronic Voting System is running on port %d\n", PORT);
    
    // Accept client connections and handle them in a loop
    while (1) {
        // Accept a new client connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("Error accepting client connection");
            continue;
        }
        
        // Create a new thread to handle the client connection
        int *pclient = malloc(sizeof(int));
        *pclient = client_socket;
        pthread_t tid;
        pthread_create(&tid, NULL, (void*)handleClient, pclient);
    }
    
    // Close the server socket
    close(server_socket);
    
    // Free the allocated memory
    for (int i = 0; i < num_candidates; i++) {
        free(candidates[i]);
    }
    
    return EXIT_SUCCESS;
}