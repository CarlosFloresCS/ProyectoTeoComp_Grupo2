#include <iostream>
#include <string>
using namespace std;

// Rango del alfabeto: ( 33 ! ) - ( 126 ~ )

struct State{
    int s;
    string t; // con t se avanza al siguiente estado
    State *nextState; // puntero al siguiente estado

    State(){
        this->nextState = nullptr;
    }
};

struct StateInitial{
    int s = 1;
    string Z, ts; // Z es el abcdario, ts almacena los State::t para ir a los estados del array nextStateArr
    State *nextStateArr; // puntero a los siguientes estados
    int sz; // size

    StateInitial(){
        nextStateArr = new State[sz];
    }
};


struct AFN{
    string Za; // abcdario
    StateInitial root; // estado incial

    public:
        AFN(string Za, int sz, string *arrT){
            this->Za = Za;
            root.Z = Za;
            for (int i = 0; i < sz; i++){
                root.ts += arrT[i][0];
                
                auto *IterState = root.nextStateArr+i;

                for (int j = 0; j < (arrT[i].size()-1); j++){
                    IterState->t = arrT[i][j+1];

                    State *nxtS = new State;
                    IterState->nextState = nxtS;

                    IterState = IterState->nextState;
                }
            }
        }
};

int main(){
    string *arrString;
    arrString = new string[3];
    arrString[0] = "fernando";
    arrString[1] = "carlos";
    arrString[2] = "alexis";



    AFN prueba("abcdefghijklmnopqrstuvwxyz", 3, arrString);

    //cout << prueba.root.ts;

    cout << prueba.root.nextStateArr[0].nextState->nextState->nextState->t;
}