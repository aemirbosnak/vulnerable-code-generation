//GEMINI-pro DATASET v1.0 Category: Networking ; Style: retro
// Welcome to the Astral Network, brave adventurer!

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  // Prepare our ship for intergalactic communication
  struct sockaddr_in server;
  int sockfd;

  // Fetch the coordinates of the distant realm
  if (argc < 3) {
    printf("Usage: %s <IP address> <port>\n", argv[0]);
    return 1;
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);

  // Establish a connection to the cosmic host
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Error connecting");
    return 1;
  }

  // Transmission log:
  char message[] = "Greetings from the astral plains!";
  int len = strlen(message);
  send(sockfd, &len, sizeof(int), 0);
  send(sockfd, message, len, 0);

  // Listening for alien transmissions:
  int recv_len;
  recv(sockfd, &recv_len, sizeof(int), 0);
  char *alien_message = malloc(recv_len + 1);
  recv(sockfd, alien_message, recv_len, 0);
  alien_message[recv_len] = '\0';

  // Decode the alien's message:
  printf("Alien response: %s\n", alien_message);

  // Disconnect and return to our own dimension
  close(sockfd);
  return 0;
}