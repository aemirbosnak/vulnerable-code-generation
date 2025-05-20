//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_LIST_LEN 100

struct subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

struct mailing_list {
    char name[MAX_NAME_LEN];
    struct subscriber subscribers[MAX_LIST_LEN];
    int num_subscribers;
};

int create_mailing_list(char *name) {
    FILE *fp;
    struct mailing_list list;

    fp = fopen(name, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    memset(&list, 0, sizeof(list));
    strcpy(list.name, name);

    fwrite(&list, sizeof(list), 1, fp);
    fclose(fp);

    return 0;
}

int add_subscriber(char *name, char *email) {
    FILE *fp;
    struct mailing_list list;

    fp = fopen(name, "r+");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fread(&list, sizeof(list), 1, fp);

    if (list.num_subscribers >= MAX_LIST_LEN) {
        fprintf(stderr, "Error: list is full\n");
        return -1;
    }

    strcpy(list.subscribers[list.num_subscribers].name, name);
    strcpy(list.subscribers[list.num_subscribers].email, email);
    list.num_subscribers++;

    fseek(fp, 0, SEEK_SET);
    fwrite(&list, sizeof(list), 1, fp);
    fclose(fp);

    return 0;
}

int send_email(char *name, char *subject, char *body) {
    FILE *fp;
    struct mailing_list list;
    int i;

    fp = fopen(name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    fread(&list, sizeof(list), 1, fp);
    fclose(fp);

    for (i = 0; i < list.num_subscribers; i++) {
        // Send email to list.subscribers[i].email
        printf("Sending email to %s (%s)\n", list.subscribers[i].name, list.subscribers[i].email);
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <command> <name> <args>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "create") == 0) {
        return create_mailing_list(argv[2]);
    } else if (strcmp(argv[1], "add") == 0) {
        return add_subscriber(argv[2], argv[3]);
    } else if (strcmp(argv[1], "send") == 0) {
        return send_email(argv[2], argv[3], argv[4]);
    } else {
        fprintf(stderr, "Error: unknown command '%s'\n", argv[1]);
        return 1;
    }

    return 0;
}