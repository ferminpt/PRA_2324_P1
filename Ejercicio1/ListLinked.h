
#include"Node.h"
#include<ostream>
#include <stdexcept>

template <typename T>

class ListLinked{
private:
	Node<T>* first;
	int n;
public:
	ListLinked(){
	first=nullptr;
	n=0;
}

~ListLinked(){
 while (first != nullptr) {
 Node<T>* aux = first->next;	   
 delete first;              
 first = aux;             
	 }
}
T operator[](int pos){
if(pos <0 || pos > n){
	throw std::out_of_range("Fuera de rango");
}

Node<T>* aux = first;
for(int i =0; i <pos; i++){
	aux= aux -> next;
	}
	return aux-> data;
}

friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* aux = list.first;
        out << "[";
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) {
                out << ", ";
            }
            aux = aux->next;
        }
        out << "]";
        return out;
    }

 // Implementación de métodos de la interfaz List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Node<T>* newNode = new Node<T>(e);
        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
        n++;
    }

    void append(T e) override {
        Node<T>* newNode = new Node<T>(e);
        if (first == nullptr) {
            first = newNode;
        } else {
            Node<T>* aux = first;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
        n++;
    }

    void prepend(T e) override {
        Node<T>* newNode = new Node<T>(e);
        newNode->next = first;
        first = newNode;
        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Node<T>* toDelete;
        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->next;
            }
            toDelete = aux->next;
            aux->next = toDelete->next;
        }
        T data = toDelete->data;
        delete toDelete;
        n--;
        return data;
    }

    T get(int pos) override {
        return operator[](pos);
    }

    int search(T e) override {
        Node<T>* aux = first;
        for (int i = 0; i < n; ++i) {
            if (aux->data == e) {
                return i;
            }
            aux = aux->next;
        }
        return -1; // No encontrado
    }

    bool empty() override {
        return n == 0;
    }

    int size() override { 
        return n;
    }











};

