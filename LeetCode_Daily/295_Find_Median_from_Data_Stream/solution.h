#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (front.empty()) {
            front.push(num);
        } else if (front.size() == back.size()) {
            if (num < back.top()) {
                front.push(num);
            } else {
                front.push(back.top());
                back.pop();
                back.push(num);
            }
        } else {
            if (num > front.top()) {
                back.push(num);
            } else {
                back.push(front.top());
                front.pop();
                front.push(num);
            }
        }
    }
    
    double findMedian() {
        if(front.empty()) return 0;

        if (front.size() == back.size()) {
            return (front.top() + back.top()) / 2.0;
        } else {
            return front.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */