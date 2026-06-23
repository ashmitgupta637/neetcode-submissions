class MinStack {
   private:
    class Node {
        public : 
        int val;
        int mini;
        Node* next;

        Node(int val, int mini, Node* next) {
            this->val = val;
            this->mini = mini;
            this->next = next;
        }
    };
    Node*head; 
       public:
        MinStack() { head = nullptr; }

        void push(int val) {
            if (head == nullptr) {
                head = new Node(val, val, nullptr);
            } else {
                head = new Node(val, min(val, head->mini), head);
            }
        }

        void pop() {
            if (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        int top() { return head->val; }

        int getMin() { 
            return head->mini;
         }
    };
