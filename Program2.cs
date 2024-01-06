using System;
using System.Collections.Generic;
using System.Reflection;

class QueueWithTwoStacks<T> {
    private Stack<T> stack1;
    private Stack<T> stack2;

    public QueueWithTwoStacks()
    {
    stack1 = new Stack<T>();
    stack2 = new Stack<T>();
    }

    public void Enqueue(T item)
    {
    // Переносим все элементы из stack1 в stack2
    while (stack1.Count > 0)
    {
    stack2.Push(stack1.Pop());
    }

    // Добавляем новый элемент в stack1
    stack1.Push(item);

    // Возвращаем элементы обратно из stack2 в stack1
    while (stack2.Count > 0)
    {
    stack1.Push(stack2.Pop());
    }
    }

    public T Dequeue()
    {
    // Если стеки пусты, генерируем исключение
    if (stack1.Count == 0)
    {
    throw new InvalidOperationException("The queue is empty");
    }

    // Удаляем и возвращаем элемент из stack1
    return stack1.Pop();
    }

    public int Count()
    {
    // Возвращаем количество элементов в очереди
    return stack1.Count;
    }
}

class Program {
    static void Main() {
    QueueWithTwoStacks<int> queue = new QueueWithTwoStacks<int>();

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    Console.WriteLine(queue.Dequeue()); // Вывод: 1
    Console.WriteLine(queue.Dequeue()); // Вывод: 2
    Console.WriteLine(queue.Dequeue()); // Вывод: 3
    Console.WriteLine(queue.Count()); // Вывод: 0
    }
}