#include <iostream>

using namespace std;

class node{
    private:
    node *next;
    int data;

    public:
    node(int=0);
    int getdata();
    void setdata(int i);
    node* getnext();
    void setnext(node *j);
    void showdata();

};

node::node(int i)
{
    data=i;
    next=0;
}

int node::getdata(){
    return data;
}

void node::setdata(int i){
    data=i;
}

node* node::getnext(){
    return next;
}

void node::setnext(node* j){
    next=j;
}

void node::showdata(){
    cout<<getdata()<<" ";
}


class List{
    private:
    node* head;
    node* tail;
    int size=0;

    public:
    List();
    void add(int);
    int length();
    void remove();
    void showlist();
    void setstart(int);
    void next();
    void begin();

};

List::List(){
    head=tail=0;
}

void List::add(int x){
    node *p=new node(x);
    if(head==0){
        head=p;
        tail=p;
        p->setnext(head);
    }
    else{
        p->setnext(tail->getnext());
        tail->setnext(p);
        tail=p;
    }
    size++;
}

int List::length(){
    return size;
}

void List::showlist(){
    node *p;
    p=head;
    do{
        p->showdata();
        p=p->getnext();
    }while(p!=head);
    cout<<endl;
}

void List::remove(){
    if(tail==0)
        {
            cout<<"List is empty"<<endl;
            return;
        }
    else
    {
        if(head!=tail){
            node *p;
            p=head;
            while(p->getnext()!=tail)
                p=p->getnext();
            p->setnext(tail->getnext());
            tail=p;
            size--;
        }
        else{
            node *p,*d;
            p=head;
            d=tail->getnext();
            while(p->getnext()!=head)
                p=p->getnext();
            p->setnext(d);
            head=d;
            size--;
        }
    }

}

void List::setstart(int value){
    if(head->getdata()==value)
        return;
    else
        {
            node *p=head;
            while(p->getdata()!=value)
                p=p->getnext();
            head=p;
            for(int i=1;i<size;i++)
                p=p->getnext();
            tail=p;
        }
}

void List::next(){
    if(tail->getnext()!=NULL)
        tail=tail->getnext();
}

void List::begin(){
    tail=head;
}

int main(){
    List l;
    int elements,k,start;
    do{
        cout<<"Introduce number of persons: ";
        cin>>elements;
    }while(elements<=0);
    do{
        cout<<"Introduce number of steps to be taken: ";
        cin>>k;
    }while(k<=0);
    do{
        cout<<"Introduce the starting point: ";
        cin>>start;
    }while(start<=0 || start>elements);
    for(int i=1;i<=elements;i++)
        l.add(i);
    l.showlist();
    l.setstart(start);
    l.showlist();
    cout<<endl;
    l.begin();

    while(l.length()!=1)
    {
       for(int i=1;i<k;i++)
        {
            l.next();
        }
        l.remove();
        l.next();
        l.showlist();
    }
    cout<<"The survivor is ";
    l.showlist();

    return 0;
}
