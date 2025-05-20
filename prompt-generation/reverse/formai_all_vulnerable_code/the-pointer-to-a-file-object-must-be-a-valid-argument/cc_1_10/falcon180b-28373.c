//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[32];
    char ip_address[16];
} light_t;

light_t lights[MAX_LIGHTS];

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size * nmemb] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    FILE* file;
    char url[64];
    char line[256];
    int count = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        sprintf(url, "http://192.168.0.1/lights");
        file = fopen("lights.txt", "w");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        rewind(file);

        while (fgets(line, sizeof(line), file)) {
            sscanf(line, "%s %s", lights[count].name, lights[count].ip_address);
            count++;
        }

        fclose(file);
    }

    for (int i = 0; i < count; i++) {
        printf("Light %d: %s (%s)\n", i+1, lights[i].name, lights[i].ip_address);
    }

    curl_global_cleanup();
    return 0;
}