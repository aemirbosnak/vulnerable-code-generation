//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32 
#include <windows.h> 
#else 
#include <dlfcn.h>
#endif 

void getHTMLContent(char *text) {
    printf("The HTML content is: %s\n", text);
}

int main(int argc, char **argv) {
    // Load the library
    #ifdef _WIN32
        HINSTANCE handle = LoadLibrary("curl.dll");
    #else
        void* handle = dlopen("libcurl.so", RTLD_LAZY);
    #endif

    if (!handle) {
        fprintf(stderr, "Error: cannot load the library!\n");
        return EXIT_FAILURE;
    }

    // Locate the function
    typedef char* (*curlfunc)(char*);
    #ifdef _WIN32
        curlfunc getHTML = (curlfunc)GetProcAddress(handle, "getHTML");
    #else
        curlfunc getHTML = (curlfunc)dlsym(handle, "getHTML");
    #endif

    const char* error;
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        return EXIT_FAILURE;
    }

    // Call the function
    char *html = getHTML("https://www.example.com");

    // Process the result
    getHTMLContent(html);

    // Free memory and unload the library
    free(html);
    #ifdef _WIN32
        FreeLibrary(handle);
    #else
        dlclose(handle);
    #endif

    return EXIT_SUCCESS;
}