#include "translate.h"
#include <string.h>


char* cre_url(char userinput[200]) {
    char url[1000] = "https://fanyi-api.baidu.com/api/trans/vip/translate?";
    char *q = userinput;
    char *from = "en";
    char *to = "zh";
    char salt[60];
    int a = rand();
    sprintf(salt, "%d", a);

    
    
    

    char *appid = (char *)malloc(sizeof(char) * 50);
    char *secret_key = (char *)malloc(sizeof(char) * 50);

    //read config
    //计算签名sign
    read_config(&appid, &secret_key);
    char sign[120] = "";
    strcat(sign, appid);
    strcat(sign, q);
    strcat(sign, salt);
    strcat(sign, secret_key);
    // printf("appid:%s\n", appid);
    // printf("secret_key:%s\n", secret_key);
    
    //计算md5
    char* tmp = calculate_md5(sign); 
    char *encode_q = curl_easy_escape(NULL, userinput, 0);
    
    strcat(url, "q=");
    strcat(url, encode_q);
    strcat(url, "&from=");
    strcat(url, from);
    strcat(url, "&to=");
    strcat(url, to);
    strcat(url, "&appid=");
    strcat(url, appid);
    strcat(url, "&salt=");
    strcat(url, salt);
    strcat(url, "&sign=");
    strcat(url, tmp);

    char *result = strdup(url);//创建一个url字符串副本，返回指向副本的指针，url在函数结束时被释放
    free(tmp);  // 释放calculate_md5分配的内存
    free(encode_q);
    return result;
}