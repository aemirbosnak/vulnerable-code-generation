//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 256
#define MAX_SPAM_WORDS 10

char* spam_words[MAX_SPAM_WORDS]; // Array to store spam words
int num_spam_words = 0; // Counter for number of spam words in array

void load_spam_words(){
    // Open file containing list of spam words
    FILE *fp = fopen("spam_words.txt", "r");

    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    char buffer[MAX_EMAIL_SIZE];

    // Read each line from file and add to array
    while(fgets(buffer, MAX_EMAIL_SIZE, fp) != NULL) {

        size_t len = strlen(buffer);

        if (len > 0 && buffer[len-1] == '\n') {
            buffer[--len-1] = '\0';
        }
        char* word = malloc(len*sizeof(char));
        strcpy(word, buffer);

        spam_words[num_spam_words] = word;
        num_spam_words++;
    }

    fclose(fp);
}

int is_email_spam(char* email){
    // Check if email contains any of the spam words
    for(int i=0; i<num_spam_words; i++){
        if(strstr(email, spam_words[i]) != NULL){
            return 1;
        }
    }

    return 0;
}

int main(){

    load_spam_words();

    // Test with example emails
    char* email1 = "Hello, this email is not spam";
    char* email2 = "Make money fast with this amazing offer!";
    char* email3 = "URGENT: Your account has been compromised";

    if(is_email_spam(email1)){
        printf("Error: Email 1 has been marked as spam!\n");
    } else {
        printf("Email 1 is not spam.\n");
    }

    if(is_email_spam(email2)){
        printf("Email 2 has been marked as spam!\n");
    } else {
        printf("Error: Email 2 is not spam.\n");
    }

    if(is_email_spam(email3)){
        printf("Email 3 has been marked as spam!\n");
    } else {
        printf("Error: Email 3 is not spam.\n");
    }

    // Free memory used by spam_words array
    for(int i=0; i<num_spam_words; i++){
        free(spam_words[i]);
    }

    return 0;
}