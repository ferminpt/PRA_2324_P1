#ifndef LIST_H
#define LIST_H

#include <stdexcept> 

template <typename T>
class List {
private:
    T* elementos;  
    int capacidad;
    int longitud; 

    void resize(int nuevaCapacidad) {
        T* nuevosElementos = new T[nuevaCapacidad];
        for (int i = 0; i < longitud; i++) {
            nuevosElementos[i] = elementos[i];
        }
        delete[] elementos;
        elementos = nuevosElementos;
        capacidad = nuevaCapacidad;
    }

public:
    // Constructor
    List() {
        capacidad = 50;
        elementos = new T[capacidad];
        longitud = 0;
    }

    // Destructor
    ~List() {
        delete[] elementos;
    }

    // Devuelve el número de elementos en la lista
    int size() {
        return longitud;
    }

    // Inserta un elemento en una posición específica
    void insert(int pos, T e) {
        if (pos < 0 || pos > size()) {
            throw std::out_of_range("La posición no es correcta");
        }
        if (longitud == capacidad) {
            resize(capacidad * 2); // Duplicamos la capacidad si es necesario
        }

        // Mover los elementos para hacer espacio
        for (int i = longitud; i > pos; i--) {
            elementos[i] = elementos[i - 1];
        }
        elementos[pos] = e;
        longitud++;
    }

  
    void append(T e) {
        insert(size(), e);
    }

    // Inserta un elemento al principio de la lista
    void prepend(T e) {
        insert(0, e);
    }

    T remove(int pos) {
        if (pos < 0 || pos >= size()) {
            throw std::out_of_range("La posición no es correcta");
        }
        T elementoEliminado = elementos[pos];

        for (int i = pos; i < longitud - 1; i++) {
            elementos[i] = elementos[i + 1];
        }
        longitud--;
        return elementoEliminado;
    }

    // Devuelve el elemento en una posición específica
    T get(int pos) {
        if (pos < 0 || pos >= size()) {
            throw std::out_of_range("La posición no es correcta");
        }
        return elementos[pos];
    }

    // Busca el elemento e y devuelve su posición, o -1 si no se encuentra
    int search(T e) {
        for (int i = 0; i < longitud; i++) {
            if (elementos[i] == e) {
                return i;
            }
        }
        return -1; // Elemento no encontrado
    }

    // Devuelve true si la lista está vacía
    bool empty() {
        return longitud == 0;
    }
};

#endif




