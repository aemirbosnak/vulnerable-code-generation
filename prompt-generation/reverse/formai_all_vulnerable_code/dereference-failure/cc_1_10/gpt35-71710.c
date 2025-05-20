//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024 // maximum message size

char from[40]; // sender's email address
char to[40]; // recipient's email address
char subject[60]; // email subject
char message[BUFFER_SIZE]; // email message

void receiveResponse(int sock) {
  char buffer[BUFFER_SIZE]; // server response buffer
  memset(buffer, 0, sizeof(buffer)); // clear the buffer

  recv(sock, buffer, sizeof(buffer), 0); // receive the response
  printf("%s", buffer); // print the response
}

void sendCommand(int sock, char *command) {
  char buffer[BUFFER_SIZE]; // command buffer
  sprintf(buffer, "%s\r\n", command); // format the command

  send(sock, buffer, strlen(buffer), 0); // send the command
  receiveResponse(sock); // receive the response
}

void sendEmail(int sock) {
  char buffer[BUFFER_SIZE];

  // send the MAIL command
  sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
  sendCommand(sock, buffer);

  // send the RCPT command
  sprintf(buffer, "RCPT TO:<%s>\r\n", to);
  sendCommand(sock, buffer);

  // send the DATA command
  sendCommand(sock, "DATA");

  // send the email headers and body
  sprintf(buffer, "From: %s\r\n", from);
  send(sock, buffer, strlen(buffer), 0);

  sprintf(buffer, "To: %s\r\n", to);
  send(sock, buffer, strlen(buffer), 0);

  sprintf(buffer, "Subject: %s\r\n", subject);
  send(sock, buffer, strlen(buffer), 0);

  send(sock, "\r\n", 2, 0);

  send(sock, message, strlen(message), 0);

  // send the end-of-data marker
  sendCommand(sock, ".");

  printf("Email sent successfully!\n");
}

int main(int argc , char *argv[]) {

  if(argc<4) {
    printf("Usage: ./client <from> <to> <subject>");
    return 1;
  }

  // get user input
  strcpy(from, argv[1]);
  strcpy(to, argv[2]);
  strcpy(subject, argv[3]);

  printf("Enter your message:\n");
  fgets(message, BUFFER_SIZE, stdin);

  // create a socket for SMTP protocol
  int sock = socket(AF_INET , SOCK_STREAM , 0);
  
  if (sock == -1) {
    printf("Could not create socket");
    return 1;
  }

  // set the server address and port
  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); // change this to your SMTP server address
  server.sin_port = htons(SMTP_PORT);

  // connect to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Connect failed. Error");
    return 1;
  }

  // receive the server greeting
  receiveResponse(sock);

  // send the HELO command
  sendCommand(sock, "HELO localhost");

  // send the MAIL command
  sprintf(from, "MAIL FROM:<%s>\r\n", from);
  sendCommand(sock, from);

  // send the RCPT command
  sprintf(to, "RCPT TO:<%s>\r\n", to);
  sendCommand(sock, to);

  // send the DATA command
  sendCommand(sock, "DATA");

  // send the email headers and body
  sprintf(subject, "Subject: %s\r\n", subject);
  send(sock, subject, strlen(subject), 0);

  sprintf(from, "From: %s\r\n", from);
  send(sock, from, strlen(from), 0);

  sprintf(to, "To: %s\r\n", to);
  send(sock, to, strlen(to), 0);

  send(sock, "\r\n", 2, 0);

  send(sock, message, strlen(message), 0);

  // send the end-of-data marker
  sendCommand(sock, ".");

  printf("Email sent successfully!\n");

  close(sock); // close the socket

  return 0;
}