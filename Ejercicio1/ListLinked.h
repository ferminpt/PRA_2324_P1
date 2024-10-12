
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













};

