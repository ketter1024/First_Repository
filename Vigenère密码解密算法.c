#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decrypt(const char *key, const char *cipher, char *clear) {
    int key_len = strlen(key);
    int text_len = strlen(cipher);

    for (int i = 0; i < text_len; i++) {
        char c = cipher[i];
        int shift = tolower(key[i % key_len]) - 'a';

        if (isalpha(c)) {
            if (isupper(c)) {
                clear[i] = (c - 'A' - shift + 26) % 26 + 'A';
            } else {
                clear[i] = (c - 'a' - shift + 26) % 26 + 'a';
            }
        } else {
            clear[i] = c;  // 保持非字母字符不变
        }
    }
    clear[text_len] = '\0';  // 添加字符串结束符
}

int main() {
    char key[101], cipher[101], clear[101];

    // 输入密钥和密文
    printf("请输入密钥：");
    scanf("%s", key);
    printf("请输入密文：");
    scanf("%s", cipher);

    // 解密
    decrypt(key, cipher, clear);

    // 输出明文
    printf("解密后的明文：%s\n", clear);

    return 0;
}
