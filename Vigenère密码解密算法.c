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
    char key[101], cipher[1001], clear[1001];

    // 输入密钥和密文
    scanf("%100s", key);
    scanf("%1000s", cipher);

    // 解密
    decrypt(key, cipher, clear);

    // 输出明文
    printf("%s", clear);

    return 0;
}
