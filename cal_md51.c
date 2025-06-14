#include "translate.h"

char *calculate_md5(const char *input)
{
	MD5_CTX ctx;
	unsigned char md[16];
	char *md5_result = malloc(33);
	
	if (md5_result == NULL) {
		fprintf(stderr, "memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	MD5((const unsigned char *)input, strlen((const char *)input), md);
	
	for (int i = 0; i < 16; ++i) {
		snprintf(md5_result + 2 * i, 3, "%02x", md[i]);
	}
	
	return md5_result;
}
