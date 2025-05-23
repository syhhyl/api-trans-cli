#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mbedtls/md.h"

int main() {
    const char *input = "Hello, world!";
    unsigned char md5_binary[16]; // MD5 结果为 16 字节
    char *md5_result = malloc(33); // 分配 33 字节内存

    // 初始化 MD5 上下文
    mbedtls_md_context_t ctx;
    mbedtls_md_init(&ctx);
    mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(MBEDTLS_MD_MD5), 0);
    mbedtls_md_starts(&ctx);

    // 更新上下文
    mbedtls_md_update(&ctx, (const unsigned char *)input, strlen(input));

    // 完成 MD5 计算
    mbedtls_md_finish(&ctx, md5_binary);

    // 释放上下文资源
    mbedtls_md_free(&ctx);

    for (int i = 0; i < 16; i++) {
        printf("%02x", md5_binary[i]);
    }
    printf("\n");

    // 将二进制结果转换为十六进制字符串
    for (int i = 0; i < 16; i++) {
        //写入两位16进制，size为3，自动添加一个'\0'
        snprintf(md5_result + 2 * i, 3, "%02x", md5_binary[i]);
        printf("%s strlen: %ld\n", md5_result, strlen(md5_result));
    }
    //md5_result[32] = '\0'; // 添加字符串结尾的空字符

    // 输出结果
    printf("MD5 hash: %s\n", md5_result); // 输出 MD5 哈希值的十六进制字符串

    // 释放动态分配的内存
    free(md5_result);

    return 0;
}