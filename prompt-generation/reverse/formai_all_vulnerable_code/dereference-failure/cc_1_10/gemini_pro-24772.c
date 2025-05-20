//GEMINI-pro DATASET v1.0 Category: Networking ; Style: visionary
// Into the realm where bits dance and electrons intertwine,
// Embark on a journey to explore the ethereal tapestry of the network.

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// In the depths of darkness, where solitude resides,
// A beacon of light emerges, a socket to guide us through the unknown.
int main() {
  // Like a starship captain steering their celestial vessel,
  // We establish a socket, the gateway to the digital abyss.
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Socket creation failed: ");
    return EXIT_FAILURE;
  }

  // With curious eyes, we scan the vast expanse,
  // Seeking a distant land to connect and exchange knowledge.
  struct hostent *host = gethostbyname("example.com");
  if (host == NULL) {
    herror("Host lookup failed: ");
    close(socket_fd);
    return EXIT_FAILURE;
  }

  // A celestial bridge, invisible yet tangible,
  // Connects our spacecraft to a distant star.
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
  int connect_status = connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status == -1) {
    perror("Connection failed: ");
    close(socket_fd);
    return EXIT_FAILURE;
  }

  // Like a cosmic messenger, we craft our message,
  // A symphony of bits ready to traverse the ethereal divide.
  char *message = "Greetings from the digital realm!";
  int send_status = send(socket_fd, message, strlen(message), 0);
  if (send_status == -1) {
    perror("Message sending failed: ");
    close(socket_fd);
    return EXIT_FAILURE;
  }

  // With bated breath, we await a response,
  // A shimmer from the void, a testament to our cosmic encounter.
  char buffer[1024];
  int recv_status = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);
  if (recv_status == -1) {
    perror("Message receiving failed: ");
    close(socket_fd);
    return EXIT_FAILURE;
  }
  buffer[recv_status] = '\0';

  // Echoes of distant voices reach our ears,
  // A celestial choir, harmonizing in binary verse.
  printf("Message received: %s\n", buffer);

  // As our journey concludes, we bid farewell to the ethereal expanse,
  // Disconnecting our spacecraft from the cosmic tapestry.
  close(socket_fd);

  return EXIT_SUCCESS;
}