//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000

typedef struct {
    char* email;
    int label;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void read_emails(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        Email* email = &emails[num_emails++];
        char* label = strtok(line, "\t");
        email->label = atoi(label);
        char* email_text = strtok(NULL, "\n");
        email->email = strdup(email_text);
    }
    fclose(fp);
}

void detect_spam(const char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        Email* email = &emails[num_emails++];
        char* email_text = strtok(line, "\n");
        if (strstr(email_text, "viagra")!= NULL) {
            email->label = 1;
        } else if (strstr(email_text, "free money")!= NULL) {
            email->label = 1;
        } else {
            email->label = 0;
        }
    }
    fclose(fp);
}

int main() {
    read_emails("emails.txt");
    detect_spam("rules.txt");
    printf("Emails labeled as spam: %d\n", num_emails);
    return 0;
}