#include "translate.h"


int main(void) {
	char userinput[200];
    char exitcode = 'q';
    printf("welcomej~~~\n");
    
    while (1) {
		printf("enter your content(q quit): ");
		fgets(userinput, sizeof(userinput), stdin);

		//处理换行符
		size_t len = strlen(userinput);
		if (len > 0 && userinput[len-1] == '\n') {
			userinput[len-1] = '\0';
		}
		if (strcmp(userinput, "q") == 0) break;
		
		for (int i = 0; i < strlen(userinput); ++i) {
			if (userinput[i] == ' ') userinput[i] = '\n';
		}
		//puts(userinput);
		
		//处理多单词和多段文本
				

		char* url = cre_url(userinput);
		//printf("url:%s\n", url);
		printf("%s\n", extract_dst_from_json(get_json_data(url)));
		free(url); //释放资源
	}
	
	return 0;
}
