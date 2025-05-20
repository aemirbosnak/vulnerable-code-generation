//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_PORTS 100

int main() {
  // Initialize variables
  int sockfd, n, i, j, k;
  struct sockaddr_in servaddr;
  char **hostnames;
  int *ports;
  int **matrix;

  // Allocate memory for hostnames, ports, and matrix
  hostnames = malloc(sizeof(char *) * MAX_HOSTS);
  ports = malloc(sizeof(int) * MAX_PORTS);
  matrix = malloc(sizeof(int *) * MAX_HOSTS);

  // Initialize hostnames, ports, and matrix
  for (i = 0; i < MAX_HOSTS; i++) {
    hostnames[i] = malloc(sizeof(char) * 100);
    matrix[i] = malloc(sizeof(int) * MAX_PORTS);
  }

  for (i = 0; i < MAX_PORTS; i++) {
    ports[i] = 0;
  }

  // Get hostname and port from user
  printf("Enter hostname: ");
  scanf("%s", hostnames[0]);
  printf("Enter port: ");
  scanf("%d", &ports[0]);

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // Set server address
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(ports[0]);
  servaddr.sin_addr.s_addr = inet_addr(hostnames[0]);

  // Connect to server
  connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Send hostname and port to server
  n = write(sockfd, &hostnames[0], strlen(hostnames[0]));
  n = write(sockfd, &ports[0], sizeof(ports[0]));

  // Receive matrix from server
  for (i = 0; i < MAX_HOSTS; i++) {
    for (j = 0; j < MAX_PORTS; j++) {
      n = read(sockfd, &matrix[i][j], sizeof(matrix[i][j]));
    }
  }

  // Close socket
  close(sockfd);

  // Print matrix
  for (i = 0; i < MAX_HOSTS; i++) {
    for (j = 0; j < MAX_PORTS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < MAX_HOSTS; i++) {
    free(hostnames[i]);
    free(matrix[i]);
  }

  free(hostnames);
  free(ports);
  free(matrix);

  return 0;
}