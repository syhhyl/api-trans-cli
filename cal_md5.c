#include "translate.h"
#include "mbedtls/md.h"  // 替换旧的头文件

char* calculate_md5(const char* input) {
    mbedtls_md_context_t ctx;//结构体对象
    unsigned char md5_binary[16]; // MD5结果为16字节
    char* md5_result = malloc(33);//分配33字节内存

    //分配失败处理
    if (md5_result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // 初始化上下文
    mbedtls_md_init(&ctx);
    const mbedtls_md_info_t* md_info = mbedtls_md_info_from_type(MBEDTLS_MD_MD5);

    // 设置哈希算法为MD5, md_info=3 代表md5 
    //如果没有setup成功退出
    if (mbedtls_md_setup(&ctx, md_info, 0) != 0) {
        fprintf(stderr, "Failed to initialize MD5 context\n");
        exit(EXIT_FAILURE);
    }

    // 计算MD5
    mbedtls_md_starts(&ctx);
    mbedtls_md_update(&ctx, (const unsigned char *)input, strlen(input));//可以多次调用
    mbedtls_md_finish(&ctx, md5_binary);//计算完成写入md5_binary
    mbedtls_md_free(&ctx);//释放资源

    // 将二进制结果转换为十六进制字符串
    for (int i = 0; i < 16; i++) {
        snprintf(md5_result + 2 * i, 3, "%02x", md5_binary[i]);
    }
    //md5_result[32] = '\0'; 多次一举，snprintf自动添加'\0' 

    return md5_result;//一个32字节的空间
}
