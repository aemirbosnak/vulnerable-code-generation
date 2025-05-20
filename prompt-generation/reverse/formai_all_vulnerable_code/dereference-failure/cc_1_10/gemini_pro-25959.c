//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Main function
 * @param argc: Number of arguments
 * @param argv: Array of arguments
 * @return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
  // Check if the correct number of arguments were provided
  if (argc != 2)
  {
    printf("Usage: %s <port>\n", argv[0]);
    return -1;
  }

  // Parse the port number
  int port = atoi(argv[1]);

  // Create a new socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror("socket");
    return -1;
  }

  // Set up the socket address
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
  {
    perror("bind");
    close(sockfd);
    return -1;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) == -1)
  {
    perror("listen");
    close(sockfd);
    return -1;
  }

  // Handle incoming connections in a loop
  while (1)
  {
    // Accept an incoming connection
    int clientfd = accept(sockfd, NULL, NULL);
    if (clientfd == -1)
    {
      perror("accept");
      continue;
    }

    // Handle the client connection in a new thread
    pid_t pid = fork();
    if (pid == 0)
    {
      // Child process: handle the client request
      char buffer[1024] = {0};
      recv(clientfd, buffer, sizeof(buffer), 0);
      printf("Received request:\n%s\n", buffer);

      // Send a response to the client
      char response[] = "HTTP/1.1 200 OK\n\nHello, world!\n";
      send(clientfd, response, strlen(response), 0);

      close(clientfd);
      exit(0);
    }
    else if (pid > 0)
    {
      // Parent process: continue listening for new connections
      close(clientfd);
    }
    else
    {
      // Fork failed
      perror("fork");
      close(clientfd);
      continue;
    }
  }

  // Close the server socket
  close(sockfd);

  return 0;
}