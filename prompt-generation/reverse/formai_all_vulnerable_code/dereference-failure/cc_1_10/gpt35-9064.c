//FormAI DATASET v1.0 Category: Email Client ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mail {
    char recipient[50];
    char sender[50];
    char subject[100];
    char content[500];
};

void send_mail(struct mail *m){
    printf("Recipient: ");
    fgets(m->recipient,50,stdin);
    printf("Subject: ");
    fgets(m->subject,100,stdin);
    printf("Content (max 500 characters):\n");
    fgets(m->content,500,stdin);
    printf("Mail sent successfully!\n");
}

void check_mails(){
    printf("Checking mails...\n");
    printf("You have no new mails.\n");
}

void print_menu(){
    printf("\n---------------------------------\n");
    printf("[1] Send Mail\n");
    printf("[2] Check Mails\n");
    printf("[3] Quit\n");
}

void clear_input(){
    while(getchar()!='\n');
}

int main(){
    int choice;
    struct mail *m = malloc(sizeof(struct mail));
    printf("Welcome to Ephemeral Mail Client!\n");
    while(1){
        print_menu();
        printf("Enter your choice: ");
        scanf("%d",&choice);
        clear_input();
        switch(choice){
            case 1:
                send_mail(m);
                break;
            case 2:
                check_mails();
                break;
            case 3:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}