//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Initialize variables
    char buffer[BUF_SIZE];
    char username[50];
    char password[50];
    char imap_server[100];
    char subject[BUF_SIZE];
    char message[BUF_SIZE];
    char command[200];
    char *ptr;
    int fd, nbytes, pid;

    if(argc != 4) {
        // Check for correct command-line arguments
        printf("Usage: %s <username> <password> <IMAP server>\n", argv[0]);
        exit(1);
    }

    // Copy command-line arguments to variables
    strcpy(username, argv[1]);
    strcpy(password, argv[2]);
    strcpy(imap_server, argv[3]);

    // Connect to IMAP server
    sprintf(command, "telnet %s 143", imap_server);
    system(command);

    // Log in to IMAP server
    sprintf(command, "A001 LOGIN %s %s", username, password);
    write(fd, command, strlen(command));
    nbytes = read(fd, buffer, BUF_SIZE);
    buffer[nbytes] = '\0';
    printf("%s\n", buffer);

    // Select mailbox to read from
    sprintf(command, "A002 SELECT INBOX");
    write(fd, command, strlen(command));
    nbytes = read(fd, buffer, BUF_SIZE);
    buffer[nbytes] = '\0';
    printf("%s\n", buffer);

    // Get list of available messages
    sprintf(command, "A003 FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT)])");
    write(fd, command, strlen(command));

    // Parse message list
    ptr = strstr(buffer, "BODY[HEADER.FIELDS (SUBJECT)]") + 30;
    while(*ptr != '}') {
        // Copy subject line
        strncpy(subject, ptr, BUF_SIZE);
        subject[strcspn(subject, "\r\n")] = 0;
        printf("%s\n", subject);

        // Move on to next message
        ptr = strstr(ptr, "} ") + 2;
    }

    // Read message body
    sprintf(command, "A004 FETCH 1 BODY[TEXT]");
    write(fd, command, strlen(command));
    nbytes = read(fd, buffer, BUF_SIZE);
    buffer[nbytes] = '\0';
    printf("%s", buffer);

    // Log out of IMAP server
    sprintf(command, "A005 LOGOUT");
    write(fd, command, strlen(command));
    nbytes = read(fd, buffer, BUF_SIZE);
    buffer[nbytes] = '\0';
    printf("%s\n", buffer);

    return 0;
}