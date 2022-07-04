template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(){
        data = 0;
        next = nullptr;
    }

    Node(T value){
        data = value;
        next = nullptr;
    }

    void killSelf(){
        delete next;
    }
};
