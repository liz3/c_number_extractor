#include <stdio.h>
#include "http/http_utils.h"
#include "regex_lib/re.h"

char* tostr(char c) {
    char* str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return str;
}

char *extract(const char *raw, int pos) {
    char *output = malloc(sizeof(char) * 25);
    int breaked = 0;
    for (int i = 0; i < 25; ++i) {
        char c = raw[pos + i];
        if (c == '<' || c == '"' || re_match("[a-zA-Z]", tostr(c)) == 0) {
            breaked = 1;
        }
        if(c == ' ' &&  re_match("[a-zA-Z]", tostr(raw[pos + 1 + i])) == 0)
            breaked = 1;

        if (breaked == 0)
            output[i] = c;
        else
            output[i] = 0;
    }
    return output;

}
int extract_true_len(const char *raw) {
    for (int i = 0; i < 25; ++i) {
        char c = raw[i];
        if (c == 0) {
            return i;
        }

    }
    return -1;

}
char *substr(char *raw, int pos) {
    size_t len = strlen(raw);
    size_t new_len = len - pos;
    char *new_str = malloc(sizeof(char) * new_len);

    for (int i = 0; i < new_len; ++i) {
        new_str[i] = raw[pos + i];
    }
    return new_str;
}

void regex_check(const char *raw) {

    const char *spaces_regex = "\\+49 \\d+ \\d+";
    const char *easy_regex = "\\+\\d+";

    char *next = (char *) raw;
    while (1) {
        int result = re_match(easy_regex, next);
        if (result < 0) {
            break;
        }
        char* number = extract(next, result);
        int true_length = extract_true_len(number);
        printf("Number found: %s\n", number);
        next = substr(next, result + true_length);

    }
}

int main() {

    http_get("https://xayah.info");
    char *raw = last_request;
    regex_check(raw);

    return 0;
}