//FormAI DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
  int sock, port, result, i;
  struct addrinfo hints, *server_info;
  struct sockaddr_in *ipv4;
  struct timeval start, end;

  if(argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  if((result = getaddrinfo(hostname, NULL, &hints, &server_info)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
    exit(1);
  }

  ipv4 = (struct sockaddr_in *) server_info->ai_addr;
  port = 7;

  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    perror("socket");
    exit(1);
  }

  printf("Pinging %s [IP: %s] on port %d...\n", hostname, inet_ntoa(ipv4->sin_addr), port);

  int sequence_number;
  for(sequence_number = 1; sequence_number <= 10; sequence_number++) {
    gettimeofday(&start, NULL);

    char send_buffer[25];
    sprintf(send_buffer, "PING %d", sequence_number);

    if(sendto(sock, send_buffer, strlen(send_buffer), 0, (struct sockaddr *) &ipv4, sizeof(struct sockaddr)) == -1) {
      perror("sendto");
      exit(1);
    }

    char recv_buffer[25];
    struct sockaddr_in recv_addr;
    socklen_t recv_addr_len = sizeof(recv_addr);

    if(recvfrom(sock, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *) &recv_addr, &recv_addr_len) == -1) {
      perror("recvfrom");
      exit(1);
    }

    gettimeofday(&end, NULL);

    double elapsed_time = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);

    printf("Ping reply from %s: seq=%d time=%.2fms\n", inet_ntoa(recv_addr.sin_addr), sequence_number, elapsed_time);

    sleep(1);
  }

  printf("Ping test completed.");

  freeaddrinfo(server_info);
  close(sock);

  return 0;
}