//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 25
#define BUF_SIZE 1024

typedef enum { CMD_HELO, CMD_MAIL, CMD_RCPT, CMD_DATA, CMD_QUIT } cmd_t;

void send_line(FILE *fp_out, const char *str) {
  fprintf(fp_out, "%s\r\n", str);
  fflush(fp_out);
}

void helo(FILE *fp_out, const char *host) {
  char helo_str[64];
  sprintf(helo_str, "HELO %s", host);
  send_line(fp_out, helo_str);
}

void mail(FILE *fp_out, const char *from, const char *to) {
  char mail_str[128];
  sprintf(mail_str, "MAIL FROM:<%s>", from);
  send_line(fp_out, mail_str);

  sprintf(mail_str, "RCPT TO:<%s>", to);
  send_line(fp_out, mail_str);
}

void rcpt(FILE *fp_out, const char *to) {
  char rcpt_str[64];
  sprintf(rcpt_str, "RCPT TO:<%s>", to);
  send_line(fp_out, rcpt_str);
}

void data(FILE *fp_out, size_t file_size) {
  char data_str[32];
  sprintf(data_str, "DATA\r\n");
  send_line(fp_out, data_str);

  char buffer[BUF_SIZE];
  ssize_t bytes_read;
  FILE *fp_in = stdin;

  while ((bytes_read = fread(buffer, 1, BUF_SIZE, fp_in)) > 0) {
    fwrite(buffer, 1, bytes_read, fp_out);
  }

  send_line(fp_out, "\r\n.\r\n");
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <message>\n", argv[0]);
    exit(1);
  }

  const char *host = argv[1];
  const char *message = argv[2];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  FILE *fp_out = fdopen(sockfd, "w");
  if (!fp_out) {
    perror("fdopen");
    exit(1);
  }

  helo(fp_out, host);
  mail(fp_out, "AlanTuring@bletchley.park", "Recipient@example.com");
  rcpt(fp_out, "Recipient@example.com");
  data(fp_out, strlen(message));
  fputs(message, stdout);
  fclose(fp_out);

  close(sockfd);
  return 0;
}