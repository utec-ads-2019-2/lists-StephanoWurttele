#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
void MergeSort(Node<T>* elements, size_t size) {
            const auto ordenar = [&](const auto ordenar/*,Node<T>** elements*/, int inicio,int final, int centro)->int{
                int t1=centro-inicio+1;
                int t2=final-centro;
                Node<T> temp1[t1],temp2[t2];
                for(int i=0;i<t1;i++){
                    temp1[i]=elements[inicio+i];
                }
                for(int i=0;i<t2;i++)
                    temp2[i]=elements[centro+1+i];                
                int i=0,j=0,k=inicio;
                while(i<t1 && j<t2){ 
                    if (temp1[i].data <= temp2[j].data) {
                        elements[k] = temp1[i];
                        i++;
                    } 
                    else{
                        elements[k] = temp2[j]; 
                        j++; 
                    } 
                    k++; 
                } 
                while(i<t1){
                    elements[k] = temp1[i]; 
                    i++; 
                    k++; 
                } 
                while(j<t2){
                    elements[k] = temp2[j]; 
                    j++; 
                    k++; 
                } 
            };

            const auto merge = [&](const auto merge/*, Node<T>** elements*/, int inicio, int final)->int{
                int centro;
                if(inicio<final){
                    centro=(inicio+final)/2;
                    merge(merge/*,elements*/,inicio,centro);
                    merge(merge/*,elements*/, centro+1, final);
                    ordenar(ordenar/*,elements*/, inicio, final, centro);
                }
            };
            merge(merge/*,elements*/,0,size -1);
            }

template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        ~List() {
            head->killSelf();
            head->next=nullptr;
        }
};

#endif