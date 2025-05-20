//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 256

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s <hostname> <port1> <port2> ...\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the hostname and port numbers from the command line arguments
  char hostname[MAX_HOST_LEN];
  strncpy(hostname, argv[1], MAX_HOST_LEN - 1);
  hostname[MAX_HOST_LEN - 1] = '\0';

  int ports[argc - 2];
  for (int i = 2; i < argc; i++)
  {
    ports[i - 2] = atoi(argv[i]);
  }

  // Create a socket for the port scanner
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set up the socket address structure
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80); // Use port 80 for testing
  addr.sin_addr.s_addr = inet_addr(hostname);

  // Scan the specified ports
  for (int i = 0; i < argc - 2; i++)
  {
    // Set the port number in the socket address structure
    addr.sin_port = htons(ports[i]);

    // Try to connect to the port
    int connfd = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

    // Check if the connection was successful
    if (connfd == 0)
    {
      printf("Port %d is open\n", ports[i]);
    }
    else
    {
      printf("Port %d is closed\n", ports[i]);
    }

    // Close the connection
    close(connfd);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}