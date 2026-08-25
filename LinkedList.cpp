#include <iostream>

using namespace std;

template <typename data_type>
struct LinkedListNode{
    data_type value;
    LinkedListNode<data_type>* next;

    LinkedListNode (){
        next = nullptr;
    }

    LinkedListNode(data_type v) : value(v) {
        next = nullptr;
    }
    LinkedListNode(data_type v, LinkedListNode<data_type>* n) : value(v), next(n){
    }
};

template <typename data_type>
struct LinkedList{
    LinkedListNode<data_type>* head;
    LinkedListNode<data_type>* tail;
    LinkedList(){
        head = tail = nullptr;
    }

    void push_front(data_type value){
        LinkedListNode<data_type>* new_node = new LinkedListNode<data_type>(value, head);
        if(head == nullptr){
            tail = new_node;
        }
        head = new_node;
    }
    void push_back(data_type value){
        if(tail == nullptr){
            head = tail = new LinkedListNode<data_type>(value);
        }
        else{
            tail -> next = new LinkedListNode<data_type>(value);
            tail = tail ->next;
        }
    }

    void insert(int k, data_type value){
        if(k == 0) push_front(value);
        else{
            LinkedListNode<data_type>* current = head;
            for(int i = 1; i <=k-1; i++){
                current = current-> next;
            }
            insert(current, value);
        }
    }

    void insert(LinkedListNode<data_type>* node, data_type value){
        LinkedListNode<data_type>* new_node = new LinkedListNode<data_type>(value, node -> next);
        if(node == tail){
            tail = new_node;
        }
        node -> next = new_node;
    }

    void pop_front(){
        LinkedListNode<data_type>* current = head;
        head = head ->next;
        if(head==nullptr) tail = nullptr;
        delete current;
    }

    void erase(LinkedListNode<data_type>* node){
        if(node -> next){
            LinkedListNode<data_type>* current = node->next;
            if(node ->next == tail){
                tail = node;
            }
            node -> next = node -> next ->next;
            delete current;
        }
    }
    void erase(int k){
        if(k==0) pop_front();
        else{
            LinkedListNode<data_type>* current = head;
            for(int i = 1; i <=k-1;i++){
                current = current->next;
            }
            erase(current);
        }
    }

    void print(){
        LinkedListNode<data_type>* current = head;
        while(current){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList<int> L;

    L.insert(0, 1);
    L.insert(1, 2);
    L.insert(2, 3);
    L.push_front(4);
    L.push_back(5);
    L.print();
    L.pop_front();
    L.print();

    return 0;
}