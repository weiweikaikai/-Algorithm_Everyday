/*************************************************************************
	> File Name: 8.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 24 Oct 2017 11:20:18 AM CST
 ************************************************************************/

#include<iostream>
#include<deque>
using namespace std;

//一个长度为n整形数组arr和一个大小为w的窗口  每次窗口向右滑动一个数的大小
//求出每次窗口中的最大值并发到一个长度为n-w+1的数组中

//1.最简单的实现 time:O(N*W)
//2.使用双端队列 实现 time:O(N) room:O(W)

void MaxWindow(int *arr,int n,int w,int *result) //time:O(n) room:O(n)
{
    if (arr == NULL || result == NULL) {
        return; 
    }
    if (w > n) {
        w = n; 
    }
    deque<int> dq;
    int index = 0;
    for (int i=0; i< n; ++i) { 
        while(!dq.empty() && arr[dq.back()] <= arr[i]) { //空  或者尾部节点小于当前节点
            dq.pop_back(); 
        } 
        dq.push_back(i);   
        if (dq.front() == i-w) {
            dq.pop_front(); 
        }
        if (i >= w-1) {
            result[index++] = arr[dq.front()]; 
        }
    }
}


int main()
{
    int arr[] = {4, 3, 5, 4, 3, 3, 6, 7};
    int n = 8;
    int w = 3;
    int result[n-w+1];
    MaxWindow(arr,n,w,result);
    for (int i=0;i<n-w+1;++i) {
        cout<<result[i]<<endl;
    }
    return 0;
}

