class Node{
public:
    int key , value;
    Node* next; Node* prev;

    Node(int x , int y){
        key = x;
        value = y;
        next = nullptr;
        prev = nullptr;
    }

};

class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add_node(Node* new_node){
        Node* curr_headnxt = head->next;
        head->next = new_node;
        new_node->next = curr_headnxt;
        new_node->prev = head;
        curr_headnxt->prev = new_node;
    }

    void del_node(Node* del_node){
        Node* new_prevnode = del_node->prev;
        Node* new_nextnode = del_node->next;
        new_prevnode->next = new_nextnode;
        new_nextnode->prev = new_prevnode;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* result = mp[key];
            int res = result->value;
            del_node(result);
            add_node(result);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
       if(mp.find(key) != mp.end()){
        Node* result = mp[key];
        del_node(result);
        add_node(result);
        mp[key] = head->next;
        result->value = value;
       }
       else{
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            del_node(tail->prev);
        }
        add_node(new Node(key,value));
        mp[key] = head->next;
       } 
    }
};