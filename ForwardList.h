#include "Node.h"
#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class ForwardList{
    private:
        Node<T>* head;
        int nodes;
    
    public:
        ~ForwardList(){
            this->clear();
        }

        T front(){
            if(!this->is_empty()){
                return this->head->data;
            } 
            else{
                cout<<"Lista vacia1"<<endl;
                exit(0);
            }
        }

        T back(){           
            if(!this->is_empty()){
                Node<T>* temp = this->head;
                for(int i = 0; i < this->nodes - 1; i++){
                    temp = temp->next;
                }
                return temp->data;
            } 
            else{
                cout<<"Lista vacia2"<<endl;
                exit(0);
            }

        }

        void push_front(T data){
            Node<T>* node = new Node<T>(data);
            node->data = data;
            node->next = this->head;
            this->head = node;
            nodes++;
        }

        void push_back(T data){
            Node<T>* node = new Node<T>(data);
            if (this->is_empty()) head=node;
            else{
                Node<T>* temp = this->head;
                for(int i = 0; i < this->size()-1; i++){
                    temp = temp->next;
                }
                temp->next = node;
            }
            nodes++;
        }

        T pop_front(){
            if (!this->is_empty()){
                Node<T>* temp = this->head;
                this->head = this->head->next;
                this->nodes--;
                T data = temp->data;
                delete temp;
                return data;
            }
            else{
                cout<<"Lista vacia4"<<endl;
                exit(0);
            }      
        }

        T pop_back(){
            if(!this->is_empty()){
                Node<T>* temp = this->head;
                for(int i = 0; i < this->nodes - 1; i++){
                    temp = temp->next;
                }
                T data = temp->data;
                delete temp;
                this->nodes--;
                return data;
            } 
            else{
                cout<<"Lista vacia5"<<endl;
                exit(0);
            }
        }

        T& operator[](int pos){
            if(!this->is_empty() && pos < this->size()){
                Node<T>* temp = this->head;
                for(int i = 0; i < pos; i++){
                    temp = temp->next;
                }
                return temp->data;
            } 
            else{
                cout<<"Lista vacia6"<<endl;
                exit(0);
            }
        }

        bool is_empty(){
            return this->head == nullptr;
        }

        int size(){
            return this->nodes;
        }

        void clear(){          
            if(!this->is_empty()){
                int iter = this->size();
                for(int i = 0; i < iter; i++){
                    Node<T>* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                    this->nodes--;
                }
            }        
        }

        void display(){
            Node<T>* temp = head;
            while (temp->next != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            };
            cout<<temp->data<<" "<<endl;
        }
};
