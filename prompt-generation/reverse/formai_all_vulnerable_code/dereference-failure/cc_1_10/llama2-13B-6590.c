//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan, starting from 1024

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <target_host>\n", argv[0]);
    return 1;
  }

  // create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation failed");
    return 1;
  }

  // set up the target host address
  struct sockaddr_in target_addr;
  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(1024); // start port scanning from port 1024
  inet_pton(AF_INET, "127.0.0.1", &target_addr.sin_addr); // use local host as target

  // perform port scans
  for (int i = 1; i < PORT_RANGE; i++) {
    // create a socket option to set the source and destination addresses
    socklen_t optlen = sizeof(struct sockaddr_in);
    struct sockaddr_in *src_addr = (struct sockaddr_in *)malloc(optlen);
    *src_addr = target_addr;

    // set up the socket option
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&src_addr, optlen);

    // connect to the target port
    int connect_result = connect(sock, (struct sockaddr *)src_addr, optlen);
    if (connect_result < 0) {
      perror("connect() failed");
      continue;
    }

    // check if the port is open
    if (listen(sock, 1) == 0) {
      printf("Port %d is open on %s\n", i, inet_ntoa(target_addr.sin_addr));
    }

    // close the socket
    close(sock);
  }

  return 0;
}