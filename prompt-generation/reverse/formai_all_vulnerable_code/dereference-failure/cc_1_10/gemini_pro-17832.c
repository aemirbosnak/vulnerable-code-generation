//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <time.h>

// Define the maximum number of hops for the traceroute
#define MAX_HOPS 30

// Define the maximum size of the packet
#define MAX_PACKET_SIZE 512

// Define the port number for the traceroute
#define PORT_NUMBER 33434

// Define the timeout for the traceroute
#define TIMEOUT 1000

// Define the number of probes to send for each hop
#define NUM_PROBES 3

// Define the interval between probes in milliseconds
#define PROBE_INTERVAL 100

// Define the message to send for each probe
#define MESSAGE "Roses are red, violets are blue,"

// Define the response message to look for
#define RESPONSE "Sugar is sweet, and so are you."

// Define the function to create a socket
int create_socket() {
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("Could not create socket");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

// Define the function to set the socket options
void set_socket_options(int sockfd) {
  int reuseaddr = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) < 0) {
    perror("Could not set socket options");
    exit(EXIT_FAILURE);
  }
}

// Define the function to send a probe
int send_probe(int sockfd, struct sockaddr_in *addr, int hop) {
  char packet[MAX_PACKET_SIZE];
  int len = sprintf(packet, "%s %d", MESSAGE, hop);
  if (sendto(sockfd, packet, len, 0, (struct sockaddr *) addr, sizeof(*addr)) < 0) {
    perror("Could not send probe");
    return -1;
  }
  return 0;
}

// Define the function to receive a response
int receive_response(int sockfd, struct sockaddr_in *addr, int hop) {
  char packet[MAX_PACKET_SIZE];
  struct timeval tv;
  tv.tv_sec = TIMEOUT / 1000;
  tv.tv_usec = (TIMEOUT % 1000) * 1000;
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
    perror("Could not set socket timeout");
    return -1;
  }
  int len = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *) addr, sizeof(*addr));
  if (len < 0) {
    if (errno == EAGAIN) {
      return -1;
    } else {
      perror("Could not receive response");
      return -1;
    }
  }
  if (strcmp(packet, RESPONSE) != 0) {
    return -1;
  }
  return 0;
}

// Define the function to perform the traceroute
int traceroute(char *hostname) {
  int sockfd;
  struct sockaddr_in addr;
  int hop;
  int probes;
  int rtt;
  char buf[INET_ADDRSTRLEN];

  // Create the socket
  sockfd = create_socket();

  // Set the socket options
  set_socket_options(sockfd);

  // Resolve the hostname
  if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
    perror("Could not resolve hostname");
    exit(EXIT_FAILURE);
  }

  // Set the destination address
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT_NUMBER);

  // Start the traceroute
  for (hop = 1; hop <= MAX_HOPS; hop++) {
    printf("Hop %d: ", hop);

    // Send the probes
    for (probes = 0; probes < NUM_PROBES; probes++) {
      if (send_probe(sockfd, &addr, hop) < 0) {
        perror("Could not send probe");
        exit(EXIT_FAILURE);
      }
    }

    // Receive the responses
    rtt = 0;
    for (probes = 0; probes < NUM_PROBES; probes++) {
      if (receive_response(sockfd, &addr, hop) < 0) {
        continue;
      }

      // Calculate the round-trip time
      struct timeval tv;
      gettimeofday(&tv, NULL);
      rtt += (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    }

    // Print the results
    if (rtt > 0) {
      printf("%s (%d ms)\n", inet_ntop(AF_INET, &addr.sin_addr, buf, INET_ADDRSTRLEN), rtt / NUM_PROBES);
    } else {
      printf("*\n");
    }

    // Increment the hop count
    addr.sin_addr.s_addr++;
  }

  // Close the socket
  close(sockfd);

  return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Perform the traceroute
  traceroute(argv[1]);

  return 0;
}