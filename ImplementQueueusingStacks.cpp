// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
// Implement the MyQueue class:
// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes: You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
#include<bits/stdc++.h>
#include<stack>
class MyQueue {

private:
        stack<int>stackenqueue;  //enqueue
        stack<int>stackdequeue;  //dequeue

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackenqueue.push(x);

    }
    
    int pop() {
        if(stackdequeue.empty())
        {
            while(!stackenqueue.empty())
            {
                stackdequeue.push(stackenqueue.top());
                stackenqueue.pop();
            }
        }
        
        if(!stackdequeue.empty())
        {
           int front = stackdequeue.top();
           stackdequeue.pop();
           return front;
        }
        else{
            return -1;
        }

        
    }
    
    int peek() {
        if(stackdequeue.empty())
        {
            while(!stackenqueue.empty())
            {
                stackdequeue.push(stackenqueue.top());
                stackenqueue.pop();
            }
        }
        if(!stackdequeue.empty())
        {
            return stackdequeue.top();
        }
        else{
            return -1;
        }
    }
    
    bool empty() {
        if(stackdequeue.empty() && stackenqueue.empty())
        return true;
        else
        return false;
    }
};

