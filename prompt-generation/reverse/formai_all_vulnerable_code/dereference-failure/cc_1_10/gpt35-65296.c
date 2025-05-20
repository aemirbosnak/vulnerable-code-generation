//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char message[1000];
    int is_sent;
} Email;

int send_email(Email *email);

int main() {
    Email *my_email = (Email*)malloc(sizeof(Email));
    printf("Welcome to the surreal C email client!\n");

    printf("Please enter sender email address: ");
    fgets(my_email->sender, sizeof(my_email->sender), stdin);

    printf("Please enter receiver email address: ");
    fgets(my_email->receiver, sizeof(my_email->receiver), stdin);

    printf("Please enter email subject: ");
    fgets(my_email->subject, sizeof(my_email->subject), stdin);

    printf("Please enter email message: ");
    fgets(my_email->message, sizeof(my_email->message), stdin);

    printf("Sending email in 5 seconds...");
    sleep(5);

    int result = send_email(my_email);
    if (result) {
        printf("Email sent successfully!\n");
        my_email->is_sent = 1;
    } else {
        printf("Error sending email\n");
        my_email->is_sent = 0;
    }

    free(my_email);
    return 0;
}

int send_email(Email *email) {
    // make use of imagination to send email in a surrealistic way
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            printf("|||...Encrypting...|||\n");
        } else {
            printf("|||...Decrypting...|||\n");
        }
        sleep(1);
    }

    double random_number = roundf(((double)rand() / RAND_MAX) * 100);
    if (random_number < 50) {
        return 0;
    } else {
        return 1;
    }
}