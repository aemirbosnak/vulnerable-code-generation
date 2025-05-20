//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

// The Hatter's tea party
typedef enum {
  MAD,
  MARCH,
  DORMOUSE
} TeaParticipant;

// The Cheshire Cat's grin
typedef enum {
  SMILE,
  FROW,
  PURR
} CatExpression;

// The Queen of Hearts' croquet game
typedef enum {
  RED,
  BLACK,
  WHITE
} CroquetColor;

// The White Rabbit's pocket watch
typedef struct {
  int hours;
  int minutes;
  int seconds;
} Time;

// The Mad Hatter's riddle
typedef struct {
  char *question;
  char *answer;
} Riddle;

// The Dormouse's lullaby
typedef struct {
  char *lyrics;
  int length;
} Lullaby;

// The March Hare's teacup
typedef struct {
  TeaParticipant owner;
  int size;
  char *contents;
} Teacup;

// The client side of the looking glass
int client_main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Connect to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a riddle to the server
  Riddle riddle = {"Why is a raven like a writing desk?", "Because it can produce a few notes, though they are very flat."};
  if (send(sockfd, &riddle, sizeof(riddle), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a lullaby from the server
  Lullaby lullaby;
  if (recv(sockfd, &lullaby, sizeof(lullaby), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the lullaby
  printf("The Dormouse's lullaby:\n%s\n", lullaby.lyrics);

  // Close the connection
  close(sockfd);

  return EXIT_SUCCESS;
}

// The server side of the looking glass
int server_main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to an address
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[1]));
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept a connection
  int connfd;
  struct sockaddr_in cliaddr;
  socklen_t len = sizeof(cliaddr);
  connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
  if (connfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Receive a riddle from the client
  Riddle riddle;
  if (recv(connfd, &riddle, sizeof(riddle), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send a lullaby to the client
  Lullaby lullaby = {"Twinkle, twinkle, little bat,\nHow I wonder what you're at!\nUp above the world you fly,\nLike a teacup in the sky.", 4};
  if (send(connfd, &lullaby, sizeof(lullaby), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the connection
  close(connfd);

  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
  if (argc == 2 && strcmp(argv[1], "-s") == 0) {
    return server_main(argc - 1, argv + 1);
  } else {
    return client_main(argc - 1, argv + 1);
  }
}