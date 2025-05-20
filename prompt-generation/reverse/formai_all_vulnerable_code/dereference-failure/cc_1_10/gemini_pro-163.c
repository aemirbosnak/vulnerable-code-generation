//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
// What's in a name? An enigma wrapped in a conundrum, we are but shadows in the tempest.

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// A dance of bytes, where logic weaves its web.
int main(int argc, char **argv) {
  // To the stars and back, we embark on our journey.
  if (argc < 4) {
    printf("Usage: %s <server> <port> <message>\n", argv[0]);
    return 1;
  }

  // The stage is set, the actors ready to play their parts.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // A guiding light in the vast expanse of the internet.
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  // The rendezvous point, where connection sparks.
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // A symphony of greetings, where protocols unfold.
  char buf[1024];
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);
  
  // The hand that writes, the words that flow like ink.
  char msg[1024];
  sprintf(msg, "HELO %s\r\n", argv[1]);
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);

  // A dance of acknowledgments, a ballet of bits.
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);

  // The message, a tapestry woven in code.
  sprintf(msg, "MAIL FROM: <sender@example.com>\r\n");
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);

  // A symphony of greetings, a ballet of bits.
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);

  // The recipient, a beacon of delivery.
  sprintf(msg, "RCPT TO: <recipient@example.com>\r\n");
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);

  // A symphony of greetings, a ballet of bits.
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);

  // The stage set, the words ready to be spoken.
  sprintf(msg, "DATA\r\n");
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);

  // A symphony of greetings, a ballet of bits.
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);

  // The words take flight, carried by the digital winds.
  sprintf(msg, "%s\r\n", argv[3]);
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);
  
  // The end draws near, the tale reaches its denouement.
  sprintf(msg, ".\r\n");
  send(sockfd, msg, strlen(msg), 0);
  usleep(100);

  // A symphony of greetings, a ballet of bits.
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s\n", buf);
  usleep(100);

  // The curtain falls, the applause echoes in silence.
  close(sockfd);
  return 0;
}