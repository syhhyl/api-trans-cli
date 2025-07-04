#include "translate.h"
#include <stdio.h>
#include <string.h>

char* extract_dst_from_json(const char* json_data) {
	cJSON* root = cJSON_Parse(json_data);

	//解析失败，抛出异常
	if (root == NULL) {
		fprintf(stderr, "json parsing error\n");
		exit(EXIT_FAILURE);
	}
	
	//从root找trans_result对应的值,翻译结果
	cJSON* trans_result = cJSON_GetObjectItemCaseSensitive(root, "trans_result");

	//没找到或者不是一个json数组或者数组大小为0,抛出异常
	if (trans_result == NULL || !cJSON_IsArray(trans_result) || cJSON_GetArraySize(trans_result) == 0) {
		fprintf(stderr, "Error extracting 'trans_result' from JSON\n");
		cJSON_Delete(root);//释放资源
		return NULL;
	}

	// char* json_str = cJSON_Print(trans_result);
	// printf("JSON:\n%s\n", json_str);

	/*
	[{
				"src":  "like",
				"dst":  "喜欢"
		}]
	*/ 

	int len = cJSON_GetArraySize(trans_result);
	char dst_result[300] = "";  
	for (int i = 0; i < len; ++i) {
		cJSON *entry = cJSON_GetArrayItem(trans_result, i);
		cJSON *dst = cJSON_GetObjectItemCaseSensitive(entry, "dst");
		if (dst == NULL|| !cJSON_IsString(dst)) {
			fprintf(stderr, "error dst\n");
			continue;
		}
		strcat(dst_result, dst->valuestring);	
		//strcat(dst_result, " ");
	}
	


	// char* json_str = cJSON_Print(dst);
	// printf("JSON:\n%s\n", json_str);
	// if (dst == NULL || !cJSON_IsString(dst)) {
	// 	fprintf(stderr, "Error extracting 'dst' from JSON\n");
	// 	cJSON_Delete(root);
	// 	return NULL;
	// }
	
	
	
	cJSON_Delete(root); //释放资源
	//return dst_value; //返回翻译
	return dst_result;
}
