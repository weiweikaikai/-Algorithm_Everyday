/*************************************************************************
	> File Name: 11.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 30 Jan 2018 11:23:03 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//典型动态规划问题

//最长公共子序列
//eg: 求 2 7 1 5 6 4 3 8 9 的最长上升子序列  //不是连续的

//解析:
//当arr[j]<arr[i](j<i)且tmp[j]+1>tmp[i](j<i)时,tmp[i]=num[j]+1。
//复杂度很明显，外层i枚举每个数，内层j枚举目前i的最优值，即O（n^2）
int LIS(int *arr, int n) {

    int *tmp = new int[n];
    int max_len = 1;
    for (int i=0; i<n; ++i) {
        tmp[i] = 1; 
        for (int j=0; j<i; ++j) {
            if (arr[j] <= arr[i] &&  (tmp[j]+1) > tmp[i]) {
                tmp[i] = tmp[j]+1; 
            }
        }
        if(tmp[i] > max_len) {
            max_len = tmp[i]; 
        }
    }
    delete tmp;
    return max_len;
}



void test() {
    int arr[] = {2, 7, 1, 5, 6, 4, 3, 8, 9};
    cout<<LIS(arr, sizeof(arr)/sizeof(*arr))<<endl;
}






int main()
{
    test();
    return 0;
}

