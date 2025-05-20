//FormAI DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MAX_CLIENTS 30

static int client_sockets[MAX_CLIENTS] = {0};
static volatile int num_clients = 0;

void send_to_all_clients(const char* message) {
  for (int i = 0; i < num_clients; ++i) {
    write(client_sockets[i], message, strlen(message));
  }
}

void handle_new_connection(int master_socket) {
  int new_socket;
  struct sockaddr_in addr;
  int addr_len = sizeof(addr);
  if ((new_socket = accept(master_socket, (struct sockaddr*)&addr, (socklen_t*)&addr_len)) < 0) {
    perror("accept");
    return;
  }
  printf("New connection: %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
  client_sockets[num_clients++] = new_socket;
  send_to_all_clients("New client connected!\n");
}

void handle_client_message(int client_socket) {
  char buffer[1024] = {0};
  if (read(client_socket, buffer, 1024) == 0) {
    printf("Client disconnected\n");
    for (int i = 0; i < num_clients; ++i) {
      if (client_sockets[i] == client_socket) {
        client_sockets[i] = client_sockets[num_clients-1];
        --num_clients;
      }
    }
    close(client_socket);
  } else {
    printf("Received message: %s", buffer);
    send_to_all_clients(buffer);
  }
}

int main(int argc, char** argv) {

  int master_socket;
  struct sockaddr_in addr;

  if((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);

  if (bind(master_socket, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if(listen(master_socket, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d\n", PORT);

  while (1) {

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(master_socket, &read_fds);
    for (int i = 0; i < num_clients; ++i) {
      FD_SET(client_sockets[i], &read_fds);
    }

    if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
      perror("select");
      exit(EXIT_FAILURE);
    }

    if (FD_ISSET(master_socket, &read_fds)) {
      handle_new_connection(master_socket);
    }

    for (int i = 0; i < num_clients; ++i) {
      if (FD_ISSET(client_sockets[i], &read_fds)) {
        handle_client_message(client_sockets[i]);
      }
    }

  }

  return 0;
}