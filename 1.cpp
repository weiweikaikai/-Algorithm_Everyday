/*************************************************************************
	> File Name: 1.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Wed 09 Aug 2017 09:40:30 PM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

//实现 hex 到bin 的转换   以及bin 到hex的转换


int get_hex(char ch)
{
    if(ch >='0' && ch <='9')  return ch-'0'; //是字符数字
    else if (ch >='A' && ch <='F') return 10+ch-'A';
    else if (ch >='a' && ch <='f') return 10+ch-'a';
    else return 0;
}
//16进制数转ASCII字符
void hex2bin(char *dst,const char* src,int len)
{
    for( int i=0; i<len; i++){

        int num1 = get_hex(src[i*2]);
        // cout<<"num1:= "<<num1<<endl;
        int num2 = num1<<4;
        //cout<<"num2:= "<<num2<<endl;
        int num3 = get_hex(src[i*2+1]);
        //cout<<"num3:= "<<num3<<endl;
        int num4 = num2+num3;
//        cout<<"num4:= "<<num4<<endl;
        dst[i]=(char)num4; 
        //dst[i] = (unsigned char)((get_hex(src[i*2])<<4)+get_hex(src[i*2+1]));
        //printf("%c\n",dst[i]);
    }
    cout<<endl;
}

int main(){

    const char*src="41414141414141414141414141414141";
    // const char*src="11000000000000000000000000000000";
    char md5[16]={'\0'};

    hex2bin(md5,src,16);
    printf("%s\n",md5);

    return 0;
}

