//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

typedef struct {
    char* username;
    char* password;
    char* hostname;
    int port;
} FTPClient;

void print_usage() {
    printf("Usage: ftp <username> <password> <hostname> <port>\n");
}

FTPClient* create_ftp_client(char* username, char* password, char* hostname, int port) {
    FTPClient* client = (FTPClient*)malloc(sizeof(FTPClient));
    client->username = username;
    client->password = password;
    client->hostname = hostname;
    client->port = port;
    return client;
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        print_usage();
        return 1;
    }

    FTPClient* client = create_ftp_client(argv[1], argv[2], argv[3], atoi(argv[4]));

    printf("Connecting to %s:%s...\n", client->hostname, client->port);

    FILE* ftp_stream = popen("ftp -n -v -b -i %s", client->username);

    if (ftp_stream == NULL) {
        printf("Failed to connect to %s:%s\n", client->hostname, client->port);
        return 1;
    }

    fputs("USER ", ftp_stream);
    fputs(client->username, ftp_stream);
    fputc('\n', ftp_stream);

    fputs("PASS ", ftp_stream);
    fputs(client->password, ftp_stream);
    fputc('\n', ftp_stream);

    fputs("TYPE I", ftp_stream);
    fputc('\n', ftp_stream);

    fputs("CD /", ftp_stream);
    fputc('\n', ftp_stream);

    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), ftp_stream)!= NULL) {
        printf("%s", line);
    }

    pclose(ftp_stream);

    return 0;
}