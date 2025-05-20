//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Create a socket and connect to the server
int create_socket(char *hostname, int port) {
  struct sockaddr_in server_addr;
  struct hostent *server;

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Get the server's IP address
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("Error getting server's IP address");
    exit(1);
  }

  // Set the server's address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  server_addr.sin_port = htons(port);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  return sockfd;
}

// Send a request to the server
void send_request(int sockfd) {
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n";
  int request_length = strlen(request);

  // Send the request
  if (write(sockfd, request, request_length) < 0) {
    perror("Error sending request");
    exit(1);
  }
}

// Receive the response from the server
char *receive_response(int sockfd) {
  char *response = malloc(1024);
  int response_length = 0;

  // Receive the response
  while ((response_length = read(sockfd, response, 1024)) > 0) {
    response[response_length] = '\0';
  }

  if (response_length < 0) {
    perror("Error receiving response");
    exit(1);
  }

  return response;
}

// Calculate the download speed
double calculate_download_speed(char *response, time_t start_time, time_t end_time) {
  double download_speed = 0;
  int content_length = 0;

  // Get the content length
  char *content_length_header = strstr(response, "Content-Length: ");
  if (content_length_header != NULL) {
    content_length = atoi(content_length_header + strlen("Content-Length: "));
  }

  // Calculate the download speed
  if (content_length > 0) {
    download_speed = (double)content_length / (end_time - start_time);
  }

  return download_speed;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  // Create a socket and connect to the server
  int sockfd = create_socket(argv[1], atoi(argv[2]));

  // Send a request to the server
  send_request(sockfd);

  // Start the timer
  time_t start_time = time(NULL);

  // Receive the response from the server
  char *response = receive_response(sockfd);

  // Stop the timer
  time_t end_time = time(NULL);

  // Calculate the download speed
  double download_speed = calculate_download_speed(response, start_time, end_time);

  // Print the download speed
  printf("Download speed: %.2f KB/s\n", download_speed);

  // Close the socket
  close(sockfd);

  return 0;
}