//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef struct {
  char ip[INET_ADDRSTRLEN];
  int port;
  int status;
} ScanResult;

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <IP_ADDRESS> <START_PORT> <END_PORT>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char ip[INET_ADDRSTRLEN];
  strcpy(ip, argv[1]);
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  int sockfd;
  struct sockaddr_in serv_addr;

  printf("Scanning ports on %s (%s) from %d to %d...\n", ip, inet_ntoa(*(struct in_addr *)(&serv_addr.sin_addr)), start_port, end_port);

  ScanResult *results = malloc(sizeof(ScanResult) * (end_port - start_port + 1));

  for (int i = start_port; i <= end_port; i++) {
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(i);

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
      perror("Error converting IP to binary format");
      exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("Error creating socket");
      exit(EXIT_FAILURE);
    }

    int connected = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (connected < 0) {
      results[i - start_port].port = i;
      results[i - start_port].status = 0;
      continue;
    }

    close(sockfd);

    results[i - start_port].port = i;
    results[i - start_port].status = 1;

    printf("Port %d on %s open\n", i, ip);
  }

  free(results);

  printf("Scan complete.\n");
  return EXIT_SUCCESS;
}