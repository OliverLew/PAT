/**
 * 1062. 最简分数(20)
 * 
 * 一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
 * 
 * 现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
 * 
 * 输入格式：
 * 
 * 输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。题目保证给出的所有整数都不超过1000。
 * 
 * 输出格式：
 * 
 * 在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。
 * 
 * 输入样例：
 * 7/18 13/20 12
 * 输出样例：
 * 5/12 7/12
 */
#include <stdio.h>

int gcd(int a, int b)
{
    for(int r; (r = a % b); a = b, b = r) ;
    return b;
}

int main()
{
    int N1, N2, M1, M2, K, L, count = 0;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    
    if(N1 * M2 > N2 * M1)
    {
        L = N1, N1 = N2, N2 = L;
        L = M1, M1 = M2, M2 = L;
    }
    
    for(L = N1 * K / M1 + 1; N2 * K > M2 * L; L++)  if(gcd(L, K) == 1)
        printf("%s%d/%d", count++ ? " " : "", L, K);
            
    return 0;
}