// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  int beginQueue, endQueue, counter, sizeMaxQueue;
  T* arr;

 public:
  TPQueue():beginQueue(0), endQueue(0), counter(0), sizeMaxQueue(size) {
    arr = new T[sizeMaxQueue+1];
  }
  bool isEmpty() const {
    return 0 == counter;
  }
  bool isFull() const {
    return sizeMaxQueue == counter;
  }
  ~TPQueue() {
    delete[] arr;
  }
  void push(const T& item) {
    assert(counter < sizeMaxQueue);
    if (counter == 0) {
      arr[endQueue++] = item;
      counter++;
    } else {
      int i = endQueue - 1;
      bool flag = 0;
      while (i >= beginQueue && item.prior > arr[i].prior) {
        flag = 1;
        arr[i + 1] = arr[i];
        arr[i] = item;
        i--;
      }
      if (flag == 0) {
        arr[endQueue] = item;
      }
      endQueue++;
      counter++;
    }
    if (endQueue > sizeMaxQueue) {
      endQueue -= sizeMaxQueue + 1;
    }
  }
  const T& pop() {
    assert(counter > 0);
    counter--;
    if (beginQueue > sizeMaxQueue) {
      beginQueue -= sizeMaxQueue + 1;
    }
    return arr[beginQueue++];
  }
  char get() const {
    assert(count > 0);
    return arr[beginQueue].ch;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
