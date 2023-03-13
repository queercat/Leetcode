#include <stdio.h>
#include <unordered_map>

class Node {
	int key;
	int value;

public:
	Node* previous;
	Node* next;

	Node(int key, int value) {
		this->key = key;
		this->value = value;

		previous = 0;
		next = 0;
	}

	int getValue() {
		return value;
	}

	int getKey() {
		return key;
	}
};

class LRUCache {
    int size, capacity;
    Node* LRU;
    Node* MRU;
    std::unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
    	
    	LRU = new Node(0, 0);
    	MRU = new Node(0, 0);

    	LRU->next = MRU;
    	MRU->previous = LRU;
    }

    void remove(Node* node) {
    	Node* previous = node->previous;
    	Node* next = node->next;

    	previous->next = next;
    	next->previous = previous;
    }

    void insert(Node* node) {
    	Node* previous = MRU->previous;
    	Node* next = MRU;

    	previous->next = node;
    	next->previous = node;

    	node->previous = previous;
    	node->next = next;
    }
    
    int get(int key) {

    	if (cache.find(key) != cache.end()) {
    		remove(cache[key]);
    		insert(cache[key]);

    		return cache[key]->getValue();
    	}

    	return -1;
    }
    
    void put(int key, int value) {
        printf("%d %d\n", key, value);
        
        if (cache.find(key) != cache.end()) {
    		remove(cache[key]);
    	}

    	Node* node = new Node(key, value);
    	cache[key] = node;

    	insert(cache[key]);

    	if (cache.size() > capacity) {
    		Node* target = LRU->next;
    		remove(target);
    		cache.erase(cache.find(target->getKey()));
        }
    }
};