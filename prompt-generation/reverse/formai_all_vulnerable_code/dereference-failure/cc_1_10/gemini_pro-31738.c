//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

// Random sleep time between checks in seconds
#define SLEEP_TIME (rand() % (60 * 60 * 2) + 60 * 30)

// Default timeout value for connections in seconds
#define TIMEOUT 15

// Default port to connect to
#define PORT 80

// Main function
int main(int argc, char **argv) {
  // Initialize random number generator
  srand(time(NULL));

  // Check if enough arguments were provided
  if (argc < 2) {
    printf("Usage: %s <domain name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the domain name from the command line
  char *domain = argv[1];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket timeout
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Get the IP address of the domain name
  struct hostent *host = gethostbyname(domain);
  if (host == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  // Initialize the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr = *(struct in_addr *)host->h_addr;

  // Main loop
  while (1) {
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
      if (errno == ECONNREFUSED) {
        printf("Connection refused\n");
      } else {
        perror("connect");
      }
    } else {
      // If the connection was successful, print the current time and the domain name
      time_t now = time(NULL);
      printf("%s %s\n", ctime(&now), domain);
    }

    // Close the socket
    close(sockfd);

    // Sleep for a random amount of time
    sleep(SLEEP_TIME);
  }

  return EXIT_SUCCESS;
}