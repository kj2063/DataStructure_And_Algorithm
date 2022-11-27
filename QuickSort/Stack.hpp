template <typename T>

class Stack {
    T *data;
    int top;

public:
    Stack(int stackSize): top{-1}, data{new T[stackSize]} {}

    ~Stack() {
        delete[] data;
        data = nullptr;
    }

    void push(T inputData) {
        data[top + 1] = inputData;
        top += 1;
    }

    T pop() {
        T result = data[top];
        top -= 1;
        return result;
    }

    T getTop() {
        return data[top];
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return size() == 0 ? true : false;
    }

    T* getData() {
        return data;
    }

};
