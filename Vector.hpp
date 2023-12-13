#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <exception>

class IndexException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Index out of bounds";
    }
};

class EmptyException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Vector is empty";
    }
};

template<class T>
class Vector {
private:
    T* data;
    size_t _size;
    size_t capacity;

    const size_t EMPTY = 0;
    const size_t INITIAL_CAPACITY = 1;
    const size_t RESIZE_FACTOR = 2;

    // Pre: ~
    // Pos: aumenta el tamaño de datos al tamanio maximo actual
    void resize();

public:
    // Constructor.
    Vector();

    // Pre: -
    // Post: adds new_element to the end of the vector.
    void add(T new_element);

    // Pre: index must be less or equal than the size of the vector.
    // Post: adds new_element before the element at the given index, moving all the following elements. If the index is equal to
    // the size of the vector, it just adds it to the end.
    void add(T new_element, size_t index);

    // Pre: vector can't be empty.
    // Post: removes the last element and returns it.
    T remove();

    // Pre: vector can´t be empty. Index must be less than the size of the vector.
    // Post: removes the element at the given index, moving all the following elements. If the index is equal to the
    // size of the vector - 1, it just removes the last element.
    T remove(size_t index);

    // Pre: -
    // Post: returns true if the vector is empty.
    [[nodiscard("ignoring empty() return")]] bool empty();

    // Pre: -
    // Post: returns the number of elements in the vector.
    [[nodiscard("ignoring size() return")]] size_t size();

    // Pre: vector can't be empty. Index must be less than the size of the vector.
    // Post: returns a reference of the element at the given index.
    [[nodiscard("ignoring [] operator return")]] T& operator[](size_t index);

    // Destructor.
    ~Vector();
};

template<class T>
void Vector<T>::resize() {
    T* data_aux = new T[capacity];

    for (size_t i = 0; i < size(); i++) {
        data_aux[i] = data[i];
    }

    delete[] data;

    data = data_aux;

    data_aux = nullptr;
}

template<class T>
Vector<T>::Vector() {
    _size = EMPTY;
    capacity = EMPTY;
    data = nullptr;
}

template<class T>
void Vector<T>::add(T new_element) {
    if (empty()) {
        capacity = INITIAL_CAPACITY;
        data = new T[capacity];
    }
    else if (size() == capacity) {
        capacity *= RESIZE_FACTOR;
        resize();
    }

    data[size()] = new_element;
    _size++;
}

template<class T>
void Vector<T>::add(T new_element, size_t index) {
    if (index > _size) throw IndexException();

    if (empty()) {
        capacity = INITIAL_CAPACITY;
        data = new T[capacity];
    }
    else if (size() == capacity) {
        capacity *= RESIZE_FACTOR;
        resize();
    }

    for (size_t i = index; i < size(); i++) {
        data[i + 1] = data[i];
    }

    data[index] = new_element;
    _size++;
}

template<class T>
T Vector<T>::remove() {
    if (empty()) throw EmptyException();

    T valor_eliminado = data[size() - 1];
    _size--;

    if (empty()) {
        capacity = EMPTY;
        delete[] data;
        data = nullptr;
    }
    else if (size() / RESIZE_FACTOR == capacity) {
        capacity /= RESIZE_FACTOR;
        resize();
    }

    return valor_eliminado;
}

template<class T>
T Vector<T>::remove(size_t index) {
    if (empty()) throw EmptyException();

    if (index >= size()) throw IndexException();

    T removed_element = data[index];

    for (size_t i = index; i < size() - 1; i++) {
        data[i] = data[i + 1];
    }
    _size--;

    if (empty()) {
        capacity = EMPTY;
        delete[] data;
        data = nullptr;
    }
    else if (size() / RESIZE_FACTOR == capacity) {
        capacity /= RESIZE_FACTOR;
        resize();
    }

    return removed_element;
}

template<class T>
bool Vector<T>::empty() {
    return size() == EMPTY;
}

template<class T>
size_t Vector<T>::size() {
    return _size;
}

template<class T>
T& Vector<T>::operator[](size_t index) {
    if (empty()) throw EmptyException();

    if (index >= size()) throw IndexException();

    return data[index];
}

template<class T>
Vector<T>::~Vector() {
    _size = EMPTY;
    capacity = EMPTY;
    delete[] data;
    data = nullptr;
}

#endif //VECTOR_HPP
