//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Constant definitions
#define MAX_CLIENTS 10
#define MAX_USERNAME_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Data structure to represent a client
typedef struct client_t {
	int socket;
	char username[MAX_USERNAME_LENGTH];
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;

// Function to handle client connections
void *handle_client(void *arg) {
	// Get the client structure from the argument
	client_t *client = (client_t *)arg;

	// Receive the username from the client
	char username[MAX_USERNAME_LENGTH];
	recv(client->socket, username, MAX_USERNAME_LENGTH, 0);

	// Add the client to the list of clients
	clients[num_clients++] = *client;

	// Send a welcome message to the client
	char welcome_message[MAX_MESSAGE_LENGTH];
	sprintf(welcome_message, "Welcome to the chat server, %s!", username);
	send(client->socket, welcome_message, strlen(welcome_message), 0);

	// Keep receiving messages from the client
	while (1) {
		// Receive the message from the client
		char message[MAX_MESSAGE_LENGTH];
		recv(client->socket, message, MAX_MESSAGE_LENGTH, 0);

		// Check if the client has disconnected
		if (strcmp(message, "exit") == 0) {
			break;
		}

		// Send the message to all other clients
		for (int i = 0; i < num_clients; i++) {
			if (clients[i].socket != client->socket) {
				char formatted_message[MAX_MESSAGE_LENGTH];
				sprintf(formatted_message, "%s: %s", username, message);
				send(clients[i].socket, formatted_message, strlen(formatted_message), 0);
			}
		}
	}

	// Remove the client from the list of clients
	for (int i = 0; i < num_clients; i++) {
		if (clients[i].socket == client->socket) {
			clients[i] = clients[num_clients - 1];
			num_clients--;
			break;
		}
	}

	// Close the client's socket
	close(client->socket);

	// Return NULL to indicate that the thread has finished
	return NULL;
}

int main() {
	// Create a socket
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1) {
		perror("socket");
		return EXIT_FAILURE;
	}

	// Bind the socket to an address and port
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(1234);
	server_address.sin_addr.s_addr = INADDR_ANY;
	if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
		perror("bind");
		return EXIT_FAILURE;
	}

	// Listen for incoming connections
	if (listen(server_socket, MAX_CLIENTS) == -1) {
		perror("listen");
		return EXIT_FAILURE;
	}

	// Accept incoming connections and spawn threads to handle them
	while (1) {
		// Accept an incoming connection
		struct sockaddr_in client_address;
		socklen_t client_address_length = sizeof(client_address);
		int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
		if (client_socket == -1) {
			perror("accept");
			continue;
		}

		// Create a new client structure
		client_t client;
		client.socket = client_socket;

		// Create a new thread to handle the client
		pthread_t thread;
		if (pthread_create(&thread, NULL, handle_client, (void *)&client) != 0) {
			perror("pthread_create");
			close(client_socket);
			continue;
		}
	}

	// Close the server socket
	close(server_socket);

	return EXIT_SUCCESS;
}