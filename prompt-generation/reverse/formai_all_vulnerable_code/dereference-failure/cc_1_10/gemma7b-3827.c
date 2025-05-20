//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080

typedef struct Client {
  int sockfd;
  char ip[20];
  struct Client* next;
} Client;

Client* insertClient(Client* head, int sockfd, char* ip) {
  Client* newClient = malloc(sizeof(Client));
  newClient->sockfd = sockfd;
  strcpy(newClient->ip, ip);
  newClient->next = NULL;

  if (head == NULL) {
    head = newClient;
  } else {
    Client* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newClient;
  }

  return head;
}

void proxy(Client* head) {
  Client* currentClient = head;
  while (currentClient) {
    char buffer[1024];
    int bytesRead = recv(currentClient->sockfd, buffer, 1024, 0);
    if (bytesRead > 0) {
      printf("Received %d bytes from %s:\n", bytesRead, currentClient->ip);
      printf("Data: %s\n", buffer);

      char message[1024];
      printf("Enter your message: ");
      scanf("%s", message);

      int bytesSent = send(currentClient->sockfd, message, strlen(message), 0);
      if (bytesSent > 0) {
        printf("Sent %d bytes to %s:\n", bytesSent, currentClient->ip);
        printf("Message: %s\n", message);
      }
    }
    currentClient = currentClient->next;
  }
}

int main() {
  Client* head = NULL;

  int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  struct sockaddr_in sockAddr;
  sockAddr.sin_port = htons(PORT);
  bind(sockfd, (struct sockaddr*)&sockAddr, sizeof(sockAddr));

  printf("Proxy server listening on port %d...\n", PORT);

  while (1) {
    int newsockfd = accept(sockfd, NULL, NULL);
    insertClient(head, newsockfd, "UNKNOWN");
  }

  proxy(head);

  return 0;
}