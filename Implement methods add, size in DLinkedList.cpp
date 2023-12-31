template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
     if(count == 0){
        tail = head = new Node(e);
    }
    else{
        Node* tmp = new Node(e);
        tail->next = tmp;
        tmp->previous = tail;
        tail = tmp;
    }
    count ++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    if(index < 0 && index > count) throw out_of_range("");
    else if(count == 0 || index == count ) add(e);
    else if(index == 0){
        Node* tmp = new Node(e);
        tmp->next = head;
        head->previous = tmp;
        head = tmp;
        count  ++;
    }
    else{
        Node* curr = head->next,* prev = head;
        index --;  
        while(index){
            index--;
            prev = curr;
            curr= curr->next;
        }
        Node* tmp = new Node(e);
        prev->next = tmp;
        tmp->previous = prev;
        tmp->next = curr;
        curr->previous = tmp;
        count ++;
    }
    
    
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
