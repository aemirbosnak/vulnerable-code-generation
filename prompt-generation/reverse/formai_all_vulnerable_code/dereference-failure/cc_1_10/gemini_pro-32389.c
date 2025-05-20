//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PING_DATA_SIZE 64

typedef struct {
  struct timeval tv_start;
  struct timeval tv_end;
  int seq_num;
} ping_data;

void print_help(char *argv[]) {
  printf("Usage: %s <host> <# of packets>\n", argv[0]);
  printf("Example: %s www.google.com 10\n", argv[0]);
}

void print_ping_response(ping_data *data) {
  long ms = (data->tv_end.tv_sec - data->tv_start.tv_sec) * 1000 +
            (data->tv_end.tv_usec - data->tv_start.tv_usec) / 1000;
  printf("Seq=%d, Time=%ldms\n", data->seq_num, ms);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    print_help(argv);
    return 1;
  }

  struct sockaddr_in dest;
  dest.sin_family = AF_INET;
  dest.sin_port = htons(80);

  struct hostent *he = gethostbyname(argv[1]);
  if (he == NULL) {
    fprintf(stderr, "Invalid host: %s\n", argv[1]);
    return 1;
  }
  memcpy(&dest.sin_addr, he->h_addr_list[0], sizeof(dest.sin_addr));

  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  int num_packets = atoi(argv[2]);
  ping_data data[num_packets];

  for (int i = 0; i < num_packets; i++) {
    memset(&data[i], 0, sizeof(data[i]));
    data[i].seq_num = i + 1;

    gettimeofday(&data[i].tv_start, NULL);
    sendto(sock, &data[i], PING_DATA_SIZE, 0, (struct sockaddr *) &dest,
            sizeof(dest));

    struct sockaddr_in src;
    socklen_t src_len = sizeof(src);
    recvfrom(sock, &data[i], PING_DATA_SIZE, 0, (struct sockaddr *) &src,
              &src_len);
    gettimeofday(&data[i].tv_end, NULL);

    print_ping_response(&data[i]);
  }

  close(sock);
  return 0;
}