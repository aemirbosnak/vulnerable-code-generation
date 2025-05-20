//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
// Welcome to the Proxy Party, where data flows like confetti!

#include <curl/curl.h>

// A struct to hold our proxy details with a dash of zest
typedef struct {
    char *host;
    int port;
    char *type;
} Proxy;

// Our trusty proxy factory, ready to conjure up the perfect proxy
Proxy *proxy_create(const char *host, int port, const char *type) {
    Proxy *proxy = malloc(sizeof(Proxy));
    proxy->host = strdup(host);
    proxy->port = port;
    proxy->type = strdup(type);
    return proxy;
}

// Time to set the proxy, buckle up for the ride!
void proxy_set(CURL *curl, Proxy *proxy) {
    curl_easy_setopt(curl, CURLOPT_PROXY, proxy->host);
    curl_easy_setopt(curl, CURLOPT_PROXYPORT, proxy->port);
    curl_easy_setopt(curl, CURLOPT_PROXYTYPE, proxy->type);
}

// Let's rock and roll!
int main() {
    // Initialize the party guests:
    CURL *curl = curl_easy_init();
    
    // Choose your proxy adventure:
    Proxy *proxy = proxy_create("1.2.3.4", 8080, "HTTP");
    proxy_set(curl, proxy); // Set the proxy stage

    // Prepare for the data dance party:
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

    // Execute the merry request:
    CURLcode res = curl_easy_perform(curl);
    
    // Time to boogie with the response!
    if(res != CURLE_OK) return -1; // Party's over, time for cleanup

    // Cleanup the party:
    curl_easy_cleanup(curl);
    free(proxy->host);
    free(proxy->type);
    free(proxy);
    return 0;
}