#include <iostream>
#include <string>
using namespace std;

// Rango del alfabeto: ( 33 ! ) - ( 126 ~ )

// PREGUNTA 1

struct State{
    int nameState;
    string t;
    State *nextState;

    State(){
        this->nextState = nullptr;
    }
};

struct StateInitial{
    int nameState = 1;
    string Z, ts;
    State *nextStateArr;
    int sz;

    StateInitial(){
        nextStateArr = new State[sz];
    }
    ~StateInitial(){
        delete [] nextStateArr;
    }
};

struct AFN{
    string Za;
    StateInitial root;

    AFN(string Za, int sz, string *arrT){
        this->Za = Za;
        root.Z = Za;

        int namecont = 2;

        for (int i = 0; i < sz; i++){
            root.ts += arrT[i][0];
            
            auto IterState = root.nextStateArr+i;
            IterState->nameState = namecont; namecont += 1;

            for (int j = 0; j < (arrT[i].size()-1); j++){
                IterState->t = arrT[i][j+1];

                State *next = new State;
                IterState->nextState = next;

                IterState = IterState->nextState;
                IterState->nameState = namecont; namecont += 1;
            }
        }
    }

    pair<int*, int> statelist (int stateI, string vale);

    // int* state_state(int state, string v);
    // void substring(string s);
};



// PREGUNTA 2

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
        ~queue(){
            delete[] array;
        }
        T _rear(){
            return array[rear];
        }
        T _front(){
            array[front];
        }
        void resize(int &cap, int newcap){
            resize(array, capacity, capacity*2);
        }
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
        T* operator*(){
            return array;
        }
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
        for (int i = 0; i < this->root.ts.size(); i++){
            if(stateI == root.nextStateArr[i].nameState){
                retorno = new int[1];

                if(value == root.nextStateArr[i].t){
                    retorno[0] = stateI+1;
                    size = 1;
                }
                else{
                    retorno[0] = 0;
                    size = 1;
                }

                break;
            }

            else if(stateI < root.nextStateArr[i].nameState){
                retorno = new int[1];

                auto iter = this->root.nextStateArr+i-1;
                for (int j = 0; j < (stateI - iter->nameState); j++){
                    iter = iter->nextState;
                }

                if(value == iter->t){
                    retorno[0] = stateI+1;
                    size = 1;
                }
                else{
                    retorno[0] = 0;
                    size = 1;
                }

                break;
            }
        }
    }

    return {retorno, size};
}


int main(){
    string arrstr[] = {"aaa", "bbb"};
    string x = "abcde";



    string y ;
    y = arrstr[0][0];

    int size = 2;
    string *arrString;
    arrString = new string[size];
    arrString[0] = "web";
    arrString[1] = "ebay";

    AFN prueba("abcdefghijklmnopqrstuvwxyz", size, arrString);

    pair<int*, int> xd = prueba.statelist(1, "e");

    cout << xd.second << endl;
    
    for (int i = 0; i < xd.second; i++)
    {
        cout << xd.first[i];
    }
}