#include <iostream>
#include <unordered_map>

using std::unordered_map;

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity), tail_(&head_) {}

  int get(int key) {
    auto itr = cache_.find(key);
    if (itr == cache_.end()) return -1;
    // move to tail
    move2tail(itr->second);
    return itr->second->value;
  }

  void put(int key, int value) {
    auto itr = cache_.find(key);
    if (itr != cache_.end()) {
      itr->second->value = value;
      move2tail(itr->second);
    } else if (int(cache_.size()) >= capacity_) {
      // reuse existing node
      cache_.erase(head_.next->key);
      move2tail(head_.next);
      tail_->key = key;
      tail_->value = value;
      cache_[key] = tail_;
    } else {
      auto node = new DLinkNode(key, value);
      cache_[key] = node;
      add2tail(node);
    }
  }

  void showCache() {
    DLinkNode *node = head_.next;
    std::cout << "{";
    while (node) {
      std::cout << "{key: " << node->key << ", value: " << node->value << "}, ";
      node = node->next;
    }
    std::cout << "}" << std::endl;
  }

 private:
  struct DLinkNode {
    int value;
    int key;
    DLinkNode *pre;
    DLinkNode *next;

    DLinkNode() {}
    DLinkNode(int key, int value)
        : value(value), key(key), pre(nullptr), next(nullptr) {}
  };

  int capacity_;
  DLinkNode head_;
  DLinkNode *tail_;
  unordered_map<int, DLinkNode *> cache_;

  void move2tail(DLinkNode *node) {
    if (node == tail_) return;
    node->pre->next = node->next;
    node->next->pre = node->pre;
    add2tail(node);
  }

  void add2tail(DLinkNode *node) {
    node->next = tail_->next;
    node->pre = tail_;
    tail_->next = node;
    tail_ = node;
  }
};

int main(int argc, char const *argv[]) {
  LRUCache *lruCache = new LRUCache(2);
  lruCache->put(1, 1);
  lruCache->showCache();
  lruCache->put(2, 2);
  lruCache->showCache();
  int value = lruCache->get(1);
  if (value != 1) {
    std::cout << "get value of key(1) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 1 ok" << std::endl;
  }
  lruCache->put(3, 3);
  lruCache->showCache();
  value = lruCache->get(2);
  if (value != -1) {
    std::cout << "get value of key(2) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 2 ok, 2 kicked out" << std::endl;
  }
  lruCache->showCache();
  lruCache->put(4, 4);
  lruCache->showCache();
  value = lruCache->get(1);
  if (value != -1) {
    std::cout << "get value of key(1) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 1 ok, 1 kicked out" << std::endl;
  }
  value = lruCache->get(3);
  if (value != 3) {
    std::cout << "get value of key(3) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 3 ok" << std::endl;
  }
  value = lruCache->get(4);
  if (value != 4) {
    std::cout << "get value of key(4) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 4 ok" << std::endl;
  }

  lruCache->put(4, 40);
  value = lruCache->get(4);
  if (value != 40) {
    std::cout << "get value of key(4) not wright, get " << value << std::endl;
  } else {
    std::cout << "get 4 ok" << std::endl;
  }
  return 0;
}
