//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define POP3_PORT 110
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    int sock_fd, n, new_count, delete_count, list_count, cnt;
    char receive_buffer[MAX_BUF], username[MAX_BUF], password[MAX_BUF], command[MAX_BUF];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if(argc < 2) {
        fprintf(stderr,"Please enter hostname.\n");
        exit(1);
    }

    // Retrieve the server name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"No host found.\n");
        exit(1);
    }

    // creating socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed.");
        exit(1);
    }

    // setting zero to server_addr
    bzero((char *) &server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    // Connecting to the server
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed.");
        exit(1);
    }

    // receiving response from server
    n = read(sock_fd, receive_buffer, MAX_BUF);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }

    receive_buffer[n] = '\0';
    printf("%s", receive_buffer);

    // get username
    printf("Enter your username: ");
    fgets(username, MAX_BUF-1, stdin);
    username[strcspn(username, "\n")] = 0;

    // get password
    printf("Enter your password: ");
    fgets(password, MAX_BUF-1, stdin);
    password[strcspn(password, "\n")] = 0;

    // login with username and password
    sprintf(command, "user %s\r\n", username);
    write(sock_fd, command, strlen(command));
    n = read(sock_fd, receive_buffer, MAX_BUF);
    receive_buffer[n] = '\0';
    printf("%s\n", receive_buffer);

    sprintf(command, "pass %s\r\n", password);
    write(sock_fd, command, strlen(command));
    n = read(sock_fd, receive_buffer, MAX_BUF);
    receive_buffer[n] = '\0';
    printf("%s\n\n", receive_buffer);

    // check number of unread mails
    write(sock_fd, "stat\r\n", 6);
    n = read(sock_fd, receive_buffer, MAX_BUF);
    receive_buffer[n] = '\0';
    sscanf(receive_buffer, "+OK %d %d", &new_count, &delete_count);
    printf("You have %d new mails in your inbox.\n\n", new_count);

    // print out list of mails
    write(sock_fd, "list\r\n", 6);
    n = read(sock_fd, receive_buffer, MAX_BUF);
    receive_buffer[n] = '\0';
    sscanf(receive_buffer, "+OK %d", &cnt);
    printf("List of mails:\n%s\n", receive_buffer);

    // read a particular mail
    printf("Which mail do you wish to read? Enter id: ");
    int mail_id;
    scanf("%d", &mail_id);

    sprintf(command, "retr %d\r\n", mail_id);
    write(sock_fd, command, strlen(command));
    n = read(sock_fd, receive_buffer, MAX_BUF);
    receive_buffer[n] = '\0';

    printf("Here is your mail:\n%s", receive_buffer);

    // quit from session
    write(sock_fd, "quit\r\n", 6);

    // close socket
    close(sock_fd);

    return 0;
}