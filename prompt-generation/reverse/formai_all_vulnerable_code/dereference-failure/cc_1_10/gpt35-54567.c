//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
// Romeo and Juliet C Browser Plugin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toUpper(char *str) {
    char *newStr = malloc(sizeof(char) * strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        newStr[i] = toupper(str[i]);
    }
    return newStr;
}

const char *romeo = "romeo@capulet.com";
const char *juliet = "juliet@montague.com";

int main() {
    char *email = malloc(sizeof(char) * 100);
    char *subject = malloc(sizeof(char) * 100);
    char *body = malloc(sizeof(char) * 1000);

    // Welcome message
    printf("Welcome to the Romeo and Juliet Browser Plugin!\n");
    printf("Please enter your email address: ");
    scanf("%s", email);

    // Check if email is Romeo or Juliet
    char *user = strstr(email, "romeo") == NULL ? juliet : romeo;
    printf("\n");
    printf("%s,\n\n", user);

    // Get subject and body
    printf("What is the subject of your message?: ");
    scanf(" %[^\n]", subject);
    printf("What is the body of your message?: ");
    scanf(" %[^\n]", body);

    // Format message for output
    char *title = toUpper(user == romeo ? "Montague Messenger" : "Capulet Courier");
    printf("\n-------------------------------------------------------------\n");
    printf("     %s - New Message\n", title);
    printf("-------------------------------------------------------------\n\n");
    printf("%s,\n\n", user == romeo ? juliet : romeo);
    printf("Subject: %s\n\n", subject);
    printf("%s\n\n", body);
    printf("-------------------------------------------------------------\n\n");

    // Say goodbye
    printf("Thank you for using the Romeo and Juliet Browser Plugin!\n");

    free(email);
    free(subject);
    free(body);
    free(title);

    return 0;
}