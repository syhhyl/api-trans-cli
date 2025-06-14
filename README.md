# api-trans-cli
api-trans-cli一个轻量级的命令行翻译工具。
使用C、OpenSsl、cJSON、curl写的

编译：gcc main.c json_parser.c cre_url.c cal_md51.c http_request.c -o trans-cli -I/opt/homebrew/include/ -L/opt/homebrew/lib/ -lcurl -lcjson -lcrypto 