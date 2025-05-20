//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  // Declare variables.
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUFFER_SIZE];
  clock_t start, end;
  double time_taken;

  // Get the host name and port number from the user.
  printf("Enter the host name: ");
  scanf("%s", buffer);
  printf("Enter the port number: ");
  scanf("%d", &portno);

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Get the server's IP address.
  server = gethostbyname(buffer);
  if (server == NULL) {
    perror("ERROR, no such host");
    exit(1);
  }

  // Fill in the server's address.
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Start the timer.
  start = clock();

  // Send a message to the server.
  n = write(sockfd, "Hello world", 11);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Receive a message from the server.
  n = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Stop the timer.
  end = clock();

  // Calculate the time taken.
  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

  // Print the time taken.
  printf("Time taken: %f seconds\n", time_taken);

  // Close the socket.
  close(sockfd);

  return 0;
}