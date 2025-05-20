//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// Thread structure
typedef struct {
  int sockfd;
} thread_args;

// Thread function
void *thread_func(void *args) {
  char buffer[1024];
  thread_args *arg = (thread_args *)args;

  // Receive the request
  int n = recv(arg->sockfd, buffer, sizeof(buffer), 0);
  if (n < 0) {
    perror("recv");
    pthread_exit(NULL);
  }

  // Parse the request
  char *method = strtok(buffer, " ");
  char *path = strtok(NULL, " ");
  char *version = strtok(NULL, "\r\n");

  // Check if the method is GET
  if (strcmp(method, "GET") != 0) {
    pthread_exit(NULL);
  }

  // Check if the path is valid
  if (strcmp(path, "/") == 0) {
    path = "/index.html";
  }

  // Open the file
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    pthread_exit(NULL);
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Generate the response
  char response[1024];
  sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", file_size);

  // Send the response
  n = send(arg->sockfd, response, strlen(response), 0);
  if (n < 0) {
    perror("send");
    pthread_exit(NULL);
  }

  // Send the file
  while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    n = send(arg->sockfd, buffer, n, 0);
    if (n < 0) {
      perror("send");
      pthread_exit(NULL);
    }
  }

  // Close the file and the socket
  fclose(file);
  close(arg->sockfd);

  // Exit the thread
  pthread_exit(NULL);
}

int main() {
  // Create the socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  int opt = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sockfd, MAX_CLIENTS) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept connections and create threads
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  while (1) {
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
      perror("accept");
      continue;
    }

    // Create a thread for the client
    pthread_t thread;
    thread_args *args = malloc(sizeof(thread_args));
    args->sockfd = client_sockfd;
    if (pthread_create(&thread, NULL, thread_func, args) != 0) {
      perror("pthread_create");
      close(client_sockfd);
      continue;
    }

    // Detach the thread
    pthread_detach(thread);
  }

  // Close the socket
  close(sockfd);

  return 0;
}