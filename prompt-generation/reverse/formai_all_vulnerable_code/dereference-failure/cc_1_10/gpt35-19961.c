//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Function to check if the character is an alphanumeric
int is_alphanumeric(char c) {
    return isalnum(c);
}

//Function to check if the character is a valid character for a URL
int is_valid_char_for_url(char c) {
    return is_alphanumeric(c) || c == '.' || c == '/';
}

//Function to check if the given string s contains a valid URL
int contains_valid_url(char *s) {
    int len = strlen(s);
    int i = 0;
    int flag = 0;
    while(i < len) {
        if(s[i] == '.') {
            if(i == 0 || i == len-1) {
                flag = 1;
                break;
            }
        } else if(s[i] == '/') {
            if(i == 0 || i == len-1) {
                flag = 1;
                break;
            }
            if(!is_valid_char_for_url(s[i-1]) || !is_valid_char_for_url(s[i+1])) {
                flag = 1;
                break;
            }
        } else if(!is_valid_char_for_url(s[i])) {
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 1) {
        return 0;
    }
    return 1;
}

//Function to sanitize the URL in the given string s
void sanitize_url(char *s) {
    int len = strlen(s);
    int i = 0;
    int j = 0;
    char *new_str = (char*)calloc(len+1, sizeof(char));
    while(i < len) {
        if(is_valid_char_for_url(s[i])) {
            new_str[j] = tolower(s[i]);
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    strcpy(s, new_str);
    free(new_str);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    if(contains_valid_url(str)) {
        sanitize_url(str);
        printf("Sanitized URL: %s", str);
    } 
    else {
        printf("The string does not contain a valid URL.");
    }
    return 0;
}