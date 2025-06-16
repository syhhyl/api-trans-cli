#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>
#include <string.h>

int read_config(char **appid, char **secret_key)
{
	FILE *fp = fopen("config.json", "r");
	if (!fp) {
		perror("open fail");
		return 1;
	}

	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);
	rewind(fp);

	char *json_data = malloc(len+1);
	fread(json_data, 1, len, fp);
	json_data[len] = '\0';
	fclose(fp);
	
	cJSON *root = cJSON_Parse(json_data);
	if (!root) {
		printf("parse fail %s\n", cJSON_GetErrorPtr());
		return 1;
	}

	*appid = strdup(cJSON_GetObjectItem(root, "appid")->valuestring);
	*secret_key = strdup(cJSON_GetObjectItem(root, "secret_key")->valuestring);

	// printf("appid:%s\n", appid);
	// printf("secret_key:%s\n", secret_key);

	cJSON_Delete(root);
	free(json_data);
	return 0;	
}