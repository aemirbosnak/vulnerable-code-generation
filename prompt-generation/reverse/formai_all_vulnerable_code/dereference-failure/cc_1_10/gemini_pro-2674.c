//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_MSG_SIZE 10240
#define CRLF "\r\n"
#define CRLF_LEN 2

static int sockfd = -1;
static char buffer[MAX_BUFFER_SIZE];

static bool paranoid_connect(const char *server_ip, int server_port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return false;
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) != 0) {
        return false;
    }

    return true;
}

static bool paranoid_send_command(const char *command) {
    int len = strlen(command);
    int sent_bytes = send(sockfd, command, len, 0);
    if (sent_bytes != len) {
        return false;
    }
    return true;
}

static bool paranoid_receive_response() {
    int received_bytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (received_bytes <= 0) {
        return false;
    }
    buffer[received_bytes] = '\0';
    return true;
}

static bool paranoid_login(const char *username, const char *password) {
    // Send the LOGIN command
    char login_command[MAX_MSG_SIZE];
    snprintf(login_command, MAX_MSG_SIZE, "LOGIN %s %s" CRLF, username, password);
    if (!paranoid_send_command(login_command)) {
        return false;
    }

    // Receive the response
    if (!paranoid_receive_response()) {
        return false;
    }

    // Check if the response is OK
    if (strncmp(buffer, "+OK LOGIN completed", 18) != 0) {
        return false;
    }

    return true;
}

static bool paranoid_list_mailboxes() {
    // Send the LIST command
    if (!paranoid_send_command("LIST \"\" *\n")) {
        return false;
    }

    // Receive the response
    if (!paranoid_receive_response()) {
        return false;
    }

    // Check if the response is OK
    if (strncmp(buffer, "+OK LIST completed", 18) != 0) {
        return false;
    }

    // Parse the response and print the mailboxes
    char *mailbox_list = buffer + 18;
    while (*mailbox_list != '\0') {
        char *mailbox_name = mailbox_list;
        while (*mailbox_list != '\n' && *mailbox_list != '\0') {
            mailbox_list++;
        }
        if (*mailbox_list == '\n') {
            *mailbox_list = '\0';
            printf("%s\n", mailbox_name);
            mailbox_list++;  // Skip the newline character
        }
    }

    return true;
}

static bool paranoid_select_mailbox(const char *mailbox_name) {
    // Send the SELECT command
    char select_command[MAX_MSG_SIZE];
    snprintf(select_command, MAX_MSG_SIZE, "SELECT \"%s\"\n", mailbox_name);
    if (!paranoid_send_command(select_command)) {
        return false;
    }

    // Receive the response
    if (!paranoid_receive_response()) {
        return false;
    }

    // Check if the response is OK
    if (strncmp(buffer, "+OK [READ-ONLY] SELECT completed", 32) != 0) {
        return false;
    }

    return true;
}

static bool paranoid_fetch_message(unsigned int message_id, bool fetch_body) {
    // Send the FETCH command
    char fetch_command[MAX_MSG_SIZE];
    snprintf(fetch_command, MAX_MSG_SIZE, "FETCH %u (UID RFC822", message_id);
    if (fetch_body) {
        strcat(fetch_command, " BODY[TEXT]");
    }
    strcat(fetch_command, ")\n");
    if (!paranoid_send_command(fetch_command)) {
        return false;
    }

    // Receive the response
    if (!paranoid_receive_response()) {
        return false;
    }

    // Check if the response is OK
    if (strncmp(buffer, "+OK FETCH completed", 20) != 0) {
        return false;
    }

    // Parse the response and print the message
    char *message_text = buffer + 20;
    while (*message_text != '\0') {
        if (strncmp(message_text, "UID ", 4) == 0) {
            message_text += 4;
            while (*message_text != ' ') {
                message_text++;
            }
            message_text++;
        }
        if (strncmp(message_text, "RFC822", 6) == 0) {
            message_text += 6;
            while (*message_text != ' ') {
                message_text++;
            }
            message_text++;
        }
        if (strncmp(message_text, "BODY[TEXT]", 10) == 0) {
            message_text += 10;
            while (*message_text != ' ') {
                message_text++;
            }
            message_text++;
        }
        if (*message_text != '\0') {
            printf("%s\n", message_text);
            while (*message_text != CRLF[1] && *message_text != '\0') {
                message_text++;
            }
            message_text += CRLF_LEN;
        }
    }

    return true;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <server_ip> <server_port> <username> <password>\n", argv[0]);
        return 1;
    }

    if (!paranoid_connect(argv[1], atoi(argv[2]))) {
        printf("Failed to connect to the server\n");
        return 1;
    }

    if (!paranoid_login(argv[3], argv[4])) {
        printf("Failed to login to the server\n");
        return 1;
    }

    if (!paranoid_list_mailboxes()) {
        printf("Failed to list mailboxes\n");
        return 1;
    }

    if (!paranoid_select_mailbox("INBOX")) {
        printf("Failed to select mailbox\n");
        return 1;
    }

    if (!paranoid_fetch_message(1, true)) {
        printf("Failed to fetch message\n");
        return 1;
    }

    return 0;
}