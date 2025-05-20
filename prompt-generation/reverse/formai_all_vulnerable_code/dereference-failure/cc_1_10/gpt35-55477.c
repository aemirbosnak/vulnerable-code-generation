//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAIL_LENGTH 1000

int is_spam(char* mail){
    int i, j,count=0,ratio,mail_size;
    char* keywords[] = {"inheritance","lottery","viagra","offer","discount", "money", "earn", "win", "cash", "supplies", "medication", "online", "limited time"};
    int no_of_keywords = 13;
    mail_size = strlen(mail);

    for(i=0;i<no_of_keywords;i++){
        for(j=0;j<mail_size;j++){
            if(mail[j] == keywords[i][0]){
                if(strncmp(&mail[j], keywords[i], strlen(keywords[i])) == 0){
                    count++;
                }
            }
        }
    }

    ratio = (count/no_of_keywords)*100;
    if(ratio > 50){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char* mail;
    int is_spam_mail;
    
    mail = (char*) malloc(MAX_MAIL_LENGTH * sizeof(char));
    
    printf("Enter the email content: ");
    scanf("%[^\n]%*c", mail);

    is_spam_mail = is_spam(mail);

    if(is_spam_mail){
        printf("\nThe email is spam!");
    }
    else{
        printf("\nThe email is not spam.");
    }

    free(mail);

    return 0;
}