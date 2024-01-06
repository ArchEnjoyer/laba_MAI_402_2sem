class Stack:
    def __init__(self):
        self.stack = []

    def __bool__(self):
        return bool(self.stack)

    def push(self, elem):
        if self.stack:
            self.stack.append((elem, min(elem, self.stack[-1][1])))
        else:
            self.stack.append((elem, elem))

    def pop(self):
        return self.stack.pop()[0]

    def get_min(self):
        if not self.stack:
            return 99999999999999999999999999999999999999
        return self.stack[-1][1]
    

class Queue:
    def __init__(self):
        self.s1 = Stack()
        self.s2 = Stack()

    def push(self, elem):
        self.s1.push(elem)

    def pop(self):
        if not self.s2:
            while self.s1:
                self.s2.push(self.s1.pop())
        return self.s2.pop()

    def get_min(self):
        return min(self.s1.get_min(), self.s2.get_min())
    

def main():
    mystack = Queue()
    mystack.push(22)
    mystack.push(55.5)
    mystack.push(11)
    mystack.push(123)
    mystack.push(34.5)
    print(mystack.pop())
    print(mystack.get_min())

if __name__ == "__main__":
    main()
