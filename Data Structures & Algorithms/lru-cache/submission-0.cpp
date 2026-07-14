struct Node {
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};


class LRUCache {
   private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = nullptr;
        node->next = nullptr;
    }
    void insertFront(Node* node){
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    };

   public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* node = mp[key];
        remove(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->value = value;
            remove(node);
            insertFront(node);
        }else{
            Node* node = new Node(key, value);
            if(mp.size() < cap){
                mp[key] = node;
                insertFront(node);
            }else{
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
                mp[key] = node;
                insertFront(node);
            }
        }
    }
};
