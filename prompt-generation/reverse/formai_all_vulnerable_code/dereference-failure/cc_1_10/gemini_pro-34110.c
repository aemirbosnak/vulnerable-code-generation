//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char **argv)
{
  int sockfd, port;
  struct sockaddr_in servaddr;
  char *ip_address;
  char ports[MAX_PORTS][10];
  int num_ports;
  int i, j;
  int success;

  if (argc < 3)
  {
    printf("Usage: %s <IP address> <port1> <port2> ... <portN>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  ip_address = argv[1];
  num_ports = argc - 2;

  for (i = 0; i < num_ports; i++)
  {
    strcpy(ports[i], argv[i + 2]);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(ip_address);
  servaddr.sin_port = htons(0);

  for (i = 0; i < num_ports; i++)
  {
    port = atoi(ports[i]);
    servaddr.sin_port = htons(port);

    success = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (success == 0)
    {
      printf("Port %d is open\n", port);
    }
    else
    {
      printf("Port %d is closed\n", port);
    }
  }

  close(sockfd);

  return 0;
}