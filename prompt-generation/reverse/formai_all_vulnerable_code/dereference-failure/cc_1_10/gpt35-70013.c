//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if(argc != 3) {
    fprintf(stderr,"Usage: %s <ip_address> <port>\n", argv[0]);
    exit(1);
  }

  char *ip_address = argv[1];
  int port = atoi(argv[2]);

  int sock = socket(AF_INET, SOCK_STREAM, 0);

  if(sock < 0) {
    perror("Failed to create socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
    perror("Failed to convert IP address");
    exit(1);
  }

  if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Failed to connect to server");
    exit(1);
  }

  printf("Connected to server\n");

  // Send a message to the server
  char message[256] = "Hello, server!";
  int len = strlen(message);
  int sent = send(sock, message, len, 0);

  if(sent == -1) {
    perror("Failed to send message to server");
    exit(1);
  }

  printf("Sent message to server: %s\n", message);

  // Receive a message from the server
  char response[256];
  int received = recv(sock, response, sizeof(response), 0);

  if(received == -1) {
    perror("Failed to receive message from server");
    exit(1);
  }

  printf("Received message from server: %s\n", response);

  close(sock);

  return 0;
}