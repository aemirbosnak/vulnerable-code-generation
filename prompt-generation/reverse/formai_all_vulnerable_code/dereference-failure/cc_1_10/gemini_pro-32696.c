//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#define PORT 5555
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  char *buffer;
  int buffer_len;
  int checksum;
} client_t;

typedef struct {
  int shmid;
  void *shmaddr;
  int client_count;
  pthread_mutex_t mutex;
} shared_mem_t;

shared_mem_t shared_mem;

void *client_thread(void *arg) {
  client_t *client = (client_t *)arg;
  int n;

  while ((n = read(client->sockfd, client->buffer, BUFFER_SIZE)) > 0) {
    client->buffer_len = n;

    // Calculate checksum
    client->checksum = 0;
    for (int i = 0; i < client->buffer_len; i++) {
      client->checksum += client->buffer[i];
    }

    // Write checksum to shared memory
    pthread_mutex_lock(&shared_mem.mutex);
    shared_mem.client_count++;
    memcpy(shared_mem.shmaddr + (shared_mem.client_count - 1) * sizeof(client_t), client, sizeof(client_t));
    pthread_mutex_unlock(&shared_mem.mutex);

    // Send checksum back to client
    write(client->sockfd, &client->checksum, sizeof(int));
  }

  // Close client socket
  close(client->sockfd);

  return NULL;
}

int main() {
  int sockfd, newsockfd, clilen;
  struct sockaddr_in serv_addr, cli_addr;
  pthread_t threads[MAX_CLIENTS];
  client_t clients[MAX_CLIENTS];

  // Create shared memory
  shared_mem.shmid = shmget(IPC_PRIVATE, MAX_CLIENTS * sizeof(client_t), IPC_CREAT | 0666);
  shared_mem.shmaddr = shmat(shared_mem.shmid, NULL, 0);
  shared_mem.client_count = 0;
  pthread_mutex_init(&shared_mem.mutex, NULL);

  // Create server socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set server address
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind server socket to address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for incoming connections
  listen(sockfd, MAX_CLIENTS);

  // Accept incoming connections
  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }

    // Create client thread
    clients[shared_mem.client_count].sockfd = newsockfd;
    clients[shared_mem.client_count].addr = cli_addr;
    clients[shared_mem.client_count].buffer = malloc(BUFFER_SIZE);
    clients[shared_mem.client_count].buffer_len = 0;
    clients[shared_mem.client_count].checksum = 0;
    pthread_create(&threads[shared_mem.client_count], NULL, client_thread, &clients[shared_mem.client_count]);
  }

  // Close server socket
  close(sockfd);

  // Destroy shared memory
  shmdt(shared_mem.shmaddr);
  shmctl(shared_mem.shmid, IPC_RMID, NULL);

  return 0;
}