//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void handle_connection(int sockfd) {
  char buffer[1024];
  int n;

  while (1) {
    // Read data from the client
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
      perror("read");
      break;
    } else if (n == 0) {
      // Client closed the connection
      printf("Client closed the connection\n");
      break;
    }

    // Process the data
    for (int i = 0; i < n; i++) {
      buffer[i] = toupper(buffer[i]);
    }

    // Write data back to the client
    n = write(sockfd, buffer, n);
    if (n < 0) {
      perror("write");
      break;
    }
  }

  close(sockfd);
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set up the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    return -1;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    return -1;
  }

  while (1) {
    // Accept an incoming connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("accept");
      continue;
    }

    // Handle the connection in a separate thread
    int *newsockfd_ptr = malloc(sizeof(int));
    *newsockfd_ptr = newsockfd;
    pthread_t thread;
    if (pthread_create(&thread, NULL, (void *) handle_connection, newsockfd_ptr) != 0) {
      perror("pthread_create");
      close(newsockfd);
      continue;
    }

    // Detach the thread so that it can run independently of the main thread
    if (pthread_detach(thread) != 0) {
      perror("pthread_detach");
      close(newsockfd);
      continue;
    }
  }

  // Close the socket
  close(sockfd);

  return 0;
}