/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月28日 星期二 23时49分23秒
 ************************************************************************/

#include <iostream>

#include "stack.hpp"

using namespace std;

int main() {
    my_stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    while (!stack.empty()) {
        int ret = stack.top();
        std::cout << ret << std::endl;
        stack.pop();
    }

    my_stack<std::string> stack_2;
    stack_2.push("hello");
    stack_2.push("work");
    stack_2.push("test");
    while (!stack_2.empty()) {
        std::string ret = stack_2.top();
        std::cout << ret << std::endl;
        stack_2.pop();
    }

    return 0;
}
