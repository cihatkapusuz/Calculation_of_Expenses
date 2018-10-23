#include "SurveyClass.h"

SurveyClass::SurveyClass(){
    members=new LinkedList();
}
SurveyClass::SurveyClass(const SurveyClass& other){
    if(other.members) {
        this->members = new LinkedList(*(other.members));
    }
}
SurveyClass& SurveyClass:: operator=(const SurveyClass& list){
    if(list.members) {
        delete this->members;
        this->members = new LinkedList(*(list.members));
    }
    return *this;
}
SurveyClass::SurveyClass(SurveyClass&& other){
    this->members = move(other.members);
    other.members=NULL;
}
SurveyClass& SurveyClass:: operator=(SurveyClass&& list){
    this->members = move(list.members);
    list.members=NULL;
    return *this;
}
SurveyClass::~SurveyClass(){
    if(members){
        delete members;
    }
}

// Adds a new Node to the linked list or updates the corresponding Node in the linked list
void SurveyClass :: handleNewRecord(string _name, float _amount){
    Node* p = members->head;
    while(p && p->name!=_name){
        p = p->next;
    }
    if(p){
        members->updateNode(_name, _amount);
    }
    else{
        members->pushTail(_name, _amount);
    }
}
// Calculates and returns the minimum amount of expense.
// The minimum amount can have up to two decimal points.
float SurveyClass :: calculateMinimumExpense(){
    float min = members->head->amount;
    Node* p = members->head;
    if(p) {
        while (p){
            if(min > p->amount) {
                min = p->amount;
            }
            p=p->next;
        }
    }
    return min;
}
// Calculates and returns the maximum amount of expense.
// The maximum amount can have up to two decimal points.
float SurveyClass :: calculateMaximumExpense(){
    float max=members->head->amount;
    Node* p = members->head;
    while (p){
        if(max < p->amount){
            max=p->amount;
        }
        p=p->next;
    }
    return max;
}
// Calculates and returns the average amount of expense.
// The average amount can have up to two decimal points.
float SurveyClass :: calculateAverageExpense(){
    int count=0;
    float overall=0;
    Node* p = members->head;
    while(p) {
        overall += p->amount;
        count++;
        p=p->next;
    }
    int temp = (int)((overall/count)*100);
    return ((float) temp) / 100;
}

