//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <errno.h>

// Define the request message
#define REQUEST_MESSAGE "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"

// Function to establish a connection to the server
int connect_to_server(char *host, int port) {
  int sockfd;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Get the server's IP address
  server = gethostbyname(host);
  if (server == NULL) {
    perror("Error getting host by name");
    exit(1);
  }

  // Fill in the server's address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  return sockfd;
}

// Function to send a request to the server
void send_request(int sockfd) {
  // Send the request message
  if (write(sockfd, REQUEST_MESSAGE, strlen(REQUEST_MESSAGE)) < 0) {
    perror("Error sending request");
    exit(1);
  }
}

// Function to receive a response from the server
char *receive_response(int sockfd) {
  char *buffer = malloc(1024);
  int n;

  // Read the response from the server
  while ((n = read(sockfd, buffer, 1023)) > 0) {
    buffer[n] = '\0';
  }

  if (n < 0) {
    perror("Error receiving response");
    exit(1);
  }

  return buffer;
}

// Function to parse the response from the server
void parse_response(char *response) {
  char *line;

  // Split the response into lines
  line = strtok(response, "\r\n");
  while (line != NULL) {
    printf("%s\n", line);
    line = strtok(NULL, "\r\n");
  }
}

// Main function
int main(int argc, char *argv[]) {
  int sockfd;
  char *response;

  // Check if the correct number of arguments is provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(1);
  }

  // Connect to the server
  sockfd = connect_to_server(argv[1], atoi(argv[2]));

  // Send a request to the server
  send_request(sockfd);

  // Receive a response from the server
  response = receive_response(sockfd);

  // Parse the response from the server
  parse_response(response);

  // Close the connection to the server
  close(sockfd);

  return 0;
}