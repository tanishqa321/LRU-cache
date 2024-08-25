class Node {
    public:
      int key;
      int val;
      Node * next;
      Node * prev;
      Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = nullptr;  // Initialize pointers to null
        prev = nullptr;
      }
    };
class LRUCache {
public:
    
    int c;
    unordered_map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        c= capacity;
        mpp.clear();
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(Node* node){
        Node* pre = node->prev;
        Node* ne=  node->next;
        pre->next = ne;
        ne->prev= pre;
    }
    void interafterhead(Node* node){
        Node* temp = head->next;
        head->next=node;
        node->prev=head;
        temp->prev= node;
        node->next=temp;


    }
    
    
    int get(int key) {
        if(mpp.find(key)== mpp.end())return -1;
        Node* ele=  mpp[key];
        deletenode(ele);
        interafterhead(ele);
        return ele->val;

    }
    
    void put(int key, int value) {
         if(mpp.find(key)== mpp.end()){
            if(mpp.size()==c){
                Node* temp= tail->prev;
                deletenode(temp);
                mpp.erase(temp->key);
                delete temp;
            }
            Node* ele= new Node(key,value);
             interafterhead(ele);
             mpp[key] = ele;
         }
         else {
            Node* ele= mpp[key];
            ele->val=value;
            deletenode(ele);
            interafterhead(ele);

         }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
