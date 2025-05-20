//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 1024
#define MAX_ATTACH_LEN 1024

typedef struct
{
    char *email;
    char *attach;
} Email;

Email *create_email()
{
    Email *email = malloc(sizeof(Email));
    email->email = malloc(MAX_EMAIL_LEN);
    email->attach = malloc(MAX_ATTACH_LEN);
    return email;
}

void destroy_email(Email *email)
{
    free(email->email);
    free(email->attach);
    free(email);
}

int send_email(Email *email)
{
    FILE *fp = fopen("email.txt", "w");
    if (fp == NULL)
    {
        return -1;
    }

    fprintf(fp, "From: %s\n", email->email);
    fprintf(fp, "To: %s\n", email->email);
    fprintf(fp, "Subject: %s\n", email->email);
    fprintf(fp, "\n");
    fprintf(fp, "%s\n", email->attach);

    fclose(fp);
    return 0;
}

int main()
{
    Email *email = create_email();

    printf("Enter your email address: ");
    scanf("%s", email->email);

    printf("Enter the recipient's email address: ");
    scanf("%s", email->attach);

    printf("Enter the subject of the email: ");
    scanf("%s", email->attach);

    printf("Enter the body of the email: ");
    scanf("%s", email->attach);

    int result = send_email(email);
    if (result == 0)
    {
        printf("Email sent successfully.\n");
    }
    else
    {
        printf("Error sending email.\n");
    }

    destroy_email(email);
    return 0;
}