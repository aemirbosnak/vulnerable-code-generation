//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to connect to POP3 server
int connect_to_pop3(char *host, int port) {
    FILE *connection;
    connection = popen("telnet %s %d", "r");
    if (connection == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    printf("Connected to POP3 server\n");
    pclose(connection);
    return 0;
}

// Function to login to POP3 server
int login_to_pop3(char *user, char *password, char *host, int port) {
    FILE *connection;
    connection = popen("telnet %s %d", "r");
    if (connection == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    fprintf(connection, "USER %s\r\n", user);
    fflush(connection);
    fscanf(connection, "%s", password);
    fprintf(connection, "PASS %s\r\n", password);
    fflush(connection);
    if (pclose(connection)!= 0) {
        perror("pclose");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to list all emails in the inbox
int list_inbox_emails(char *host, int port) {
    FILE *connection;
    connection = popen("telnet %s %d", "r");
    if (connection == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    fprintf(connection, "STAT\r\n");
    fflush(connection);
    if (pclose(connection)!= 0) {
        perror("pclose");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// Function to download email
int download_email(char *email_id, char *host, int port) {
    FILE *connection;
    connection = popen("telnet %s %d", "r");
    if (connection == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    fprintf(connection, "RETR %s\r\n", email_id);
    fflush(connection);
    if (pclose(connection)!= 0) {
        perror("pclose");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <host> <port> <user> <password>\n", argv[0]);
        return 1;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *user = argv[3];
    char *password = argv[4];

    connect_to_pop3(host, port);
    login_to_pop3(user, password, host, port);
    list_inbox_emails(host, port);
    download_email("1", host, port);

    return 0;
}