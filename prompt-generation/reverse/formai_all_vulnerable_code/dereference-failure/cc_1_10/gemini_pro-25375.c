//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>

// This function is used to get the IP address of the interface
char *get_ip_address(char *interface) {
  struct ifreq ifr;
  int sockfd;
  char *ip_address = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return NULL;
  }

  // Get the interface index
  strncpy(ifr.ifr_name, interface, IFNAMSIZ);
  if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
    perror("ioctl");
    close(sockfd);
    return NULL;
  }

  // Get the IP address
  if (ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
    perror("ioctl");
    close(sockfd);
    return NULL;
  }

  // Convert the IP address to a string
  ip_address = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);

  // Close the socket
  close(sockfd);

  return ip_address;
}

// This function is used to get the MAC address of the interface
char *get_mac_address(char *interface) {
  struct ifreq ifr;
  int sockfd;
  char *mac_address = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return NULL;
  }

  // Get the interface index
  strncpy(ifr.ifr_name, interface, IFNAMSIZ);
  if (ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0) {
    perror("ioctl");
    close(sockfd);
    return NULL;
  }

  // Get the MAC address
  if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) < 0) {
    perror("ioctl");
    close(sockfd);
    return NULL;
  }

  // Convert the MAC address to a string
  mac_address = ether_ntoa((struct ether_addr *)&ifr.ifr_hwaddr);

  // Close the socket
  close(sockfd);

  return mac_address;
}

// This function is used to get the list of interfaces
char **get_interfaces() {
  struct if_nameindex *interfaces;
  int num_interfaces;
  char **interface_list;
  int i;

  // Get the list of interfaces
  interfaces = if_nameindex();
  if (interfaces == NULL) {
    perror("if_nameindex");
    return NULL;
  }

  // Count the number of interfaces
  num_interfaces = 0;
  while (interfaces[num_interfaces].if_name != NULL) {
    num_interfaces++;
  }

  // Allocate memory for the list of interfaces
  interface_list = malloc(sizeof(char *) * (num_interfaces + 1));
  if (interface_list == NULL) {
    perror("malloc");
    if_freenameindex(interfaces);
    return NULL;
  }

  // Copy the interface names into the list
  for (i = 0; i < num_interfaces; i++) {
    interface_list[i] = strdup(interfaces[i].if_name);
    if (interface_list[i] == NULL) {
      perror("strdup");
      free(interface_list);
      if_freenameindex(interfaces);
      return NULL;
    }
  }

  // Add a NULL pointer to the end of the list
  interface_list[num_interfaces] = NULL;

  // Free the list of interfaces
  if_freenameindex(interfaces);

  return interface_list;
}

// This function is used to print the network topology
void print_network_topology(char **interfaces) {
  int i;

  // Print the header
  printf("Network Topology\n================\n");

  // Print the interfaces
  for (i = 0; interfaces[i] != NULL; i++) {
    printf("%s\n", interfaces[i]);
    printf("  IP Address: %s\n", get_ip_address(interfaces[i]));
    printf("  MAC Address: %s\n", get_mac_address(interfaces[i]));
  }
}

// This function is used to free the list of interfaces
void free_interfaces(char **interfaces) {
  int i;

  // Free the interface names
  for (i = 0; interfaces[i] != NULL; i++) {
    free(interfaces[i]);
  }

  // Free the list of interfaces
  free(interfaces);
}

// This function is the main function
int main() {
  char **interfaces;

  // Get the list of interfaces
  interfaces = get_interfaces();
  if (interfaces == NULL) {
    return 1;
  }

  // Print the network topology
  print_network_topology(interfaces);

  // Free the list of interfaces
  free_interfaces(interfaces);

  return 0;
}