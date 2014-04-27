#pragma once

template<typename T>
class XListElem{
	T data;
	XListElem<T> * next;
	XListElem<T> * early;
public:
	T getData(){return data;}
	void setData(T x){this->data = x;}
	XListElem<T> * getNext(){return next;}
	XListElem<T> * getEarly(){return early;}
	void setEarly(XListElem<T> * x){this->early = x;}
	void setNext(XListElem<T> * x){this->next = x;}
};

template<typename T>
class XList{
	XListElem<T> * head;
	XListElem<T> * tail;
public:
	XList(){head = tail = NULL;}

	void addHead(T x){
		XListElem<T> * elem = new XListElem<T>();
		elem->setData(x);
		if(this->empty()){
			this->head = this->tail = elem;
			return;
		}
		(this->head)->setEarly(elem);
		elem->setNext(this->head);
		this->head = elem;
	}

	void addTail(T x){
		XListElem<T> * elem = new XListElem<T>();
		elem->setData(x);
		if(this->empty()){
			this->head = this->tail = elem;
			return;
		}
		(this->tail)->setNext(elem);
		elem->setEarly(this->tail);
		this->tail = elem;
	}

	int getSize(){
		int i = 1;
		if( this->empty() )
			return 0;
		XListElem<T> * elem = this->head;
		while(elem->getNext() != NULL){
			i++;
			elem = elem->getNext();
		}
		return i;
	}

	void clean(){
		if( this->empty() )
			throw "Error(from delHead): list is empty.";
		XListElem<T> * elem = this->head;
		if(elem->getNext() != NULL){
			elem = elem->getNext();
			delete elem->getEarly();
		}
		delete elem;		
	}
	
	bool empty(){
		if(this->head == NULL && this->tail == NULL)
			return true;
		return false;
	}

	void delHead(){
		if( this->empty() )
			throw "Error(from delHead): list is empty.";
		XListElem<T> * elem = this->head;
		elem = elem->getNext();
		delete elem->getEarly();
		this->head = elem;
		elem->setEarly(NULL);
	}
	
	void delTail(){
		if( this->empty() )
			throw "Error(from delTail): list is empty.";
		XListElem<T> * elem = this->tail;
		elem = elem->getEarly();
		delete elem->getNext();
		this->tail = elem;
		elem->setNext(NULL);
	}

	T getData(int i){
		if( this->empty() )
			throw "Error(from getData): list is empty.";
		int j = 0;
		XListElem<T> * elem = this->head;
		while(++j < i)
			elem = elem->getNext();
		return elem->getData();
	}

	void iterHead(){
		if( this->empty() )
			throw "Error(from getData): list is empty.";
		XListElem<T> * elem = this->head;
		int i = 0, size = this->getSize();
		while(i++ < size){
			cout<<elem->getData()<<"  ";
			elem = elem->getNext();
		}
		cout<<endl;
	}

	void iterTail(){
		if( this->empty() )
			throw "Error(from getData): list is empty.";
		XListElem<T> * elem = this->tail;
		int i = this->getSize();
		while(i-- > 0){
			cout<<elem->getData()<<"  ";
			elem = elem->getEarly();
		}
		cout<<endl;
	}
};




		
			
	