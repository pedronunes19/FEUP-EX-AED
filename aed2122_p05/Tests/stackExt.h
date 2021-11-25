# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T> 
bool StackExt<T>::empty() const {
	return values.empty();
}

template <class T> 
T& StackExt<T>::top() {
    return values.top();
}

template <class T> 
void StackExt<T>::pop() {
    if (minimums.top() == values.top())
        minimums.pop();
    values.pop();
}

template <class T> 
void StackExt<T>::push(const T& val) {
    if (values.empty())
        minimums.push(val);
    else {
        if (minimums.top() >= val)
            minimums.push(val);
    }
    values.push(val);
}

template <class T> 
T& StackExt<T>::findMin() {
    return minimums.top();
}

