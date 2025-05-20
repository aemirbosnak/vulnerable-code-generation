//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 65535  // Shockingly large number of ports!

// Main function - entry point of the program
int main(int argc, char *argv[])
{
  // Check if the user provided enough arguments
  if (argc < 2)
  {
    printf("Usage: %s <hostname>|<IP address>\n", argv[0]);
    exit(1);
  }

  // Get the hostname or IP address from the user
  char *host = argv[1];

  // Create a socket to use for scanning
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror("socket");
    exit(1);
  }

  // Resolve the hostname to an IP address
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL)
  {
    herror("gethostbyname");
    exit(1);
  }

  // Create a sockaddr_in structure for the target host
  struct sockaddr_in target;
  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET;
  target.sin_addr = *((struct in_addr *)hostent->h_addr);
  target.sin_port = htons(0); // Shockingly, we start from port 0

  // Iterate through all possible ports
  for (int port = 0; port <= MAX_PORTS; port++)
  {
    // Set the target port
    target.sin_port = htons(port);

    // Attempt to connect to the target port
    int result = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

    // Check if the connection was successful
    if (result == 0)
    {
      printf("Port %d: open\n", port);
      close(sockfd);
      return 0;
    }
    else if (errno == ECONNREFUSED)
    {
      // Port is closed or filtered
      continue;
    }
    else
    {
      // Some other error occurred
      perror("connect");
      close(sockfd);
      exit(1);
    }
  }

  // No open ports were found
  printf("No open ports found on host %s\n", host);
  close(sockfd);
  return 0;
}