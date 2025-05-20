//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_INTERFACES 20

typedef struct {
  char name[IFNAMSIZ];
  char mac[6];
} interface_info;

void print_usage() {
  fprintf(stderr, "Usage: %s\n", __FILE__);
}

int main(int argc, char **argv) {
  int sockfd;
  struct ifreq ifr;
  interface_info interfaces[MAX_INTERFACES];
  int num_interfaces = 0;

  if (argc != 1) {
    print_usage();
    exit(EXIT_FAILURE);
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < MAX_INTERFACES; i++) {
    memset(&ifr, 0, sizeof(ifr));
    snprintf(ifr.ifr_name, IFNAMSIZ, "wlan%d", i);

    if (ioctl(sockfd, SIOCGIFNAME, &ifr) == -1) {
      if (errno == ENODEV) {
        break;
      } else {
        perror("ioctl");
        exit(EXIT_FAILURE);
      }
    }

    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
      perror("ioctl");
      exit(EXIT_FAILURE);
    }

    strcpy(interfaces[num_interfaces].name, ifr.ifr_name);
    memcpy(interfaces[num_interfaces].mac, ifr.ifr_hwaddr.sa_data, 6);

    num_interfaces++;
  }

  close(sockfd);

  printf("Found %d wireless interfaces:\n", num_interfaces);

  if (num_interfaces == 0) {
    printf("No wireless interfaces found.\n");
    return 0;
  }

  for (int i = 0; i < num_interfaces; i++) {
    printf("%s: ", interfaces[i].name);

    for (int j = 0; j < 6; j++) {
      printf("%02X", interfaces[i].mac[j]);
    }

    printf("\n");
  }

  return 0;
}