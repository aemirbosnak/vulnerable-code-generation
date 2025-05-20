//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

typedef struct JsonStruct {
    char key[MAX_LEN];
    int value;
}JsonStruct;

int getLengthOfNumber(int num) { // helper function to get length of integer
    int count = 0;
    while(num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

JsonStruct parseJSON(char* jsonString) {
    JsonStruct json;
    int keyStartIndex = 0, keyEndIndex = 0, valStartIndex = 0, valEndIndex = 0;

    // get key
    for(int i = 1; i < strlen(jsonString); i++) {
        if(jsonString[i] == '\"') {
            keyStartIndex = i+1;
            break;
        }
    }
    
    
    for(int i = keyStartIndex+1; i < strlen(jsonString); i++) {
        if(jsonString[i] == '\"') {
            keyEndIndex = i;
            break;
        }
    }
    
    // get value
    for(int i=keyEndIndex+2; i<strlen(jsonString); i++) {
        if(jsonString[i] == '-') {
            valStartIndex = i;
            break;
        }
    }
    
    for(int i=valStartIndex; i<strlen(jsonString); i++) {
        if(jsonString[i] == ',') {
            valEndIndex = i-1;
            break;
        }
    }
    // converting string to integer value
    char value[valEndIndex - valStartIndex + 1];
    int j = 0;
    for(int i=valStartIndex; i<=valEndIndex; i++) {
        value[j] = jsonString[i];
        j++;
    }
    value[j] = '\0';
    json.value = atoi(value);
    
    // store key
    j = 0;
    for(int i = keyStartIndex; i < keyEndIndex; i++) {
        json.key[j] = jsonString[i];
        j++;
    }
    json.key[j] = '\0';
    
    return json;
}

int main() {
    char jsonString[MAX_LEN];
    printf("Enter a JSON string with a single key-value pair:\n");
    fgets(jsonString, MAX_LEN, stdin);
    
    printf("\nParsing JSON...\n");
    JsonStruct json = parseJSON(jsonString);
    
    // mathematical operations on integer value
    int length = getLengthOfNumber(json.value);
    int sum = 0;
    int num = json.value;
    while(num > 0) {
        int digit = num % 10;
        sum += digit*digit;
        num /= 10;
    }
    printf("Length of integer value in JSON: %d\n", length);
    printf("Sum of squares of digits of integer value in JSON: %d\n", sum);

    return 0;
}