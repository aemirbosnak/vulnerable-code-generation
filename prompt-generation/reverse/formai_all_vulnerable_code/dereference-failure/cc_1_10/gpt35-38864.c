//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./port_scanner <IP Address>\n");
    return 1; // Improper number of arguments, exit program
  }

  char *ip_address = argv[1];

  struct hostent *he;
  he = gethostbyname(ip_address);
  if (he == NULL) {
    printf("Error: Cannot resolve IP address %s\n", ip_address);
    return 1; // Failed to resolve IP address, exit program
  }

  int socket_descriptor;
  struct sockaddr_in server;
  int port;

  printf("-------------------------------\n");
  printf("Port Scanner\n");
  printf("IP Address: %s\n", ip_address);
  printf("-------------------------------\n\n");

  for (port = 1; port <= 65535; port++) {
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor < 0) {
      printf("Error: Cannot open socket\n");
      return 1; // Failed to open socket, exit program
    }

    server.sin_family = AF_INET;
    server.sin_addr = *((struct in_addr *) he->h_addr);
    server.sin_port = htons(port);

    int connection_status = connect(socket_descriptor, (struct sockaddr *) &server, sizeof(server));
    if (connection_status == 0) {
      printf("Port %d: Open\n", port);
    } else {
      printf("Port %d: Closed\n", port);
    }

    close(socket_descriptor);
  }

  printf("\n-------------------------------\n");
  printf("Scan Complete\n");
  printf("-------------------------------\n");

  return 0;
}