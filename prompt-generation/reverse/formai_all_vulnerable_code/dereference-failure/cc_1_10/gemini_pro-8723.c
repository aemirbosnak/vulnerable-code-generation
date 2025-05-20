//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RULES 100

typedef struct {
  unsigned int ip_addr;
  unsigned short port;
  unsigned char protocol;
  unsigned char action;
} firewall_rule;

firewall_rule rules[MAX_RULES];
int num_rules = 0;

void add_rule(unsigned int ip_addr, unsigned short port, unsigned char protocol, unsigned char action) {
  if (num_rules >= MAX_RULES) {
    fprintf(stderr, "Error: too many rules\n");
    exit(1);
  }

  rules[num_rules].ip_addr = ip_addr;
  rules[num_rules].port = port;
  rules[num_rules].protocol = protocol;
  rules[num_rules].action = action;
  num_rules++;
}

int check_rule(unsigned int ip_addr, unsigned short port, unsigned char protocol) {
  int i;

  for (i = 0; i < num_rules; i++) {
    if (rules[i].ip_addr == ip_addr &&
        rules[i].port == port &&
        rules[i].protocol == protocol) {
      return rules[i].action;
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  int sockfd, newsockfd, portno, pid;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[256];
  int n;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }

    pid = fork();
    if (pid < 0) {
      perror("ERROR on fork");
      exit(1);
    }

    if (pid == 0) {
      close(sockfd);

      memset(buffer, 0, sizeof(buffer));
      n = recv(newsockfd, buffer, sizeof(buffer) - 1, 0);
      if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
      }

      unsigned int ip_addr = inet_addr(buffer);
      unsigned short port = htons(atoi(buffer + strlen(buffer) + 1));
      unsigned char protocol = buffer[strlen(buffer)];
      unsigned char action = check_rule(ip_addr, port, protocol);

      n = send(newsockfd, &action, 1, 0);
      if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
      }

      close(newsockfd);
      exit(0);
    } else {
      close(newsockfd);
    }
  }

  return 0;
}