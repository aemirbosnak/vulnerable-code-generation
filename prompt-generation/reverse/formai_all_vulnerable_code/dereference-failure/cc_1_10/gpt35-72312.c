//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 5

typedef struct {
  int sockfd;
  struct sockaddr_in cli_addr;
} ClientInfo;

void *threadedFunction(void *client) {
  ClientInfo *cl = (ClientInfo*) client;
  int sockfd = cl->sockfd;
  char buffer[BUFFER_SIZE] = {0};
  int valread;
  
  // Send a thank you message to the client
  char *message = "Thanks for connecting!\n";
  write(sockfd, message, strlen(message));
  
  // Receive incoming messages from the client
  while ((valread = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
    printf("%s", buffer);
    memset(buffer, 0, BUFFER_SIZE);
  }
  
  // Close the socket connection
  close(sockfd);
  free(client);
  return NULL;
}

int main() {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  
  // Create the server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    return -1;
  }
  
  // Set socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Setsockopt failed");
    return -1;
  }
  
  // Configure server address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  // Bind the socket to the server address
  if (bind(server_fd, (struct sockaddr*) &address, sizeof(address))<0) {
    perror("Bind failed");
    return -1;
  }
  
  // Listen for incoming connection requests
  if (listen(server_fd, MAX_CONNECTIONS) < 0) {
    perror("Listen failed");
    return -1;
  }
  
  // Accept incoming connections in a loop
  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
      perror("Accept failed");
      return -1;
    }
     
    // Create a new thread to handle the incoming connection
    pthread_t thread_id;
    ClientInfo *client = (ClientInfo*) malloc(sizeof(ClientInfo));
    client->sockfd = new_socket;
    client->cli_addr = address;
    if (pthread_create(&thread_id, NULL, threadedFunction, (void*) client) < 0) {
      perror("Pthread creation failed");
      return -1;
    }
    
    printf("Client connected successfully\n");
  }
  
  // Close the server socket
  close(server_fd);
  return 0;
}