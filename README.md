# api-trans-cli
### [项目地址](https://github.com/syhhyl/api-trans-cli)



### 项目简介

开发了一个基于百度翻译 API 的命令行翻译工具，支持实时英汉互译，涵盖 URL 构造、MD5 加密、网络请求、JSON 解析等功能模块，具备较强的跨平台移植性和系统编程实战价值。



### 技术栈

-   **C语言** 编程，模块化实现 URL 拼接、HTTP 请求、JSON 解析等功能
-   使用 **OpenSSL** 实现 MD5 签名计算，用于构建 API 请求签名
-   使用 **libcurl** 实现网络请求，基于 WriteMemoryCallback 回调处理响应数据
-   使用 **cJSON** 实现对百度翻译 API 响应中 JSON 结构的解析和抽取
-   支持动态内存管理和异常处理，保证程序稳定性



### 实现亮点

-   支持交互式输入、命令行退出等基本 CLI 交互逻辑
-   封装内存缓冲结构体 MemoryStruct，实现 curl 传输回调动态扩容
-   精简、模块化架构：translate.h 中集中定义模块接口，便于维护与扩展
-   对原 mbedtls 实现进行重构，改用更通用、易部署的 OpenSSL 方案
-   使用 strdup / malloc / realloc 等标准函数实现完整内存生命周期管理



### 编译

```shell
gcc main.c json_parser.c cre_url.c cal_md51.c http_request.c -o trans-cli -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lcurl -lcjson -lcrypto    
```

