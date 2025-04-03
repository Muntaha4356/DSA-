https://www.programiz.com/online-compiler/8gfv2ciRdu6c2
class StackInt {
  constructor(size = 0) {
    this.capacity = size;
    this.top = 0;
    this.arr = new Array(size);
  }

  push(value) {
    if (!this.isFull()) {
      this.arr[this.top] = value;
      this.top++;
      console.log(`${value} pushed into stack.`);
    } else {
      console.log("Stack Overflow!");
    }
  }

  pop() {
    if (!this.isEmpty()) {
      console.log(`${this.arr[--this.top]} popped from stack.`);
    } else {
      console.log("Stack Underflow!");
    }
  }

  isEmpty() {
    return this.top <= 0;
  }

  isFull() {
    return this.top === this.capacity;
  }

  display() {
    if (this.isEmpty()) {
      console.log("Stack is Empty!");
    } else {
      console.log("Stack elements:", this.arr.slice(0, this.top).join(" "));
    }
  }

  peek() {
    if (!this.isEmpty()) {
      console.log("Stack is peeked");
      return this.arr[this.top - 1];
    } else {
      console.log("Stack is empty!");
      return -1;
    }
  }

  topElement() {
    if (!this.isEmpty()) {
      console.log("Stack is topped");
      return this.arr[this.top - 1];
    } else {
      console.log("Stack is empty!");
      return -1;
    }
  }
}

const stack = new StackInt(45);
stack.push(10);
stack.push(20);
stack.push(30);  // Output: [10, 20, 30]
console.log(stack.pop()); // Output: 30
console.log(stack.peek()); // Output: 20
console.log(stack.topElement());
