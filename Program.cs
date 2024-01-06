using System.Collections;

public interface IStack {
    int Count {get;}
    object Pop();
    object Peek{get;}
    bool Push (object item);
    string [] ToStringArray();
}

class StackList : IStack {
    ArrayList list;
    public StackList() { 
    list = new ArrayList();
    }

    public object Pop() { 
        object returnelement = list.Count is 0 ? "null" : list[list.Count-1] ; 
        if (returnelement is "null") {
            return returnelement;
        }
        else {
            list.RemoveAt(list.Count-1);
            return returnelement;
        }
    }
    public object Peek {
        get {
            return list.Count is 0 ? "null" : list[list.Count-1] ;
        }
    }
    public bool Push(object item) {
        list.Add(item);
        return true;
    }
    public int Count {
        get {
            return list.Count;
        }
    }
    //public string[] ToStringArray() { // в порядке первый в стеке - первый в списке
    //    if (list.Count == 0) {
    //        string[] returnstringnull = {"null"};
    //        return returnstringnull;
    //    };
    //    string[] returnstring = new string[list.Count];
    //    for (int i = 0; i < list.Count; i++) {
    //        returnstring[list.Count -1 -i] = list[i].ToString();
    //    }
    //    return returnstring;
    //}
    public string[] ToStringArray() { // в порядке первый в стеке - последний в списке
        if (list.Count == 0) {
            string[] returnstringnull = {"null"};
            return returnstringnull;
        };
        string[] returnstring = new string[list.Count];
        for (int i = 0; i < list.Count; i++) {
            returnstring[i] = list[i].ToString();
        }
        return returnstring;
    }
    static void Main() {
        static void printStack(IStack list) {
            foreach(var elem in list.ToStringArray()) Console.WriteLine(elem);
        }
    
        StackList blabla = new StackList();
        Console.WriteLine(blabla.Pop());
        Console.WriteLine(blabla.Peek);
        Console.WriteLine(blabla.Count); 
        //Console.WriteLine(String.Join("              ", blabla.ToStringArray()));
        Console.WriteLine("___________________________");
        printStack(blabla);
    
        blabla.Push("Lorem");
        blabla.Push("Ipsum");
        blabla.Push("blabla123");
        blabla.Push(3.27);
        blabla.Push(327);
        blabla.Push("blabla 11");
        blabla.Push(-1352462421346146246);
        blabla.Push('h');
    
        Console.WriteLine(blabla.Pop());
        Console.WriteLine(blabla.Peek);
        Console.WriteLine(blabla.Count); 
        //Console.WriteLine(String.Join("              ", blabla.ToStringArray()));
        Console.WriteLine("___________________________");
        printStack(blabla);
    }
};

class StackArray: IStack {
    object [] arr; // элементы стека
    int top; //число элементов стеке
    int maxtop;
    public StackArray (int capacity) {
        arr =new object[capacity];
        top =0;
        maxtop = capacity;
    }
    public int Count {
        get {
            return top;
        }
    }
    public bool Push(object item) {
        if (maxtop==top) {
            return false;
        }
        else {
            arr[top] = item;
            top += 1;
            return true;
        }
    }
    public object Peek {
        get {
            return top is 0 ? "null" : arr[top-1] ;
        }
    }
    public object Pop() { 
        object returnelement = top is 0 ? "null" : arr[top-1] ; 
        if (returnelement is "null") {
            return returnelement;
        }
        else {
            top -= 1;
            return returnelement;
        }
    }


    //public string[] ToStringArray() { // в порядке первый в стеке - первый в списке
    //    if (top == 0) {
    //        string[] returnstringnull = {"null"};
    //        return returnstringnull;
    //    }
    //    else {
    //        string[] returnstring = new string[top];
    //        for (int i = 0; i < top; i++) {
    //            returnstring[top -1 -i] = arr[i].ToString();
    //            }
    //        return returnstring;
    //    }
    //}
    public string[] ToStringArray() { // в порядке первый в стеке - последний в списке
        if (top == 0) {
            string[] returnstringnull = {"null"};
            return returnstringnull;
        }
        else {
            string[] returnstring = new string[top];
            for (int i = 0; i < top; i++) {
                returnstring[i] = arr[i].ToString();
                }
            return returnstring;
        }
    }

    //static void Main() {
    //    static void printStack(IStack list) {
    //        foreach(var elem in list.ToStringArray()) Console.WriteLine(elem);
    //    }
    //
    //    StackArray blabla = new StackArray(5);
    //    Console.WriteLine(blabla.Pop());
    //    Console.WriteLine(blabla.Peek);
    //    Console.WriteLine(blabla.Count); 
    //    Console.WriteLine("___________________________");
    //    printStack(blabla);
    //
    //    blabla.Push("Lorem");
    //    blabla.Push("Ipsum");
    //    blabla.Push("blabla123");
    //    blabla.Push(3.27);
    //    blabla.Push(327);
    //    blabla.Push("blabla 11");
    //    blabla.Push(-1352462421346146246);
    //    blabla.Push('h');
    //
    //    Console.WriteLine(blabla.Pop());
    //    Console.WriteLine(blabla.Peek);
    //    Console.WriteLine(blabla.Count); 
    //    //Console.WriteLine(String.Join("              ", blabla.ToStringArray()));
    //    Console.WriteLine("___________________________");
    //    printStack(blabla);
    //}

};