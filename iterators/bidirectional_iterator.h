#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current=other->current;
            return(*this);
        }

        bool operator!=(BidirectionalIterator<T> other) {
            return(this->current!=this->current->next);
        }

        BidirectionalIterator<T> operator++() {
            if(this->current->next!=nullptr){
                this->current=this->current->next;
                return(*this);
            }
            else
            {
                throw out_of_range("Out of range");
            }
        }

        BidirectionalIterator<T> operator--() {
            if(this->current->prev!=nullptr){
                this->current=this->current->prev;
                return(*this);
            }
            else
            {
                throw out_of_range("Out of range");
            }
        }

        T operator*() {
            // Caso vacío?
            return(this->current->data);
        }
};

#endif