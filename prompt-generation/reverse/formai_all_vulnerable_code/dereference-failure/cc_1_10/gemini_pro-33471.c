//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
} client_info;

void* handle_client(void* arg) {
  client_info* client = (client_info*)arg;
  char buffer[1024];
  int n;

  // Read the request from the client
  n = read(client->sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
  }

  // Parse the request
  char* method = strtok(buffer, " ");
  char* path = strtok(NULL, " ");
  char* version = strtok(NULL, "\r\n");

  // Check if the request is valid
  if (strcmp(method, "GET") != 0) {
    // Send an error response
    char* error_response = "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/plain\r\nContent-Length: 0\r\n\r\n";
    write(client->sockfd, error_response, strlen(error_response));
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
  }

  // Send the response
  char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello world!";
  write(client->sockfd, response, strlen(response));

  // Close the socket
  close(client->sockfd);
  free(client);
  pthread_exit(NULL);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in addr;
  int addrlen;
  pthread_t tid;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
    perror("Error setting socket options");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the address
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);
  addrlen = sizeof(addr);
  if (bind(sockfd, (struct sockaddr*)&addr, addrlen) < 0) {
    perror("Error binding socket");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0) {
    perror("Error listening for connections");
    close(sockfd);
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d\n", PORT);

  // Accept incoming connections
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr*)&addr, (socklen_t*)&addrlen);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Create a new thread to handle the client
    client_info* client = malloc(sizeof(client_info));
    client->sockfd = newsockfd;
    client->addr = addr;
    if (pthread_create(&tid, NULL, handle_client, (void*)client) != 0) {
      perror("Error creating thread");
      close(newsockfd);
      free(client);
      continue;
    }
  }

  // Close the socket
  close(sockfd);
  return 0;
}