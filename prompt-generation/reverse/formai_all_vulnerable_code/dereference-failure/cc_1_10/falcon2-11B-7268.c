//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 100
#define MAX_API_URL_LENGTH 512
#define API_URL_FORMAT "https://translate.googleapis.com/translate_a/single?client=gtx&sl=%s&tl=%s&dt=t&q=%s"

void print_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source> <target>\n", argv[0]);
        return 1;
    }
    
    char source[MAX_TEXT_LENGTH], target[MAX_TEXT_LENGTH], text[MAX_TEXT_LENGTH], translated[MAX_TEXT_LENGTH] = "";
    strcpy(source, argv[1]);
    strcpy(target, argv[2]);
    
    CURL *curl;
    CURLcode res;
    char url[MAX_API_URL_LENGTH];
    
    sprintf(url, API_URL_FORMAT, source, target, text);
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, translated);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        
        res = curl_easy_perform(curl);
        
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            print_error("Error executing API");
        }
        
        curl_easy_cleanup(curl);
    }
    
    printf("%s\n", translated);
    
    return 0;
}