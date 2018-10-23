#include "LinkedList.h"

LinkedList::LinkedList() {
    length = 0;
    head = NULL;
    tail = NULL;
}

LinkedList:: LinkedList(const LinkedList& list){
    this->length = list.length;
    if(list.head) {
        this->head = new Node(*(list.head));
    }
    Node* p = head;
    while(p){
        p=p->next;
    }
    this->tail=p;
}

LinkedList& LinkedList::operator=(const LinkedList& list){
    this->length = list.length;
    if(list.head) {
        delete this->head;
        this->head = new Node(*(list.head));
    }
    Node* p = head;
    while(p){
        p=p->next;
    }
    this->tail=p;
    return *this;
}

LinkedList::LinkedList(LinkedList&& list){
    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    list.head = NULL;
    list.tail = NULL;

}

LinkedList& LinkedList::operator=(LinkedList&& list){
    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length = 0;
    list.head = NULL;
    list.tail = NULL;

    return *this;
}
// add a new element to the back of LinkedList
void LinkedList:: pushTail(string _name, float _amount){
    Node* p=head;
    if(p){
        while (p->next){
            p=p->next;
        }
        p->next = new Node(_name, _amount);
        tail = p->next;
    }
    else{
        head = new Node(_name, _amount);
        tail = head;
    }
    length=length+1;
}

// update an existing element
void LinkedList:: updateNode(string _name, float _amount){
    Node *p= head;
    while(p && p->name != _name){
        p= p->next;
    }
    if(p) {
        p->amount = _amount;
    }
}


LinkedList::~LinkedList(){
    if (head) {
        delete head;
    }
}


