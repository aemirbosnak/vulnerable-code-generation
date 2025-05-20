//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

typedef struct {
  char *addr;
  char *port;
  char *action;
} FirewallRule;

FirewallRule rules[MAX_RULES];
int num_rules = 0;

void load_rules(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[MAX_RULE_LEN];
  while (fgets(line, MAX_RULE_LEN, f)) {
    if (line[0] == '#') {
      continue;
    }

    char *addr = strtok(line, " ");
    char *port = strtok(NULL, " ");
    char *action = strtok(NULL, "\n");

    FirewallRule rule;
    rule.addr = strdup(addr);
    rule.port = strdup(port);
    rule.action = strdup(action);

    rules[num_rules++] = rule;
  }

  fclose(f);
}

int check_rule(char *addr, char *port) {
  for (int i = 0; i < num_rules; i++) {
    FirewallRule rule = rules[i];

    if (strcmp(rule.addr, addr) == 0 && strcmp(rule.port, port) == 0) {
      return *rule.action == 'A';
    }
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <firewall-rules-file> <port>\n", argv[0]);
    exit(1);
  }

  load_rules(argv[1]);

  int port = atoi(argv[2]);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  if (listen(sockfd, 5) < 0) {
    perror("Error listening on socket");
    exit(1);
  }

  while (1) {
    struct sockaddr_in cli_addr;
    socklen_t cli_addr_len = sizeof(cli_addr);

    int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_addr_len);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    char *addr = inet_ntoa(cli_addr.sin_addr);
    char *port = ntohs(cli_addr.sin_port);

    if (check_rule(addr, port)) {
      printf("Allowed connection from %s:%s\n", addr, port);
    } else {
      printf("Denied connection from %s:%s\n", addr, port);
      close(newsockfd);
      continue;
    }

    int n;
    char buffer[256];
    while ((n = read(newsockfd, buffer, sizeof(buffer))) > 0) {
      printf("Received %d bytes from %s:%s\n", n, addr, port);
      write(newsockfd, buffer, n);
    }

    if (n < 0) {
      perror("Error reading from socket");
    }

    close(newsockfd);
  }

  close(sockfd);

  return 0;
}