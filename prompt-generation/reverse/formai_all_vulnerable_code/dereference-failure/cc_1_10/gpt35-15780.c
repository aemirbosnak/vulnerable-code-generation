//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

// Struct to hold the email
typedef struct email {
    char subject[BUF_SIZE];
    char sender[BUF_SIZE];
    char date[BUF_SIZE];
    char content[BUF_SIZE];
} Email;

// Function to process IMAP response
void process_imap_response(int sockfd, char *command, char *response) {
    char buffer[BUF_SIZE];

    // Send IMAP command to server
    write(sockfd, command, strlen(command));

    // Receive response from server
    read(sockfd, buffer, BUF_SIZE);

    // Process response and print to console
    sscanf(buffer, "%s %s", response, buffer);
    printf("%s %s\n", command, response);
}

// Function to read email from server
Email read_email(int sockfd, char *seq_num) {
    char command[BUF_SIZE];
    char response[BUF_SIZE];
    char buffer[BUF_SIZE];
    Email email;

    // Select email using sequence number
    sprintf(command, "FETCH %s BODY[HEADER.FIELDS (SUBJECT FROM DATE)]\r\n", seq_num);
    process_imap_response(sockfd, command, response);

    // Read email headers and store in email struct
    read(sockfd, buffer, BUF_SIZE);
    sscanf(buffer, "Subject: %[^\r]\r\nFrom: %[^\r]\r\nDate: %[^\r]\r\n", email.subject, email.sender, email.date);

    // Select body of email
    sprintf(command, "FETCH %s BODY[TEXT]\r\n", seq_num);
    process_imap_response(sockfd, command, response);

    // Read email body and store in email struct
    read(sockfd, buffer, BUF_SIZE);
    sscanf(buffer, "%[^\r]", email.content);

    return email;
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    char command[BUF_SIZE];
    char response[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char mailbox[BUF_SIZE];
    char seq_num[BUF_SIZE];

    Email email;

    // Check if all arguments are given
    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port mailbox\n", argv[0]);
        exit(0);
    }

    // Get mailbox from arguments
    strcpy(mailbox, argv[3]);

    // Establish connection with server
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Login to server
    strcpy(username, "yourusername");
    strcpy(password, "yourpassword");
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    process_imap_response(sockfd, command, response);

    // Select mailbox
    sprintf(command, "SELECT %s\r\n", mailbox);
    process_imap_response(sockfd, command, response);

    // Fetch number of emails in mailbox
    sprintf(command, "SEARCH ALL\r\n");
    process_imap_response(sockfd, command, response);

    // Read number of emails from server response
    read(sockfd, buffer, BUF_SIZE);
    strtok(buffer, " ");
    strcpy(seq_num, strtok(NULL, " "));

    // Read and print email information for all emails in mailbox
    while (strcmp(seq_num, "0")) {
        email = read_email(sockfd, seq_num);
        printf("Subject: %s\nFrom: %s\nDate: %s\n\n%s\n\n", 
            email.subject, email.sender, email.date, email.content);
        sprintf(command, "FETCH %s FLAGS\r\n", seq_num);
        process_imap_response(sockfd, command, response);
        read(sockfd, buffer, BUF_SIZE);
        strtok(buffer, " ");
        strcpy(seq_num, strtok(NULL, " "));
    }

    // Logout and close connection
    process_imap_response(sockfd, "LOGOUT\r\n", response);
    close(sockfd);

    return 0;
}