#include "assignment/linked_list.hpp"

#include <utility>  // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    // Напишите здесь свой код ...
    if (size_ <= 1) {
      return;
    }
    Node* cur = front_;
    Node* prev = nullptr;
    while (cur != back_) {
      Node* future = cur->next;
      cur->next = prev;
      prev = cur;
      cur = future;
    }
    cur->next = prev;
    Node* variable = front_;
    Node* varible_more = back_;
    back_ = variable;
    front_ = varible_more;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ <= 1){
      return;
    }
    reverse_recursive_helper(front_->next, front_);
    Node* variable = front_;
    Node* varible_more = back_;
    back_ = variable;
    front_ = varible_more;
    back_->next = nullptr;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr){
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
