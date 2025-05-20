//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct JSONValue {
    enum { e_string, e_number, e_object, e_array, e_true, e_false, e_null } type;

    union {
        char *s;
        double n;
        struct JSONObject *o;
        struct JSONArray *a;
    } val;
} JSONValue;

typedef struct JSONArray {
    int size;
    JSONValue *values;
} JSONArray;

typedef struct JSONPair {
    char *name;
    JSONValue *value;
} JSONPair;

typedef struct JSONObject {
    int size;
    JSONPair *pairs;
} JSONObject;

char* getJSONString(const char *path);
JSONObject* parseJSONObject(const char *jsonstring);
JSONValue* parseJSONValue(const char *jsonstring, int *i);
JSONArray* parseJSONArray(const char *jsonstring, int *i);
char* parseJSONString(const char *jsonstring, int *i);
double parseJSONNumber(const char *jsonstring, int *i);

char* getJSONString(const char *path)
{
    FILE *fp = fopen(path, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *jsonstring = malloc(length + 1);
    fread(jsonstring, 1, length, fp);
    fclose(fp);
    jsonstring[length] = '\0';
    return jsonstring;
}

JSONObject* parseJSONObject(const char *jsonstring)
{
    int i = 0;
    if (jsonstring[i] != '{') {
        fprintf(stderr, "Error: Invalid input\n");
        return NULL;
    }
    i++;
    JSONObject *object = malloc(sizeof(JSONObject));
    object->size = 0;
    do {
        if (isspace(jsonstring[i])) {
            i++;
            continue;
        }
        if (jsonstring[i] == '}') {
            i++;
            break;
        }
        if (jsonstring[i] != '\"') {
            fprintf(stderr, "Error: Invalid input\n");
            return NULL;
        }
        char *name = parseJSONString(jsonstring, &i);
        if (jsonstring[i] != ':') {
            fprintf(stderr, "Error: Invalid input\n");
            return NULL;
        }
        i++;
        JSONValue *value = parseJSONValue(jsonstring, &i);
        JSONPair pair = { name, value };
        object->size++;
        object->pairs = realloc(object->pairs, sizeof(JSONPair) * object->size);
        object->pairs[object->size - 1] = pair;

        if (jsonstring[i] == ',') {
            i++;
            continue;
        }
        if (jsonstring[i] != '}' && jsonstring[i] != '\0') {
            fprintf(stderr, "Error: Invalid input\n");
            return NULL;
        }
    } while (jsonstring[i] != '\0');

    return object;
}

JSONValue* parseJSONValue(const char *jsonstring, int *i)
{
    JSONValue *value = malloc(sizeof(JSONValue));
    if (jsonstring[*i] == '\"') {
        value->type = e_string;
        value->val.s = parseJSONString(jsonstring, i);
    } else if (isdigit(jsonstring[*i]) || jsonstring[*i] == '-') {
        value->type = e_number;
        value->val.n = parseJSONNumber(jsonstring, i);
    } else if (jsonstring[*i] == '[') {
        value->type = e_array;
        value->val.a = parseJSONArray(jsonstring, i);
    } else if (jsonstring[*i] == '{') {
        value->type = e_object;
        value->val.o = parseJSONObject(jsonstring);
    } else if (strncmp(jsonstring + *i, "true", 4) == 0) {
        value->type = e_true;
        *i += 4;
    } else if (strncmp(jsonstring + *i, "false", 5) == 0) {
        value->type = e_false;
        *i += 5;
    } else if (strncmp(jsonstring + *i, "null", 4) == 0) {
        value->type = e_null;
        *i += 4;
    } else {
        fprintf(stderr, "Error: Invalid input\n");
        return NULL;
    }
    return value;
}

JSONArray* parseJSONArray(const char *jsonstring, int *i)
{
    int size = 0;
    JSONValue *values = NULL;
    do {
        (*i)++;
        if (isspace(jsonstring[*i])) {
            continue;
        }
        if (jsonstring[*i] == ']') {
            (*i)++;
            break;
        }
        JSONValue *value = parseJSONValue(jsonstring, i);
        size++;
        values = realloc(values, sizeof(JSONValue) * size);
        values[size - 1] = *value;
        if (jsonstring[*i] == ',') {
            continue;
        }
        if (jsonstring[*i] != ']' && jsonstring[*i] != '\0') {
            fprintf(stderr, "Error: Invalid input\n");
            return NULL;
        }
    } while (jsonstring[*i] != '\0');
    JSONArray *array = malloc(sizeof(JSONArray));
    array->size = size;
    array->values = values;
    return array;
}

char* parseJSONString(const char *jsonstring, int *i)
{
    (*i)++;
    int size = 0;
    char *string = malloc(1);
    while (jsonstring[*i] != '\"') {
        if (jsonstring[*i] == '\\') {
            (*i)++;
            if (jsonstring[*i] == '\"') {
                string[size] = '\"';
            } else if (jsonstring[*i] == '\\') {
                string[size] = '\\';
            } else if (jsonstring[*i] == '/') {
                string[size] = '/';
            } else if (jsonstring[*i] == 'b') {
                string[size] = '\b';
            } else if (jsonstring[*i] == 'f') {
                string[size] = '\f';
            } else if (jsonstring[*i] == 'n') {
                string[size] = '\n';
            } else if (jsonstring[*i] == 'r') {
                string[size] = '\r';
            } else if (jsonstring[*i] == 't') {
                string[size] = '\t';
            } else if (jsonstring[*i] == 'u') {
                fprintf(stderr, "Error: Sorry, I haven't implemented UTF-16 decoding\n");
                return NULL;
            } else {
                fprintf(stderr, "Error: Invalid input\n");
                return NULL;
            }
        } else {
            string[size] = jsonstring[*i];
        }
        (*i)++;
        size++;
        string = realloc(string, size + 1);
    }
    (*i)++;
    string[size] = '\0';
    return string;
}

double parseJSONNumber(const char *jsonstring, int *i)
{
    int isNegative = 0;
    if (jsonstring[*i] == '-') {
        isNegative = 1;
        (*i)++;
    }
    int integerPart = 0;
    int decimalPart = 0;
    int fractionalDigits = 0;
    while (isdigit(jsonstring[*i])) {
        integerPart = (integerPart * 10) + (jsonstring[*i] - '0');
        (*i)++;
    }
    if (jsonstring[*i] == '.') {
        (*i)++;
        while (isdigit(jsonstring[*i])) {
            decimalPart = (decimalPart * 10) + (jsonstring[*i] - '0');
            (*i)++;
            fractionalDigits++;
        }
    }
    if (fractionalDigits == 0) {
        return isNegative ? -integerPart : integerPart;
    }
    double decimalValue = (double)decimalPart / pow(10, fractionalDigits);
    return isNegative ? -(integerPart + decimalValue) : integerPart + decimalValue;
}

int main()
{
    char *jsonstring = getJSONString("example.json");
    JSONObject *object = parseJSONObject(jsonstring);
    printf("%s\n", object->pairs[0].value->val.s);
    return 0;
}