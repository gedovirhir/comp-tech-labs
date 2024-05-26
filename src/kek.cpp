#include <stdio.h>
#include <iostream>
#include <map>
#include <functional>
#include <string>


/*

 - просто int get_n {return n} возвращает значение, которое можно только скопировать
 - int& get_n {return n} возвращает ссылку на значение, которое можно принять в int и скопировать,
     либо в int& и принять объект по ссылке
 - int* get_n {retrun &n} возвращает указатель на объект в виде переменной-указателя

 [object
  
*/

using namespace std;

template <typename T, typename C>
class Interface {
public:
    // Method that accepts an instance of the same class
    void doSomethingWithSelf(const T& obj) {
        // Call a method on the provided object
        obj.someMethod();
    }

    // Pure virtual method, to be implemented by subclasses
    virtual void someMethod() = 0;
};

// Example implementation of the interface
template <typename T>
class MyClass : public Interface<MyClass<T>, T> {
public:
    int kekesh;

    MyClass(int kek) : kekesh(kek) {
        //_id();
    }
    
    void _id() {
        std::cout << this << std::endl;
    };

    int get_k() {
        return 123;
    }

    // Implement the pure virtual method
    void someMethod() override {
        // Define the behavior of the method
        // For example:
        std::cout << "Doing something in MyClass\n";
    }
};

MyClass<int> get_myclass() {
    MyClass<int> cock = MyClass<int>(1);
    
    return cock;
}

int kek2() {
    int k = 2;
    std::cout << &k << std::endl;
    return k;
};  

struct X {
    int cock;

    X(int c) : cock(c) { cout << "X()" << endl; }
    X(X const&) { cout << "X(X const&)" << endl; }
    X(X&&) = default;
    ~X() { 
        cout << "~X()" << endl;
    }
};


X keke2(X&& cock) {
    return cock;
}

template <typename T> T stub(T&& cock) {
    return cock;
}




template <typename T>
T(*keke)(T&& cock) = &stub;



int foox(const int& k) {
    return k;
}
template <typename T>
T pzd(const T& a) {
    return a;
}
template <typename T>
T pzd(T&& a) {
    return pzd<T>(a);
}

//int main() {
//    X new_k(1);
//
//    //int kke = pzd<int>(1);
//    X old_k = keke<X>(X(1));
//    //X copy_k = keke(new_k);
//
//
//    cout << "DEAD END" << endl;
//}