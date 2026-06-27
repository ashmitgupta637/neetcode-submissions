class LRUCache {
public:

struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

int capacity;
unordered_map<int, Node*> mp;

Node* head;
Node* tail;


    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }


    void addNode(Node* node){

        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }


    void deleteNode(Node* node){

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    int get(int key) {

        if(mp.find(key) == mp.end()){
            return -1;
        }


        Node* node = mp[key];


        // remove from current position
        deleteNode(node);


        // move to front (recent)
        addNode(node);


        return node->value;
    }


    void put(int key, int value) {


        // already exists
        if(mp.find(key) != mp.end()){

            Node* node = mp[key];

            node->value = value;

            deleteNode(node);

            addNode(node);

        }

        else{


            Node* newNode = new Node(key,value);

            mp[key] = newNode;

            addNode(newNode);



            // capacity exceed
            if(mp.size() > capacity){

                Node* lru = tail->prev;


                deleteNode(lru);


                mp.erase(lru->key);


                delete lru;
            }
        }
    }
};