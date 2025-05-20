//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
  int hostname;
  struct hostent *host_info;
  struct sockaddr_in server_addr;

  // Let's get the IP address of a random server!
  hostname = gethostname(NULL, 0);
  if (hostname == -1) {
    perror("gethostname");
    exit(1);
  }
  host_info = gethostbyname("www.google.com");
  if (!host_info) {
    perror("gethostbyname");
    exit(1);
  }
  memset((char *)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_addr = *((struct in_addr *)host_info->h_addr_list[0]);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);

  // Now, time to talk to the server!
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }
  if (connect(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Ready to send a message!
  char message[] = "Hello, Server! What's the time?";
  int message_len = strlen(message);
  int sent_bytes = send(sockfd, message, message_len, 0);
  if (sent_bytes < 0) {
    perror("send");
    exit(1);
  }

  // Waiting for a reply!
  char buffer[512];
  int received_bytes = recv(sockfd, buffer, 512, 0);
  if (received_bytes < 0) {
    perror("recv");
    exit(1);
  }
  buffer[received_bytes] = '\0';
  printf("Time from server: %s\n", buffer);

  // All done! Let's close the shop.
  close(sockfd);

  return 0;
}