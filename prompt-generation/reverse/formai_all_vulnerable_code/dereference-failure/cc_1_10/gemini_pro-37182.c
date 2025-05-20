//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024
#define MAXCLIENTS 10

char *greetings[] = {
  "Welcome to the chat server!",
  "Glad to have you here!",
  "Let's chat!",
  "Feel free to express yourself!",
  "No topic is taboo.",
  "Please be respectful of other users."
};

typedef struct client {
  int sockfd;
  struct sockaddr_in addr;
  pthread_t thread;
  char username[50];
  char message[BUFSIZE];
} client;

typedef struct chatroom {
  int num_clients;
  client clients[MAXCLIENTS];
} chatroom;

chatroom room;

void *handle_client(void *arg) {
  client *c = (client *)arg;
  int bytes_read;

  // Greet the client
  strcpy(c->message, greetings[rand() % (sizeof(greetings) / sizeof(char *))]);
  send(c->sockfd, c->message, strlen(c->message), 0);

  // Receive messages from the client
  while ((bytes_read = recv(c->sockfd, c->message, BUFSIZE, 0)) > 0) {
    // Process the message and echo it back to the client
    if (bytes_read >= 4 && strncmp(c->message, "/quit", 4) == 0) {
      // Client wants to quit
      send(c->sockfd, "Goodbye!", 7, 0);
      close(c->sockfd);
      pthread_exit(NULL);
    } else {
      // Echo the message back to the client
      send(c->sockfd, c->message, bytes_read, 0);
    }
  }

  // Client disconnected
  for (int i = 0; i < room.num_clients; i++) {
    if (room.clients[i].sockfd == c->sockfd) {
      // Remove the client from the chatroom
      room.clients[i] = room.clients[room.num_clients - 1];
      room.num_clients--;
      break;
    }
  }

  pthread_exit(NULL);
}

int main() {
  // Initialize the chatroom
  room.num_clients = 0;

  // Create the server socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the server socket to the IP address and port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  if (listen(sockfd, MAXCLIENTS) == -1) {
    perror("Error listening for clients");
    exit(1);
  }

  // Accept clients and create threads to handle them
  while (1) {
    client c;
    socklen_t addrlen = sizeof(c.addr);
    c.sockfd = accept(sockfd, (struct sockaddr *)&c.addr, &addrlen);
    if (c.sockfd == -1) {
      perror("Error accepting client");
      continue;
    }

    // Get the client's username
    recv(c.sockfd, c.username, sizeof(c.username), 0);

    // Add the client to the chatroom
    room.clients[room.num_clients] = c;
    room.num_clients++;

    // Create a thread to handle the client
    pthread_create(&c.thread, NULL, handle_client, (void *)&c);
  }

  // Close the server socket
  close(sockfd);

  return 0;
}