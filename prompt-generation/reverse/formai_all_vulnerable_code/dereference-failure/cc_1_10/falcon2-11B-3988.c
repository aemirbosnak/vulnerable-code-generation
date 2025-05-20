//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main() {
  int socket_fd, valread;
  int portno = 12345;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Create socket
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Resolve server address
  server = gethostbyname("localhost");
  if (server == NULL) {
    perror("ERROR, no such host");
    exit(1);
  }

  // Assign server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to server
  if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send data
  if (send(socket_fd, "Hello, World!", 13, 0) < 0) {
    perror("ERROR sending data");
    exit(1);
  }

  // Receive data
  valread = recv(socket_fd, "Received Data", 13, 0);
  if (valread < 0) {
    perror("ERROR receiving data");
    exit(1);
  }

  // Print data
  printf("Received data: %s\n", "Received Data");

  // Close socket
  close(socket_fd);

  return 0;
}