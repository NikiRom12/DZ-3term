template <typename type>
struct elem{
	public:
	type val;
	elem *next;
	
	elem(type val = type(), elem *n = nullptr) : val(val), next(n) {}
};


template <typename type>
class List{
	elem<type> *base;
	elem<type> *current;
	void clear()
	{
		elem<type> *curr = base->next;
		while (curr != base)
		{
			elem<type> *nextElem = curr->next;
			delete curr;
			curr = nextElem;
		}
		delete base;
	}

  public:
  
	List()
	{
		try {base = new elem<type>;}
		catch (...) {cout << "error memory" << endl; exit(1);}
		base->next = base;
		current = base;
	}
	
	~List() {clear(); }
	
	
	bool AtBeg()	{return current == base;}
	
	bool Insert(type val){
		elem<type> *newElem;
		
		try {newElem = new elem<type>(val, current->next);}
		catch(...) {return 1;}
		
		current->next = newElem;
		return 0;
	}
	
	
	bool Delete(){
		if (current->next == base) return 1;	
		
		elem<type> *del = current->next;
		
		current->next = (current->next)->next;
		delete del;
		
		return 0;
	}
	
	
	bool Get(type *val){
		if (current == base) return 1;
		
		*val = current->val;
		return 0;
	}
	
	bool Set(type val){
		if (current == base) return 1;
		
		current->val = val;
		return 0;
	}
	
	bool StepForward(){
		if (current->next == base) return 1;
		
		current = current->next;
		
		return 0;
	}
	
	
	void GotoBeg(){
		current = base;
	}
	
	bool IsEmpty() {return base->next == base;}
	
	void show(){
		cout<<"=====List======"<<endl;
		
		elem<type> *curr=base->next;
		
		if(base==current) cout<<"[base] <-current"<<endl;
		else cout<<"[base]"<<endl;
		
		while(curr!=base)
		{
			cout<<curr->val;
			if(curr==current) cout<<"<-current";
			cout<<endl;
			curr=curr->next;
		}
		cout<<"==End of List=="<<endl;
	}
};
