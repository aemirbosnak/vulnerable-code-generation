//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_URL_LEN 256
#define MAX_RESP_LEN 4096

// Custom error codes
#define ERR_INVALID_URL -1
#define ERR_SOCKET_FAILED -2
#define ERR_CONNECT_FAILED -3
#define ERR_RECV_FAILED -4

struct Monitor {
  char url[MAX_URL_LEN];
  int interval;
  time_t last_check;
  int status;
};

int init_monitor(struct Monitor* monitor, const char* url, int interval) {
  if (strlen(url) >= MAX_URL_LEN) {
    return ERR_INVALID_URL;
  }
  strcpy(monitor->url, url);
  monitor->interval = interval;
  monitor->last_check = 0;
  monitor->status = 0;
  return 0;
}

int check_url(struct Monitor* monitor) {
  // Check if it's time to check the URL again
  time_t now = time(NULL);
  if (now - monitor->last_check < monitor->interval) {
    return monitor->status;
  }
  monitor->last_check = now;

  // Parse the URL and resolve the hostname
  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  int err = getaddrinfo(monitor->url, "http", &hints, &result);
  if (err != 0) {
    return ERR_SOCKET_FAILED;
  }

  // Create a socket and connect to the server
  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    freeaddrinfo(result);
    return ERR_SOCKET_FAILED;
  }
  err = connect(sockfd, result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);
  if (err != 0) {
    close(sockfd);
    return ERR_CONNECT_FAILED;
  }

  // Send an HTTP GET request
  const char* request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
  char request_buf[MAX_URL_LEN + sizeof(request)];
  snprintf(request_buf, sizeof(request_buf), request, monitor->url);
  err = send(sockfd, request_buf, strlen(request_buf), 0);
  if (err == -1) {
    close(sockfd);
    return ERR_RECV_FAILED;
  }

  // Receive the HTTP response
  char response_buf[MAX_RESP_LEN];
  memset(response_buf, 0, sizeof(response_buf));
  err = recv(sockfd, response_buf, sizeof(response_buf) - 1, 0);
  close(sockfd);
  if (err == -1) {
    return ERR_RECV_FAILED;
  }

  // Check the HTTP status code
  char* status_line = strtok(response_buf, "\r\n");
  if (status_line == NULL) {
    return ERR_RECV_FAILED;
  }
  char http_version[16], status_code[4];
  sscanf(status_line, "%s %s", http_version, status_code);
  int code = atoi(status_code);
  if (code < 200 || code >= 300) {
    return code;
  }

  // Set the monitor status
  monitor->status = code;
  return code;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: %s <URL> <interval>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the monitor
  struct Monitor monitor;
  if (init_monitor(&monitor, argv[1], atoi(argv[2])) != 0) {
    printf("Error initializing monitor\n");
    return EXIT_FAILURE;
  }

  // Check the URL every specified interval
  while (1) {
    int status = check_url(&monitor);
    switch (status) {
      case 0:
        printf("%s is up (200)\n", monitor.url);
        break;
      case ERR_INVALID_URL:
        printf("Invalid URL\n");
        break;
      case ERR_SOCKET_FAILED:
        printf("Socket error\n");
        break;
      case ERR_CONNECT_FAILED:
        printf("Connection failed\n");
        break;
      case ERR_RECV_FAILED:
        printf("Receive failed\n");
        break;
      default:
        printf("Error checking URL (status: %d)\n", status);
        break;
    }
    sleep(monitor.interval);
  }

  return EXIT_SUCCESS;
}