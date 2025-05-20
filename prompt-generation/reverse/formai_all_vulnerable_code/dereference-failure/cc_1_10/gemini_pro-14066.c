//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

enum {
  MSEC_PER_SEC  = 1000,
  USEC_PER_MSEC = 1000,
};

/*********************************************************************************************************************************/
typedef struct {
  struct sockaddr_in addr;
  int fd;
  size_t ping_count, ping_bytes;
  struct timespec start_time, end_time;
} Host;
/*********************************************************************************************************************************/
size_t
ping_host(const Host *host)
{
  size_t bytes_sent = 0, bytes_recv = 0, i, len = 0, size = 0;
  int opt = 0, ret, n, r = 0;
  char buf[256] = { 0 };
  clock_t start, end;
  struct timespec ping_time_start, ping_time_end, us, ms, ping_time;
  double ping_avg = 0.0, ping_sd = 0.0, ping_sd_dev = 0.0;

  for (i = 0; i < host->ping_count; i++) {
    if ((n = send(host->fd, buf, sizeof(buf), MSG_NOSIGNAL)) == -1) {
      perror("send");
      return 0;
    }

    bytes_sent += n;

    start = clock();

    len = sizeof(host->addr);
    if ((r = recvfrom(host->fd, buf, sizeof(buf), 0, (struct sockaddr *)&host->addr, &len)) == -1) {
      perror("recv");
      return 0;
    }

    bytes_recv += r;

    end = clock();
    // get overall ping time
    ping_time_start.tv_sec  = (time_t)  start / MSEC_PER_SEC;
    ping_time_start.tv_nsec = (long int) start % MSEC_PER_SEC * USEC_PER_MSEC;
    ping_time_end.tv_sec   = (time_t)  end   / MSEC_PER_SEC;
    ping_time_end.tv_nsec  = (long int) end   % MSEC_PER_SEC * USEC_PER_MSEC;
    ms.tv_sec = ping_time_end.tv_sec - ping_time_start.tv_sec;
    ms.tv_nsec = ping_time_end.tv_nsec - ping_time_start.tv_nsec;
    if (ms.tv_nsec < 0) {
      ms.tv_sec--;
      ms.tv_nsec += USEC_PER_MSEC;
    } else if (ms.tv_nsec >= USEC_PER_MSEC) {
      ms.tv_sec++;
      ms.tv_nsec -= USEC_PER_MSEC;
    }
    ping_time.tv_sec = ms.tv_sec;
    ping_time.tv_nsec = ms.tv_nsec;

    printf("Ping %d bytes %s: %d ms\n", (int) r, host->addr.sin_addr.s_addr, (int) ping_time.tv_nsec / USEC_PER_MSEC);

    ping_avg += (double) ping_time.tv_nsec;
    ping_sd_dev += pow((double) ping_time.tv_nsec - ping_avg / (i + 1), 2);
}

  ping_avg = ping_avg / (i + 1);
  ping_sd_dev = sqrt(ping_sd_dev / (i + 1));

  printf("Sent %d bytes of PINGs, received %d bytes, average ping time: %d ms, standard deviation: %d ms\n",
    (int) bytes_sent, (int) bytes_recv, (int) ping_avg / USEC_PER_MSEC, (int) ping_sd_dev / USEC_PER_MSEC);

  return r;
}
/*********************************************************************************************************************************/
int
main(int argc, char **argv)
{
  int i;
  Host host;
  struct hostent *ent;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <ping count>\n", argv[0]);
    return 1;
  }

  if ((host.ping_count = atoi(argv[2])) < 1) {
    fprintf(stderr, "Invalid ping count: %s\n", argv[2]);
    return 1;
  }

  if ((ent = gethostbyname(argv[1])) == NULL) {
    perror("gethostbyname");
    return 1;
  }

  memset(&host.addr, 0, sizeof(host.addr));
  host.addr.sin_family = AF_INET;
  host.addr.sin_port = htons(atoi("80"));
  memcpy(&host.addr.sin_addr.s_addr, ent->h_addr_list[0], ent->h_length);

  if ((host.fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    return 1;
  }

  if (ping_host(&host) == 0) {
    perror("ping");
    return 1;
  }

  close(host.fd);
  return 0;
}