//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

// Worker thread function
void *worker_thread(void *arg) {
  int sockfd = *(int *)arg;
  char buffer[MAXLINE];

  // Receive data from client
  int n = read(sockfd, buffer, MAXLINE);
  if (n < 0) {
    perror("Error reading from socket");
    return NULL;
  }

  // Process data
  printf("Received: %s\n", buffer);
  char *response = "Hello from worker thread!";

  // Send data back to client
  n = write(sockfd, response, strlen(response));
  if (n < 0) {
    perror("Error writing to socket");
    return NULL;
  }

  // Close socket
  close(sockfd);

  return NULL;
}

int main() {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;

  // Create a socket
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Set server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for incoming connections
  if (listen(listenfd, 10) < 0) {
    perror("Error listening for connections");
    return 1;
  }

  // Accept incoming connections
  while (1) {
    clilen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    if (connfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Create a new worker thread to handle the connection
    pthread_t tid;
    int *arg = malloc(sizeof(int));
    *arg = connfd;
    if (pthread_create(&tid, NULL, worker_thread, arg) != 0) {
      perror("Error creating worker thread");
      close(connfd);
      free(arg);
      continue;
    }

    // Detach the thread
    pthread_detach(tid);
  }

  // Close the listening socket
  close(listenfd);

  return 0;
}