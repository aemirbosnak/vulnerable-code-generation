//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_CLIENTS 10
#define BUF_SIZE 1024

typedef struct client_info {
  int sockfd;
  char* username;
  struct client_info* next;
} client_info;

client_info* clients = NULL;

int create_server_socket(int port) {
  int sockfd;
  struct sockaddr_in servaddr;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(port);

  if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    exit(1);
  }

  if(listen(sockfd, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(1);
  }

  return sockfd;
}

client_info* create_client_info(int sockfd) {
  client_info* new_client = malloc(sizeof(client_info));
  new_client->sockfd = sockfd;
  new_client->username = NULL;
  new_client->next = NULL;
  return new_client;
}

void add_client(client_info* client) {
  if(clients == NULL) {
    clients = client;
  } else {
    client_info* curr = clients;
    while(curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = client;
  }
}

void remove_client(int sockfd) {
  if(clients == NULL) {
    return;
  } else if(clients->sockfd == sockfd) {
    clients = clients->next;
  } else {
    client_info* curr = clients;
    while(curr->next != NULL) {
      if(curr->next->sockfd == sockfd) {
        curr->next = curr->next->next;
        break;
      }
      curr = curr->next;
    }
  }
}

int get_client_sockfd(char* username) {
  client_info* curr = clients;
  while(curr != NULL) {
    if(strcmp(curr->username, username) == 0) {
      return curr->sockfd;
    }
    curr = curr->next;
  }
  return -1;
}

void send_message_to_all(char* message, char* sender) {
  client_info* curr = clients;
  while(curr != NULL) {
    if(strcmp(curr->username, sender) != 0) {
      send(curr->sockfd, message, strlen(message), 0);
    }
    curr = curr->next;
  }
}

void handle_client(int sockfd) {
  char buf[BUF_SIZE];
  char* username = NULL;
  int nbytes;

  while(1) {
    if((nbytes = recv(sockfd, buf, sizeof(buf), 0)) <= 0) {
      if(nbytes == 0) {
        printf("Client disconnected\n");
      } else {
        perror("recv");
      }
      remove_client(sockfd);
      close(sockfd);
      break;
    }

    if(username == NULL) {
      username = strdup(buf);
      add_client(create_client_info(sockfd));
      send_message_to_all(username, "joined the chat");
    } else {
      send_message_to_all(buf, username);
    }
  }
}

int main() {
  int server_sockfd, client_sockfd;
  struct sockaddr_in cliaddr;
  socklen_t cliaddr_len;

  server_sockfd = create_server_socket(PORT);

  while(1) {
    cliaddr_len = sizeof(cliaddr);
    if((client_sockfd = accept(server_sockfd, (struct sockaddr*)&cliaddr, &cliaddr_len)) == -1) {
      perror("accept");
      continue;
    }

    printf("New client connected: %s\n", inet_ntoa(cliaddr.sin_addr));
    handle_client(client_sockfd);
  }

  close(server_sockfd);
  return 0;
}