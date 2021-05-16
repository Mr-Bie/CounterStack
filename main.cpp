#include <iostream>

class CounterStack{
public:
    CounterStack(){
        arr = new int[100];
        arrSize = 100;
    }
    CounterStack(int size){
        arr = new int[size];
        arrSize = size;
    }
    bool isFull(){
        return top == arrSize - 1;
    }
    bool isEmtpy(){
        return top == -1;
    }

private:
    int top = -1;
    int *arr;
    int arrSize;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
