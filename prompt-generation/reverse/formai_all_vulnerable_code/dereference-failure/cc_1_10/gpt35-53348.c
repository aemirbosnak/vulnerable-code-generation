//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_BUFFER_SIZE 1024
#define UPTIME_THRESHOLD 95.00

struct Url {
    char url[MAX_BUFFER_SIZE];
    bool is_down;
    double uptime;
};

struct Url urls[MAX_URLS];
int num_urls = 0;

void check_url(struct Url *url) {
    CURL *curl;
    CURLcode response;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url->url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        response = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (response == CURLE_OK) {
            url->is_down = false;
        } else {
            url->is_down = true;
        }
    }
}

void calculate_uptime(struct Url *url) {
    int num_checks = 10;
    int num_down = 0;

    for (int i = 0; i < num_checks; i++) {
        check_url(url);
        if (url->is_down) num_down++;
        sleep(10);
    }

    url->uptime = (1 - ((double) num_down / num_checks)) * 100;
}

void print_status(struct Url *url) {
    printf("%s is %s. Uptime: %.2f%%\n", url->url, url->is_down ? "down" : "up", url->uptime);

    if (url->uptime < UPTIME_THRESHOLD) {
        printf("*** Alert: %s has fallen below the uptime threshold of %.2f%% ***\n", url->url, UPTIME_THRESHOLD);
    }
}

int main(int argc, char *argv[]) {
    // read urls from file or command line arguments
    if (argc == 2) {
        FILE *fp;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("*** Error: could not open file: %s ***\n", argv[1]);
            return 1;
        }
        
        while ((read = getline(&line, &len, fp)) != -1) {
            strtok(line, "\n");
            strcpy(urls[num_urls].url, line);
            num_urls++;
        }

        fclose(fp);
        if (line) free(line);
    } else {
        for (int i = 1; i < argc; i++) {
            strcpy(urls[num_urls].url, argv[i]);
            num_urls++;
        }
    }
    
    // check status of urls and print status
    for (int i = 0; i < num_urls; i++) {
        check_url(&urls[i]);
        if (!urls[i].is_down) calculate_uptime(&urls[i]);
        print_status(&urls[i]);
    }

    return 0;
}