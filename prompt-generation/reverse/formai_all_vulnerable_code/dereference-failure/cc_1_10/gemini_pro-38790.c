//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <pthread.h>

struct host {
  char *name;
  struct in_addr ip;
  int port;
  struct host *next;
};

struct thread_data {
  struct host *host;
  int sockfd;
  int n;
};

void *thread_function(void *arg) {
  struct thread_data *data = (struct thread_data *)arg;
  struct host *host = data->host;
  int sockfd = data->sockfd;
  int n = data->n;
  char buffer[1024];

  printf("Connecting to %s:%d\n", host->name, host->port);

  if (connect(sockfd, (struct sockaddr *)&host->ip, sizeof(struct sockaddr_in)) < 0) {
    perror("connect");
    close(sockfd);
    free(data);
    return NULL;
  }

  printf("Connected to %s:%d\n", host->name, host->port);

  while (1) {
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
      perror("read");
      close(sockfd);
      free(data);
      return NULL;
    } else if (n == 0) {
      printf("Connection closed by %s:%d\n", host->name, host->port);
      close(sockfd);
      free(data);
      return NULL;
    } else {
      write(1, buffer, n);
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  struct host *hosts = NULL;
  struct host *host;
  struct in_addr ip;
  int port;
  int sockfd;
  int num_threads;
  pthread_t *threads;
  int i;

  // Parse the hostname and port number
  if (sscanf(argv[1], "%s:%d", host->name, &port) != 2) {
    printf("Invalid hostname or port number: %s\n", argv[1]);
    return 1;
  }

  // Resolve the hostname to an IP address
  if (inet_pton(AF_INET, host->name, &ip) != 1) {
    printf("Invalid hostname: %s\n", host->name);
    return 1;
  }

  // Create a socket for the host
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  // Add the host to the list of hosts
  host->ip = ip;
  host->port = port;
  host->next = hosts;
  hosts = host;

  // Determine the number of threads to create
  num_threads = argc - 2;

  // Create the threads
  threads = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
  for (i = 0; i < num_threads; i++) {
    struct thread_data *data = (struct thread_data *)malloc(sizeof(struct thread_data));
    data->host = hosts;
    data->sockfd = sockfd;
    data->n = 0;
    pthread_create(&threads[i], NULL, thread_function, (void *)data);
  }

  // Join the threads
  for (i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  // Close the socket
  close(sockfd);

  // Free the list of hosts
  while (hosts) {
    host = hosts->next;
    free(hosts->name);
    free(hosts);
    hosts = host;
  }

  return 0;
}