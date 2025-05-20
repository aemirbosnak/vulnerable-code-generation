//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct port_info {
  int port;
  char name[50];
};

void print_port_info(struct port_info *ports, int count) {
  int i;

  for (i = 0; i < count; i++) {
    printf("%d - %s\n", ports[i].port, ports[i].name);
  }
}

int main(void) {
  int sock, port;
  struct sockaddr_in server_addr;
  struct port_info ports[PORT_RANGE];
  int count = 0;

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(0);

  // Bind the socket to the address and port
  bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for incoming connections
  listen(sock, 3);

  // Loop through all possible ports and perform a connect
  for (port = 1; port < PORT_RANGE; port++) {
    struct sockaddr_in client_addr;

    // Set up the client address
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(port);

    // Connect to the client
    connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));

    // Get the port name
    char *port_name = inet_ntoa(client_addr.sin_addr);
    strcpy(ports[count].name, port_name);
    ports[count].port = ntohs(client_addr.sin_port);
    count++;

    // Print the port information
    if (count % 10 == 0) {
      print_port_info(ports, count);
      count = 0;
    }
  }

  // Print the remaining port information
  print_port_info(ports, count);

  // Close the socket
  close(sock);

  return 0;
}