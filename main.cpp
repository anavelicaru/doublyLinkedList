#include <iostream>
using namespace std;

class node{
protected:
	int data;
	node *next;
public:
	node(int, node*);
	node(Node&);
	node& operator=(node&);
	int getData(){
		return data;}
	node *getNext(){
		return next;}
	void setNext(node *n){
		next=n;}
	void setData(int i){
		data=i;}
	friend istream& operator >> (istream&, node&);
	friend ostream& operator << (ostream&, node&);
	friend class doubleLinked;

};

node::node (int n=0, node *p = NULL){
	data=n;
	next=p;}

node::node(node &p){
	data=p.data;
	next=p.next;}
node::~node(){}
node& node::operator = (node &p){
	data=p.data;
	next=p.next;
	return *this;}
istream& operator >> (istream &in, node&p){
	int n;
	in>>n;
	p.data=n;
	p.next=NULL;
	return in;
}

ostream& operator << (ostream &out,node *p){
	out<<p.data<<endl;
	return out;
}


class doubleNode::public node {
protected:
	 node* prev;
public:
	doubleNode(int n, node*p, node *q);
	doubleNode(doubleNode&);
	~doubleNode();
	node *getPrev(){
		return prev;}
	void setPrev(node *pr){
		prev=pr;}
	doubleNode& operator = (doubleNode&);
	friend istream& operator >> (istream&, doubleNode&);
	friend ostream& operator << (ostream&, doubleNode&);
	friend class doubleLinked;
};

doubleNode::doubleNode(int n=0, node *p=NULL, node *q=NULL):node(n,p){
	prev = q;}//init

doubleNode::doubleNode(doubleNode &p):node(p){
	prev = p.prev;}//copy
doubleNode::~doubleNode(){}

/*doubleNode& doubleNode::operator = (doubleNode &p){
	data=p.data;
	next=p.next;
	prev=p.prev;
	return *this;
}*/


istream& operator >> (istream& in, doubleNode &p){
	in>>(node&)p;
	p.prev=NULL;
	return in;
}


ostream& operator << (ostream& out, doubleNode &p){
	out << (node&)p;
	return out;
}

class doublyLinked{
protected:
	doubleNode *head, *tail;
	static int n;
public:
	doublyLinked();//init
	doublyLinked(doublyLinked&);//copy
	~doublyLinked();
	doubleNode *getHead(){
		return head;}
	doubleNode *getTail(){
		return tail;}
	void setHead(doubleNode *p){
		head = p;
	void  setTail(doubleNode *q){
		tail = q;
	bool checkEmpty(){
		return head == 0;}
	void delette(int);
	int dim();
	void print(){
		cout << n;}
	void push(int x){
		doubleNode *p;
		p = new doubleNode(x);
	if (checkEmpty())
		head = tail = p;
	else{
		doubleNode *temp = tail;
		tail->next = p;
		tail = p;
		tail->prev = temp;}
	}
	friend istream& operator >> (istream&, doublyLinked&);
	friend ostream& operator << (ostream&, doublyLinked&);
};


int doublyLinked::n;

doublyLinked::doublyLinked(){
	n++;
	head = tail = 0;}

doublyLinked::doublyLinked(doublyLinked &l){
	if (!l.checkEmpty()){
		n++;
		doubleNode *a = l.head;
		head = tail = new doubleNode(*a);
		a = (doubleNode *)a->next;
		while (a){
			doubleNode *temp = new doubleNode(*a);
			temp->prev = (node*)tail;
			tail->next = (node*)temp;
			tail = temp;
			a=(doubleNode *)a->next;}
		}
	else
		head = tail = 0;
}


int doublyLinked:: dim(){
node *p = this->head;
int k = 0;
if (p){
	while (p!=this->tail->getNext()){
	k++;
	p=p->getNext();}
return k;}



void doublyLinked::delette(int key){
	if (!checkEmpty() && key <= dim()){
		doubleNode *p = head;
		int k = 1;
		while (k != key){
		p = (doubleNode*)p->next;
		k++;}
		if (dim()>1){
		doubleNode *pr = (doubleNode*)p->prev;
		doubleNode *nx = (doubleNode*)p->next;
		if (key>1 && key<dim()){
			pr->next = p->next;
			nx->prev = p->prev;}
		else
			if (key==1){
			head = (doubleNode*)p->next;
			head->prev=0;}
		else
			if (key==dim()){
			pr->next=0;
			tail=pr;}
		delete(p);
		}
	else head = tail = 0;
}

//overloading operators

istream& operator >> (istream& in, doublyLinked& l){
	cout << "Number of elements in list:";
	int n; in >> n;
	if (n) {
	doubleNode *temp = new doubleNode;
	cout << "First element:"; in >> *temp;
	l.tail = l.head = temp;
	int i=2;
	for (i=2; i<=n; i++){
		temp = new doubleNode;
		in >> *temp;
		l.tail->setNext(temp);
		temp->setPrev((node*)l.tail);
		l.tail=temp;}
	}
	return in;
}


ostream& operator << (ostream& out, doublyLinked& l){
	if (l.checkEmpty())
		out<<" ";
	else {
		out<<l.head->getData()<<" ";
	for (doubleNode*p = (doubleNode*)l.head->getNext(); p!=NULL; p=(doubleNode*)p->getNext())
		out<<p->getData()<<" ";
	} //left-right

	for(doubleNode*p = (doubleNode*)l.tail->getPrev(); p!=NULL; p=(doubleNode*)p->getPrev())
        out<<p->get_info()<<" ";
    }
    out<<"\n";
    return out;
}

int main(){
l = new doubleLinked;
}
