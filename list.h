/*
 * linkedlist.h
 *
 *  Created on: 09/21/23
 *      Author: Sebastian Colin
 */

#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include "imagen.h"

using namespace std;

template <class T> class List;

template <class T> 
class Node {

    private: 
        Node(T);
        Node(T, Node<T>*);
        Node(const Node<T>&);

        T value;
        Node<T> *next;

        friend class List<T>;
        friend class Image;

};

template <class T>
Node<T>::Node(T val) : value(val), next(NULL) {}

template <class T>
Node<T>::Node(T val, Node<T> *nxt) : value(val), next(nxt) {}

template <class T>
Node<T>::Node(const Node<T> &other) {

    this->value = other.value;
    this->next = other.next;

}


template <class T>
class List : public Image {

    private:

        Node<T> *head;
        int size;
        //void swap(List<T>&, int, int);

    public: 

        List() : head(NULL), size(0) {}
		List(const List<T>&) ;
		~List();

        std::string toString() const;
        int getSize() {return size;};
        int getYear() {return year;};

        void insert(T); 
        int search (T) const; 
        T deleteAt (int); 
        T deleteFirst (int);
        void clear();

        void sort();

        bool operator<(const Node<T>*);
        bool operator<(const Node<T>&);
        bool operator>(const Node<T>*);
        bool operator>(const Node<T>&);
        bool operator==(const Node<T>*);
        bool operator==(const Node<T>&);
        
};

template <class T> 
List<T>::List(const List<T> &other) {
    this->head = other.head;
    this->size = other.size;
} 

template <class T>
List<T>::~List() {
	Node<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
void List<T>::clear() {
    Node<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}


template <class T>
std::string List<T>::toString() const {
    std::stringstream prnt;

    Node<T>* current = head;
    while (current != NULL) {
        prnt << current->value.toString();
        current = current->next;
    }

    return prnt.str();
}

template <class T>
void List<T>::insert(T val) {

    Node<T> *newNode;

    newNode = new Node<T> (val);
    if (newNode == 0) {
        cout << "Out of Memory";
    }

   newNode->next = head;
   head = newNode;
   size++;

}

template <class T>
int List<T>::search(T img) const {

    Node <T> *temp;

    temp = head;
    int pos = 0;
    while (temp != 0) {
        if (temp->value == img) {
            cout << temp->value.toString();
            return pos;
        }
        temp = temp->next;
        pos++;
    }

    return -1;

}

template <class T>
T List<T>::deleteFirst(int i) {
    T val;
    Node<T> *temp;

    if (head == NULL) {
        cout << "No such element";
    }

    temp = head; 
    head = temp->next;
    val = temp->value;

    delete temp;
    size--;

    return val;

}

template <class T>
T List<T>::deleteAt(int i) {
    Node<T> *temp = head;
    Node<T> *q;
    T val; int pos= 0;

    if (i == 0) {
        return deleteFirst(i);
    }

    while (pos != i) {
        q = temp;
        temp = temp->next;
        pos++;
    }

    q->next = temp->next;
    val = temp->value;

    delete temp;
    size--;

    return val;

}

template <class T>
void List<T>::sort() {
    if (head == NULL || head->next == NULL) {
        return; // Empty list or only one element
    }

    bool swapped;
    do {
        swapped = false;
        Node<T>* prev = NULL;
        Node<T>* current = head;
        Node<T>* next = head->next;

        while (next != NULL) {
            if (current->value > next->value) {
                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;
                swapped = true;
                current = next;
                next = current->next;
            }

            prev = current;
            current = next;
            if (next == NULL) 
                next = NULL;
            else 
                next = next->next;
        }
    } while (swapped);
}


template <class T>
bool List<T>::operator<(const Node<T> &other) {
    if  (this->year < other.year) {
        return true;
    } 
    if (this->year == other.year) {
        if (this->month < other.month) {
            return true;
        } else if (this->month == other.month) {
            if (this->day < other.day) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool List<T>::operator<(const Node<T> *other) {
    if (this->year < other->year) {
        return true;
    } 
    if (this->year == other->year) {
        if (this->month < other->month) {
            return true;
        } else if (this->month == other->month) {
            if (this->day < other->day) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool List<T>::operator>(const Node<T> &other) {
    if (this->year > other.year) {
        return true;
    } 
    if (this->year == other.year) {
        if (this->month > other.month) {
            return true;
        } else if (this->month == other.month) {
            if (this->day > other.day) {
                return true;
            }
        }
    }
    return false;

}

template <class T>
bool List<T>::operator>(const Node<T> *other) {
    if  (this->year > other->year) {
        return true;
    } 
    if (this->year == other->year) {
        if (this->month > other->month) {
            return true;
        } else if (this->month == other->month) {
            if (this->day > other->day) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool List<T>::operator==(const Node<T> *other) {
    if (this->year == other->year) {
        if (this->month == other->month) {
            if (this->day == other->day) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool List<T>::operator==(const Node<T> &other) {
    if (this->year == other.year) {
        if (this->month == other.month) {
            if (this->day == other.day) {
                return true;
            }
        }
    }
    return false;
}


#endif