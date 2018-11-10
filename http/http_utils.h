//
// Created by Yann Holme Nielsen on 09.11.18.
//

#ifndef PHONE_EXTRACTOR_HTTP_UTILS_H
#define PHONE_EXTRACTOR_HTTP_UTILS_H

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>


char* last_request;
char* str_append(char*a, char* b);
int http_get(char* target_url);


#endif //PHONE_EXTRACTOR_HTTP_UTILS_H
