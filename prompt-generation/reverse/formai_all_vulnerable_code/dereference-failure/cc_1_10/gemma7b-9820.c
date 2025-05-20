//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 100

int main() {
  int i, host_count = 0, status;
  char **hosts = NULL;

  // Allocate memory for the hosts array
  hosts = malloc(MAX_HOSTS * sizeof(char *));
  if (hosts == NULL) {
    perror("malloc");
    exit(1);
  }

  // Get the host list from the user
  printf("Enter a list of hosts, separated by commas: ");
  char host_list[1024];
  fgets(host_list, 1024, stdin);

  // Split the host list into individual hosts
  char *host_parts = strtok(host_list, ",");
  while (host_parts) {
    hosts[host_count++] = strdup(host_parts);
    host_parts = strtok(NULL, ",");
  }

  // Ping each host
  for (i = 0; i < host_count; i++) {
    status = ping(hosts[i]);
    if (status == 0) {
      printf("%s is alive.\n", hosts[i]);
    } else {
      printf("%s is not alive.\n", hosts[i]);
    }
  }

  // Free the memory allocated for the hosts array
  free(hosts);

  return 0;
}

int ping(char *host) {
  int sockfd, status;
  struct sockaddr_in sock_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_RAW, htons(5));
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set up the socket address
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(53);
  sock_addr.sin_addr.s_addr = inet_addr(host);

  // Send a ping packet
  unsigned char message[1] = "P";
  sendto(sockfd, message, 1, 0, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

  // Receive the reply packet
  unsigned char reply[1];
  recvfrom(sockfd, reply, 1, 0, (struct sockaddr *)&sock_addr, NULL);

  // Check if the reply is positive
  if (reply[0] == 'R') {
    status = 0;
  } else {
    status = -1;
  }

  // Close the socket
  close(sockfd);

  return status;
}