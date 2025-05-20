//MISTRAL-7B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <errno.h>

#define SSID_LEN 32
#define BUF_SIZE 1024

void die(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  int s, c, i;
  char host[SSID_LEN], buf[BUF_SIZE], *ssid = "your_ssid_here";
  struct sockaddr_in server;
  struct hostent *hp;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) die("socket");

  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  inet_aton(argv[1], &server.sin_addr);

  if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
    die("connect");

  send(s, ssid, strlen(ssid), 0);

  i = recv(s, buf, BUF_SIZE, 0);
  if (i <= 0) {
    close(s);
    die("recv");
  }

  if (strstr(buf, "Your request:") && strstr(buf, ssid)) {
    int signal_strength;

    for (c = i - 1; c >= 0 && isdigit(buf[c]); c--)
      signal_strength = signal_strength * 10 + buf[c] - '0';

    printf("Signal strength: %d dBm\n", signal_strength);
  } else {
    fprintf(stderr, "Invalid response from access point.\n");
  }

  close(s);
  exit(EXIT_SUCCESS);
}