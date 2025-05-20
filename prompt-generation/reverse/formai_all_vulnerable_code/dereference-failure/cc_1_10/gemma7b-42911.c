//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonValue {
    char type;
    union {
        int integerValue;
        double doubleValue;
        char* stringValue;
        struct JsonValue* arrayValue;
        struct JsonValue* objectValue;
    } valueUnion;
} JsonValue;

JsonValue* parseJson(char* jsonStr) {
    JsonValue* jsonObject = NULL;
    int pos = 0;
    int bufferSize = MAX_BUFFER_SIZE;
    char* buffer = malloc(bufferSize);

    while (pos < strlen(jsonStr) && jsonStr[pos] != '}') {
        switch (jsonStr[pos]) {
            case '"':
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                pos++;
                while (jsonStr[pos] != '"') {
                    buffer[pos - 1] = jsonStr[pos];
                    pos++;
                }
                buffer[pos - 1] = '\0';
                jsonObject->valueUnion.stringValue = buffer;
                break;
            case ' ':
            case ',':
            case ':':
            case '{':
            case '}':
                pos++;
                break;
            default:
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                buffer[pos - 1] = jsonStr[pos];
                pos++;
        }
    }

    free(buffer);

    return jsonObject;
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonValue* jsonObject = parseJson(jsonStr);

    printf("Name: %s\n", jsonObject->valueUnion.stringValue);
    printf("Age: %d\n", jsonObject->valueUnion.integerValue);

    free(jsonObject);

    return 0;
}