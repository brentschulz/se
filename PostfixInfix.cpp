#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
public:
    T data;
    Node<T> *next;
    explicit Node(T data, Node<T> *next = nullptr) : data(data), next(next){};
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() : top(nullptr){};

    void push(T data)
    {
        auto *temp = new Node<T>(data);
        temp->next = top;
        top = temp;
    }

    T pop()
    {
        if (top == nullptr)
        {
            return '1';
        }
        else
        {
            Node<T> *temp = top;
            top = top->next;
            temp->next = nullptr;
            T x = temp->data;
            delete temp;
            return x;
        }
    }

    bool isEmpty()
    {
        return top == nullptr ? true : false;
    }

    T getTop()
    {
        return top->data;
    }
};

int prec(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

float calculate(float a, float b, char x)
{
    float result = 0;
    if (x == '*')
        return a * b;
    else if (x == '/')
        return a / b;
    else if (x == '+')
        return a + b;
    else if (x == '-')
        return a - b;
    return 0;
}

int main()
{
    Stack<char> operatorStack;
    Stack<float> operandStack;
    float result = 0;
    string expression;
    cout << "Enter an expression :: ";
    getline(cin, expression);
    for (auto i : expression)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
        {
            cout << i;
            operandStack.push(i);
        }
        else
        {
            while (!operatorStack.isEmpty() && prec(i) <= prec(operatorStack.getTop()))
            {
                float a, b;
                a = operandStack.pop() - 48;
                b = operandStack.pop() - 48;
                float result1 = calculate(a, b, operatorStack.getTop());
                operandStack.push(result1 + 48);
                cout << operatorStack.getTop();
                operatorStack.pop();
            }
            operatorStack.push(i);
        }
    }
    while (!operatorStack.isEmpty())
    {
        float a, b;
        b = operandStack.pop() - 48;
        a = operandStack.pop() - 48;
        float result1 = calculate(a, b, operatorStack.getTop());
        operandStack.push(result1 + 48);
        cout << operatorStack.getTop();
        operatorStack.pop();
    }
    cout << "\nEvaluation is :: " << operandStack.pop() - 48;
    return 0;
}