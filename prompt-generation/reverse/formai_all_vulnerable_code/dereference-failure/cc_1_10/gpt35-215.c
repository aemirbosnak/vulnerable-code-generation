//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024
#define DELIM " \r\n"

void send_command(char*, int);
void receive_response();
int create_socket();
void Quit();
void Login(char*, char*);
void Cwd(char*);
void List();
void Download(char*);

int sock_fd;
char buffer[BUFFER_SIZE];

int main(int argc, char* argv[]) {
  sock_fd = create_socket();
  receive_response();
  Login("anonymous", "password");
  Cwd("docs");
  List();
  Download("example.txt");
  Quit();
  return 0;
}

void send_command(char* cmd, int argc) {
  sprintf(buffer, cmd, argc);
  printf(">>> %s", buffer);
  send(sock_fd, buffer, strlen(buffer), 0);
}

void receive_response() {
  ssize_t bytes = recv(sock_fd, buffer, BUFFER_SIZE - 1, 0);
  while (bytes > 0) {
    buffer[bytes] = '\0';
    printf("<<< %s", buffer);
    bytes = recv(sock_fd, buffer, BUFFER_SIZE - 1, 0);
  }
}

int create_socket() {
  struct sockaddr_in serv_addr;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
  serv_addr.sin_port = htons(SERVER_PORT);
  connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  return sock;
}

void Quit() {
  send_command("QUIT\r\n", 0);
  receive_response();
  close(sock_fd);
}

void Login(char* user, char* pass) {
  send_command("USER %s\r\n", user);
  receive_response();
  send_command("PASS %s\r\n", pass);
  receive_response();
}

void Cwd(char* path) {
  send_command("CWD %s\r\n", path);
  receive_response();
}

void List() {
  int data_sock_fd;
  char response[BUFFER_SIZE];
  struct sockaddr_in data_addr;
  socklen_t data_addr_len = sizeof(data_addr);
  send_command("PASV\r\n", 0);
  recv(sock_fd, response, BUFFER_SIZE - 1, 0);
  int data_port = atoi(strchr(response, '(') + 1);
  int i;
  for (i = 0; i < 4; i++) {
    char* comma_pos = strchr(response, ',');
    *comma_pos = '.';
  }
  char* end_pos = strchr(response, ')');
  *end_pos = '\0';
  char* data_addr_str = strchr(response, '(') + 1;
  inet_aton(data_addr_str, &data_addr.sin_addr);
  data_addr.sin_port = htons(data_port);
  data_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(data_sock_fd, (struct sockaddr*)&data_addr, data_addr_len);
  send_command("LIST\r\n", 0);
  receive_response();
  ssize_t bytes = recv(data_sock_fd, buffer, BUFFER_SIZE - 1, 0);
  while (bytes > 0) {
    buffer[bytes] = '\0';
    printf("%s", buffer);
    bytes = recv(data_sock_fd, buffer, BUFFER_SIZE - 1, 0);
  }
  close(data_sock_fd);
  receive_response();
}

void Download(char* filename) {
  int data_sock_fd;
  char response[BUFFER_SIZE];
  struct sockaddr_in data_addr;
  socklen_t data_addr_len = sizeof(data_addr);
  send_command("PASV\r\n", 0);
  recv(sock_fd, response, BUFFER_SIZE - 1, 0);
  int data_port = atoi(strchr(response, '(') + 1);
  int i;
  for (i = 0; i < 4; i++) {
    char* comma_pos = strchr(response, ',');
    *comma_pos = '.';
  }
  char* end_pos = strchr(response, ')');
  *end_pos = '\0';
  char* data_addr_str = strchr(response, '(') + 1;
  inet_aton(data_addr_str, &data_addr.sin_addr);
  data_addr.sin_port = htons(data_port);
  data_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(data_sock_fd, (struct sockaddr*)&data_addr, data_addr_len);
  char cmd[BUFFER_SIZE];
  sprintf(cmd, "RETR %s\r\n", filename);
  send_command(cmd, 0);
  receive_response();
  FILE* fp = fopen(filename, "w");
  ssize_t bytes = recv(data_sock_fd, buffer, BUFFER_SIZE - 1, 0);
  while (bytes > 0) {
    fwrite(buffer, 1, bytes, fp);
    bytes = recv(data_sock_fd, buffer, BUFFER_SIZE - 1, 0);
  }
  fclose(fp);
  close(data_sock_fd);
  receive_response();
}