#include <iostream>
#include "array.h"

Array::Array(int size, int step) {
    initialSize = size > 0 ? size : 10;
    expandStep = step > 0 ? step : 5;
    arrayPtr = new int[initialSize];
    Idx = 0;
}

Array::~Array() {
    delete[] arrayPtr;
}

void Array::showElements() const {
    for (int i = 0; i < Idx; i++) {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) {
    int newSize = initialSize + size;
    int* newArray = new int[newSize];

    for (int i = 0; i < Idx; i++) {
        newArray[i] = arrayPtr[i];
    }
    delete[] arrayPtr;

    arrayPtr = newArray;

    initialSize = newSize;
}

int Array::getSize() const {
    return initialSize;
}

int Array::getElemSize() const {
    return Idx;
}

void Array::setValue(int val) {
    if (Idx >= initialSize) {
        expandArray(expandStep);
    }

    arrayPtr[Idx++] = val;
}

void Array::setArray(int* pArr, int size) {
    for (int i = 0; i < size; i++) {
        setValue(pArr[i]);
    }
}