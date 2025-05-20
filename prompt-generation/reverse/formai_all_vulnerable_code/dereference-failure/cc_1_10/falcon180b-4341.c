//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048
#define MAX_USER_AGENT_SIZE 256
#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE (1024 * 1024 * 10) // 10 MB

struct {
    char *url;
    char *user_agent;
    char *request;
    char *response;
    int response_size;
} ctx;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    ctx.response = realloc(ctx.response, ctx.response_size + realsize + 1);
    if (ctx.response == NULL) {
        return 0;
    }
    memcpy(&ctx.response[ctx.response_size], contents, realsize);
    ctx.response[ctx.response_size + realsize] = '\0';
    ctx.response_size += realsize;
    return realsize;
}

void cleanup()
{
    if (ctx.url!= NULL) {
        free(ctx.url);
    }
    if (ctx.user_agent!= NULL) {
        free(ctx.user_agent);
    }
    if (ctx.request!= NULL) {
        free(ctx.request);
    }
    if (ctx.response!= NULL) {
        free(ctx.response);
    }
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        printf("Usage: %s <URL> <User-Agent> <Request Data>\n", argv[0]);
        return 1;
    }

    ctx.url = strdup(argv[1]);
    ctx.user_agent = strdup(argv[2]);
    ctx.request = strdup(argv[3]);

    ctx.response = malloc(1);
    ctx.response_size = 0;

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, ctx.user_agent);
        curl_easy_setopt(curl, CURLOPT_URL, ctx.url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ctx.request);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ctx);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Response:\n%s\n", ctx.response);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(ctx.response);
    }

    cleanup();
    curl_global_cleanup();

    return 0;
}