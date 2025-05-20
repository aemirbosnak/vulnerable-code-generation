//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define URL_LENGTH 100
#define CHECK_INTERVAL 5 // in seconds

typedef struct {
    char url[URL_LENGTH];
    bool is_alive;
} Website;

Website websites[] = {
    {"https://www.google.com", true},
    {"https://www.github.com", true},
    {"https://www.facebook.com", true}
};

void* check_website(void* arg) {
    Website* website = (Website*)arg;
    char command[URL_LENGTH + 20];
    sprintf(command, "curl -Is %s | head -n 1 | grep '200 OK'", website->url);
    while(true) {
        FILE* fp = popen(command, "r");
        char result[20];
        fgets(result, 20, fp);
        pclose(fp);
        if (strlen(result) == 0) {
            website->is_alive = false;
            printf("%s is down!\n", website->url);
        } else {
            website->is_alive = true;
            printf("%s is up and running!\n", website->url);
        }
        sleep(CHECK_INTERVAL);
    }
    return NULL;
}

int main() {
    int num_websites = sizeof(websites) / sizeof(Website);
    pthread_t threads[num_websites];
    for (int i = 0; i < num_websites; i++) {
        pthread_create(&threads[i], NULL, check_website, (void*)&websites[i]);
    }
    for (int i = 0; i < num_websites; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}