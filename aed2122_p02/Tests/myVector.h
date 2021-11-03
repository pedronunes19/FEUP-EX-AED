#include <iostream>
#include <vector>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------


template <class T>
T MyVector<T>::max() const {  // T: O(n)  S:O(1)
    if (values.size() == 0)
        throw(EmptyVector());
    T vmax = values.at(0);
    for (T value: values){
        if (value > vmax)
            vmax = value;
    }
    return vmax;
}


template<class T>  // T: O(n^2)  S: O(1)
bool MyVector<T>::hasDuplicates() const {
    for (int i= 0; i < values.size(); i++){
        for (int j = i + 1; j < values.size(); j++){
            if (values.at(i) == values.at(j))
                return true;
        }
    }
    return false;
}


template<class T>
void MyVector<T>::removeDuplicates() {  // T: O(n^2)  S: O(1)

    for (int i= 0; i < values.size(); i++){
        for (int j = i + 1; j < values.size(); j++){
            if (values.at(i) == values.at(j)){
                values.erase(values.begin() + j);
                j--;
            }
        }
    }
}

