//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    
    while (i < j) {
        if (str[i]!= str[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Function to check if a given IP address is valid
int isValidIP(char *ip) {
    int octet[4];
    int i = 0;
    int j = 0;
    
    // Split the IP address into four octets
    char *token = strtok(ip, ".");
    while (token!= NULL) {
        octet[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    
    // Check if each octet is within the valid range
    for (i = 0; i < 4; i++) {
        if (octet[i] < 0 || octet[i] > 255) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a given user ID is valid
int isValidUserID(char *uid) {
    int i = 0;
    int j = strlen(uid) - 1;
    
    // Check if the user ID is within the valid range
    while (i < j) {
        if (uid[i] == '-' && uid[j] == '-') {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// Main function
int main() {
    char *ip = "192.168.0.1";
    char *uid = "-1234-";
    char *token = strtok(ip, ".");
    
    while (token!= NULL) {
        printf("%d.%d.%d.%d\n", atoi(token), atoi(strtok(NULL, ".")), atoi(strtok(NULL, ".")), atoi(strtok(NULL, ".")));
        token = strtok(NULL, ".");
    }
    
    if (isValidIP(ip)) {
        printf("Valid IP address\n");
    } else {
        printf("Invalid IP address\n");
    }
    
    if (isValidUserID(uid)) {
        printf("Valid user ID\n");
    } else {
        printf("Invalid user ID\n");
    }
    
    return 0;
}