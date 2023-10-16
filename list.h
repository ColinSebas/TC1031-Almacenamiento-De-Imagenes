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
class List {

    private:

        int year;
        Node<T> *head;
        int size;
        void swap(List<T>&, int, int);

    public: 

        List();
		List(const List<T>&) ;
        List(int);
		~List();

        bool empty () const;
        std::string toString() const;
        void clear();
        void insertFirst(T);
        int getSize() {return size;};
        int getYear() {return year;};

        //HW
        void insertion(T); T search (int) const; 
        bool searchBool(int) const;
        bool update (unsigned int, T);
        T deleteAt (int); T deleteFirst (int);

        List<T> bubbleSort(const List<T>&);

        bool operator<(const List<T>*);
        bool operator<(const List<T>&);
        bool operator>(const List<T>*);
        bool operator>(const List<T>&);
        
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T> 
List<T>::List(int yr) {
    year = yr;
    head = 0;
    size = 0; 
}

template <class T> 
List<T>::List(const List<T> &other) {
    this->head = other.head;
    this->size = other.size;
} 

template <class T>
List<T>::~List() {
	clear();
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

	std::stringstream aux;
	Node<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();

}

template <class T> 
bool List<T>::empty() const {
    return (head == 0);
}

template <class T>
void List<T>::insertFirst(T val)  {
	Node<T> *newNode;

	newNode = new Node<T>(val);
	if (newNode == 0) {
		cout << "Out of memory";
	}
	newNode->next = head;
	head = newNode;
	size++;

}

template <class T>
void List<T>::insertion (T val) {

    Node<T> *newNode, *temp;

    newNode = new Node<T> (val);
    if (newNode == 0) {
        cout << "Out of Memory";
    }

    //Add empty list condition
    if (empty()) {
        insertFirst(val);
        return;
    }

    temp = head;
    while (temp->next != 0) {
        temp = temp->next;
    }

    newNode->next = 0;
    temp->next = newNode;
    size++;

}

template <class T>
T List<T>::search(int val) const {

    Node <T> *temp;

    temp = head;
    int pos = 0;
    while (temp != 0) {
        if (temp->value == val) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }

    return -1;

}
template <class T>
bool List<T>::searchBool(int val) const {
    Node <T> *temp;

    temp = head;
    int pos = 0;
    while (temp != 0) {
        if (temp->value == val) {
            return true;
        }
        temp = temp->next;
        pos++;
    }

    return false;
}

template <class T>
bool List<T>::update(unsigned int i, T val) {

    int pos = 0;
    Node <T> *temp = head;

    if (i > size) {
        return false;
    }

    while (pos != i) {
        temp = temp->next;
        pos++;
    }

    temp->value = val;
    return true;

}

template <class T>
T List<T>::deleteFirst(int i) {
    T val;
    Node<T> *temp;

    if (empty()) {
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

/*
template <class T>
void List<T>::swap(List<T> &V, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T>
List<T> List<T>::bubbleSort(const List<T> &source) {
	List<T> v(source);

	for (int i = v.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v, j, j + 1);
			}
		}
	}
	return v;
}

*/


template <class T>
bool List<T>::operator< (const List<T> &other) {
    if (this->year < other.year) {
        return true;
    } else {return false;}
}

template <class T>
bool List<T>::operator< (const List<T> *other) {
    if (this->year < other->year) {
        return true;
    } else {return false;}
}

template <class T>
bool List<T>::operator> (const List<T> &other) {
    if (this->year > other.year) {
        return true;
    } else {return false;}
}

template <class T>
bool List<T>::operator> (const List<T> *other) {
    if (this->year > other->year) {
        return true;
    } else {return false;}
}

#endif