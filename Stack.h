#include"LinkedList.h"

//Stack클래스를 LinkedList클래스에 상속시킨다
template<typename T>
class Stack: public LinkedList<T> {
  using LinkedList<T>:: first;
  using LinkedList<T>:: current_size;
  public:
    bool Delete (T &element);
};

//Delete 함수 재정의
template<typename T>
bool Stack<T>::Delete(T &element) {
         Node<T> *cnode;
         if(first == NULL) {
            return false;
         }
         cnode = first;
         first = first->link;
         delete cnode;
         current_size--;

         return true;
}
