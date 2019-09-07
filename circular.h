#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"


template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            if(this->nodes){
                return (this->head)->data;
            }
        throw out_of_range("No head");
        }

        T back() {
            if(this->nodes){
                return (this->tail)->data;
            }
        throw out_of_range("No head");
        }

        void push_front(T value) {
            Node<T>* temp=new Node<T>;
            this->tail->next=temp;
            temp->data=value;
            if(this->head==nullptr){
                temp->next=this->tail;
                this->head=temp;
                this->tail=this->head;
            }
            else{
                this->head->prev=temp;
                temp->next=this->head;
                this->head=temp;
            }
            this->nodes++;
        }

        void push_back(T value) {
            Node<T>* temp=new Node<T>;
            temp->data=value;
            if(this->head==nullptr){
                temp->next=temp;
                temp->prev=temp;
                this->head=temp;
                this->tail=temp;
            }
            else{
                temp->prev=this->tail;
                this->tail->next=temp;
                this->tail=temp;
            }
            this->nodes++;
            temp=this->head;
            
        }

        void pop_front() {
            if(this->nodes!=0){
                Node<T>* temp=this->head;
                this->head=this->head->next;
                this->head->prev=this->tail;
                delete temp;
                this->nodes--;
            }
        }

        void pop_back() {
            if(this->nodes!=0){
                Node<T>* temp=this->tail;
                temp=temp->prev;
                temp->next=this->head;
                this->head->prev=temp;
                delete this->tail;
                this->tail=temp;
                this->nodes--;
            }
            
        }

        T operator[](int index) {
            index=index%this->nodes;
            Node<T>* temp=nullptr;
            if(index>=(this->nodes)/2){
                index=this->nodes-1-index;
                temp=this->tail;
                while(index--)
                temp=temp->prev;
                return temp->data;
            }
            temp=this->head;
            while(index--)
            temp=temp->next;
            return temp->data;    
            throw out_of_range("Index out of range");
        }

        bool empty() {
            return (this->nodes==0);
        }

        int size() {
            return (this->nodes);
        }

        void clear() {
            this->head->killSelf();
            this->nodes=0;
        }

        void sort() {
            Node<T>* tempnode= this->head;
            Node<T>* temp= new Node<T>[this->nodes];

            for(int i=0;i<(this->nodes);i++){
                temp[i]=*tempnode;
                tempnode=tempnode->next;
            }
            MergeSort(temp,this->nodes);
            for(int i=0;i<this->nodes;i++){
                this->push_back(temp[i].data);
                this->pop_front();
            }
        }
    
        void reverse() {
            Node<T>* tempnode= this->head;
            Node<T>* temp= new Node<T>[this->nodes];

            
            for(int i=0;i<(this->nodes);i++){
                temp[i]=*tempnode;
                tempnode=tempnode->next;
            }

            for(int i=0;i<this->nodes;i++){
                this->push_front(temp[i].data);
                this->pop_back();
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(CircularLinkedList<T> list) {
            for(int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }
        }
};

#endif