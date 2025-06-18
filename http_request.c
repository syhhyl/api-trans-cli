#include "translate.h"

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	size_t realsize = size * nmemb;
	MemoryStruct *mem = (MemoryStruct *)userp;

	mem->memory = realloc(mem->memory, mem->size + realsize + 1);

	//分配失败
	if (mem->memory == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	//拷贝realsize大小从contents到mem->memory
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;//末尾设置0结束字符串

	return realsize;//返回
}

char *get_json_data(char *url) {
	CURL *curl;
	CURLcode res;

	MemoryStruct chunk;
	chunk.memory = malloc(1);
	chunk.size = 0;

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	puts(url);

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			exit(EXIT_FAILURE);
		}

		curl_easy_cleanup(curl);
	} else {
		fprintf(stderr, "curl_easy_init() failed\n");
		exit(EXIT_FAILURE);
	}

	if (chunk.size == 0) {
		fprintf(stderr, "No data received from the server\n");
		exit(EXIT_FAILURE);
	}

	chunk.memory = realloc(chunk.memory, chunk.size + 1);
	chunk.memory[chunk.size] = '\0';

	return chunk.memory;
}
