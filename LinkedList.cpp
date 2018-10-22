#include "LinkedList.h"

    int length;
    // pointer to the first element of LinkedList
    Node *head = 0;
    // pointer to the last element of LinkedList
    Node *tail = 0;
LinkedList::LinkedList() {
    length=0;
    head= NULL;
    tail=NULL;
}

LinkedList:: LinkedList(const LinkedList& list){
    this->length = list.length;
    if(list.head) {
        this->head = new Node(*(list.head));
    }
    if(list.tail) {
        this->tail = new Node(*(list.tail));
    }
}

LinkedList& LinkedList::operator=(const LinkedList& list){

    this->length = list.length;
    if(list.head) {
        delete this->head;
        this->head = new Node(*(list.head));
    }
    if(list.tail) {
        delete this->tail;
        this->tail = new Node(*(list.tail));
    }
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
        while (p){
            p=p->next;
        }
        p->next = new Node(_name, _amount);
        p->next = tail;
    }
    else{
        head = new Node(_name, _amount);
        head = tail;
    }
}

// update an existing element
void LinkedList:: updateNode(string _name, float _amount){
    Node *p= head;
    while(p && p->name != _name){
        p= p->next;
    }
    p->amount=_amount;

};


LinkedList::~LinkedList(){
    if (head) {
        delete head;
    }
    if (tail) {
        delete tail;
    }
}



