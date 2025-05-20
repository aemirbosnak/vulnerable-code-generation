//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 16

int main() {
  struct ifreq ifr[MAX_INTERFACES];
  int sockfd;
  int num_interfaces;
  int index;

  if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket() failed");
    return EXIT_FAILURE;
  }

  num_interfaces = 0;
  for (index = 0; index < MAX_INTERFACES; index++) {
    snprintf(ifr[index].ifr_name, sizeof(ifr[index].ifr_name), "wlan%d", index);
    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr[index]) == -1) {
      perror("ioctl() failed");
      break;
    }

    if (ifr[index].ifr_flags & IFF_UP) {
      num_interfaces++;
    }
  }

  if (num_interfaces == 0) {
    printf("No wireless interfaces found.\n");
    return EXIT_FAILURE;
  }

  printf("Found %d wireless interfaces:\n", num_interfaces);
  for (index = 0; index < num_interfaces; index++) {
    if (ioctl(sockfd, SIOCGIFADDR, &ifr[index]) == -1) {
      perror("ioctl() failed");
      continue;
    }

    printf("Interface %s has IP address %s\n", ifr[index].ifr_name, inet_ntoa(((struct sockaddr_in *) &ifr[index].ifr_addr)->sin_addr));
  }

  close(sockfd);

  return EXIT_SUCCESS;
}