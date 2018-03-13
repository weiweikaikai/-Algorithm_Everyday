/*************************************************************************
	> File Name: 12.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: 2018年03月13日 星期二 17时31分51秒
 ************************************************************************/
#include<iostream>
#include<queue>
using namespace std;

//1.如何快速的实现 大小堆的转换

struct node{
    int idx;
    int key;
    node(int a=0, int b=0):idx(a), key(b){}
    friend bool operator < (const struct node &n1, const struct node &n2) ;
};

inline bool operator < (const struct node &n1, const struct node &n2) {
    return n1.key < n2.key;
}

struct cmp{
    bool operator()(node a, node b){
        return a.key > b.key;
    }
};


void test1 () {

    cout<<"big"<<endl;
    priority_queue<node> p; //大堆  队头最大
    for(int i=0;i<10;++i){
        p.push(node(i, i));
    }

    while(!p.empty()){
        cout<<p.top().key<<endl;
        p.pop();
    }

    cout<<"small"<<endl;
    priority_queue<node, vector<node>, cmp> q; //小堆 队头最小
    for(int i=0;i<10;++i){
        q.push(node(i, i));
    }

    while(!q.empty()){
        cout<<q.top().key<<endl;
        q.pop();
    }
}
int main() {

    test1();
    return 0;
}
