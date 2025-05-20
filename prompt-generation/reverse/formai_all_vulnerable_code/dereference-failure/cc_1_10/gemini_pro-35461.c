//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define MAX_MSG_LEN 512

struct client {
  int sockfd;
  char username[50];
  pthread_t thread;
};

struct server {
  int sockfd;
  struct client clients[MAX_CLIENTS];
  int num_clients;
};

void server_init(struct server *server) {
  // Create a socket
  server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (server->sockfd == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to an address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(50000);

  if (bind(server->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(server->sockfd, MAX_CLIENTS) == -1) {
    perror("Error listening for connections");
    exit(EXIT_FAILURE);
  }
}

void server_handle_client(struct server *server, int client_sockfd) {
  char msg_buf[MAX_MSG_LEN];
  int msg_len;

  // Receive the username
  if ((msg_len = recv(client_sockfd, msg_buf, MAX_MSG_LEN, 0)) == -1) {
    perror("Error receiving username");
    close(client_sockfd);
    return;
  }

  // Add the client to the list of clients
  strcpy(server->clients[server->num_clients].username, msg_buf);
  server->clients[server->num_clients].sockfd = client_sockfd;
  server->num_clients++;

  // Send a welcome message
  strcpy(msg_buf, "Welcome to the Cyberpunk Chat Server!");
  if (send(client_sockfd, msg_buf, strlen(msg_buf), 0) == -1) {
    perror("Error sending welcome message");
    close(client_sockfd);
    return;
  }

  // Receive and broadcast messages
  while ((msg_len = recv(client_sockfd, msg_buf, MAX_MSG_LEN, 0)) > 0) {
    // Check if the client is leaving
    if (strcmp(msg_buf, "/leave") == 0) {
      break;
    }

    // Broadcast the message to all other clients
    for (int i = 0; i < server->num_clients; i++) {
      if (server->clients[i].sockfd != client_sockfd) {
        if (send(server->clients[i].sockfd, msg_buf, msg_len, 0) == -1) {
          perror("Error broadcasting message");
          close(client_sockfd);
          return;
        }
      }
    }
  }

  // Remove the client from the list of clients
  for (int i = 0; i < server->num_clients; i++) {
    if (server->clients[i].sockfd == client_sockfd) {
      server->clients[i] = server->clients[server->num_clients - 1];
      server->num_clients--;
      break;
    }
  }

  // Close the client socket
  close(client_sockfd);
}

void *server_thread(void *arg) {
  struct server *server = (struct server *)arg;

  // Accept connections
  while (1) {
    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    client_sockfd = accept(server->sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd == -1) {
      perror("Error accepting connection");
      continue;
    }

    // Handle the client
    server_handle_client(server, client_sockfd);
  }

  return NULL;
}

int main() {
  struct server server;

  // Initialize the server
  server_init(&server);

  // Start the server thread
  pthread_t thread;
  if (pthread_create(&thread, NULL, server_thread, &server) != 0) {
    perror("Error creating server thread");
    exit(EXIT_FAILURE);
  }

  // Join the server thread
  if (pthread_join(thread, NULL) != 0) {
    perror("Error joining server thread");
    exit(EXIT_FAILURE);
  }

  // Close the server socket
  close(server.sockfd);

  return 0;
}