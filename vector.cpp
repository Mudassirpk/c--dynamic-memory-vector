#include <iostream>
#include <memory>

using namespace std;

class Vector
{
public:
    Vector(int capacity);
    shared_ptr<int[]> o_array;
    int capacity;
    int size = 0;

    void push_back(int num);
    void push_front(int num);
    int operator[](int num);
    int pop();
    void print();
};

int Vector::operator[](int num)
{
    if ((num + 1) > size || (num < 0))
    {
        throw runtime_error("Out of range index accessed");
    }

    return *(this->o_array.get() + num);
}

Vector::Vector(int capacity)
{
    this->o_array = shared_ptr<int[]>(new int[capacity]);
    this->capacity = capacity;
};

void Vector::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << "position: " << i << " element: " << *(this->o_array.get() + i) << endl;
    }
};

void Vector::push_back(int num)
{
    *(this->o_array.get() + size) = num;
    this->size++;
}

void Vector::push_front(int num)
{
    if (this->size < this->capacity)
    {
        for (int i = size; i >= 1; i--)
        {
            *(this->o_array.get() + i) = *(this->o_array.get() + (i - 1));
        }
        *(this->o_array.get()) = num;
        size += 1;
    }
}

int Vector::pop()
{
    int num = *(this->o_array.get() + (size - 1));
    size -= 1;
    return num;
}

int main()
{
    Vector v1(10);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_front(1);
    cout << v1[0] << endl;
    return 0;
}