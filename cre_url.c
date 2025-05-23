#include "translate.h"

// 声明外部全局变量
extern const char *appid;
extern const char *secret_key;

char* cre_url(char userinput[200]) {
    char url[1000] = "https://fanyi-api.baidu.com/api/trans/vip/translate?";
    char *q = userinput;
    char *from = "en";
    char *to = "zh";
    char salt[60];
    int a = rand();
    sprintf(salt, "%d", a);
    


    //计算签名sign
    char sign[120] = "";
    strcat(sign, appid);
    strcat(sign, q);
    strcat(sign, salt);
    strcat(sign, secret_key);
    
    //计算md5
    char* tmp = calculate_md5(sign); 
    
    strcat(url, "q=");
    strcat(url, q);
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
    return result;
}