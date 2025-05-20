//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

#define SCAN_RANGE 1000

int main()
{
  // Define the target IP address
  char target_ip[16] = "192.168.1.1";

  // Allocate memory for the port buffer
  int *ports = (int *)malloc(SCAN_RANGE * sizeof(int));

  // Initialize the ports array
  for (int i = 0; i < SCAN_RANGE; i++)
  {
    ports[i] = 0;
  }

  // Scan the ports
  for (int port = 1; port <= SCAN_RANGE; port++)
  {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Connect to the target IP
    struct sockaddr_in sock_addr;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr(target_ip);
    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == 0)
    {
      // Port is open, mark it as such in the buffer
      ports[port] = 1;
    }

    // Close the socket
    close(sockfd);
  }

  // Print the ports that are open
  for (int i = 1; i <= SCAN_RANGE; i++)
  {
    if (ports[i] == 1)
    {
      printf("Port %d is open.\n", i);
    }
  }

  // Free the memory
  free(ports);

  return 0;
}