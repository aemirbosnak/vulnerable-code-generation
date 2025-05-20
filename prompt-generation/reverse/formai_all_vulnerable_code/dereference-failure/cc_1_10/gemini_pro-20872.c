//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>

// Romeo's private key
#define ROMEO_KEY "secretkey"

// Juliet's private key
#define JULIET_KEY "secretkey"

// Port number to listen on
#define PORT_NUM 5555

// Romeo's message (encrypted with Juliet's key)
#define ROMEO_MESSAGE "My dearest Juliet, thy beauty is unparalleled, and my love for thee knows no bounds."

// Juliet's message (encrypted with Romeo's key)
#define JULIET_MESSAGE "Oh, Romeo, my heart yearns for thee eternally. Thy love is the very essence of my being."

// Function to encrypt a message using a key
char *encrypt(char *message, char *key) {
  // Initialize the encrypted message
  char *encrypted_message = malloc(strlen(message) + 1);

  // Iterate over the message and encrypt each character using the key
  for (int i = 0; i < strlen(message); i++) {
    encrypted_message[i] = message[i] ^ key[i % strlen(key)];
  }

  // Null-terminate the encrypted message
  encrypted_message[strlen(message)] = '\0';

  // Return the encrypted message
  return encrypted_message;
}

// Function to decrypt a message using a key
char *decrypt(char *encrypted_message, char *key) {
  // Initialize the decrypted message
  char *decrypted_message = malloc(strlen(encrypted_message) + 1);

  // Iterate over the encrypted message and decrypt each character using the key
  for (int i = 0; i < strlen(encrypted_message); i++) {
    decrypted_message[i] = encrypted_message[i] ^ key[i % strlen(key)];
  }

  // Null-terminate the decrypted message
  decrypted_message[strlen(encrypted_message)] = '\0';

  // Return the decrypted message
  return decrypted_message;
}

// Function to handle incoming messages from Romeo
void handle_romeo(int socket) {
  // Receive the encrypted message from Romeo
  char encrypted_message[1024];
  int bytes_received = recv(socket, encrypted_message, sizeof(encrypted_message), 0);

  // Decrypt the message using Juliet's key
  char *message = decrypt(encrypted_message, JULIET_KEY);

  // Print the decrypted message to the console
  printf("Juliet: %s\n", message);

  // Free the decrypted message
  free(message);

  // Send a response to Romeo
  char *response = encrypt(ROMEO_MESSAGE, ROMEO_KEY);
  send(socket, response, strlen(response), 0);

  // Free the response
  free(response);

  // Close the socket
  close(socket);
}

// Function to handle incoming messages from Juliet
void handle_juliet(int socket) {
  // Receive the encrypted message from Juliet
  char encrypted_message[1024];
  int bytes_received = recv(socket, encrypted_message, sizeof(encrypted_message), 0);

  // Decrypt the message using Romeo's key
  char *message = decrypt(encrypted_message, ROMEO_KEY);

  // Print the decrypted message to the console
  printf("Romeo: %s\n", message);

  // Free the decrypted message
  free(message);

  // Send a response to Juliet
  char *response = encrypt(JULIET_MESSAGE, JULIET_KEY);
  send(socket, response, strlen(response), 0);

  // Free the response
  free(response);

  // Close the socket
  close(socket);
}

int main(int argc, char *argv[]) {
  // Create a socket for listening to incoming connections
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Set the socket options to reuse the address and port
  int optval = 1;
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, sizeof(optval)) < 0) {
    perror("Error setting socket options");
    return EXIT_FAILURE;
  }

  // Bind the socket to the specified port
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT_NUM);
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket to port");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, 10) < 0) {
    perror("Error listening for connections");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Determine the client's IP address
    char client_ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip_address, sizeof(client_ip_address));

    // Print a message to the console indicating that a new connection has been established
    printf("New connection from %s\n", client_ip_address);

    // Fork a new process to handle the incoming connection
    pid_t child_pid = fork();
    if (child_pid == 0) {
      // Child process

      // Close the server socket
      close(server_socket);

      // Determine if the client is Romeo or Juliet
      char *client_name = NULL;
      if (strcmp(client_ip_address, "127.0.0.1") == 0) {
        client_name = "Romeo";
      } else if (strcmp(client_ip_address, "127.0.0.2") == 0) {
        client_name = "Juliet";
      }

      // Print a message to the console indicating the client's identity
      printf("%s has connected\n", client_name);

      // Handle the incoming messages from the client
      if (strcmp(client_name, "Romeo") == 0) {
        handle_romeo(client_socket);
      } else if (strcmp(client_name, "Juliet") == 0) {
        handle_juliet(client_socket);
      }

      // Exit the child process
      exit(0);
    } else {
      // Parent process

      // Close the client socket
      close(client_socket);
    }
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}