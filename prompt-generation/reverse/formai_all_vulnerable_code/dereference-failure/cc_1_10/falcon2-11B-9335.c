//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, new_fd, bytes_recv, bytes_sent, ch;
  struct sockaddr_in serv_addr, cli_addr;
  struct sigaction sa;

  portno = atoi(argv[1]); // Assuming port number is provided as a command-line argument
  if (portno <= 0 || portno >= 65536) {
    fprintf(stderr, "Error: Invalid port number\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  memset((char *) &serv_addr, '\0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error on binding");
    exit(1);
  }

  listen(sockfd, 5); // Maximum 5 pending connections

  sa.sa_handler = SIG_IGN;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART;
  if (sigaction(SIGCHLD, &sa, NULL) == -1) {
    perror("Error setting up child process signal handler");
    exit(1);
  }

  while (1) {
    new_fd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &bytes_recv);
    if (new_fd < 0) {
      perror("Error on accepting");
      continue;
    }

    if (fork() == 0) {
      close(sockfd);
      dup2(new_fd, 0);
      close(new_fd);
      if (setsid() == -1) {
        perror("Error setting session ID");
        exit(1);
      }
      dup2(new_fd, 1);
      close(new_fd);
      dup2(new_fd, 2);
      close(new_fd);
      execv("/usr/bin/apache2", &argv);
      perror("Error executing server");
      exit(1);
    }
  }

  return 0;
}