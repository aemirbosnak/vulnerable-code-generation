//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Structure to pass as argument to the thread
typedef struct {
  int client_sock;
  struct sockaddr_in client_addr;
} thread_arg_t;

// Function executed by the thread
void *client_thread(void *arg) {
  thread_arg_t *thread_arg = (thread_arg_t *) arg;
  int client_sock = thread_arg->client_sock;

  // Read data from the client
  char buffer[1024] = {0};
  ssize_t bytes_read = read(client_sock, buffer, sizeof(buffer));
  if (bytes_read < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Process data
  printf("Received %ld bytes from %s:%d\n", bytes_read,
    inet_ntoa(thread_arg->client_addr.sin_addr),
    ntohs(thread_arg->client_addr.sin_port));
  buffer[bytes_read] = '\0';
  printf("Data: %s\n", buffer);

  // Send response to the client
  char response[] = "Hello, client!";
  ssize_t bytes_sent = write(client_sock, response, sizeof(response)-1);
  if (bytes_sent < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  printf("Sent %ld bytes to %s:%d\n", bytes_sent,
    inet_ntoa(thread_arg->client_addr.sin_addr),
    ntohs(thread_arg->client_addr.sin_port));

  // Close connection
  close(client_sock);

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s PORT\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create socket
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Bind to address
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(atoi(argv[1]));
  if (bind(server_sock, (struct sockaddr *) &server_addr,
      sizeof(server_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(server_sock, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %s ...\n", argv[1]);

  // Accept connections and spawn thread for each client
  while (1) {
    struct sockaddr_in client_addr = {0};
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr *) &client_addr,
      &client_addr_len);
    if (client_sock < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    printf("Client connected from %s:%d\n",
      inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    pthread_t thread;
    thread_arg_t *thread_arg = malloc(sizeof(thread_arg_t));
    thread_arg->client_sock = client_sock;
    thread_arg->client_addr = client_addr;
    if (pthread_create(&thread, NULL, client_thread, thread_arg) != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  // Close socket
  close(server_sock);

  return EXIT_SUCCESS;
}