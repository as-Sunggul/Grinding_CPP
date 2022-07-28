#include <bits/stdc++.h>
using namespace std;


template<typename T> class List{
    private:
        class _list{
            public:
            T value;
            _list* next;
        };

        _list* head = nullptr;
        long long int size = 0;

        void increment_size(){
            size++;
        }

        void head_null(){
            if(head == nullptr)return;
        }

        void index_out_of_bound(int pos){
            cout<<"Index out of bound ; "<<"size : "<<size<<" ; given index : "<<pos<<"\n";
            return;
        }
    public:
    void add_first(T val){
        _list* temp = new _list;
        temp->value = val;
        temp->next = this->head;
        this->head = temp;

        increment_size();
    }

    void add_last(T val){
        _list* temp = new _list;
        temp->value = val;
        temp->next = nullptr;

        if(this->head == nullptr){
            this->head = temp;
        }else{
            _list* traverse = this->head;
            while(traverse->next != nullptr){
                traverse = traverse->next;
            }
            traverse->next = temp;
        }

        increment_size();
    }

    void add_nth(int pos, T val){
        if(head == nullptr or pos == 0){
            add_first(val);
        }else{
            _list* temp = new _list;
            temp->value = val;
            temp->next = nullptr;

            if(pos >= size or pos < 0)index_out_of_bound(pos);
             _list* traverse = head;
            for(int i = 0; i < pos-1; i++){
                traverse = traverse->next;
            }
            _list* target = traverse->next;
            traverse->next = temp;
            temp->next = target;
                

        }

        increment_size();
    }

    void delete_end(){
        _list* traverse = this->head;
        head_null();
        
        while(traverse->next->next != nullptr){
            traverse = traverse->next;
        }
        delete traverse->next;
        traverse->next = nullptr;
    }

    void delete_begin(){
        head_null();

        _list* temp_head = this->head;
        this->head = this->head->next;
        delete temp_head;
    }

    void delete_nth(int pos){
        head_null();
        if(pos == 0)delete_begin();
        else{
            if(pos >= size or pos < 0)index_out_of_bound(pos);
            _list* traverse = head;
            for(int i = 0; i < pos-1; i++){
                traverse = traverse->next;
            }
            _list* target = traverse->next;
            _list* next = target->next;
            traverse->next = next;
            delete target;
        }
    }

    void reverse(){
        head_null();

        _list* current = head;
        _list* prev = nullptr;
        _list* next = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void show(){
        _list* traverse = this->head;
        while(traverse != nullptr){
            std::cout<<traverse->value;
            if(traverse->next != nullptr)cout<<" -> ";
            traverse = traverse->next;
        }
        cout<<"\n";
    }

};


int main(){
    /* -- sample usage --

    List<int> linked_list;
    for(int i = 0; i < 10; i++){
        linked_list.add_first(i);
    }
    linked_list.show();
    linked_list.add_nth(100, 20);
    linked_list.show();
    
    */
}
