#include <iostream>
using namespace std;

template <typename T>
class QueueArray{ 
    private:
        T* array;
        int capacity;
        int back,front;
    public:
        QueueArray(){
            QueueArray(0);
        };

        QueueArray(int _capacity){
            this->array = new T[_capacity];
            this->capacity = _capacity;
            this->front = this->back = -1;
        };

        ~QueueArray(){
            delete[] array;
        };

        int prev(int index){
            return (index == 0) ? capacity - 1 : index - 1;
        };

        int next(int index){
            return (index + 1) % capacity;
        };

        bool is_empty(){
            if(this->front == -1 && this->back == -1){
                return true; 
            }
            return false; 
        };

        bool is_full(){
            if (this->back +1 == this->front) return true;
            return false;
        }

        int stack_size(){
            if (this -> back == -1 || this -> front == -1) return 0;  
            int resultado = this->back - this->front; 
            if(this->back < this->front){
                resultado = capacity - front + back; 
            }
            if (resultado < 0) resultado = resultado * -1; 
            resultado++; 
            return resultado; 
        };

        void push(T data){
            if(is_full()) {
                cout << endl <<"Its full" << endl;
            } else {
            
            if(is_empty()) 
                this->front = this->back = 0; 
            else 
                this -> back = next(back);
            this -> array[back] = data; 
            }
        };

        void emplace(T data, int pos){
            string result = ""; 
            int temp = this->front;
            int i = 0; 
            if(back != -1 && front != -1){
                while (true){
                    if (temp == this->capacity) temp = 0;  
                    if(i == pos) {
                        *(array + temp ) = data; 
                        break; 
                    }
                    if(temp == this->back) break; 
                    temp++; 
                    i++; 
                }
            }  
        };

        void pop(){
            if(is_empty()) {
                cout << "Its empty";
            } else {
            //this -> back = prev(back); //pop_back
            this -> front = next(front); // pop_front
            }
        };

        void display(){
            for (int i = front; i <= back; i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<endl;
        } 
    
};