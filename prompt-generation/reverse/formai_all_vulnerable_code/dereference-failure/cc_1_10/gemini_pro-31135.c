//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

// A surrealist symphony of constants
#define MAX_HEADER_SIZE 4096
#define MAX_BODY_SIZE 8192
#define MAX_CONNECTIONS 10
#define PORT 8080
#define TIMEOUT 10

// The gates to the ethereal realms
struct sockaddr_in server_addr, client_addr;
socklen_t server_len, client_len;

// The ethereal tapestry
char header[MAX_HEADER_SIZE], body[MAX_BODY_SIZE];
ssize_t header_len, body_len;

// The ethereal dancers
pthread_t threads[MAX_CONNECTIONS];
int thread_count;

// The ethereal ballet
void *handle_connection(void *arg) {
  int client_fd = (int) arg;
  while (true) {
    // Receive the ethereal whispers from the client
    header_len = recv(client_fd, header, MAX_HEADER_SIZE, 0);
    if (header_len < 0) {
      perror("recv");
      break;
    } else if (header_len == 0) {
      break;
    }
    // Parse the ethereal whispers
    char *request_line = strtok(header, "\r\n");
    char *method = strtok(request_line, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, " ");

    // Connect to the ethereal realm
    struct hostent *host = gethostbyname(path);
    if (host == NULL) {
      perror("gethostbyname");
      break;
    }
    // Get the port from the ethereal realm
    in_port_t port = htons(80);

    // Open a portal to the ethereal realm
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
      perror("socket");
      break;
    }

    // Bind our ethereal gateway to the portal
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = port;
    server_addr.sin_addr = *(struct in_addr*) host->h_addr_list[0];
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
      perror("bind");
      break;
    }

    // Knock on the ethereal realm
    if (connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
      perror("connect");
      break;
    }

    // Send the ethereal whispers to the realm
    if (send(server_fd, header, header_len, 0) < 0) {
      perror("send");
      break;
    }

    // Receive the ethereal whispers from the realm
    body_len = recv(server_fd, body, MAX_BODY_SIZE, 0);
    if (body_len < 0) {
      perror("recv");
      break;
    }

    // Send the ethereal whispers to the client
    if (send(client_fd, body, body_len, 0) < 0) {
      perror("send");
      break;
    }

    // Close the portal to the ethereal realm
    close(server_fd);
  }
  close(client_fd);

  return NULL;
}

int main() {
  // Open the gates to the ethereal realms
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    exit(1);
  }

  // Bind our ethereal gateway to the gates
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Open the gates to the ethereal realms
  if (listen(server_fd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    exit(1);
  }

  // Welcome the ethereal dancers to the ballet
  while (true) {
    client_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len);
    if (client_fd < 0) {
      perror("accept");
      continue;
    }

    if (thread_count < MAX_CONNECTIONS) {
      pthread_create(&threads[thread_count++], NULL, handle_connection, (void*) client_fd);
    } else {
      close(client_fd);
    }
  }

  // Close the gates to the ethereal realms
  close(server_fd);

  return 0;
}