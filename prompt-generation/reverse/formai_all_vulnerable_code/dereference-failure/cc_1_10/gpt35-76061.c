//FormAI DATASET v1.0 Category: Client Server Application ; Style: visionary
/*
  Visionary Communication Chat Server

  This program implements a client-server chat application where multiple clients can connect to the server and communicate with each other.

  To start the server, open a terminal window and run the program with the port number as a command line argument:
  $ ./chat_server 9000

  To connect to the server, open a new terminal window and run the following command:
  $ telnet localhost 9000

  Once connected, each client can send messages to the server, which will forward them to all other connected clients. To disconnect, the client can simply close the terminal window.

  This program uses socket programming to establish the connections between the client and server.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 50
#define BUFFER_SIZE 2048

void *handle_client(void *);
void broadcast_message(char *, int, int);

int client_count = 0;
int clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
    exit(1);
  }

  int port_number = atoi(argv[1]);

  int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port_number);

  bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));

  listen(server_socket_fd, MAX_CLIENTS);

  printf("Starting Visionary Communication Chat Server on port %d\n", port_number);

  while (1) {

    int client_socket_fd = accept(server_socket_fd, NULL, NULL);

    pthread_mutex_lock(&mutex);

    clients[client_count++] = client_socket_fd;

    pthread_t new_thread;
    pthread_create(&new_thread, NULL, handle_client, (void *)&client_socket_fd);

    pthread_mutex_unlock(&mutex);
  }

  return 0;
}

void *handle_client(void *arg) {

  int client_socket_fd = *(int *)arg;

  char buffer[BUFFER_SIZE];
  int bytes_received = 0;

  while ((bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {

    broadcast_message(buffer, bytes_received, client_socket_fd);
    memset(buffer, 0, BUFFER_SIZE);
  }

  close(client_socket_fd);

  pthread_mutex_lock(&mutex);

  for (int i = 0; i < client_count; i++) {
    if (clients[i] == client_socket_fd) {
      while (i < client_count - 1) {
        clients[i] = clients[i+1];
        i++;
      }
      break;
    }
  }

  client_count--;

  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
}

void broadcast_message(char *message, int length, int sender_socket_fd) {

  pthread_mutex_lock(&mutex);

  for (int i = 0; i < client_count; i++) {

    if (clients[i] != sender_socket_fd) {

      int bytes_sent = send(clients[i], message, length, 0);
      if (bytes_sent < 0) {
        printf("Error broadcasting message to client %d\n", clients[i]);
      }
    }
  }

  pthread_mutex_unlock(&mutex);
}