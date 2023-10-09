#pragma once
template <class T>
class SListNode
{
	T data;
	SListNode<T> *next;
public:
	SListNode(T data);
	void insertAfter(T data);
	T& getData();
	SListNode<T>* getNext();
	void setNext(SListNode<T>*next);
};
template <class T>
SListNode<T>::SListNode(T data)
{
	this->data = data;
	this->next = nullptr;
}
template <class T>
void SListNode<T>::insertAfter(T data)
{
	if (next == nullptr)
	{
		next = new SListNode(data);
	}
	else
	{
		SListNode* temp = next;
		next = new SListNode(data);
		next->next = temp;
	}


}
template <class T>
T& SListNode<T>::getData()
{
	return this->data;
}
template <class T>
SListNode<T>* SListNode<T>::getNext()
{
	return this->next;
}

template<class T>
void SListNode<T>::setNext(SListNode<T> *next)
{
	this->next = next;
}