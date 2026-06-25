#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        Node* prevNode = right->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        left = new Node(0, 0);
        right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];

            remove(node);
            insert(node);

            return node->value;
        }

        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            delete cache[key];
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > capacity) {
            Node* lru = left->next;

            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    LRUCache cache(3);

    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    cout << cache.get(2) << endl;

    cache.put(4, 400);

    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}
