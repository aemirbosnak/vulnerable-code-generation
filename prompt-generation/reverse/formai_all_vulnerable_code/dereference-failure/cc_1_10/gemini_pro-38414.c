//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define DOWNLOAD_SIZE (1024 * 1024)
#define DOWNLOAD_URL "http://speedtest.googlefiber.net/1GB.test"
#define HTTP_GET "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: keep-alive\r\n\r\n"

static int g_sock = -1;
static struct sockaddr_in g_addr;
static char g_host[256];
static char g_userAgent[256];
static char g_buffer[DOWNLOAD_SIZE];
static ssize_t g_total = 0;
static struct timeval g_start;
static int g_running = 1;
static int g_done = 0;

static void finish(int sig) {
  g_running = 0;
}

static void print_status(int sig) {
  double time, speed;

  gettimeofday(&g_start, NULL);
  time = (g_start.tv_sec - g_addr.sin_port) + (g_start.tv_usec - g_addr.sin_addr.s_addr) / 1000000.0;
  speed = (double)g_total / time;
  printf("\r%.2f MB/s", speed);
  fflush(stdout);
}

static void cleanup() {
  if (g_done) {
    close(g_sock);
  }
}

static int connect_to_host() {
  int sock;
  struct hostent *host;

  if ((host = gethostbyname(g_host)) == NULL) {
    perror("gethostbyname");
    return -1;
  }

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return -1;
  }

  g_addr.sin_family = AF_INET;
  g_addr.sin_port = htons(80);
  g_addr.sin_addr = *(struct in_addr *)*host->h_addr_list;

  if (connect(sock, (struct sockaddr *)&g_addr, sizeof(g_addr)) == -1) {
    perror("connect");
    close(sock);
    return -1;
  }

  return sock;
}

static int send_request() {
  char request[1024];

  snprintf(request, sizeof(request), HTTP_GET, DOWNLOAD_URL, g_host, g_userAgent);
  if (write(g_sock, request, strlen(request)) == -1) {
    perror("write");
    return -1;
  }

  return 0;
}

static int receive_response() {
  ssize_t n;

  while ((n = read(g_sock, g_buffer, sizeof(g_buffer))) > 0) {
    g_total += n;
  }

  if (n == -1) {
    perror("read");
    return -1;
  }

  return 0;
}

static int main_loop() {
  fd_set rfds;

  while (g_running) {
    FD_ZERO(&rfds);
    FD_SET(g_sock, &rfds);

    if (select(g_sock + 1, &rfds, NULL, NULL, NULL) == -1) {
      perror("select");
      return -1;
    }

    if (FD_ISSET(g_sock, &rfds)) {
      if (receive_response() == -1) {
        return -1;
      }
    }

    print_status(0);
  }

  g_done = 1;
  return 0;
}

int main(int argc, char *argv[]) {
  struct sigaction sa;
  int sock;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <user-agent>\n", argv[0]);
    return -1;
  }

  strcpy(g_host, argv[1]);
  strcpy(g_userAgent, argv[2]);

  sa.sa_handler = finish;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  if (sigaction(SIGINT, &sa, NULL) == -1) {
    perror("sigaction");
    return -1;
  }

  sa.sa_handler = print_status;
  sa.sa_flags = SA_RESTART;
  sigemptyset(&sa.sa_mask);
  if (sigaction(SIGALRM, &sa, NULL) == -1) {
    perror("sigaction");
    return -1;
  }

  if ((sock = connect_to_host()) == -1) {
    return -1;
  }

  g_sock = sock;
  if (send_request() == -1) {
    return -1;
  }

  if (main_loop() == -1) {
    return -1;
  }

  cleanup();
  return 0;
}