#include <iostream>
using namespace std;
template <typename T>
class LinkedList{   
    struct node{
        T data;
        node *next;
        node *prev;
    };
    node *head;
    node *tail;
    int size;
public:
    LinkedList();
    void insert(T data);
    void remove(T data);
    void print();
    int find(T data);
    T get(int index);

};


int main(){
    return 0;
}