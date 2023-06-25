package com.link;

public class LL {
    private Node head;
    private Node tail;
    private  int size;

    public LL(){
        this.size = 0;
    }
    public class Node{
        private int data;

        private Node next;
        Node(int data){
            this.data = data;
        }
        Node(int data, Node next){
            this.data = data;
            this.next = next;
        }

    }

    public void insertFirst(int val){
        Node node = new Node(val);
        node.next = head;
        head = node;

        if (tail == null){
            tail = head;
        }
        size = size+1;
    }

    public void display(){
        Node tmp = head;
        while (tmp != null){
            System.out.print(tmp.data+"-->");
            tmp = tmp.next;
        }

        System.out.println("END");
    }
    //insert the element at th
    public void insertLast(int val){
        Node node = new Node(val);
        tail.next = node;
        tail = node;
        size++;
    }
    //insert at any point
    public void insert(int val,int index){
        if(index == 0){
            insertFirst(val);
            return;
        } else if (index == size) {
            insertLast(val);
        }else{
            Node temp = head;
            for(int i = 1;i<index;i++){
                temp = temp.next;
            }
            Node node = new Node(val , temp.next);
            temp.next=node;
            size++;
        }

    }
    //del the first element
    public int delFirst(){
        int val = head.data;
        head = head.next;
        if (head == null){
            tail = null;
        }
        size --;
        return val;
    }

    //del the last element
    public int deletLast(){
        if(size == 1){
            return delFirst();
        }
        Node secLast = get(size-1);
        int val = tail.data;
        tail = secLast;
        tail.next = null;
        return val;
    }

    //get the node
    public Node get(int index){
        Node node = head;
        for (int i = 0;i<index;i++){
            node = node.next;
        }
        return node;
    }

    //delet element from middle
    public  int delet(int index){
        if(index == 0 ){
            return delFirst();
        }else if(index == size-1){
            return deletLast();
        }else {
            Node pre = get(index - 1);
            int val = pre.next.data;
            pre.next = pre.next.next;

            return val;
        }
    }
}
