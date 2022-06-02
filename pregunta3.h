#include "pregunta2.h"

struct AFD{
    string Za;
    string ts;

    string **tableStates;

    AFD(string Za, int sz, string *arrT){
        this->Za = Za;

        for (int i = 0; i < sz; i++){
            for (int j = 0; j < arrT[i].size(); j++){
                bool verificador = true;

                for (int k = 0; k < ts.size(); k++){
                    if (arrT[i][j] == ts[k]){
                        verificador = false;
                        break;
                    }
                }

                if (verificador == true){ts += arrT[i][j];}
            }
        }
    }
};

/*AFD*/
void afntoafd(int sz, string *arrT, AFN &afn){
    int* finalStates = new int[afn.root.ts.size()]; 
    for (int i = 0; i < afn.root.ts.size(); i++){
        auto Iter = afn.root.nextStateArr+i;
        while (true){
            if (Iter->nextState==nullptr){
                finalStates[i] = Iter->nameState;
                break;
            }
            Iter= Iter->nextState;
        }
    }

    AFD retorno(afn.Za, sz, arrT);
    queue<string*> table(0);


    queue<string> StatesColumn(3);
    //3+retorno.ts.size();

    string *ifsts = new string[3+retorno.ts.size()];

    ifsts[0] = "y";
    ifsts[1] = "n";
    ifsts[2] = "1";
    for (int i = 0; i < retorno.ts.size(); i++){
        pair<int*, int> rellenartable = afn.statelist(1, string(1, retorno.ts[i]));
        string strtable = "";

        for (int j = 0; j < rellenartable.second; j++){
            strtable += to_string(rellenartable.first[j]);
        }

        ifsts[i+3] = strtable;

        auto iter = *StatesColumn;
        bool verificador = true;
        for (int k = 0; k < StatesColumn._size(); k++){
            if (iter[k]==strtable){
                verificador = false;
                break;
            }
        }
        if (verificador == true){
            StatesColumn.push(strtable);
        }
    }
    table.push(ifsts);

    queue<string> mainStatesColumn(3);
    mainStatesColumn.push("1");

    auto iterator = *StatesColumn;

    int range = StatesColumn._size();

    for (int r = 0; r < range ; r++){
        if(iterator[r] != "1"){mainStatesColumn.push(iterator[r]);}
    }

    while (StatesColumn._size() != 0){
        string *ifsts = new string[3+retorno.ts.size()];
        ifsts[0] = "n";
        ifsts[1] = "n";

        for (int x = 0; x < afn.root.ts.size(); x++){
            if(StatesColumn._front() == to_string(finalStates[x])){
                ifsts[1] = "y";
                break;
            }
        }

        int it = stoi(StatesColumn._front());
        
        for (int i = 0; i < retorno.ts.size(); i++){
            pair<int*, int> rellenartable = afn.statelist(it, string(1, retorno.ts[i]));
            string strtable = "";

            for (int j = 0; j < rellenartable.second; j++){
                strtable += to_string(rellenartable.first[j]);
            }

            ifsts[i+3] = strtable;
           
            auto iter = *mainStatesColumn;
            bool verificador = true;
            for (int k = 0; k < StatesColumn._size(); k++){
                if (iter[k]==strtable){
                    verificador = false;
                    break;
                }
            }
            if (verificador == true){
                StatesColumn.push(strtable);
                mainStatesColumn.push(strtable);
            }

            StatesColumn.pop();
        }
    }
}