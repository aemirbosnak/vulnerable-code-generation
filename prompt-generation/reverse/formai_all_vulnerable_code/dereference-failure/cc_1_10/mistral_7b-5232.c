//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <sys/xattr.h>

#define FROM "admin@example.com"
#define TO "user@example.com"
#define SUBJECT "Reminder: Upcoming Deadline"

void send_email(char *subject, char *body) {
    char cmd[1024];
    FILE *fp;

    sprintf(cmd, "echo '%s' | sendmail -t -f %s %s", body, FROM, TO);
    fp = popen(cmd, "w");
    if (fp == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    sprintf(cmd, "echo '%s' | sendmail -t -f %s %s", subject, FROM, TO);
    if (popen(cmd, "w") == NULL) {
        perror("popen failed");
        pclose(fp);
        exit(EXIT_FAILURE);
    }

    pclose(fp);
}

int main() {
    time_t now;
    struct tm *ltm;
    char subject[128];
    char body[256];

    time(&now);
    ltm = localtime(&now);

    if (ltm->tm_hour >= 18) { // If it's 6 PM or later
        strftime(subject, sizeof(subject), "Today is %A, %B %d, %Y", ltm);
        strcpy(body, "This is a reminder that today's deadline is approaching.\nGood luck!");
        send_email(subject, body);
        printf("Email sent successfully.\n");
    } else {
        printf("It's not yet 6 PM. No email will be sent.\n");
    }

    return EXIT_SUCCESS;
}