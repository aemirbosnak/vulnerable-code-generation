//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add an email address to the list
void add_email(char **emails, int *count, char *email) {
    if (*emails == NULL) {
        *emails = (char *)malloc(sizeof(char) * 128);
        *emails = strcpy(*emails, email);
        *count = 1;
    } else {
        char *temp = strstr(*emails, email);
        if (temp == NULL) {
            char *new_emails = (char *)malloc(sizeof(char) * (strlen(*emails) + strlen(email) + 1));
            strcpy(new_emails, *emails);
            strcat(new_emails, ", ");
            strcat(new_emails, email);
            *emails = new_emails;
            (*count)++;
        }
    }
}

// Function to print the list of emails
void print_emails(char **emails, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", emails[i]);
    }
}

int main() {
    char *emails[128];
    int count = 0;

    // Read emails from file
    FILE *fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char email[128];
    while (fscanf(fp, "%s", email)!= EOF) {
        add_email(emails, &count, email);
    }
    fclose(fp);

    // Print unique emails
    print_emails(emails, count);

    return 0;
}