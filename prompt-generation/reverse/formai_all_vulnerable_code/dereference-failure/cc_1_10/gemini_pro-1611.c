//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
// A POP3 client in a shape-shifting style

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants
#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

// Function prototypes
int connect_to_server(char *hostname, int port);
void send_command(int sockfd, char *command);
char *receive_response(int sockfd);
void handle_response(char *response);

// Main function
int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return -1;
  }

  // Connect to the server
  int sockfd = connect_to_server(argv[1], atoi(argv[2]));
  if (sockfd == -1) {
    printf("Could not connect to server.\n");
    return -1;
  }

  // Send the USER command
  send_command(sockfd, "USER username");

  // Receive the response
  char *response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the PASS command
  send_command(sockfd, "PASS password");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the STAT command
  send_command(sockfd, "STAT");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the LIST command
  send_command(sockfd, "LIST");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the RETR command
  send_command(sockfd, "RETR 1");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the DELE command
  send_command(sockfd, "DELE 1");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Handle the response
  handle_response(response);

  // Send the QUIT command
  send_command(sockfd, "QUIT");

  // Receive the response
  response = receive_response(sockfd);
  if (response == NULL) {
    printf("Could not receive response from server.\n");
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}

// Function to connect to the server
int connect_to_server(char *hostname, int port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Could not create socket.\n");
    return -1;
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Could not resolve hostname.\n");
    return -1;
  }

  // Create the server address
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  memcpy(&server_address.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    printf("Could not connect to server.\n");
    return -1;
  }

  return sockfd;
}

// Function to send a command to the server
void send_command(int sockfd, char *command) {
  // Send the command
  if (send(sockfd, command, strlen(command), 0) == -1) {
    printf("Could not send command to server.\n");
    return;
  }

  // Send a newline character
  if (send(sockfd, "\r\n", 2, 0) == -1) {
    printf("Could not send newline character to server.\n");
    return;
  }
}

// Function to receive a response from the server
char *receive_response(int sockfd) {
  // Receive the response
  char *response = malloc(MAX_LINE_LENGTH);
  if (response == NULL) {
    printf("Could not allocate memory for response.\n");
    return NULL;
  }

  int bytes_received = recv(sockfd, response, MAX_LINE_LENGTH, 0);
  if (bytes_received == -1) {
    printf("Could not receive response from server.\n");
    return NULL;
  }

  // Null-terminate the response
  response[bytes_received] = '\0';

  return response;
}

// Function to handle a response from the server
void handle_response(char *response) {
  // Print the response
  printf("%s\n", response);

  // Parse the response
  char *code = strtok(response, " ");
  char *message = strtok(NULL, "\r\n");

  // Print the code and message
  printf("Code: %s\n", code);
  printf("Message: %s\n", message);
}