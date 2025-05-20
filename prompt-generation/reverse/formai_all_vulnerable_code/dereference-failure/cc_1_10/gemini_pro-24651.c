//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_INTERFACES 100
#define MAX_IP_ADDR_LEN 16

int main() {
  int sockfd;
  struct ifreq ifr[MAX_INTERFACES];
  struct sockaddr_in *addr;
  char ip_addr[MAX_IP_ADDR_LEN];
  int num_interfaces;
  int i;

  // Create a socket for ioctl() calls.
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket()");
    exit(EXIT_FAILURE);
  }

  // Get the number of network interfaces.
  num_interfaces = ioctl(sockfd, SIOCGIFCOUNT, 0);
  if (num_interfaces < 0) {
    perror("ioctl(SIOCGIFCOUNT)");
    exit(EXIT_FAILURE);
  }

  // Get the IP address of each network interface.
  for (i = 0; i < num_interfaces; i++) {
    snprintf(ifr[i].ifr_name, IFNAMSIZ, "eth%d", i);
    if (ioctl(sockfd, SIOCGIFADDR, &ifr[i]) < 0) {
      perror("ioctl(SIOCGIFADDR)");
      exit(EXIT_FAILURE);
    }

    addr = (struct sockaddr_in *)&ifr[i].ifr_addr;
    strcpy(ip_addr, inet_ntoa(addr->sin_addr));
    printf("Interface %s has IP address %s.\n", ifr[i].ifr_name, ip_addr);
  }

  // Close the socket.
  close(sockfd);

  return 0;
}