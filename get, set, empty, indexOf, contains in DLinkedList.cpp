template<class T>
T DLinkedList<T>::get(int index) {
     if(index < 0 && index >= count) throw out_of_range("");
    Node* tmp = head;
    while(index){ 
        tmp = tmp->next;
        index --;
    }
    return tmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    if(index < 0 && index >= count) throw out_of_range("");
    Node* tmp = head;
    while(index){
        tmp = tmp->next;
        index --;
    }
    tmp->data = e;  
}

template<class T>
bool DLinkedList<T>::empty() {
    return count == 0;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    Node* tmp = head;
    int index = 0;
    while(tmp){
        if(tmp->data == item) return index;
        tmp = tmp->next;
        index ++;
    }
    return -1;
    
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
  
    Node* tmp = head;
    while(tmp){
        if(tmp->data == item) return true;
        tmp = tmp->next;
    }
    return false;
    
}
