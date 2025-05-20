//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 4096
#define MAX_STATUS_LEN 16
#define MAX_HISTORY_LOG 1000

typedef struct {
    char url[MAX_URL_LEN];
    char status[MAX_STATUS_LEN];
    char response[MAX_RESPONSE_LEN];
} WebsiteState;

WebsiteState current_state;
WebsiteState previous_state;

WebsiteState* check_website(char* url) {
    char command[MAX_URL_LEN + 32];
    sprintf(command, "curl -Is --connect-timeout 5 %s", url);

    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to execute command.\n");
        exit(1);
    }

    char response[MAX_RESPONSE_LEN];
    size_t len = fread(response, 1, MAX_RESPONSE_LEN, fp);
    response[len] = '\0';

    int status_code = -1;
    char* line = strtok(response, "\n");
    while (line != NULL) {
        if (sscanf(line, "HTTP/1.%*[01] %d", &status_code) == 1) {
            break;
        }
        line = strtok(NULL, "\n");
    }

    WebsiteState* state = (WebsiteState*)malloc(sizeof(WebsiteState));
    strcpy(state->url, url);
    sprintf(state->status, "%d", status_code);
    strcpy(state->response, response);
    pclose(fp);
    return state;
}

void log_state(WebsiteState* state) {
    FILE* fp = fopen("history.log", "a");
    if (fp == NULL) {
        printf("Failed to open history.log for writing.\n");
        return;
    }
    fprintf(fp, "%s,%s\n", state->url, state->status);
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please provide a URL to monitor.\n");
        exit(1);
    }
    strcpy(current_state.url, argv[1]);
    while (1) {
        previous_state = current_state;
        current_state = *check_website(current_state.url);
        if (strcmp(current_state.status, "200") != 0) {
            printf("Error: %s returned status code %s\n", current_state.url, current_state.status);
        }
        if (strcmp(current_state.status, previous_state.status) != 0) {
            printf("Status for %s changed from %s to %s\n", current_state.url, previous_state.status, current_state.status);
            log_state(&current_state);
        }
    }
    return 0;
}