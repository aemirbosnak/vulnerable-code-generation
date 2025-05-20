//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan
#define MAX_HOSTNAME_LEN 100 // maximum length of hostname

int main(int argc, char *argv[]) {
  int sock, port, i;
  struct sockaddr_in server_addr;
  char hostname[MAX_HOSTNAME_LEN];

  // check if enough arguments are provided
  if (argc < 2) {
    printf("Usage: %s <host_ip>\n", argv[0]);
    return 1;
  }

  // parse host IP address
  strcpy(hostname, argv[1]);

  // create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation failed");
    return 2;
  }

  // set up server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(hostname);
  server_addr.sin_port = htons(0); // listen on any available port

  // bind the socket to the address and port
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    return 3;
  }

  // listen for incoming connections
  if (listen(sock, 5) < 0) {
    perror("listen failed");
    return 4;
  }

  // loop through the range of ports and scan each one
  for (port = 1; port < PORT_RANGE; port++) {
    // create a new socket for the connection
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
      perror("socket creation failed");
      continue;
    }

    // connect to the server on the current port
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connect failed");
      close(client_sock);
      continue;
    }

    // send a request to the server to see if it's alive
    char request[] = "Hello, server!";
    send(client_sock, request, strlen(request), 0);

    // receive a response from the server
    char buffer[1024];
    recv(client_sock, buffer, 1024, 0);

    // print the response
    printf("Server responded with: %s\n", buffer);

    // close the client socket
    close(client_sock);
  }

  // close the listening socket
  close(sock);

  return 0;
}