#include <math.h>
#include <stdio.h>

void work(char* str, int score) {
    int a = 0, b = 0;

    for (int i = 0; str[i] != 'E'; i++) {
        if (str[i] == 'W') {
            a++;
        }
        else if (str[i] == 'L') {
            b++;
        }

        // 检查是否满足结束条件
        if ((a >= score || b >= score) && abs(a - b) >= 2) {
            printf("%d:%d\n", a, b);
            a = b = 0; // 重新计分
        }
    }
    // 输出未结束的最后一局比分
    printf("%d:%d\n", a, b);
}

int main() {
    char str[3000 * 25];
    int n = 0;

    // 逐字符读取输入，直到遇到 'E' 表示输入结束
    char ch;
    while ((ch = getchar()) != 'E') {
        str[n++] = ch;
    }
    str[n] = 'E'; // 添加结束标记

    // 分别按照11分制和21分制输出比分
    work(str, 11);
    puts("");  // 输出部分之间的空行
    work(str, 21);

    return 0;
}
