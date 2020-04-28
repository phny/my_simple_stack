#include <iostream>
#include <stdexcept>

// my_stack的前置声明
template<typename T> class my_stack;

// 链表节点模板类
template<typename T>
class list_node {
    T value;
    list_node* next;
    // 私有构造函数，只能由友元函数来构造
    list_node(T const& v, list_node* n): value(v), next(n) {}
    // 友元函数必须是类模板my_stack的实例
    friend class my_stack<T>;
};


template<typename T=int>
class my_stack {
    typedef list_node<T> node_type;
    node_type* head;

    // my_stack不可复制也不可构造
    my_stack operator=(my_stack const& ) {}
    my_stack(my_stack const& s) {}
public:
    // 构造与析构
    my_stack() : head(0) {}
    ~my_stack() {
        while(!empty()) {
            pop();
        }
    }

    // 在类模板中实现成员函数
    bool empty() const {
        return head == 0;
    }

    T const& top() const throw (std::runtime_error) {
        if (empty()) {
            throw std::runtime_error("stack is empty");
        }
        return head->value;
    }

    void push(T const& v) {
        head = new node_type(v, head);
    }

    void pop();
};

// 在模板类外面实现类的成员函数
template<typename T>
void my_stack<T>::pop() {
    if (head) {
        node_type* tmp = head;
        head = head->next;
        delete tmp;
    }
}




