//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_URL_LEN 2048

void sanitize_url(char* url){
    char *start = NULL, *end = NULL;
    int i, url_len = strlen(url);
    char* sanitized_url = (char*)malloc(MAX_URL_LEN*sizeof(char));
    
    // Copying the protocol to the sanitized URL
    if (strncmp(url, "http://", 7) == 0){
        strncpy(sanitized_url, "http://", 7);
        start = url+7;
    } else if (strncmp(url, "https://", 8) == 0){
        strncpy(sanitized_url, "https://", 8);
        start = url+8;
    } else {
        strncpy(sanitized_url, "http://", 7);
        start = url;
    }
    
    // Sanitizing the domain name
    end = strchr(start, '/');
    if (end == NULL){
        end = url + url_len;
    }
    
    for (i=0; i<(end-start); i++){
        if (*(start+i) != ' '){
            sanitized_url[strlen(sanitized_url)] = *(start+i);
        }
    }
    
    // Sanitizing the path
    start = strchr(url, '/');
    if (start != NULL){
        strcpy(sanitized_url+strlen(sanitized_url), start);
    } else {
        strcpy(sanitized_url+strlen(sanitized_url), "/");
    }
    
    // Copying the sanitized URL back to the original array
    strcpy(url, sanitized_url);
    
    // Freeing the memory allocated for the sanitized URL
    free(sanitized_url);
}

int main(){
    char url[MAX_URL_LEN];
    printf("Enter a URL: ");
    fgets(url, MAX_URL_LEN, stdin);
    url[strlen(url)-1] = '\0'; // Removing the newline character from fgets
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}