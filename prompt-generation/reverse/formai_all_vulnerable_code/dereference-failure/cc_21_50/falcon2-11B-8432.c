//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sockfd, portno, newsockfd;
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  char buffer[256];

  if (argc < 2) {
    printf("Usage: %s port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    printf("ERROR opening socket\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR on binding\n");
    exit(0);
  }

  listen(sockfd, 5);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &n);

    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }

    printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));

    bzero(buffer, 256);

    read(newsockfd, buffer, 256);

    if (strcmp(buffer, "rock") == 0) {
      printf("Player 1: Rock\n");
    } else if (strcmp(buffer, "paper") == 0) {
      printf("Player 1: Paper\n");
    } else if (strcmp(buffer, "scissors") == 0) {
      printf("Player 1: Scissors\n");
    }

    bzero(buffer, 256);

    write(newsockfd, "Computer: ", 9);

    if (strcmp(buffer, "rock") == 0) {
      printf("Computer: Rock\n");
    } else if (strcmp(buffer, "paper") == 0) {
      printf("Computer: Paper\n");
    } else if (strcmp(buffer, "scissors") == 0) {
      printf("Computer: Scissors\n");
    }

    bzero(buffer, 256);

    read(newsockfd, buffer, 256);

    if (strcmp(buffer, "rock") == 0) {
      printf("Player 2: Rock\n");
    } else if (strcmp(buffer, "paper") == 0) {
      printf("Player 2: Paper\n");
    } else if (strcmp(buffer, "scissors") == 0) {
      printf("Player 2: Scissors\n");
    }

    bzero(buffer, 256);

    write(newsockfd, "Computer: ", 9);

    if (strcmp(buffer, "rock") == 0) {
      printf("Computer: Rock\n");
    } else if (strcmp(buffer, "paper") == 0) {
      printf("Computer: Paper\n");
    } else if (strcmp(buffer, "scissors") == 0) {
      printf("Computer: Scissors\n");
    }

    bzero(buffer, 256);

    read(newsockfd, buffer, 256);

    if (strcmp(buffer, "rock") == 0) {
      printf("Player 2: Rock\n");
    } else if (strcmp(buffer, "paper") == 0) {
      printf("Player 2: Paper\n");
    } else if (strcmp(buffer, "scissors") == 0) {
      printf("Player 2: Scissors\n");
    }

    if (strcmp(buffer, "tie") == 0) {
      printf("It's a tie!\n");
    } else if (strcmp(buffer, "player1") == 0) {
      printf("Player 1 wins!\n");
    } else if (strcmp(buffer, "player2") == 0) {
      printf("Player 2 wins!\n");
    } else {
      printf("ERROR: Invalid move!\n");
    }
  }

  close(newsockfd);

  return 0;
}