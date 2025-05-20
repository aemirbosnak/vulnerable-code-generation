//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct _ClientData {
  char username[256];
  char password[256];
  char host[256];
  int port;
  int sockfd;
  struct _ClientData* next;
} ClientData;

ClientData* createClientData(char* username, char* password, char* host, int port) {
  ClientData* data = (ClientData*)malloc(sizeof(ClientData));
  strcpy(data->username, username);
  strcpy(data->password, password);
  strcpy(data->host, host);
  data->port = port;
  data->sockfd = -1;
  data->next = NULL;
  return data;
}

void connectClient(ClientData* data) {
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(data->port));
  struct sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(data->port);
  inet_aton(data->host, &sockaddr.sin_addr);
  connect(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
  data->sockfd = sockfd;
}

void sendCommand(ClientData* data, char* command) {
  char buffer[MAX_BUFFER_SIZE];
  sprintf(buffer, "%s\r\n", command);
  send(data->sockfd, buffer, strlen(buffer), 0);
}

void receiveResponse(ClientData* data) {
  char buffer[MAX_BUFFER_SIZE];
  int bytesRead = recv(data->sockfd, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s", buffer);
}

int main() {
  ClientData* head = createClientData("johndoe", "secret", "localhost", 21);
  connectClient(head);
  sendCommand(head, "LIST");
  receiveResponse(head);
  return 0;
}