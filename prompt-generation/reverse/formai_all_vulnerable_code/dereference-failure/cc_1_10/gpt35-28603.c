//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char const *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Unable to create socket\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110); // POP3 port

    struct hostent *server = gethostbyname("pop.gmail.com");
    if (server == NULL) {
        printf("Unable to resolve host\n");
        return 1;
    }

    memcpy(&serv_addr.sin_addr, server->h_addr_list[0], server->h_length);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Unable to connect to server\n");
        return 1;
    }

    char recv_buff[MAX_MSG_SIZE];

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Send USER command
    const char *user_cmd = "USER example@gmail.com\r\n";
    send(sock, user_cmd, strlen(user_cmd), 0);

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Send PASS command
    const char *pass_cmd = "PASS yourpasswordhere\r\n";
    send(sock, pass_cmd, strlen(pass_cmd), 0);

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Send LIST command
    const char *list_cmd = "LIST\r\n";
    send(sock, list_cmd, strlen(list_cmd), 0);

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Send RETR command to retrieve email
    const char *retr_cmd = "RETR 1\r\n";
    send(sock, retr_cmd, strlen(retr_cmd), 0);

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Send QUIT command
    const char *quit_cmd = "QUIT\r\n";
    send(sock, quit_cmd, strlen(quit_cmd), 0);

    if (recv(sock, recv_buff, sizeof(recv_buff), 0) < 0) {
        printf("Received invalid response from server\n");
        return 1;
    }

    printf("%s", recv_buff);

    // Close socket
    close(sock);

    return 0;
}