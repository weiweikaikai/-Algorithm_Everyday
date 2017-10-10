/*************************************************************************
	> File Name: 3.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 10 Oct 2017 11:43:54 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//有一座高度是10级台阶的楼梯，从下往上走，每跨一步可以走1级或者2级台阶,
//请问一共有多少种走法可以走上去?
//eg:每次走1步 有10种走法   每次走2步 有5种走法

//1.最普通的想法是 直接暴力求解 多层循环嵌套

//2.动态规划   分阶段求解决策问题的数学思想  就是大事化小 小事化了
//假设只差最后一步就到第10阶台阶了  此时你可能处于两个位置
//(1)8阶台阶  假设走到8阶有x种走法   如果只需要一步走到10阶 就也有x中走法  
//(2)9阶台阶  同上理 假设走到9阶有y种走法  走到10阶也就有y种走法
//所以走到10阶走法就是 x+y

int answer2(int num) //time: O(2^N)
{
    if (num < 1)
        return 0;
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    return answer2(num-1) + answer2(num-2); 
}

vector<int> vec(256);
int answer2_map(int num) //time: O(N)  room: O(N)
{
    if (num < 1)
        return 0;
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    if (vec[num]) {
       return vec[num];
    } else {
       int value = answer2_map(num-1) + answer2_map(num-2);
       vec[num] = value;
       return value;
    }
}

//3.迭代法(循环)
int answer3(int num) //time: O(N)  room: O(1)
{
    if (num < 1)
        return 0;
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    int f1 = 1;
    int f2 = 2;
    
    int fn = 0;
    for (int i=3; i<=num; ++i) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }
    return fn; 
}



int main()
{

   cout<<answer2(10)<<endl;
   cout<<answer2_map(10)<<endl;
   cout<<answer3(10)<<endl;
         
    return 0;
}

