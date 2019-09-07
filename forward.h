#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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
            temp->data=value;
            if(this->head==nullptr){
                this->head=temp;
                this->tail=this->head;
            }
            else{
                temp->next=this->head;
                this->head=temp;
            }
            this->nodes++;
        }

        void push_back(T value) {
            Node<T>* temp=new Node<T>;
            temp->data=value;
            if(this->head==nullptr){
                this->head=temp;
                this->tail=this->head;
            }
            else{
                this->tail->next=temp;
                this->tail=temp;
            }
            this->nodes++;
        }

        void pop_front() {
            if(this->nodes!=0){
                Node<T>* temp=this->head;
                this->head=this->head->next;
                delete temp;
                this->nodes--;
            }
        }

        void pop_back() {
            if(this->nodes!=0){
                Node<T>* temp=this->head;
                while(temp->next!=this->tail){
                    temp=temp->next;
                }
                delete this->tail;
                this->tail=temp;
                this->nodes--;
            }
            
        }

        T operator[](int index) {
            if (index<this->nodes){
                Node<T>* temp=this->head;
                while(index--)
                    temp=temp->next;
                return temp->data;
            }
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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // TODO
        }

        ForwardIterator<T> end() {
            // TODO
        }

        void merge(ForwardList<T> list) {
            for(int i=0;i<list.nodes;i++){
                this->push_back(list[i]);
            }
        }
};

#endif