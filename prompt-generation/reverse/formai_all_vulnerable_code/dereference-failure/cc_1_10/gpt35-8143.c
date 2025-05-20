//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define DSCP_OFFSET 1

void print_dscp_status(uint8_t dscp_value) {
  switch (dscp_value >> 2) {
    case 0:
      printf("Best Effort (BE)");
      break;
    case 1:
      printf("Priority (CS1)");
      break;
    case 2:
      printf("Immediate (CS2)");
      break;
    case 3:
      printf("Flash (CS3)");
      break;
    case 4:
      printf("Flash Override (CS4)");
      break;
    case 5:
      printf("Critical (CS5)");
      break;
    case 6:
      printf("Internet (CS6)");
      break;
    case 7:
      printf("Network Control (CS7)");
      break;
    default:
      printf("Invalid DSCP value");
      break;
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: ./qos-monitor <port>\n");
    exit(EXIT_FAILURE);
  }

  uint16_t port_number = atoi(argv[1]);

  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_number);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  printf("QoS Monitor started...\n");

  while (true) {
    int n_recv = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &client_addr_len);
    if (n_recv < 0) {
      perror("Error receiving data");
      continue; // ignore and move on to next packet
    }

    uint8_t dscp_value = (uint8_t)buffer[DSCP_OFFSET];
    printf("Received packet from %s:%d with DSCP value %d (%s)\n",
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port),
           dscp_value >> 2,
           ((dscp_value & 0x03) == 0) ? "Low Drop Probability" : "High Drop Probability");
  }

  return 0; 
}