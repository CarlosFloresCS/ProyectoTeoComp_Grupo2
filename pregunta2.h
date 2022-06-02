#include "pregunta1.h"

template <typename T>
class queue{
    private:
        T* array;
        int capacity;
        int size;
        int rear, front;
    public:
        queue(int sz){
            size = 0;
            capacity = sz;
            array = new T[sz];
            front = rear = -1;
        }
        ~queue(){delete[] array;}
        int _size(){return size;}
        T _rear(){return array[rear];}
        T _front(){return array[front];}
        void resize(int &cap, int newcap){resize(array, capacity, capacity*2);}
        void push(T value){
            if (rear==capacity-1){
                this->resize(capacity, capacity*2);
            }
            if (front==-1){
                front = 0;
                rear = 0;
                array[rear] = value;
                size++;
            }
            else{
                rear++;
                array[rear] = value;
                size++;
            }
        }
        void pop(){
            for (int i = 0; i < size-1; i++){
                array[i] = array[i+1];
            }
            array[size-1] = 0;
            rear--;
            size--;
        }
        T* operator*(){return array;}
    private:
        void resize(T *array, int &cap, int newcap){
            T* new_array = new T[newcap];
            for (int i = 0; i < cap; i++){new_array[i] = array[i];}
            cap = newcap;
            array = new_array;
        }
};

pair<int*, int> AFN::statelist (int stateI, string value){
    int *retorno;
    int size;

    if(stateI == 1){
        int contSizereturn = 1;
        for (auto i : this->root.ts){
            if(value == string(1, i)){
                contSizereturn += 1;
            }
        }

        retorno = new int[contSizereturn];
        size = contSizereturn;
        retorno[0] = 1; contSizereturn = 1;

        for (int i = 0; i < this->root.ts.size(); i++){
            if(value == string(1, this->root.ts[i])){
                retorno[contSizereturn] = this->root.nextStateArr[i].nameState;
                contSizereturn += 1;
            }
        }
    }
    else{
        retorno = new int[1];
        size = 1;

        auto iter1 = this->root.nextStateArr;
        auto iter2 = this->root.nextStateArr;

        while (true){
            if(iter1->nameState==stateI){break;}
            iter1 = iter1->nextState;
            if(iter1->nextState == nullptr){
                iter2 = iter2+1;
                iter1 = iter2;
            }
        }
        
        if(value == iter1->t){
            retorno[0] = stateI+1;
            size = 1;
        }
        else{
            retorno[0] = 0;
            size = 1;
        }
    }

    return {retorno, size};
}

void AFN::substring(string s){
    int* finalStates = new int[this->root.ts.size()]; 
    for (int i = 0; i < this->root.ts.size(); i++){
        auto Iter = root.nextStateArr+i;
        while (true){
            if (Iter->nextState==nullptr){
                finalStates[i] = Iter->nameState;
                break;
            }
            Iter= Iter->nextState;
        }
    }
    
    queue<int> q((s.size())*2);
    queue<int> h((s.size())*2);

    bool loop=true;

    q.push(1);
    for (int i = 0; i < s.size(); i++){
        int size_q = q._size();
        for (int j = 0; j < size_q; j++){
            h.push(q._front());
            q.pop();
            pair<int*,int> states_s = statelist(h._front(),string(1,s[i]));
            for (int k = 0; k < states_s.second; k++){
                if (states_s.first[k] != 0){
                    q.push(states_s.first[k]);
                }
            }
            h.pop();
        }

        auto iter = *q;
        for (int l = 0; l < q._size(); l++){
            for (int m = 0; m < this->root.ts.size(); m++){
                if (*(iter+l) == finalStates[m]){
                    loop = false;
                    cout << "YES" << endl;
                    break;
                }
            }
            if (loop == false){break;}
        }
        if(loop == false) {break;}
        if (s.size()-1 == i){cout << "NO" << endl;}
    }
}