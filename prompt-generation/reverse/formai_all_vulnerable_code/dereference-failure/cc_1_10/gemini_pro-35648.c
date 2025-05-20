//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Defines the maximum number of hops.
#define MAX_HOPS 10

// Defines the maximum number of hosts per hop.
#define MAX_HOSTS_PER_HOP 100

// Defines the maximum length of a host name.
#define MAX_HOSTNAME_LENGTH 100

// Defines the maximum length of a IP address.
#define MAX_IP_ADDRESS_LENGTH 16

// Defines the maximum length of a hop.
#define MAX_HOP_LENGTH 100

// Defines the maximum length of a reply.
#define MAX_REPLY_LENGTH 100

struct host {
  char hostname[MAX_HOSTNAME_LENGTH];
  char ip_address[MAX_IP_ADDRESS_LENGTH];
  int hops;
};

struct hop {
  struct host hosts[MAX_HOSTS_PER_HOP];
  int num_hosts;
  int hops;
};

struct reply {
  struct hop hops[MAX_HOPS];
  int num_hops;
};

void print_host(struct host *host) {
  printf("Hostname: %s\n", host->hostname);
  printf("IP Address: %s\n", host->ip_address);
  printf("Hops: %d\n", host->hops);
}

void print_hop(struct hop *hop) {
  int i;
  for (i = 0; i < hop->num_hosts; i++) {
    print_host(&hop->hosts[i]);
  }
  printf("Hops: %d\n", hop->hops);
}

void print_reply(struct reply *reply) {
  int i;
  for (i = 0; i < reply->num_hops; i++) {
    print_hop(&reply->hops[i]);
  }
}

int main(int argc, char **argv) {
  struct sockaddr_in addr;
  int sockfd;
  char *hostname;
  struct host *host;
  struct hop *hop;
  struct reply *reply;
  int i;

  // Creates a socket.
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Gets the hostname of the local machine.
  hostname = malloc(MAX_HOSTNAME_LENGTH);
  if (gethostname(hostname, MAX_HOSTNAME_LENGTH) == -1) {
    perror("gethostname");
    exit(1);
  }

  // Gets the IP address of the local machine.
  host = malloc(sizeof(struct host));
  if (inet_pton(AF_INET, hostname, host->ip_address) == -1) {
    perror("inet_pton");
    exit(1);
  }

  // Sets the socket address.
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  addr.sin_port = htons(5000);

  // Sends a request to the server.
  if (sendto(sockfd, host, sizeof(struct host), 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("sendto");
    exit(1);
  }

  // Receives a reply from the server.
  reply = malloc(sizeof(struct reply));
  if (recvfrom(sockfd, reply, sizeof(struct reply), 0, NULL, NULL) == -1) {
    perror("recvfrom");
    exit(1);
  }

  // Prints the network topology map.
  print_reply(reply);

  // Closes the socket.
  close(sockfd);

  return 0;
}