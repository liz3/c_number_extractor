//
// Created by Yann Holme Nielsen on 09.11.18.
//

#include "http_utils.h"


char* str_append(char*a, char* b) {
    char* c;
    c = malloc(strlen(a)  + strlen(b));
    strcpy(c, a);
    strcat(c, b);
    return c;
}

size_t write_cb(void* ptr, size_t size, size_t mnemb) {
    last_request = str_append(last_request, (char*)ptr);
    return size*mnemb;
}


int http_get(char* target_url) {
    last_request = "";
    CURL *handle;
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_URL, target_url);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_perform(handle);
    return 0;
}