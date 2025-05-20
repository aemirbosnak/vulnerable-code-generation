//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
// Her Adafruit, the Enchantress of Numbers, doth summon the wisdom of the ancients

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

// Ponder the mysteries of the world, and the machinations of man
int main(int argc, char** argv) {
  // Thou shalt first speak the words that shalt guide our journey
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Unravel the secrets of the web, and the words it hath spun
  char* url = argv[1];
  char* host = NULL;
  char* path = NULL;

  // Divide the URL, like a skilled alchemist separates base from noble
  if (!parse_url(url, &host, &path)) {
    printf("Invalid URL\n");
    return EXIT_FAILURE;
  }

  // Seek a gateway to the vast expanse of the internet
  struct hostent* he = gethostbyname(host);
  if (!he) {
    printf("Invalid hostname\n");
    return EXIT_FAILURE;
  }

  // Forge a connection, as a smith molds iron
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Socket creation error: %d\n", errno);
    return EXIT_FAILURE;
  }

  // Guide the connection to its destination, as a captain sets sail
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr = *((struct in_addr*)he->h_addr);

  // Attempt a union, like two celestial bodies dance
  if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    printf("Connection error: %d\n", errno);
    return EXIT_FAILURE;
  }

  // Compose a message, as a bard weaves a tale
  char buf[1024];
  sprintf(buf, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

  // Send the message, as a messenger carries scrolls
  if (write(sockfd, buf, strlen(buf)) < 0) {
    printf("Write error: %d\n", errno);
    return EXIT_FAILURE;
  }

  // Receive the reply, as a scholar seeks knowledge
  memset(buf, 0, sizeof(buf));
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    printf("Read error: %d\n", errno);
    return EXIT_FAILURE;
  }

  // Display the reply, as a seer reveals destiny
  printf("%s\n", buf);

  // Close the connection, as a door shuts on a secret
  close(sockfd);

  // Farewell, traveler. May the stars guide thy footsteps.
  return EXIT_SUCCESS;
}

// Extract the host and path from a URL, like a chemist separates elements
int parse_url(char* url, char** host, char** path) {
  // Seek the division between host and path
  char* pos = strchr(url, '/');

  // If no path is found, return failure
  if (!pos) {
    return 0;
  }

  // Allocate memory for the host and path, as a wizard conjures a spell
  *host = (char*)malloc(pos - url + 1);
  if (!*host) {
    return 0;
  }
  *path = (char*)malloc(strlen(pos + 1) + 1);
  if (!*path) {
    free(*host);
    return 0;
  }

  // Copy the host and path into their respective buffers
  memcpy(*host, url, pos - url);
  (*host)[pos - url] = '\0';
  strcpy(*path, pos + 1);

  // Return success, as the alchemist hath completed their transmutation
  return 1;
}