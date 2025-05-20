//GEMINI-pro DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the port number
#define PORT 8080

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the maximum size of the message buffer
#define MAX_MSG_SIZE 1024

// Define the thread function
void *thread_function(void *arg);

// Define the main function
int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Create a thread pool
  pthread_t threads[MAX_CLIENTS];

  // Accept connections and create threads
  while (1) {
    // Accept a connection
    int connfd = accept(sockfd, NULL, NULL);
    if (connfd == -1) {
      perror("accept");
      continue;
    }

    // Create a new thread
    pthread_create(&threads[connfd], NULL, thread_function, (void *)connfd);
  }

  // Close the socket
  close(sockfd);

  return 0;
}

// Define the thread function
void *thread_function(void *arg) {
  // Get the connection file descriptor
  int connfd = (int)arg;

  // Receive a message from the client
  char buf[MAX_MSG_SIZE];
  int n = recv(connfd, buf, MAX_MSG_SIZE, 0);
  if (n == -1) {
    perror("recv");
    close(connfd);
    return NULL;
  }

  // Process the message
  printf("Received message: %s\n", buf);

  // Send a message to the client
  char *msg = "Hello from the server!\n";
  n = send(connfd, msg, strlen(msg), 0);
  if (n == -1) {
    perror("send");
    close(connfd);
    return NULL;
  }

  // Close the connection
  close(connfd);

  return NULL;
}