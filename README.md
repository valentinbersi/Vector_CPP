# Vector
 My implementation of an ADT Vector in C++.

 Manual:

 - add(new_element): adds new_element to the end of the vector

 - add(new_element, index): adds new_element before the element at the given index, moving all the following elements. If the index is equal to the size of the vector, it just adds it to the end.

 - remove(): removes the last element and returns it.

 - remove(index): removes the element at the given index, moving all the following elements. If the index is equal to the size of the vector - 1, it just removes the last element

 - empty(): returns true if the vector is empty.

 - size(): returns the number of elements in the vector.

 - operator[index]: returns a reference of the element at the given index.

The vector uses a resize factor of 2, this means that when the number of elements reaches the capacity, it duplicates its size. Also, when the number of elements is half the capacity, it shrinks in half.
