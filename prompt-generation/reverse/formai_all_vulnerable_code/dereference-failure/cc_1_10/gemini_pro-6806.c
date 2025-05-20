//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define the port range to scan
#define START_PORT 1
#define END_PORT 65535

// Define the maximum number of concurrent connections
#define MAX_CONNECTIONS 100

// Create a socket and connect to the specified host and port
int connect_to_host(char *host, int port) {
  int sockfd;
  struct sockaddr_in server_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return -1;
  }

  // Resolve the host name
  struct hostent *host_entry = gethostbyname(host);
  if (host_entry == NULL) {
    perror("Error resolving host name");
    return -1;
  }

  // Set the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *((struct in_addr *)host_entry->h_addr);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    return -1;
  }

  return sockfd;
}

// Scan the specified host for open ports
void scan_host(char *host) {
  int i, sockfd;

  // Iterate through the port range
  for (i = START_PORT; i <= END_PORT; i++) {
    // Connect to the host on the current port
    sockfd = connect_to_host(host, i);

    // Check if the connection was successful
    if (sockfd != -1) {
      printf("Port %d is open\n", i);
      close(sockfd);
    }
  }
}

// Get the host name from the user
char *get_host_name() {
  char *host_name;
  size_t host_name_len;

  // Allocate memory for the host name
  host_name = (char *)malloc(256);
  if (host_name == NULL) {
    perror("Error allocating memory for host name");
    return NULL;
  }

  // Prompt the user for the host name
  printf("Enter the host name: ");
  host_name_len = getline(&host_name, &host_name_len, stdin);
  if (host_name_len <= 0) {
    perror("Error getting host name");
    return NULL;
  }

  // Remove the newline character from the host name
  host_name[strlen(host_name) - 1] = '\0';

  return host_name;
}

// Main function
int main() {
  char *host_name;

  // Get the host name from the user
  host_name = get_host_name();
  if (host_name == NULL) {
    return EXIT_FAILURE;
  }

  // Scan the host for open ports
  scan_host(host_name);

  // Free the memory allocated for the host name
  free(host_name);

  return EXIT_SUCCESS;
}