//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <netdb.h>

#define MAX_CONNECTIONS 100
#define PORT_START 1
#define PORT_END 1000

int main(int argc, char *argv[]) {
  int server_fd, port_no, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(PORT_START);

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  for (port_no = PORT_START; port_no <= PORT_END; port_no++) {
    if (port_no == PORT_START) {
      serv_addr.sin_port = htons(port_no);
    } else {
      serv_addr.sin_port = htons(port_no + 1);
    }

    if (connect(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("Error connecting");
      exit(1);
    }

    n = write(server_fd, "Hello, world!\n", 13);
    if (n < 0) {
      perror("Error writing");
      exit(1);
    }

    n = read(server_fd, "Received: ", 11);
    if (n < 0) {
      perror("Error reading");
      exit(1);
    }

    printf("Port %d is open\n", ntohs(serv_addr.sin_port));

    close(server_fd);
  }

  return 0;
}