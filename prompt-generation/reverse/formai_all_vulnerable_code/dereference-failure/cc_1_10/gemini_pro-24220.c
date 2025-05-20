//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 10

int main() {
  int sockfd;
  struct ifreq ifr[MAX_INTERFACES];
  struct sockaddr_in *addr;
  char buf[1024];
  int i, num_interfaces;

  // Create a socket for network interface operations
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Get the list of network interfaces
  num_interfaces = ioctl(sockfd, SIOCGIFCONF, &ifr);
  if (num_interfaces < 0) {
    perror("ioctl");
    return -1;
  }

  // Iterate over the network interfaces
  for (i = 0; i < num_interfaces; i++) {
    // Get the interface name
    strcpy(buf, ifr[i].ifr_name);

    // Get the IP address of the interface
    addr = (struct sockaddr_in *) &ifr[i].ifr_addr;
    inet_ntop(AF_INET, &addr->sin_addr, buf, sizeof(buf));

    // Print the interface name and IP address
    printf("%s: %s\n", buf, inet_ntoa(addr->sin_addr));
  }

  // Close the socket
  close(sockfd);

  return 0;
}