#include "translate.h"

int main(void) {
	char userinput[200];

  while (1) {
    printf(">>> ");
    fgets(userinput, sizeof(userinput), stdin);

    size_t len = strlen(userinput);
    if (len > 0 && userinput[len-1] == '\n')
      userinput[len-1] = '\0';
    if (strcmp(userinput, "q") == 0) break;
    
    for (int i = 0; i < strlen(userinput); ++i) {
      if (userinput[i] == ' ') userinput[i] = '\n';
    }

    char *url = cre_url(userinput);
    char *json_data	= get_json_data(url);
    char *trans_result = extract_dst_from_json(json_data);
    printf("%s\n", trans_result);
    free(url);
    free(json_data);
    free(trans_result);
	}
	
	return 0;
}
