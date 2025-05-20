//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>

#define MAX_INTERFACES 10

struct interface_info {
  char name[IFNAMSIZ];
  char ip_address[INET_ADDRSTRLEN];
  char mac_address[18];
};

void print_interface_info(struct interface_info *interface) {
  printf("Interface: %s\n", interface->name);
  printf("IP address: %s\n", interface->ip_address);
  printf("MAC address: %s\n\n", interface->mac_address);
}

int main() {
  int sockfd;
  struct ifreq ifr[MAX_INTERFACES];
  struct interface_info interfaces[MAX_INTERFACES];
  int num_interfaces = 0;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Get the list of network interfaces
  for (int i = 0; i < MAX_INTERFACES; i++) {
    ifr[i].ifr_addr.sa_family = AF_INET;
    snprintf(ifr[i].ifr_name, IFNAMSIZ, "eth%d", i);
    if (ioctl(sockfd, SIOCGIFADDR, &ifr[i]) == -1) {
      break;
    }

    // Get the IP address of the interface
    struct sockaddr_in *addr = (struct sockaddr_in *)&ifr[i].ifr_addr;
    strcpy(interfaces[num_interfaces].ip_address, inet_ntoa(addr->sin_addr));

    // Get the MAC address of the interface
    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr[i]) == -1) {
      perror("ioctl");
      exit(EXIT_FAILURE);
    }

    struct sockaddr *hwaddr = &ifr[i].ifr_hwaddr;
    snprintf(interfaces[num_interfaces].mac_address, 18, "%02x:%02x:%02x:%02x:%02x:%02x",
             hwaddr->sa_data[0], hwaddr->sa_data[1], hwaddr->sa_data[2],
             hwaddr->sa_data[3], hwaddr->sa_data[4], hwaddr->sa_data[5]);

    // Increment the number of interfaces
    num_interfaces++;
  }

  // Close the socket
  close(sockfd);

  // Print the network topology
  printf("Network Topology:\n\n");
  for (int i = 0; i < num_interfaces; i++) {
    print_interface_info(&interfaces[i]);
  }

  return 0;
}