/*************************************************************************
	> File Name: 5.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 23 Oct 2017 09:24:02 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;


//1.在stl stack 适配器 的基础上 实现每次返回栈中最小的数

class MinStack
{
    public:
     bool push_stack(int dt)
     {
        data.push(dt);
        if (min_data.empty()) {
            min_data.push(dt); 
        } else if (dt <= min_data.top()) { 
            min_data.push(dt); 
        }
        return true;
     }
     int pop_stack(){
         if (data.empty()) {
             return -1; 
         }
         int ret = data.top();
         data.pop();
         if (ret == min_data.top()) {
             min_data.pop(); 
         }
         return ret; 
     }

     int get_min()
     { 
         if (min_data.empty()) {
             return -1; 
         }
         int ret = min_data.top();
         return ret;
     }


    private:
        stack<int> data;
        stack<int> min_data;
};


void test1() //time:O(1)  room: O(n)
{
    MinStack stack;
    for(int i = 50; i< 100; ++i) {
        stack.push_stack(i);
        cout <<"min:"<<stack.get_min()<<endl; 
        stack.pop_stack();
    }
    cout<<endl;
    for(int i = 1; i< 50; ++i) {
        stack.push_stack(i);
        cout <<"min:"<< stack.get_min()<<endl; 
        stack.pop_stack();
    }
}


//1.在stl stack 适配器 的基础上 使用两个栈实现队列

class MyQueue
{
    public:
       void push(int data)
       {
          data1.push(data);
       }
       int pop()
       {
           if (data1.empty() && data2.empty()) {
               return -1; 
           }

           if (data2.empty()) {
               while (!data1.empty()) {
                   data2.push(data1.top());
                   data1.pop();
               }
           }
           int ret = data2.top();
           data2.pop();
           return ret; 
       }
    private:
        stack<int> data1;
        stack<int> data2;
};

void test2()
{

    MyQueue queue;
    //for (int i = 50; i< 100; ++i) {
    //    queue.push(i);
    //}
   // for (int i = 100; i>=0; --i) {
   //     queue.push(i);
   // }
    for (int i=0; i<50;++i) {
    cout<<queue.pop()<<endl; 
    }
}

//3.用递归函数和栈操作逆序一个栈

int RemoveLastElement(stack<int> &st) { //移除并返回当前栈底元素
    int ret = st.top();
    st.pop();
    if (st.empty()) {
       return ret; 
    } else {
       int num = RemoveLastElement(st);
       st.push(ret);
       return num;
    }
}

void ReveseStack(stack<int> &st) {
    if(st.empty()) {
        return ; 
    }
    int i = RemoveLastElement(st);
    ReveseStack(st);
    st.push(i);
}

void test3()
{
    stack<int> st;
    for (int i=0;i<5;++i){
        st.push(i);
    }
    for (int i=0;i<5;++i) {
        cout<<st.top()<<" " ;
        st.pop();
    }
    cout<<endl;
    for (int i=0;i<5;++i){
        st.push(i);
    }
    ReveseStack(st);
    for (int i=0;i<5;++i) {
        cout<<st.top()<<" " ;
        st.pop();
    }
    cout<<endl;
}

int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}




