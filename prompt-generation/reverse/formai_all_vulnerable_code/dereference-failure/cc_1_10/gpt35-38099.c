//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

char* recv_line(int sd);
void send_cmd(int sd, char* cmd);

int main(int argc, char** argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s [SERVER] [PORT] [USERNAME] [PASSWORD]\n", argv[0]);
        exit(1);
    }

    char* server = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];
    char* password = argv[4];
    
    // First, we create a socket to connect to the server
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket");
        exit(1);
    }

    // Then, we create a sockaddr_in structure with the server address and port
    struct sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    struct hostent *hp = gethostbyname(server);
    if (hp == NULL) {
        fprintf(stderr, "Unknown host: %s\n", server);
        exit(1);
    }
    memcpy(&srv_addr.sin_addr, hp->h_addr, sizeof(srv_addr.sin_addr));

    // Now we connect to the server
    if (connect(sd, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // First, we receive the greeting message from the server
    char* greeting = recv_line(sd);
    printf("%s", greeting);

    // Then, we send the username
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "USER %s\r\n", username);
    send_cmd(sd, cmd);

    // Next, we receive the response to the username command
    char* response = recv_line(sd);
    printf("%s", response);

    // Now we send the password
    sprintf(cmd, "PASS %s\r\n", password);
    send_cmd(sd, cmd);

    // And we receive the response to the password command
    response = recv_line(sd);
    printf("%s", response);

    // Finally, we send the quit command to close the connection
    send_cmd(sd, "QUIT\r\n");

    // And we receive the response to the quit command
    response = recv_line(sd);
    printf("%s", response);

    // We close the socket
    close(sd);

    return 0;
}

// This function receives a line from the socket and returns it as a null-terminated string
char* recv_line(int sd) {
    char recv_buf[BUFFER_SIZE];
    int n = recv(sd, recv_buf, BUFFER_SIZE - 1, 0);
    recv_buf[n] = '\0';
    return strdup(recv_buf);
}

// This function sends a command to the server as a string
void send_cmd(int sd, char* cmd) {
    send(sd, cmd, strlen(cmd), 0);
}