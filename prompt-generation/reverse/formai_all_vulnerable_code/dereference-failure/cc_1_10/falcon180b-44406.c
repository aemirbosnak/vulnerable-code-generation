//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

struct StringList {
    char *string;
    struct StringList *next;
};

struct StringList *addString(struct StringList *list, char *string) {
    struct StringList *new = malloc(sizeof(struct StringList));
    new->string = string;
    new->next = list->next;
    list->next = new;
    return list;
}

void printList(struct StringList *list) {
    while (list!= NULL) {
        printf("%s\n", list->string);
        list = list->next;
    }
}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    struct StringList *list = userp;
    char *string = malloc(size * nmemb);
    memcpy(string, contents, size * nmemb);
    list = addString(list, string);
    return size * nmemb;
}

int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    struct StringList *list = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[100];
        sprintf(url, "https://www.speedtest.net/speedtest.php?server=%s&unit=Mbps", "1111");
        fp = fopen("result.html", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &list);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            fclose(fp);
            printf("Results:\n");
            printList(list);
        }
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}