#include <bits/stdc++.h>
using namespace std;
class DoubleLL{
    public:
     int data;
     DoubleLL *next,*prev;

     DoubleLL(){
         data=-1;
         next = prev = NULL;
     }
     DoubleLL(int x){
         data = x;
         next = prev = NULL;
     }
     
};
class Deque{
    DoubleLL *front,*rear;
    public:
      void insertfront(int val){
         DoubleLL* temp = new DoubleLL(val);
         if(!front){
             front = rear = temp;
         }else{
             front->prev = temp;
             temp->next = front;
             front = temp;
         }
      }
      void insertend(int val){
        DoubleLL* temp = new DoubleLL(val);
        if(!rear){
            rear = front = temp;
        }else{
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
      }
      int deletefront(){
         if(!front)
          return -1;
         else{
             int val = front->data;
             DoubleLL *temp = front;
             front = front->prev;
             delete(temp);
             return val;
         } 
      }
      int deleteend(int val){
         if(!rear){
             return -1;
         }else{
             int val = rear->data;
             DoubleLL *temp = rear;
             rear = rear->prev;
             delete(temp);
             return val;
         }
      }    
};
int main(){
    
}