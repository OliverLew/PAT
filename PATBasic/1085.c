/**
 * 1085. PAT单位排行 (25)
 *
 * 每次 PAT 考试结束后，考试中心都会发布一个考生单位排行榜。本题就请你实现这个
 * 功能。
 *
 * 输入格式：
 *
 * 输入第一行给出一个正整数N（<=105），即考生人数。随后N行，每行按下列格式给出
 * 一个考生的信息：
 *
 * 准考证号 得分 学校
 *
 * 其中“准考证号”是由6个字符组成的字符串，其首字母表示考试的级别：“B”代表乙级，
 * “A”代表甲级，“T”代表顶级；“得分”是 [0,100] 区间内的整数；“学校”是由不超过6个
 * 英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。
 *
 * 输出格式：
 *
 * 首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：
 *
 * 排名 学校 加权总分 考生人数
 *
 * 其中“排名”是该单位的排名（从1开始）；“学校”是全部按小写字母输出的单位码；“加
 * 权总分”定义为“乙级总分/1.5 + 甲级总分 + 顶级总分*1.5”的整数部分；“考生人数”是
 * 该属于单位的考生的总人数。
 *
 * 学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。
 * 如果仍然并列，则按单位码的字典序输出。
 * 输入样例：
 *
 * 10
 * A57908 85 Au
 * B57908 54 LanX
 * A37487 60 au
 * T28374 67 CMU
 * T32486 24 hypu
 * A66734 92 cmu
 * B76378 71 AU
 * A47780 45 lanx
 * A72809 100 pku
 * A03274 45 hypu
 *
 * 输出样例：
 *
 * 5
 * 1 cmu 192 2
 * 1 au 192 3
 * 3 pku 100 1
 * 4 hypu 81 2
 * 4 lanx 81 2
 **/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct {char id[7], school[7]; int score; } Student;
typedef struct {char name[7]; int score, num; } School;

int cmp_school(const void *a, const void *b)
{
    return strcmp((*(Student**)a)->school, (*(Student**)b)->school);
}

int cmp_sort_all(const void *a, const void *b)
{
    School *s1 = *(School**)a, *s2 = *(School**)b;
    if(s1->score - s2->score)
        return s2->score - s1->score;
    else if(s1->num - s2->num)
        return s1->num - s2->num;
    else
        return strcmp(s1->name, s2->name);
}

int main()
{
    int N, M = 0, num = 0;
    double total_score = 0;
    Student students[100001] = {0}, *stu[100001] = {0};
    School schools[100001] = {0}, *sch[100001] = {0};
    
    /* Read into an array */
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        stu[i] = students + i;  /* Initialize pointer array */
        scanf("%s %d %s", stu[i]->id, &stu[i]->score, stu[i]->school);
        for(char *s = stu[i]->school; *s; s++)
            *s = tolower(*s);   /* Change to lower case */
    }
    
    /* Sort by school name */
    qsort(stu, N, sizeof(Student*), cmp_school);
    
    /* Calculate, count and record */
    for(Student **p = stu; p < stu + N; p++)
    {
        switch((*p)->id[0]) /* Calculate total score */
        {
            case 'B': total_score += (*p)->score / 1.5; break;
            case 'A': total_score += (*p)->score;       break;
            case 'T': total_score += (*p)->score * 1.5; break;
        }
        num++;              /* Count number of students */
        if(!*(p + 1) || strcmp((*p)->school, (*(p + 1))->school))
        {                   /* Record into an array */
            sch[M] = schools + M;
            strcpy(sch[M]->name, (*p)->school);
            sch[M]->score = (int)total_score;
            sch[M]->num = num;
            total_score = 0, num = 0, M++;  /* Reset and increament counter */
        }
    }
    
    /* Sort according to rules */
    qsort(sch, M, sizeof(School*), cmp_sort_all);
    
    /* Print result */
    printf("%d\n", M);
    for(int i = 0, ranking = 0; i < M; i++)
    {
        if(i > 0 && sch[i]->score < sch[i - 1]->score)
            ranking = i;
        printf("%d %s %d %d\n", ranking + 1, sch[i]->name, 
               sch[i]->score, sch[i]->num);
    }
    
    return 0;
}
