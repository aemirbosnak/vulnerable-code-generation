//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
  // Argument parsing
  if (argc != 2) {
    printf("Usage: %s <interface>\n", argv[0]);
    return EXIT_FAILURE;
  }
  char *interface = argv[1];

  // Socket creation
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Interface configuration
  struct ifreq ifr;
  strcpy(ifr.ifr_name, interface);
  if (ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
    perror("ioctl");
    return EXIT_FAILURE;
  }

  // Scanning loop
  struct sockaddr_in broadcast_addr;
  bzero(&broadcast_addr, sizeof(broadcast_addr));
  broadcast_addr.sin_family = AF_INET;
  broadcast_addr.sin_port = htons(9);
  broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

  char buf[MAX_BUF];
  int len = sizeof(broadcast_addr);
  while (1) {
    // Send broadcast packet
    strcpy(buf, "DISCOVER_REQUEST");
    if (sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&broadcast_addr, len) < 0) {
      perror("sendto");
      continue;
    }

    // Receive responses
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sockfd, &fds);
    struct timeval timeout = {1, 0};
    if (select(sockfd + 1, &fds, NULL, NULL, &timeout) < 0) {
      perror("select");
      continue;
    }

    if (FD_ISSET(sockfd, &fds)) {
      recvfrom(sockfd, buf, MAX_BUF, 0, (struct sockaddr *)&broadcast_addr, &len);
      printf("%s\n", buf);
    }
  }

  // Cleanup
  close(sockfd);
  return EXIT_SUCCESS;
}