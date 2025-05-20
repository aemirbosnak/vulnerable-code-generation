//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/* Struct to hold the response data */
struct response_data {
    size_t size;
    char* data;
};

/* Callback function to handle the response */
static size_t response_callback(char *data, size_t size, size_t nmemb, void *userdata) {
    size_t n = size*nmemb;
    struct response_data *rdata = (struct response_data*) userdata;
    rdata->data = realloc(rdata->data, rdata->size + n + 1);
    if(rdata->data == NULL) {
        printf("Memory allocation error\n");
        return 0;
    }
    memcpy(rdata->data + rdata->size, data, n);
    rdata->size += n;
    rdata->data[rdata->size] = '\0';
    return n;
}

/* Function to check the uptime of a website */
int check_site(char* url) {
    CURL *curl_handle;
    CURLcode res;
    struct response_data response;
    response.size = 0;
    response.data = malloc(sizeof(char));

    /* Initialize curl */
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();

    /* Set the URL */
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    /* Set the response callback */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, response_callback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &response);

    /* Perform the request */
    res = curl_easy_perform(curl_handle);

    /* Check the response code */
    if(res != CURLE_OK) {
        printf("Error checking site. Error code: %d\n", res);
        return -1;
    }

    /* Parse the response */
    if(strstr(response.data, "200 OK") != NULL) {
        printf("Site %s is UP!\n", url);
        return 1;
    } else {
        printf("Site %s is DOWN!\n", url);
        return 0;
    }

    /* Clean up */
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    free(response.data);
}

/* Main function */
int main(int argc, char **argv) {
    char *sites[] = {"https://www.google.com", "https://www.yahoo.com", "https://www.bing.com"};
    int i, site_status;

    /* Check each site */
    for(i=0; i<sizeof(sites)/sizeof(sites[0]); i++) {
        printf("Checking site %s\n", sites[i]);
        site_status = check_site(sites[i]);
    }

    return 0;
}