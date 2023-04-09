// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
  int beginQueue, endQueue, counter, sizeMaxQueue;
  T* arr;
  
  public:
  TPQueue():beginQueue(0), endQueue(0), counter(0), sizeMaxQueue(size) {
    arr = new T[sizeMaxQueue+1];
 
  bool isEmpty() const {
    return 0 == counter;
  }

  bool isFull() const {
    return sizeMaxQueue == counter;
  }

  ~TPQueue() {
    delete[] arr;
  }
  
  void push(const T& value) {
    int current = endQueue;
    assert(sizeMaxQueue > counter);
    if (counter != 0) {
      for (int i = beginQueue; i < endQueue; i++) {
        if (value.prior > arr[i].prior) {
          current = i;
        }
      }
    }
    if (counter != 0) {
      for (int i = endQueue; i > current; i--) {
        arr[i] = arr[i - 1];
      }
    }
    arr[current] = value;
    counter++;
    endQueue++;
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
  
  const T& get() {
    assert(counter > 0);
    return arr[beginQueue];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
