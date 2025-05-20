//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int clientSocket, result;
  char clientMessage[BUFSIZE], serverResponse[BUFSIZE];
  struct sockaddr_in serverAddress;
  struct hostent *hostInfo;

  char *host = argv[1];
  char *port = argv[2];
  char *path = argv[3];

  // check if the user provided the necessary arguments
  if (argc != 4) {
    printf("Usage: %s <hostname> <port> <path>\n", argv[0]);
    exit(1);
  }

  // resolve host domain name to IP address 
  hostInfo = gethostbyname(host); 
  if(!hostInfo) {
    printf("Error: Invalid host name %s\n", host);
    exit(1);
  }

  // create a socket 
  clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (clientSocket < 0) {
    perror("Error: Failed to create socket");
    exit(1);
  } 

  // specify the server address and port
  memset(&serverAddress, 0, sizeof(serverAddress)); 
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(atoi(port));
  serverAddress.sin_addr = *((struct in_addr *)hostInfo->h_addr);

  // connect to the server 
  result = connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  if(result < 0) {
    perror("Error: Failed to connect to server");
    exit(1);
  }

  // craft the HTTP request 
  sprintf(clientMessage, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

  // send the HTTP request to server
  result = send(clientSocket, clientMessage, strlen(clientMessage), 0);
  if(result < 0) {
    perror("Error: Failed to send message to server");
    exit(1);
  }

  // receive the HTTP response from server
  while(true) {
    memset(serverResponse, 0, BUFSIZE);
    result = recv(clientSocket, serverResponse, BUFSIZE, 0);
    if(result <= 0) break;
    printf("%s", serverResponse);
  }

  // close the socket 
  close(clientSocket);
  
  return 0;
}