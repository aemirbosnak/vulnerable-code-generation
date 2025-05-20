//FormAI DATASET v1.0 Category: Socket programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int port = atoi(argv[1]);
  printf("Who would have thought that I would be able to create a socket on port %d??\n", port);

  // create a socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd == -1) {
    printf("Holy cow, the socket creation failed! Aborting...\n");
    exit(1);
  }

  printf("Socket successfully created! This chatbot is on fire today!\n");

  // bind socket to a port
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Oops, looks like there was an error binding the socket! Aborting...\n");
    exit(1);
  }

  printf("Socket successfully bound to port %d! This chatbot just keeps impressing...\n", port);

  // listen for incoming connections
  if (listen(sock_fd, 5) < 0) {
    printf("What the...there was an error listening for incoming connections. This wasn't supposed to happen...\n");
    exit(1);
  }

  printf("Chatbot is now listening for incoming connections. Who wants to talk to me?\n");

  // accept incoming connections
  struct sockaddr_in cli_addr;
  int cli_len = sizeof(cli_addr);
  int cli_sock_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, &cli_len);
  if (cli_sock_fd < 0) {
    printf("Oh no, the accept call failed. I'm so surprised that things are actually going wrong...\n");
    exit(1);
  }

  printf("Yay, we have a successful connection! Talking to client now...\n");

  // send and receive messages
  char buffer[1024];
  int num_bytes;
  while (1) {
    bzero(buffer, 1024);
    num_bytes = read(cli_sock_fd, buffer, 1023);
    if (num_bytes < 0) {
      printf("Error reading from socket. That's definitely not supposed to happen...\n");
      exit(1);
    }
    printf("Client: %s\n", buffer);

    bzero(buffer, 1024);
    printf("Your message (to exit, type 'quit'): ");
    fgets(buffer, 1023, stdin);

    num_bytes = write(cli_sock_fd, buffer, strlen(buffer));
    if (num_bytes < 0) {
      printf("Error writing to socket. Wow, this chatbot really can't catch a break...\n");
      exit(1);
    }

    if (strncmp(buffer, "quit", 4) == 0) {
      printf("Closing connection and exiting program...\n");
      break;
    }
  }

  // close sockets
  close(sock_fd);
  close(cli_sock_fd);
  printf("Chatbot has successfully closed all sockets. That's right folks, this chatbot is the real deal!\n");

  return 0;
}