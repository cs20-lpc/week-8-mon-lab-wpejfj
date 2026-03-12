#include <iostream>
#include <string>
#include "ArrayStack.hpp"

using namespace std;

template <typename T>
void testRotate(ArrayStack<T> &s) {
    cout << "rotate right\n" << s;
    s.rotate(Stack<T>::RIGHT);
    cout << "result\n" << s;
    s.rotate(Stack<T>::LEFT); 
}

int main() {
  
    ArrayStack<int> s(3);
    s.push(1); s.push(2); s.push(3);
    std::cout << "Int stack:\n" << s;
    std::cout << "peek: " << s.peek() << "\n";
    s.pop();
    std::cout << "After pop:\n" << s;

    try { ArrayStack<int> bad(0); }
    catch (const string& e) { std::cout << "Caught: " << e << "\n"; }
    try { s.push(9); s.push(9); s.push(9); }
    catch (const string& e) { std::cout << "Caught: " << e << "\n"; }

    ArrayStack<string> ss(2);
    ss.push("hello"); ss.push("world");
    std::cout << "\nString stack:\n" << ss;

    ArrayStack<int> a(5);
    a.push(10); a.push(20);
    ArrayStack<int> b(a);    
    b.push(30);
    std::cout << "\nOriginal a:\n" << a << "Copy b (+ 30):\n" << b;
    a = b;         
    std::cout << "a after assign from b:\n" << a;

    ArrayStack<double> d(3);
    d.push(1.1); d.push(2.2); d.push(3.3);
    std::cout << "\n";
    testRotate(d);

    return 0;
}
