/*************************************************************************
	> File Name: 10.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 30 Oct 2017 02:27:00 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
 
//最小的矩阵路径和
//给定一个矩阵  从左上角到右下角最小的路径和

int MinPathSum(int (*vec)[4], int row, int column) {

    int dp[4][4];
    dp[0][0] = vec[0][0];
    for (int j=1; j<column; ++j) { //第一行
        dp[0][j] = dp[0][j-1] + vec[0][j];
    }
    for (int i=1; i<row; ++i) { //第一列
        dp[i][0] = dp[i-1][0] + vec[i][0];
    }

    for (int i=1; i<row; ++i) {
        for (int j=1; j<column; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[j-1][i]) + vec[i][j];
        }
    }

    return dp[row-1][column-1];
}

int MinPathSum1(int vec[][4]) {    
    return 0;
}
int MinPathSum2(int (&vec)[4][4]) {
    return 0;
}
int MinPathSum3(vector<vector<int> > &vec) {
    return 0;
}



void test() {

    vector<vector<int> > vc;

    int vec[][4] = {
        {1, 3, 5, 9},
        {8, 1, 3, 4},
        {5, 0, 6, 1},
        {8, 8, 4, 0}, 
    };

    cout<<MinPathSum(vec,4,4)<<endl;
    //    MinPathSum1(vec); //三种传递二维数组的方式 这里复习一下
    //    MinPathSum2(vec);
    //    MinPathSum3(vc);

}


int main()
{

    test();
    return 0;
}

