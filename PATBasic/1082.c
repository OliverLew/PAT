/**
 * 1082. 射击比赛 (20)
 * 时间限制
 * 200 ms
 * 内存限制
 * 65536 kB
 * 代码长度限制
 * 8000 B
 * 判题程序
 * Standard
 * 作者
 * CHEN, Yue
 *
 * 本题目给出的射击比赛的规则非常简单，谁打的弹洞距离靶心最近，谁就是冠军；谁差得最远，谁就是菜鸟。本题给出一系列弹洞的平面坐标(x,y)，请你编写程序找出冠军和菜鸟。我们假设靶心在原点(0,0)。
 *
 * 输入格式：
 *
 * 输入在第一行中给出一个正整数 N（<= 10 000）。随后 N 行，每行按下列格式给出：
 *
 * ID x y
 *
 * 其中 ID 是运动员的编号（由4位数字组成）；x 和 y 是其打出的弹洞的平面坐标(x,y)，均为整数，且 0 <= |x|, |y| <= 100。题目保证每个运动员的编号不重复，且每人只打 1 枪。
 *
 * 输出格式：
 *
 * 输出冠军和菜鸟的编号，中间空 1 格。题目保证他们是唯一的。
 * 输入样例：
 *
 * 3
 * 0001 5 7
 * 1020 -1 3
 * 0233 0 -1
 *
 * 输出样例：
 *
 * 0233 0001
 **/
 
#include <stdio.h>

int main()
{
    int best_id, worst_id, cur_id;
    int x, y, N;
    int min_dist_sq = 99999, max_dist_sq = -1, cur_dist_sq; 
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &cur_id, &x, &y);
        cur_dist_sq = x * x + y * y;
        if(min_dist_sq > cur_dist_sq)
        {
            min_dist_sq = cur_dist_sq;
            best_id = cur_id;
        }
        if(max_dist_sq < cur_dist_sq)
        {
            max_dist_sq = cur_dist_sq;
            worst_id = cur_id;
        }
    }
    
    printf("%04d %04d", best_id, worst_id);
    
    return 0;
}
