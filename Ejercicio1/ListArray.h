
#include "List.h"
#include <stdexcept>
#include <ostream>

template <typename T>
class ListArray : public List<T> {
private:
    T* array;
    int max;
    int n;
    static const int MINISIZE = 10;  // Inicialización de MINISIZE

    void resize(int new_size) {
        T* newArray = new T[new_size];
        for (int i = 0; i < n; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        max = new_size;
    }

public:
    ListArray() {
        array = new T[MINISIZE];
        max = MINISIZE;
        n = 0;
    }

    ~ListArray() {
        delete[] array;
    }

   void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {  // Debe ser pos <= n, no max
            throw std::out_of_range("Posición fuera de rango");
        }

        if (n >= max) {
            resize(max * 2);
        }

        for (int i = n; i > pos; --i) {  // Cambié max por n
            array[i] = array[i - 1];
        }

        array[pos] = e;
        n++;
    }

    // Añadir al final
    void append(T e) override {
        insert(n, e);
    }

    // Añadir al principio
    void prepend(T e) override {
        insert(0, e);
    }

    // Eliminar un elemento
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {  // Cambié max por n
            throw std::out_of_range("Posición fuera de rango");
        }

        T removedValue = array[pos];
        for (int i = pos; i < n - 1; ++i) {
            array[i] = array[i + 1];
        }
        --n;

        if (n < max / 4 && max > MINISIZE) {
            resize(max / 2);
        }

        return removedValue;
    }

    // Obtener un elemento
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return array[pos];
    }

    // Buscar un elemento
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (array[i] == e) {
                return i;  // Retornar la posición si se encuentra
            }
        }
        return -1;
    }

    // Verificar si la lista está vacía
    bool empty() override {
        return n == 0;
    }

    // Retornar el tamaño de la lista
    int size() override {
        return n;
    }

    // Sobrecarga del operador [] para acceso no constante
    T& operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("La posición no es correcta");
        }
        return array[pos];
    }

    // Sobrecarga del operador [] para acceso constante
    const T& operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("La posición no es correcta");
        }
        return array[pos];
    }

    // Sobrecarga del operador << como función amiga
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.array[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};
