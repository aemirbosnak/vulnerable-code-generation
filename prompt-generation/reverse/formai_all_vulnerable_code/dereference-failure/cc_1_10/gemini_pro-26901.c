//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100

typedef struct {
  char *hostname;
  int port;
} target_t;

typedef struct {
  int sockfd;
  target_t *target;
} thread_arg_t;

void *worker_thread(void *arg) {
  thread_arg_t *ta = (thread_arg_t *)arg;
  struct sockaddr_in servaddr;

  // Create a socket
  ta->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (ta->sockfd == -1) {
    perror("socket");
    pthread_exit(NULL);
  }

  // Resolve the hostname
  struct hostent *he = gethostbyname(ta->target->hostname);
  if (he == NULL) {
    perror("gethostbyname");
    pthread_exit(NULL);
  }

  // Set the socket address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(ta->target->port);
  memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);

  // Connect to the server
  if (connect(ta->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    pthread_exit(NULL);
  }

  // Send a message to the server
  char *message = "Hello, world!";
  if (send(ta->sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    pthread_exit(NULL);
  }

  // Receive a message from the server
  char buffer[1024];
  int n = recv(ta->sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    pthread_exit(NULL);
  }

  // Print the message from the server
  printf("Received: %s\n", buffer);

  // Close the socket
  close(ta->sockfd);

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a list of targets
  target_t targets[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    targets[i].hostname = hostname;
    targets[i].port = port;
  }

  // Create a thread pool
  pthread_t threads[MAX_THREADS];
  thread_arg_t thread_args[MAX_THREADS];
  for (int i = 0; i < MAX_THREADS; i++) {
    thread_args[i].sockfd = -1;
    thread_args[i].target = &targets[i];
    if (pthread_create(&threads[i], NULL, worker_thread, &thread_args[i]) != 0) {
      perror("pthread_create");
      return EXIT_FAILURE;
    }
  }

  // Join the threads
  for (int i = 0; i < MAX_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("pthread_join");
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}