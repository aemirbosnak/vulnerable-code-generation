//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

char* sanitize(char* url) {
    char* newUrl = malloc(strlen(url) + 1); // dynamic memory allocation for new sanitized URL
    int j = 0;
    for (int i = 0; url[i]; i++) { //for loop to iterate over each character of the URL
        if (url[i] == ' ') {
            newUrl[j++] = '%'; // replace whitespaces with '%'
            newUrl[j++] = '2';
            newUrl[j] = '0';
        } else if (url[i] == '+') {
            newUrl[j++] = '%'; // replace '+' with '%2B'
            newUrl[j++] = '2';
            newUrl[j] = 'B';
        } else if (url[i] == '%') {
            if (url[i+1] != '2' || (url[i+1] == '2' && (url[i+2] != '0' && url[i+2] != 'B'))) {
                newUrl[j++] = '%'; // Keep valid instances of '%'
            }
            newUrl[j++] = url[i+1];
            newUrl[j] = url[i+2];
            i += 2;
        } else {
            newUrl[j] = url[i]; // copy all other characters as is
        }
        j++;
    }

    newUrl[j] = '\0'; // add null terminator
    return newUrl;
}

int main() {
    char* url1 = "https://www.example.com/test url with spaces"; //test URL with spaces
    char* url2 = "https://www.example.com/test+url+with+plus+signs"; //test URL with plus signs
    char* url3 = "https://www.example.com/test%20url%20with%20escaped%20spaces"; //test URL with escaped spaces
    char* url4 = "https://www.example.com/test%2Burl%2Bwith%2Bescaped%2Bplus%2Bsigns"; //test URL with escaped plus signs
    char* url5 = "https://www.example.com/test%25url%25with%25escaped%25percent%25signs"; //test URL with escaped percent signs

    char* sanUrl1 = sanitize(url1);
    char* sanUrl2 = sanitize(url2);
    char* sanUrl3 = sanitize(url3);
    char* sanUrl4 = sanitize(url4);
    char* sanUrl5 = sanitize(url5);

    printf("Sanitized URL1: %s\n", sanUrl1);
    printf("Sanitized URL2: %s\n", sanUrl2);
    printf("Sanitized URL3: %s\n", sanUrl3);
    printf("Sanitized URL4: %s\n", sanUrl4);
    printf("Sanitized URL5: %s\n", sanUrl5);

    free(sanUrl1); // free dynamically allocated memory
    free(sanUrl2);
    free(sanUrl3);
    free(sanUrl4);
    free(sanUrl5);

    return 0;
}