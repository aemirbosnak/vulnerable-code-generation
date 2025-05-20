//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <time.h>

// Ping packet size
#define PING_PACKET_SIZE 64

// Ping timeout in milliseconds
#define PING_TIMEOUT 1000

// Thread attributes
pthread_attr_t attr;

// Thread arguments
struct ping_args {
  char *hostname;
  int sockfd;
  struct sockaddr_in addr;
  int sequence_number;
  time_t start_time;
  time_t end_time;
  int success;
};

// Ping thread function
void *ping_thread(void *args) {
  struct ping_args *arg = (struct ping_args *)args;

  // Create a buffer for the ping packet
  char packet[PING_PACKET_SIZE];

  // Set the packet payload
  memset(packet, 0, PING_PACKET_SIZE);
  sprintf(packet, "PING %d %ld", arg->sequence_number, time(NULL));

  // Send the ping packet
  if (sendto(arg->sockfd, packet, PING_PACKET_SIZE, 0, (struct sockaddr *)&arg->addr, sizeof(arg->addr)) < 0) {
    perror("sendto");
    arg->success = 0;
    return NULL;
  }

  // Start the timer
  arg->start_time = time(NULL);

  // Wait for the response
  while (time(NULL) - arg->start_time < PING_TIMEOUT) {
    fd_set readfds;
    struct timeval timeout;

    // Set up the select() call
    FD_ZERO(&readfds);
    FD_SET(arg->sockfd, &readfds);
    timeout.tv_sec = 0;
    timeout.tv_usec = 10000;

    if (select(arg->sockfd + 1, &readfds, NULL, NULL, &timeout) > 0) {
      // Receive the response
      struct sockaddr_in from_addr;
      socklen_t from_len = sizeof(from_addr);
      if (recvfrom(arg->sockfd, packet, PING_PACKET_SIZE, 0, (struct sockaddr *)&from_addr, &from_len) < 0) {
        perror("recvfrom");
        arg->success = 0;
        return NULL;
      }

      // Stop the timer
      arg->end_time = time(NULL);

      // Check if the response is valid
      char *response = packet;
      if (strncmp(response, "PONG", 4) != 0 || atoi(response + 5) != arg->sequence_number) {
        arg->success = 0;
        return NULL;
      }

      // The ping was successful
      arg->success = 1;
      return NULL;
    }
  }

  // The ping timed out
  arg->success = 0;
  return NULL;
}

// Main function
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the thread attributes
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

  // Create the socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the hostname
  struct hostent *hostent = gethostbyname(argv[1]);
  if (!hostent) {
    fprintf(stderr, "gethostbyname: %s", hstrerror(h_errno));
    return EXIT_FAILURE;
  }

  // Set the socket address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(0);
  memcpy(&addr.sin_addr, hostent->h_addr_list[0], sizeof(addr.sin_addr));

  // Create a thread pool
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    // Create the thread arguments
    struct ping_args *arg = malloc(sizeof(struct ping_args));
    arg->hostname = argv[1];
    arg->sockfd = sockfd;
    arg->addr = addr;
    arg->sequence_number = i;
    arg->start_time = 0;
    arg->end_time = 0;
    arg->success = 0;

    // Create the thread
    if (pthread_create(&threads[i], &attr, ping_thread, (void *)arg) != 0) {
      perror("pthread_create");
      return EXIT_FAILURE;
    }
  }

  // Wait for the threads to finish
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  // Close the socket
  close(sockfd);

  // Print the results
  int successful_pings = 0;
  for (int i = 0; i < 10; i++) {
    struct ping_args *arg = (struct ping_args *)threads[i];
    if (arg->success) {
      printf("PING %d %s (%s): time=%ldms\n", arg->sequence_number, arg->hostname, inet_ntoa(arg->addr.sin_addr), arg->end_time - arg->start_time);
      successful_pings++;
    } else {
      printf("PING %d %s (%s): timeout\n", arg->sequence_number, arg->hostname, inet_ntoa(arg->addr.sin_addr));
    }
  }

  printf("Ping statistics for %s:\n", argv[1]);
  printf("Packets: sent = 10, received = %d, lost = %d (%d%% loss)\n", successful_pings, 10 - successful_pings, (10 - successful_pings) * 100 / 10);

  return EXIT_SUCCESS;
}