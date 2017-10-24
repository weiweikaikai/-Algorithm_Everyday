/*************************************************************************
	> File Name: 7.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Mon 23 Oct 2017 09:46:52 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
 
//使用一个栈给另一个栈中的元素排序


void Sort(stack<int> &st,stack<int> &help) {
    if (st.empty() || !help.empty()) {
        return ; 
    }
    help.push(st.top());
    st.pop();
    while (!st.empty()) {
          int left = st.top();
          st.pop();
          int right = help.top();
          if (left >= right) {
             help.push(left);
          } else {
             while (!help.empty()) {
                   int tmp = help.top();
                    help.pop(); 
                   if(tmp < left) {
                     help.push(left);
                     break;
                   } else {
                      st.push(tmp); 
                   }
             }
          }
    }


}


int main()
{
  stack<int> st;
  stack<int> help;

  cout<<"start: ";
  for (int i=10; i>=0; --i) {
      st.push(i);
      cout<<10-i<<",";
  }
  cout<<endl;
  Sort(st,help);
  cout<<"after sort: ";
  while (!help.empty()) {
      cout<<help.top()<<",";
      help.pop();
  }
  cout<<endl;

  return 0;
}

