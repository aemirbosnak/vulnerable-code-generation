//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_NAME_LENGTH 32
#define MAX_TIME_LENGTH 64
#define MAX_BUFFER_SIZE 1024

struct url {
    char name[MAX_NAME_LENGTH];
    char url[MAX_URL_LENGTH];
    int status;
    char last_checked[MAX_TIME_LENGTH];
    struct url *next;
};

void add_url(struct url **head, char *name, char *url) {
    struct url *new_url = (struct url*) malloc(sizeof(struct url));
    strcpy(new_url->name, name);
    strcpy(new_url->url, url);
    new_url->status = 0;
    time_t current_time = time(NULL);
    char time_string[MAX_TIME_LENGTH];
    strftime(time_string, MAX_TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    strcpy(new_url->last_checked, time_string);
    new_url->next = (*head);
    (*head) = new_url;
}

int check_url_status(char *url) {
    CURL *curl;
    CURLcode res;
    long response_code;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        }
        curl_easy_cleanup(curl);
    }
    return response_code;
}

void check_urls(struct url **head) {
    struct url *current_url = (*head);
    while (current_url != NULL) {
        current_url->status = check_url_status(current_url->url);
        time_t current_time = time(NULL);
        char time_string[MAX_TIME_LENGTH];
        strftime(time_string, MAX_TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
        strcpy(current_url->last_checked, time_string);
        current_url = current_url->next;
    }
}

void print_urls(struct url *head) {
    struct url *current_url = head;
    printf("%-10s%-30s%-15s%-20s\n", "Name", "URL", "Status Code", "Last Checked");
    while (current_url != NULL) {
        printf("%-10s%-30s%-15d%-20s\n", current_url->name, current_url->url, current_url->status, current_url->last_checked);
        current_url = current_url->next;
    }
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    struct url *head = NULL;
    while (1) {
        printf("Enter command (\"add [name] [url]\", \"check\", \"exit\"): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        char *token = strtok(buffer, " \n");
        if (strcmp(token, "add") == 0) {
            char *name = strtok(NULL, " \n");
            char *url = strtok(NULL, " \n");
            add_url(&head, name, url);
        } else if (strcmp(token, "check") == 0) {
            check_urls(&head);
            print_urls(head);
        } else if (strcmp(token, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}