//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 128
#define MAX_RESUME 1024

char *parse_name(char *resume){
    char *name = malloc(sizeof(char) * MAX_INPUT);
    int i = 0, j = 0;
    while (resume[i] != '\n'){
        name[j] = resume[i];
        j++;
        i++;
    }
    name[j] = '\0';
    return name;
}

char *parse_email(char *resume){
    char *email = malloc(sizeof(char) * MAX_INPUT);
    int i = 0, j = 0, at_count = 0;
    while (resume[i] != '\0'){
        if (resume[i] == '@'){
            at_count++;
        }
        if (at_count == 1){
            email[j] = resume[i];
            j++;
        }
        if (at_count == 2){
            break;
        }
        i++;
    }
    email[j] = '\0';
    return email;
}

char *parse_phone(char *resume){
    char *phone = malloc(sizeof(char) * MAX_INPUT);
    int i = 0, j = 0, digit_count = 0;
    while (resume[i] != '\0' && digit_count < 10){
        if (resume[i] >= '0' && resume[i] <= '9'){
            phone[j] = resume[i];
            j++;
            digit_count++;
        }
        i++;
    }
    phone[j] = '\0';
    return phone;
}

int main(){
    char resume[MAX_RESUME];
    printf("Enter your resume:\n");
    fgets(resume, MAX_RESUME, stdin);

    char *name = parse_name(resume);
    char *email = parse_email(resume);
    char *phone = parse_phone(resume);

    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);

    free(name);
    free(email);
    free(phone);

    return 0;
}