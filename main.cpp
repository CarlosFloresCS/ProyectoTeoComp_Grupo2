#include "pregunta2.h"

int main(){
    string alfabeto;
    int sizeT;
    int sizeS;

    cin>>alfabeto;
    cin>>sizeT;
    string *cadenasT = new  string[sizeT];
    for(int i = 0; i < sizeT; i++){
        cin>>cadenasT[i];
    }

    cin>>sizeS;
    string *cadenasS = new string[sizeS];
    for(int j = 0; j<sizeS; j++){
        cin>>cadenasS[j];
    }

    AFN afn(alfabeto,sizeT,cadenasT);
    for (int k = 0; k < sizeS; k++){
        afn.substring(cadenasS[k]);
    }
    return 0;
}