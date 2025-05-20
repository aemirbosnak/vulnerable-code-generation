//FormAI DATASET v1.0 Category: Socket programming ; Style: curious
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 3000
#define BUFFER_SIZE 1024

void *handle_client(void *arg);

int main(int argc, char *argv[]) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0}; 

  // create socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // set server address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen for client connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d\n", PORT);

  while (1) {
    // accept new connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    // handle client connection in new thread
    pthread_t tid;
    int *sock = malloc(sizeof(int));
    *sock = new_socket;
    if(pthread_create(&tid, NULL, handle_client, (void*)sock) < 0) {
      perror("pthread_create failed");
      exit(EXIT_FAILURE);
    }
    pthread_detach(tid);
  }

  return 0;
}

void *handle_client(void *arg) {
  int sock = *(int*)arg;
  char buffer[BUFFER_SIZE] = {0};

  // prompt client for number and calculate square
  while (1) {
    send(sock, "Enter a number:", strlen("Enter a number:"), 0);
    int num = 0;
    memset(buffer, 0, BUFFER_SIZE);
    int valread = read(sock, buffer, BUFFER_SIZE);
    if (valread <= 0) {
      break; // client disconnected
    }
    num = atoi(buffer);
    int square = num*num;
    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "The square of %d is %d\n", num, square);
    send(sock, buffer, strlen(buffer), 0);
  }

  // cleanup
  close(sock);
  free(arg);
  pthread_exit(NULL);
}