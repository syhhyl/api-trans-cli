#include "translate.h"

// 全局变量定义
const char *appid = "20240129001953939";
const char *secret_key = "ZjeHGmsmJqnsR6xlrBTK";

int main(void) {
	char userinput[200];
    	char exitcode = 'q';
    
    	printf("start fanyi ~~\n");
    
    	while (1) {
		printf("enter your content(q quit): ");
		fgets(userinput, sizeof(userinput), stdin);
		//只能处理单个字符，还有输入不规范都会报错

		//if (userinput[0] == exitcode && strlen(userinput) == 2) break;

		//处理换行符
		size_t len = strlen(userinput);
		if (len > 0 && userinput[len-1] == '\n') {
		userinput[len-1] = '\0';
		}
		if (strcmp(userinput, "q") == 0) break;

		char* url = cre_url(userinput);
		printf("%s\n", extract_dst_from_json(get_json_data(url)));
		free(url); //释放资源
	}
	
	return 0;
}
