#include <iostream>
#include <string.h>
#include <string>
using namespace std;


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

        cout << endl;
        cout << root.nameState;
        for (int i = 0; i < this->root.ts.size(); i++){
            cout << " -> " << this->root.nextStateArr[i].nameState;
        }
        cout << endl;

        for (int i = 0; i < this->root.ts.size(); i++){
            auto iterator = this->root.nextStateArr+i;
            while (true){
                if (iterator->nextState == nullptr){
                    cout << iterator->nameState << " -> X" << endl;
                    break;
                }
                cout << iterator->nameState << " -> " << iterator->nextState->nameState << endl;
                iterator = iterator->nextState;
            }
        }
        cout << endl;
    }

    pair<int*, int> statelist (int stateI, string vale);
    void substring(string s);
};