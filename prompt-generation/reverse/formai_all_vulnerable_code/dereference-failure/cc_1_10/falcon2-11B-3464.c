//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 500

int main() {
  struct sockaddr_in serverAddr;
  struct hostent* serverHostInfo;
  struct sockaddr_in clientAddr;
  char buffer[MAX_PACKET_SIZE];
  char packet[MAX_PACKET_SIZE];
  int serverSocket, clientSocket, i;

  serverHostInfo = gethostbyname("localhost");
  if (serverHostInfo == NULL) {
    printf("Error: Unable to find host information for 'localhost'\n");
    return -1;
  }

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(5000);
  serverAddr.sin_addr.s_addr = *(long int *)serverHostInfo->h_addr_list[0];

  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket < 0) {
    printf("Error: Unable to create socket\n");
    return -1;
  }

  if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    printf("Error: Unable to bind socket\n");
    return -1;
  }

  if (listen(serverSocket, 3) < 0) {
    printf("Error: Unable to listen on socket\n");
    return -1;
  }

  while (1) {
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, (socklen_t*)&i);
    if (clientSocket < 0) {
      printf("Error: Unable to accept connection\n");
      continue;
    }

    printf("Connection from: %s, Port: %d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    char* address = (char*)malloc(MAX_PACKET_SIZE);
    if (address == NULL) {
      printf("Error: Unable to allocate memory for address\n");
      continue;
    }

    read(clientSocket, address, MAX_PACKET_SIZE);
    printf("Received message: %s\n", address);

    sprintf(packet, "Hello from the server!\n");
    write(clientSocket, packet, strlen(packet));

    close(clientSocket);
  }

  return 0;
}