//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

// Define a struct for a mailbox
typedef struct mailbox {
    char *name;
    int num_messages;
    int recent_uid;
    char **messages;
    int *message_lengths;
} Mailbox;

// Function declarations
void error(char *msg);
void send_command(int sockfd, char *cmd);
void read_response(int sockfd, char *buffer, int buf_size);
int connect_to_server(char *hostname, int port);
void login(int sockfd, char *username, char *password);
Mailbox *list_mailboxes(int sockfd);
Mailbox *get_mailbox(int sockfd, char *mailbox_name);
void free_mailbox(Mailbox *mailbox);
void print_message(char *message, int message_length);

int main(int argc, char *argv[]) {
    char *hostname = "imap.gmail.com";
    int port = 993;
    char *username = "example@gmail.com";
    char *password = "password";
    char buffer[BUF_SIZE];
    Mailbox *inbox;
    Mailbox *spam;
    
    // Connect to the IMAP server
    int sockfd = connect_to_server(hostname, port);

    // Login
    login(sockfd, username, password);

    // List all mailboxes
    Mailbox *mailboxes = list_mailboxes(sockfd);
    for (int i = 0; mailboxes[i].name != NULL; i++) {
        printf("%s\n", mailboxes[i].name);
    }
    printf("\n");

    // Get the INBOX and SPAM mailboxes
    inbox = get_mailbox(sockfd, "INBOX");
    spam = get_mailbox(sockfd, "SPAM");

    // Print the messages in the INBOX
    for (int i = 0; i < inbox->num_messages; i++) {
        print_message(inbox->messages[i], inbox->message_lengths[i]);
    }

    // Free the mailbox struct and messages
    free_mailbox(inbox);
    free_mailbox(spam);
    free(mailboxes);

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to handle errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to send a command to the server
void send_command(int sockfd, char *cmd) {
    int n = write(sockfd, cmd, strlen(cmd));
    if (n < 0) {
        error("Error writing to socket");
    }
}

// Function to read a response from the server
void read_response(int sockfd, char *buffer, int buf_size) {
    int n = read(sockfd, buffer, buf_size-1);
    if (n < 0) {
        error("Error reading from socket");
    }
    buffer[n] = '\0';
}

// Function to connect to the server
int connect_to_server(char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        error("Error finding server");
    }

    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUF_SIZE];
    read_response(sockfd, buffer, BUF_SIZE); // Read the server greeting
    printf("%s", buffer);

    return sockfd;
}

// Function to log in to the server
void login(int sockfd, char *username, char *password) {
    char buffer[BUF_SIZE];
    sprintf(buffer, "login %s %s\n", username, password);
    send_command(sockfd, buffer);
    read_response(sockfd, buffer, BUF_SIZE);
    printf("%s\n", buffer);
}

// Function to list all mailboxes
Mailbox *list_mailboxes(int sockfd) {
    // Send the LIST command
    send_command(sockfd, "list \"\" \"*\"\n");

    char buffer[BUF_SIZE];
    read_response(sockfd, buffer, BUF_SIZE);
    printf("%s\n", buffer);

    // Parse the response to get the mailbox names
    Mailbox *mailboxes = malloc(sizeof(Mailbox) * 10);
    int mailbox_index = 0;
    char *line = strtok(buffer, "\r\n");
    while (line != NULL) {
        if (strncmp(line, "* LIST", 6) == 0) {
            char *name_start = strchr(line, '\"') + 1;
            char *name_end = strchr(name_start, '\"');
            int name_length = name_end - name_start;
            char *name = malloc(sizeof(char) * name_length);
            strncpy(name, name_start, name_length);
            name[name_length] = '\0';
            mailboxes[mailbox_index].name = name;
            mailboxes[mailbox_index].num_messages = 0;
            mailboxes[mailbox_index].recent_uid = 0;
            mailboxes[mailbox_index].messages = NULL;
            mailboxes[mailbox_index].message_lengths = NULL;
            mailbox_index++;
        }
        line = strtok(NULL, "\r\n");
    }
    mailboxes[mailbox_index].name = NULL;

    return mailboxes;
}

// Function to get the messages from a mailbox
Mailbox *get_mailbox(int sockfd, char *mailbox_name) {
    Mailbox *mailbox = malloc(sizeof(Mailbox));
    mailbox->name = mailbox_name;

    // Select the mailbox
    char buffer[BUF_SIZE];
    sprintf(buffer, "select %s\n", mailbox_name);
    send_command(sockfd, buffer);
    read_response(sockfd, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Get the number of messages in the mailbox
    char *num_messages_start = strstr(buffer, " EXISTS") - 3;
    char *num_messages_end = strstr(buffer, " EXISTS");
    int num_messages_length = num_messages_end - num_messages_start;
    char num_messages_str[num_messages_length + 1];
    strncpy(num_messages_str, num_messages_start, num_messages_length);
    num_messages_str[num_messages_length] = '\0';
    mailbox->num_messages = atoi(num_messages_str);

    // Get the UID of the most recent message
    char *recent_uid_start = strstr(buffer, " RECENT") - 3;
    char *recent_uid_end = strstr(buffer, " RECENT");
    int recent_uid_length = recent_uid_end - recent_uid_start;
    char recent_uid_str[recent_uid_length + 1];
    strncpy(recent_uid_str, recent_uid_start, recent_uid_length);
    recent_uid_str[recent_uid_length] = '\0';
    mailbox->recent_uid = atoi(recent_uid_str);

    // Get the messages
    if (mailbox->num_messages > 0) {
        mailbox->messages = malloc(sizeof(char*) * mailbox->num_messages);
        mailbox->message_lengths = malloc(sizeof(int) * mailbox->num_messages);

        // Fetch each message by UID
        for (int i = 1; i <= mailbox->num_messages; i++) {
            sprintf(buffer, "fetch %d body[]\n", i);
            send_command(sockfd, buffer);
            read_response(sockfd, buffer, BUF_SIZE);

            // Find the start and end of the message body
            char *body_start = strstr(buffer, "{");
            int body_length = atoi(body_start + 1);
            char *body_end = strstr(body_start, "\r\n");
            int header_length = body_start - buffer;
            int message_length = header_length + body_length + strlen(body_end);

            // Allocate memory for the message and copy it
            char *message = malloc(sizeof(char) * message_length);
            memcpy(message, buffer, header_length);
            memcpy(message + header_length, body_start, body_length + strlen(body_end));
            message[message_length] = '\0';

            // Store the message and its length
            mailbox->messages[i-1] = message;
            mailbox->message_lengths[i-1] = message_length;
        }
    } else {
        mailbox->messages = NULL;
        mailbox->message_lengths = NULL;
    }

    return mailbox;
}

// Function to free a mailbox and its messages
void free_mailbox(Mailbox *mailbox) {
    free(mailbox->name);
    for (int i = 0; i < mailbox->num_messages; i++) {
        free(mailbox->messages[i]);
    }
    free(mailbox->messages);
    free(mailbox->message_lengths);
    free(mailbox);
}

// Function to print a message
void print_message(char *message, int message_length) {
    printf("%.*s\n", message_length, message);
}