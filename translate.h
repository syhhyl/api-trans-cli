#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mbedtls/md5.h"
#include <curl/curl.h>
#include "cjson/cJSON.h"

// 内存结构体定义
typedef struct MemoryStruct {
    char *memory;
    size_t size;
} MemoryStruct;

// URL构造相关函数
char *cre_url(char userinput[200]);

// MD5计算相关函数
char *calculate_md5(const char *input);

// HTTP请求相关函数
char *get_json_data(char *url);

// JSON解析相关函数
char *extract_dst_from_json(const char *json_data);

// 内存管理相关函数
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

#endif // TRANSLATE_H
