//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: Not enough arguments\n");
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 2;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  char buffer[1024];
  printf("Connecting to port %d...\n", server_addr.sin_port);
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    close(sock);
    return 3;
  }

  printf("Connected to port %d\n", server_addr.sin_port);

  int port = server_addr.sin_port;
  char *port_str = NULL;
  if (port > 0 && port <= MAX_PORTS) {
    port_str = malloc(sizeof(char) * 10);
    sprintf(port_str, "%d", port);
  }

  while (1) {
    int bytes_read = read(sock, buffer, 1024);
    if (bytes_read < 0) {
      perror("read() failed");
      break;
    }

    printf("Received message: %s\n", buffer);

    if (port_str != NULL) {
      printf("Port: %s\n", port_str);
    }

    if (bytes_read > 0) {
      write(sock, "Hello, Thompson's Port Scan-a-Tron 3000 here!", 28);
    }
  }

  close(sock);
  return 0;
}