#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#include<iostream>

using namespace std;

//Linked List Node
template<typename T>
class Node{
  public:
     T data;
     Node *link;
     Node(T element) {
         data = element;
         link = NULL;
     }
};
 //Linked list Class
template<typename T>
class LinkedList {
  protected:
     Node<T>*first;
     int current_size;
  public:
     LinkedList() {
        first = 0;
        current_size = 0;
     };
     int GetSize() { 
         return current_size; 
     }  //리스트의 노드 개수를 리턴
     void Insert(T element);
     virtual bool Delete(T &element);
     void Print(); //리스트를 출력
};

template<typename T>
void LinkedList<T>::Insert(T element) {
  Node<T> *newnode = new Node<T>(element);
  newnode->link = first;
  first = newnode;
  current_size++;
}

template<typename T>
bool LinkedList<T>::Delete(T &element) {
  if(first==0) 
     return false;
  Node<T> *current = first;
  Node<T> *previous = NULL;
  while(1) {
     if(current->link == 0) {//find end node
       if(previous)previous->link = current->link;
       else first = first->link;
       break;
     }
     previous = current;
     current = current->link;
  }
  element = current->data;
  delete current;
  
  current_size--;
  return true;
}

template<typename T>
void LinkedList<T>::Print() {
  int k = 1;
  Node<T>*cnode = first;
  if(current_size != 0) {
    for(cnode = first; cnode != NULL; cnode = cnode->link) {
       if(k == current_size) {
          cout<<"["<<k<<"|";
          cout<<cnode->data<<"]";
        }
        else {
          cout<<"["<<k<<"|";
          cout<<cnode->data<<"]->";
          k++;
        }
    }
    cout<<endl;
  }
}

#endif 
