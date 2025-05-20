//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
// Linus Torvalds style IMAP client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Allocate memory, or die
#define XMALLOC(type, n) (type*)malloc(sizeof(type) * (n))

// Die with an error message
#define DIE(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

// IMAP commands
#define LOGIN "LOGIN"
#define LIST "LIST"
#define SELECT "SELECT"
#define FETCH "FETCH"
#define QUIT "QUIT"

// IMAP responses
#define OK "+OK"
#define NO "+NO"
#define BAD "+BAD"

// Maximum buffer size
#define BUFSIZE 1024

int main(int argc, char** argv)
{
  // Check arguments
  if (argc != 3) DIE("Usage: imapclient <server> <port>");

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) DIE("socket");

  // Connect to the server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) DIE("inet_pton");
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) DIE("connect");

  // Read the welcome message
  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, OK, strlen(OK)) != 0) DIE("Unexpected welcome message");

  // Login
  snprintf(buf, BUFSIZE, "%s %s %s\r\n", LOGIN, argv[3], argv[4]);
  if (write(sockfd, buf, strlen(buf)) < 0) DIE("write");
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, OK, strlen(OK)) != 0) DIE("Login failed");

  // List mailboxes
  snprintf(buf, BUFSIZE, "%s \"\" *\r\n", LIST);
  if (write(sockfd, buf, strlen(buf)) < 0) DIE("write");
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, BAD, strlen(BAD)) == 0) DIE("LIST command failed");

  // Select a mailbox
  snprintf(buf, BUFSIZE, "%s \"INBOX\"\r\n", SELECT);
  if (write(sockfd, buf, strlen(buf)) < 0) DIE("write");
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, OK, strlen(OK)) != 0) DIE("SELECT command failed");

  // Fetch a message
  snprintf(buf, BUFSIZE, "%s 1 (BODY.PEEK[TEXT])\r\n", FETCH);
  if (write(sockfd, buf, strlen(buf)) < 0) DIE("write");
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, OK, strlen(OK)) != 0) DIE("FETCH command failed");

  // Print the message
  printf("%s", buf);

  // Quit
  snprintf(buf, BUFSIZE, "%s\r\n", QUIT);
  if (write(sockfd, buf, strlen(buf)) < 0) DIE("write");
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) DIE("read");
  if (strncmp(buf, OK, strlen(OK)) != 0) DIE("QUIT command failed");

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}