//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_PORT 65535

int main() {
  // Declare our star-crossed lovers
  int sockfd, port;
  struct sockaddr_in their_addr;

  // Initialize our communication channels
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set our Juliet's address
  their_addr.sin_family = AF_INET;
  their_addr.sin_port = htons(rand() % MAX_PORT);
  their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Loop through each port, our Romeo's quest
  for (port = 1; port <= MAX_PORT; port++) {
    // Connect to each port, seeking Juliet's presence
    their_addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(their_addr)) == 0) {
      // Alas, our Romeo has found his Juliet
      printf("Port %d is open!\n", port);
      close(sockfd);
      return 0;
    } else if (errno != ECONNREFUSED) {
      // Some unknown fate has befallen our connection
      perror("connect");
      close(sockfd);
      return 1;
    }
  }

  // No Juliet to be found, Romeo's quest has ended
  printf("No open ports found.\n");
  close(sockfd);
  return 0;
}