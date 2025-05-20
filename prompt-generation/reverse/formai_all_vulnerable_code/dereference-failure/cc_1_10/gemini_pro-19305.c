//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Our trusty port scanner function, ready for action!
int scan_port(const char *hostname, const int port) {
  // Step 1: Let's set up a socket, the gateway to our network adventures.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    // Oops, something went wrong while creating the socket. Let's notify the user.
    fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
    return -1;
  }

  // Step 2: Now, let's find the IP address associated with the hostname.
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    // Uh-oh, couldn't find the IP address. Maybe the hostname is incorrect?
    fprintf(stderr, "Hostname resolution failed: %s\n", strerror(errno));
    close(sockfd);
    return -1;
  }

  // Step 3: Time to prepare our sockaddr_in structure, the address of our destination.
  struct sockaddr_in serv_addr;
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);

  // Step 4: Let's attempt to connect to the specified port.
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
    // Darn, connection failed. Maybe the port is closed?
    close(sockfd);
    return 0;
  }

  // Step 5: Success! The port is open, let's notify the user.
  printf("Bingo! Port %d is open on %s\n", port, hostname);
  close(sockfd);
  return 1;
}

// Our main function, where the magic happens.
int main(int argc, char *argv[]) {
  // Let's check if the user provided enough information.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return -1;
  }

  // Okay, let's grab the hostname and port number.
  const char *hostname = argv[1];
  const int port = atoi(argv[2]);

  // Let's scan the port and see if it's open.
  int status = scan_port(hostname, port);

  // Finally, let's interpret the result.
  if (status == -1) {
    // Uh-oh, something went wrong.
    fprintf(stderr, "Port scanning failed: %s\n", strerror(errno));
  } else if (status == 0) {
    // Port is closed.
    printf("Port %d on %s is closed.\n", port, hostname);
  }

  return 0;
}