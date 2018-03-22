/*************************************************************************
	> File Name: 13.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: 2018年03月22日 星期四 15时41分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

//请给出一个时间为O(nlgk)、用来将k个已排序链表合并为一个排序链表的算法。此处n为所有输入链表中元素的总数。（提示：用一个最小堆来做k路合并）。
//
//算法思想:
//1. 从k个链表中取出每个链表的第一个元素，组成一个大小为k的数组arr，然后将数组arr转换为最小堆，那么arr[0]就为最小元素了
//2. 取出arr[0]，将其放到新的链表中，然后将arr[0]元素在原链表中的下一个元素补到arr[0]处，即arr[0].next，如果 arr[0].next为空，即它所在的链表的元素已经取完了，那么将堆的最后一个元素补到arr[0]处，堆的大小自动减一，循环n-k次即可。

//链表节点
class Node {

public:
    Node(int dt = int()) {
        next = NULL; 
        data = dt;
    }
    int getdata() {
        return data; 
    }
    bool operator <(const Node&tmp) {
        if (data < tmp.data) {
            return true; 
        }
        return false;
    }
    bool operator >(const Node&tmp) {
        if (data > tmp.data) {
            return true; 
        }
        return false;
    }
    bool operator <=(const Node&tmp) {
        if (data <= tmp.data) {
            return true; 
        }
        return false;
    }
    Node& operator = (const Node&tmp) {
        if (this == &tmp) {
          return *this; 
        }
        this->data = tmp.data;
        this->next = tmp.next;
        return *this;
    }

    Node* next;
    int  data;
};
//链表
class List {

public:
    List() {
        first = NULL; 
    }
    void push_back(int dt) {
        Node * node = new Node(dt);
        if (first == NULL) {
            first = node; 
        } else {
           Node* tmp = first;
           while(tmp->next != NULL) {
              tmp = tmp->next; 
           }
           tmp->next = node;
        }
    }
    void del_list() {
        if (first != NULL) { 
            Node *nxt_node = first;  
            while (nxt_node != NULL) {
                Node *tmp = first->next;
                delete(nxt_node);
                nxt_node = tmp;
            }
            first = NULL;
        }
    }
    void Print() {
        Node*tmp = first;
        while(tmp != NULL) {
            cout<<tmp->getdata()<<"->";  
            tmp = tmp->next;
        }
        cout<<endl;
    }
    Node* first;
};


void MinHeap_Sift(Node* arr,int pos,int sz)                                        
{                                                                                  
    if(arr == NULL || pos <0 || sz <0)                                             
    {                                                                              
        return ;                                                                    
    }                                                                             
    int i=pos;                                                                      
    int j=2*i+1;                                                                    
    Node tmp = arr[i];                                                               

    while(j <= sz)                                                                  
    {                                                                              
        if(j<sz && arr[j] > arr[j+1])                                                
        {                                                                          
            ++j;                                                                      
        }                                                                          
        if(tmp <= arr[j])                                                          
        {                                                                          
            break;                                                                   
        }                                                                          
        else                                                                       
        {                                                                          
            arr[i]=arr[j];                                                           
            i=j;                                                                     
            j=2*i+1;                                                                 
        }                                                                          
    }                                                                              
    arr[i]=tmp;                                                                    
}                                                                                  

void MinHeap_Sort(Node* arr,int n)                                                 
{                                                                                  
    for(int i=n/2-1;i>=0;--i)                                                        
    {                                                                                
        MinHeap_Sift(arr,i,n-1);                                                      
    }                                                                                

    // for(int j=n-1;j>=1;--j)                                                         
    //{                                                                                
    //    std::swap(arr[0],arr[j]);                                                     
    //   MinHeap_Sift(arr,0,j-1);                                                      
    //}                                                                                
}                                                                                  




int main()
{
    int K =5;
    List* list_one =new List();
    List* list_two =new List();
    List* list_three =new List();
    List* list_four =new List();
    List* list_five =new List();

    for(int i =0; i <5; i++) {
        list_one->push_back(i);
        list_two->push_back(i-3);
        list_three->push_back(2+i+5);
        list_four->push_back(1+2*i);
        list_five->push_back(3*i);
    }
    list_one->Print();
    list_two->Print();
    list_three->Print();
    list_four->Print();
    list_five->Print();
    
    Node* arr =new Node[K];
    arr[0] =*(list_one->first);
    arr[1] =*(list_two->first);
    arr[2] =*(list_three->first);
    arr[3] =*(list_four->first);
    arr[4] =*(list_five->first);

    cout<<"create min heap"<<endl;
    MinHeap_Sort(arr,K);
    for (int i=0; i<5; ++i) {
     cout<<arr[i].data<<"->";
    }
    cout<<endl;
    cout<<"create new List"<<endl;
    List *list = new List();
    while(K > 0) {
        list->push_back(arr[0].data);
        if(arr[0].next != NULL) {
            arr[0] = *(arr[0].next); 
        } else {
            arr[0] = arr[K-1];
            --K;
        }
        MinHeap_Sift(arr, 0, K-1);
    }
    list->Print();
    return 0;
}

