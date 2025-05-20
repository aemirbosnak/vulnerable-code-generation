//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>

// IMAP command definitions
#define IMAP_CMD_LOGIN "LOGIN"
#define IMAP_CMD_LOGOUT "LOGOUT"
#define IMAP_CMD_LIST "LIST"
#define IMAP_CMD_SELECT "SELECT"
#define IMAP_CMD_FETCH "FETCH"

// IMAP response codes
#define IMAP_RESP_OK "+OK"
#define IMAP_RESP_NO "-ERR"
#define IMAP_RESP_BAD_LOGIN "-ERR [AUTHENTICATIONFAILED]"
#define IMAP_RESP_BAD_CMD "-ERR [BADCOMMAND]"
#define IMAP_RESP_MAILBOX_ERR "-ERR [NONEXISTENTMAILBOX]"

// Error handling
#define ERR_MSG_SIZE 256
char err_msg[ERR_MSG_SIZE];

void set_err_msg(char* msg) {
    strncpy(err_msg, msg, ERR_MSG_SIZE-1);
    err_msg[ERR_MSG_SIZE-1] = '\0';
}

char* get_err_msg() {
    return err_msg;
}

void clear_err_msg() {
    err_msg[0] = '\0';
}

// Socket communication functions
int connect_to_server(char* server, int port) {
    struct sockaddr_in saddr;
    struct hostent *h;
    int sock;
    
    // Get host info
    if ((h=gethostbyname(server)) == NULL) {
        set_err_msg("Could not resolve server address");
        return -1;
    }
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        set_err_msg("Could not create socket");
        return -1;
    }
    
    // Fill socket address details
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr = *((struct in_addr *) h->h_addr);
    saddr.sin_port = htons(port);
    
    // Connect to server
    if (connect(sock, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        set_err_msg("Connection to server failed");
        return -1;
    }
    
    return sock;
}

int read_response(int sock, char* buffer, int buf_size) {
    int bytes_read = 0;
    int status;
    
    while (bytes_read < buf_size) {
        status = read(sock, buffer + bytes_read, 1);
        if (status == -1 && errno == EINTR) continue;
        if (status == -1 || status == 0) break;
        if (buffer[bytes_read++] == '\n') break;
    }
    
    buffer[bytes_read] = '\0';
    
    return status > 0 ? bytes_read : status;
}

int send_command(int sock, char* cmd, char* args) {
    char buffer[1024];
    int bytes_written;
    int bytes_read;
    
    sprintf(buffer, "%s %s\r\n", cmd, args);
    
    bytes_written = write(sock, buffer, strlen(buffer));
    if (bytes_written == -1) return bytes_written;
    
    bytes_read = read_response(sock, buffer, 1024);
    if (bytes_read == -1) return bytes_read;
    
    if (strncmp(buffer, IMAP_RESP_OK, strlen(IMAP_RESP_OK)) == 0) {
        return 0;
    } else if (strncmp(buffer, IMAP_RESP_NO, strlen(IMAP_RESP_NO)) == 0) {
        set_err_msg(buffer);
        return -1;
    } else {
        set_err_msg("Unexpected response from server");
        return -1;
    }
}

// IMAP commands
int login(int sock, char* username, char* password) {
    char args[1024];
    
    sprintf(args, "\"%s\" \"%s\"", username, password);
    
    return send_command(sock, IMAP_CMD_LOGIN, args);
}

int logout(int sock) {
    return send_command(sock, IMAP_CMD_LOGOUT, "");
}

int list_mailboxes(int sock, char* pattern) {
    char args[1024];
    
    sprintf(args, "\"\" \"%s\"", pattern);
    
    return send_command(sock, IMAP_CMD_LIST, args);
}

int select_mailbox(int sock, char* mailbox) {
    return send_command(sock, IMAP_CMD_SELECT, mailbox);
}

int fetch_message(int sock, char* message_id) {
    char args[1024];
    
    sprintf(args, "%s BODY[]", message_id);
    
    return send_command(sock, IMAP_CMD_FETCH, args);
}

// Example program
int main(int argc, char* argv[]) {
    int sock;
    char buffer[1024];
    char* server;
    int port;
    char* username;
    char* password;
    
    int status;
    
    // Read command line arguments
    if (argc < 5) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        return 1;
    }
    
    server = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    
    // Connect to server
    sock = connect_to_server(server, port);
    if (sock == -1) {
        printf("Could not connect to server: %s\n", get_err_msg());
        return 1;
    }
    
    // Login
    status = login(sock, username, password);
    if (status == -1) {
        printf("Login failed: %s\n", get_err_msg());
        close(sock);
        return 1;
    }
    
    printf("Login successful.\n");
    
    // List mailboxes
    status = list_mailboxes(sock, "*");
    if (status == -1) {
        printf("Could not list mailboxes: %s\n", get_err_msg());
        logout(sock);
        close(sock);
        return 1;
    }
    
    printf("Mailboxes:\n");
    
    while (read_response(sock, buffer, 1024) != -1) {
        if (strncmp(buffer, IMAP_RESP_OK, strlen(IMAP_RESP_OK)) == 0) break;
        printf("%s", buffer);
    }
    
    clear_err_msg();
    
    // Select mailbox
    status = select_mailbox(sock, "INBOX");
    if (status == -1) {
        printf("Could not select mailbox: %s\n", get_err_msg());
        logout(sock);
        close(sock);
        return 1;
    }
    
    printf("Mailbox selected.\n");
    
    // Fetch message
    status = fetch_message(sock, "1");
    if (status == -1) {
        printf("Could not fetch message: %s\n", get_err_msg());
        logout(sock);
        close(sock);
        return 1;
    }
    
    while (read_response(sock, buffer, 1024) != -1) {
        if (strncmp(buffer, IMAP_RESP_OK, strlen(IMAP_RESP_OK)) == 0) break;
        printf("%s", buffer);
    }
    
    clear_err_msg();
    
    // Logout
    status = logout(sock);
    if (status == -1) {
        printf("Logout failed: %s\n", get_err_msg());
        close(sock);
        return 1;
    }
    
    printf("Logout successful.\n");
    
    // Close socket
    close(sock);
    
    return 0;
}