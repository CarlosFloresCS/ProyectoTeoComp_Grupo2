#include "ForwardList.h"

int returntamanio(string producciones_[],int regla_){
    int tamanio_ = 0;
    for (int i = 0; i < regla_; i++)
    {
        tamanio_ = tamanio_+producciones_[i].size();
    }
    return tamanio_;
}


bool busqueda_elemento(string letra,ForwardList<string>* simb_term){ //<-
    for (int i = 0; i < simb_term->size(); i++)
    {
        if (letra==(*simb_term)[i]) return true;
    }
    return false;
}

void test_vacio(string producciones[], int reglas, string terminal, string variable_){
    ForwardList<string>* simbolos_terminales = new ForwardList<string>();
    for (int m = 0; m < terminal.length(); m++) 
    {
        simbolos_terminales->push_back(terminal.substr(m,1));
    }

    for (int l = 0; l < reglas; l++)
    {   
        for (int i = 0; i < reglas; i++)
        {
            string regla = producciones[i];
            string variable = regla.substr(0,1);
            int tamanio = returntamanio(producciones,reglas);

            string simbolo = regla.substr(2,tamanio-2);
            int check = 0;
            for (int k = 0; k < simbolo.length(); k++)
            {
                if (busqueda_elemento(simbolo.substr(k,1),simbolos_terminales)) check++; 
            }
            if (check==simbolo.length()) simbolos_terminales->push_back(variable); 
        }
    }
    //simbolos_terminales->display();
    bool salida=false;
    for (int i = 0; i < simbolos_terminales->size(); i++)
    {
        if ((*simbolos_terminales)[i]==producciones[0].substr(0,1)){ // variable inicial es la variable de la primera regla
            cout<<"NO"<<endl;
            simbolos_terminales->~ForwardList();
            salida = true;
            break;
        }
    }
    if (salida==false) cout<<"SI"<<endl;
    simbolos_terminales->~ForwardList();
}

    
