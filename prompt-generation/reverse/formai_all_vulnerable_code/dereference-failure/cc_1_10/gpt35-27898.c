//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
/*
It was a foggy night in London when I first received the mission to create a website uptime monitor. My client was worried about their website's availability, and they turned to me for help. As I sat in front of my computer, I remembered the words of the great detective Sherlock Holmes - "It is a capital mistake to theorize before one has data. Insensibly one begins to twist facts to suit theories, instead of theories to suit facts."

With Holmes' words in mind, I set forth to create a program that would gather the necessary data to ensure that my client's website was always up and running. I began by initializing the necessary variables - URL of the website and how long we should wait between each check.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

int main(int argc, char **argv) {
    
    CURL *curl;
    CURLcode res;
    char *url;
    int wait_time;
    int status_code = 0;
    int error_count = 0;
    time_t current_time;
 
    if (argc < 3) {
        printf("Usage: ./uptime_monitor [URL] [Wait Time]\n");
        exit(1);
    }
 
    url = argv[1];
    wait_time = atoi(argv[2]);

//Next, I created a loop that would continuously gather data and check the website's status code, after waiting for the specified time. 

    do {
 
        curl = curl_easy_init();
 
        if (curl) {
 
            curl_easy_setopt(curl, CURLOPT_URL, url);
            res = curl_easy_perform(curl);

//If the status code was not a success code, I would increase the error count and output an error message. Otherwise, I would output a success message with the current time.

            if (res != CURLE_OK) {
                error_count += 1;
                printf("Error: %s\n", curl_easy_strerror(res));
            }
            else {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
                if (status_code != 200 && status_code != 301 && status_code != 302) {
                    error_count += 1;
                    printf("Error: Status Code %d\n", status_code);
                }
                else {
                    time(&current_time);
                    printf("Success: %s. Response Time: %ld\n", ctime(&current_time), res);
                }
            }
 
            curl_easy_cleanup(curl);
        }

//After each check, I made sure to wait the specified amount of time. If there were too many errors in a row, I would exit the program and output an error message.

        sleep(wait_time);
        if (error_count >= 10) {
            printf("Too many errors, exiting program.\n");
            exit(1);
        }
 
    } while (1);
 
    return 0;
}