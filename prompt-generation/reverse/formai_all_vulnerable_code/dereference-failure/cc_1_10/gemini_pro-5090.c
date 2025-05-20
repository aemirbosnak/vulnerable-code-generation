//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define MAX_INTERFACES 10

struct interface {
  char name[IFNAMSIZ];
  char ip_address[INET_ADDRSTRLEN];
  char mac_address[18];
};

int main() {
  struct ifreq ifr[MAX_INTERFACES];
  struct interface interfaces[MAX_INTERFACES];
  int sockfd, num_interfaces;

  // Initialize the socket.
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Get the list of interfaces.
  num_interfaces = ioctl(sockfd, SIOCGIFCONF, &ifr);
  if (num_interfaces == -1) {
    perror("ioctl");
    return 1;
  }

  // Process the interfaces.
  for (int i = 0; i < num_interfaces; i++) {
    // Get the interface name.
    strcpy(interfaces[i].name, ifr[i].ifr_name);

    // Get the interface IP address.
    struct sockaddr_in* addr = (struct sockaddr_in*)&ifr[i].ifr_addr;
    inet_ntop(AF_INET, &addr->sin_addr, interfaces[i].ip_address, INET_ADDRSTRLEN);

    // Get the interface MAC address.
    struct ifreq mac_ifr;
    strcpy(mac_ifr.ifr_name, interfaces[i].name);
    if (ioctl(sockfd, SIOCGIFHWADDR, &mac_ifr) == -1) {
      perror("ioctl");
      continue;
    }
    sprintf(interfaces[i].mac_address, "%02x:%02x:%02x:%02x:%02x:%02x",
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[0],
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[1],
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[2],
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[3],
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[4],
            (unsigned char)mac_ifr.ifr_hwaddr.sa_data[5]);
  }

  // Close the socket.
  close(sockfd);

  // Print the interfaces.
  for (int i = 0; i < num_interfaces; i++) {
    printf("Interface %d: %s\n", i, interfaces[i].name);
    printf("  IP address: %s\n", interfaces[i].ip_address);
    printf("  MAC address: %s\n", interfaces[i].mac_address);
  }

  return 0;
}