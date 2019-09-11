#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            this->current=other->current;
            return(*this);
        }

        bool operator!=(ForwardIterator<T> other) {
            return(this->current!=this->current->next);
        }

        ForwardIterator<T> operator++() {
            if(this->current->next!=nullptr){
                this->current=this->current->next;
                return(*this);
            }
            else
            {
                throw out_of_range("Out of range");
            }
        }
        T operator*() {
            return(this->current->data);
        }
};

#endif