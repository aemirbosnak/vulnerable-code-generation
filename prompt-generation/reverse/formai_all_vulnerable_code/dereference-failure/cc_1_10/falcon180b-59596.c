//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char delimiter;
    char *prefix;
} mailbox_t;

typedef struct {
    char *username;
    char *password;
    char *server;
    int port;
    mailbox_t inbox;
    mailbox_t sent;
    mailbox_t spam;
} account_t;

void read_config(account_t *account, FILE *fp) {
    char line[MAX_LINE_LEN];
    char *key, *value;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        key = strtok(line, "=");
        value = strtok(NULL, "\n");

        if (strcmp(key, "username") == 0) {
            account->username = strdup(value);
        } else if (strcmp(key, "password") == 0) {
            account->password = strdup(value);
        } else if (strcmp(key, "server") == 0) {
            account->server = strdup(value);
        } else if (strcmp(key, "port") == 0) {
            account->port = atoi(value);
        } else if (strcmp(key, "inbox.delimiter") == 0) {
            account->inbox.delimiter = value[0];
        } else if (strcmp(key, "inbox.prefix") == 0) {
            account->inbox.prefix = strdup(value);
        } else if (strcmp(key, "sent.delimiter") == 0) {
            account->sent.delimiter = value[0];
        } else if (strcmp(key, "sent.prefix") == 0) {
            account->sent.prefix = strdup(value);
        } else if (strcmp(key, "spam.delimiter") == 0) {
            account->spam.delimiter = value[0];
        } else if (strcmp(key, "spam.prefix") == 0) {
            account->spam.prefix = strdup(value);
        }
    }
}

int main(int argc, char **argv) {
    account_t account;
    FILE *fp;
    char config_file[64];

    sprintf(config_file, "config.%s", argv[1]);
    fp = fopen(config_file, "r");

    if (fp == NULL) {
        printf("Error: could not open config file.\n");
        exit(1);
    }

    read_config(&account, fp);
    fclose(fp);

    // TODO: implement IMAP client logic

    return 0;
}