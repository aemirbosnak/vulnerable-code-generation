//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Define the light states
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Define the light control commands
#define CMD_TURN_ON "turn_on"
#define CMD_TURN_OFF "turn_off"

// Define the server port
#define PORT 8080

// Declare the light states
int lights[MAX_LIGHTS];

// Declare the server socket
int server_socket;

// Declare the client socket
int client_socket;

// Declare the client address
struct sockaddr_in client_addr;

// Declare the thread
pthread_t thread;

// Function to handle client connections
void *handle_client(void *arg) {
  // Get the client socket
  int client_socket = *(int *)arg;

  // Receive the command from the client
  char command[100];
  recv(client_socket, command, sizeof(command), 0);

  // Parse the command
  char *light_id_str = strtok(command, " ");
  int light_id = atoi(light_id_str);
  char *state_str = strtok(NULL, " ");
  int state = atoi(state_str);

  // Turn the light on or off
  if (state == LIGHT_ON) {
    lights[light_id] = LIGHT_ON;
  } else if (state == LIGHT_OFF) {
    lights[light_id] = LIGHT_OFF;
  }

  // Send the response to the client
  char response[100];
  sprintf(response, "Light %d is now %s", light_id, state == LIGHT_ON ? "on" : "off");
  send(client_socket, response, strlen(response), 0);

  // Close the client socket
  close(client_socket);

  // Exit the thread
  pthread_exit(NULL);
}

// Main function
int main() {
  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the server socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for client connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept client connections
  while (1) {
    // Accept a client connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Create a thread to handle the client connection
    if (pthread_create(&thread, NULL, handle_client, &client_socket) != 0) {
      perror("pthread_create");
      close(client_socket);
      continue;
    }

    // Detach the thread
    pthread_detach(thread);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}