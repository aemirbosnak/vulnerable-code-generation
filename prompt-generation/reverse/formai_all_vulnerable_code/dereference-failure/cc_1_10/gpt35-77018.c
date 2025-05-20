//FormAI DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

void sigint_handler(int sig);

int main(int argc, char *argv[]) {

  // Check if the user provided the correct number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Register sigint_handler to handle SIGINT (ctrl+c)
  if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    perror("signal");
    exit(EXIT_FAILURE);
  }

  // Create the server socket
  int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Bind the server socket to the specified port number
  int port_number = atoi(argv[1]);
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_number);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sockfd, 10) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d...\n", port_number);

  // Accept incoming client connections
  int client_sockfd;
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  while ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len)) != -1) {

    // Create a child process to handle the client connection
    pid_t pid = fork();

    // If fork failed, alert the user and keep waiting for connections
    if (pid == -1) {
      perror("fork");
      continue;
    }

    // If this is the child process, handle the client connection
    if (pid == 0) {

      // Convert client IP address to string form
      char client_ip_str[INET_ADDRSTRLEN];
      if (inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip_str, INET_ADDRSTRLEN) == NULL) {
        perror("inet_ntop");
      }

      printf("Client connected: %s:%d\n", client_ip_str, ntohs(client_addr.sin_port));

      // Send welcome message to the client
      char welcome_msg[] = "Welcome! Type your message and press enter.\n";
      if (send(client_sockfd, welcome_msg, strlen(welcome_msg), 0) == -1) {
        perror("send");
      }

      // Main loop to receive and send messages to and from the client
      char buf[1024];
      size_t bytes_received, bytes_sent;

      while ((bytes_received = recv(client_sockfd, buf, sizeof(buf), 0)) > 0) {

        // Add null terminator to received data
        buf[bytes_received] = '\0';

        // If client sends "exit", exit the loop and close the socket
        if (strcmp(buf, "exit\n") == 0) {
          break;
        }

        // Respond with the same message the client sent
        bytes_sent = send(client_sockfd, buf, strlen(buf), 0);
        if (bytes_sent == -1) {
          perror("send");
        }
      }

      // Close the client socket and exit the child process
      if (close(client_sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
      }

      printf("Client disconnected: %s:%d\n", client_ip_str, ntohs(client_addr.sin_port));
      exit(EXIT_SUCCESS);
    }

    // If this is not the child process, close the client socket
    if (close(client_sockfd) == -1) {
      perror("close");
    }
  }

  // If accept fails, alert the user and exit
  if (client_sockfd == -1 && errno != EINTR) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Close the server socket and exit
  if (close(server_sockfd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return 0;
}

void sigint_handler(int sig) {
  printf("\nServer interrupted. Closing sockets.\n");
  exit(EXIT_SUCCESS);
}