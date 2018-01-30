/*************************************************************************
	> File Name: 9.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 24 Oct 2017 09:48:33 PM CST
 ************************************************************************/


#include<iostream>
#include<vector>
using namespace std;

#define INT_MIN 0x80000000

//最大一个数值数组中 找出和最大的序列的值 


vector<int> vec(10);
int index = 0;

int max(int lhs,int rhs) {

    if(lhs >= rhs){ 
        return lhs;
    }
    return rhs;
}

//动态规划    
//设状态为 f[j]，表示以 S[j] 结尾的最大连续子序列和，则状态转移方程如下：
//f[j] = max {f[j − 1] + S[j], S[j]} , 其中1 ≤ j ≤ n
//target = max {f[j]} , 其中1 ≤ j ≤ n

int MaxSubArray_1(int *arr ,int n) { //O(N) O(1)
    if (arr == NULL || n <= 1) {
        return -1;
    }
    int sum =0;
    int result = INT_MIN;
    for (int i=0; i<n; ++i)  {
        sum = max(sum+arr[i], arr[i]);
        result = max(result,sum);
    }
    return result;
}
//普通方法 
int MaxSubArray_2(int *arr ,int n) { //O(N) O(1)

    if (arr == NULL || n <= 1) {
        return -1;
    }
    int sum = 0;
    int result = INT_MIN;
    for (int i=0;i<n;++i) {
        if (sum <= 0) {
            sum = arr[i];
        } else {
            sum += arr[i];
        }
        result = sum > result ? sum : result;
    }
    return result;
}

void test() {

    int arr[] = {1,-1,2,3,-4,5,6};
    cout<< MaxSubArray_1(arr,7)<<endl;
    cout<< MaxSubArray_2(arr,7)<<endl;
    for(int i=0;i<vec.size();++i) {
        cout<<vec[i]<<endl; 
    }

}


int main()
{
    test();


    return 0;
}

