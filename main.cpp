#include <iostream>
#include <math.h>

using namespace std;

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
    void push(int num){
        if(isFull()) return;
        arr[++top] = num;
    }
    int pop(){
        if (isEmtpy()) return 0;
        string uniqNumbers;
        for (int i = 0; i < arrSize; ++i) {
            if (uniqNumbers.find(arr[i] + '0') == string::npos&&arr[i]!=0){
                uniqNumbers = uniqNumbers + to_string(arr[i]);
            }
        }
        const int uniqNumbersLenConst = uniqNumbers.length();
        string *arrTmp = new string[uniqNumbersLenConst];
        for (int i = 0; i < uniqNumbersLenConst; i++) {
            int numRepeat = 0;
            int index0UniqNumbers = stoi(uniqNumbers)/(pow(10,uniqNumbers.length()-1));
            uniqNumbers = uniqNumbers.substr(1,uniqNumbers.length()-1);
            for (int j = 0; j < arrSize; j++) {
                if (arr[j] == index0UniqNumbers) numRepeat++;
            }
            for (int j = 0; j < numRepeat; j++) {
                arrTmp[i] += to_string(index0UniqNumbers);
            }
        }
        int maxRepeat = 0;
        int maxRepeatNum;
        for (int i = 0; i < uniqNumbersLenConst; ++i) {
            if (arrTmp[i].length() > maxRepeat) {
                maxRepeat = arrTmp[i].length();
                maxRepeatNum = stoi(arrTmp[i].substr(0,1));
            }
            else if (arrTmp[i].length() == maxRepeat){
                for (int j = arrSize - 1; j > 0; j--) {
                    if (maxRepeatNum == arr[j]){
                        break;
                    }
                    if (stoi(arrTmp[i].substr(0,1)) == arr[j]){
                        maxRepeatNum = stoi(arrTmp[i].substr(0,1));
                        break;
                    }
                }
            }
        }
        for (int i = arrSize -1; i >= 0 ; i--) {
            if (maxRepeatNum == arr[i]){
                int pushedNum = arr[i];
                for (int j = i; j < top ; j++) {
                    arr[j] = arr[j+1];
                }
                top--;
                for (int j = top + 1; j < arrSize; ++j) {
                    arr[j] = 0;
                }
                cout<<"\n[ ";
                for (int f = 0; f < arrSize; f++) {
                    cout<<arr[f]<<"  ";
                }
                cout<<"]"<<endl;
                cout<<"Popped Number : ";
                return pushedNum;
            }
        }
return 0;
    }

private:
    int top = -1;
    int *arr;
    int arrSize;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    CounterStack stack(5);
    stack.push(1);
    stack.push(1);
    stack.push(2);
    stack.push(2);
    stack.push(1);
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    stack.push(5);
    stack.push(5);
    stack.push(5);
    stack.push(5);
    stack.push(2);
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    return 0;
}
