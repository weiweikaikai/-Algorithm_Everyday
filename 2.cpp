/*************************************************************************
	> File Name: 2.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Sat 09 Sep 2017 10:17:52 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
 


//一个无限长的数字序列 数字k 在该序列中出现的次数也是k次
//eg: 1,2,2,3,3,3........   第n项数字是几  n>=0 n<=10^18

long long FindNnum(long long num){

    if(num < 1){
        return -1; 
    }
    //n^2 +n -2*num=0;
    long long b=1;
    long long a=1;
    long long c=-2*num;
    double b24ac= (double)(b*b-4*a*c);
    long long ret = ( -b + (long long)sqrt(b24ac) ) / (2*a); 

    //n*(n+1) /2
    long long key=(ret*(ret+1))/2;
    if(key < num )
    {
        cout<<ret+1<<endl;
        return ret+1;
    }else{
        cout<<ret<<endl;
        return ret;
    }
}
int main()
{


    FindNnum(6);
    FindNnum(7);
    FindNnum(16);
    FindNnum(22);
    FindNnum(pow(10,18)); //溢出问题如何解决 用long long 类型

    return 0;
}

