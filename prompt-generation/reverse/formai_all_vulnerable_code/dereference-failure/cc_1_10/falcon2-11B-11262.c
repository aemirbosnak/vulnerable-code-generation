//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>
#include <termio.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Define constants
#define MAX_SOCKET_NUM 10
#define MAX_LINE_LENGTH 1024
#define MAX_TEMPERATURE 100.0
#define TEMPERATURE_CHANGE_THRESHOLD 0.1

// Define global variables
int sock_fd[MAX_SOCKET_NUM];
int sock_num = 0;
int temperature_index = 0;
int temperature_max = -1;
double temperature_change = 0.0;
char buffer[MAX_LINE_LENGTH];
char temperature_str[MAX_LINE_LENGTH];
int line_length = 0;
char *hostname;
struct addrinfo hints, *servinfo, *p;
int sockfd;
struct sockaddr_in serv_addr;
int yes = 1;

// Define functions
void init_socket() {
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((servinfo = getaddrinfo(hostname, "80", &hints, &p)) == NULL) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
    exit(1);
  }

  for (p = servinfo; p!= NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("server: socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      perror("server: connect");
      close(sockfd);
      continue;
    }

    break;
  }

  freeaddrinfo(servinfo);
}

void read_temperature() {
  int num_read;
  char buffer[MAX_LINE_LENGTH];
  int line_length;
  char *token;

  num_read = read(sock_fd[temperature_index], buffer, MAX_LINE_LENGTH - 1);
  if (num_read < 0) {
    perror("read:");
    exit(1);
  }

  line_length = num_read;
  if (line_length > MAX_LINE_LENGTH) {
    line_length = MAX_LINE_LENGTH;
  }

  strncpy(temperature_str, buffer, MAX_LINE_LENGTH);
  temperature_str[line_length] = '\0';

  token = strtok(temperature_str, " ");
  while (token!= NULL) {
    if (strcmp(token, "Temperature") == 0) {
      temperature_index++;
      break;
    }

    token = strtok(NULL, " ");
  }

  if (temperature_index >= MAX_SOCKET_NUM) {
    fprintf(stderr, "Max temperature socket index reached\n");
    exit(1);
  }
}

void update_temperature() {
  int temperature;
  double temperature_diff;

  temperature = atof(temperature_str);
  temperature_diff = temperature - temperature_max;

  if (temperature_diff > TEMPERATURE_CHANGE_THRESHOLD) {
    printf("Temperature change detected: %f\n", temperature_diff);
    fflush(stdout);
  }

  temperature_max = temperature;
}

void signal_handler(int sig) {
  close(sock_fd[temperature_index]);
  close(sockfd);
  exit(0);
}

int main() {
  char *hostname = "localhost";
  init_socket();
  read_temperature();
  update_temperature();
  while (1) {
    read_temperature();
    update_temperature();
  }

  return 0;
}