#include <iostream>
using namespace std;
#include "List.cpp"

int main(){	
	List<double> l;
	int control;
	double val;
	double v;
	
	while(1){
	cout<<"\n  MENU    "<<endl;
	cout<<"1. Insert"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Get"<<endl;
	cout<<"4. Set"<<endl;
	cout<<"5. StepForward"<<endl;
	cout<<"6. GotoBeg"<<endl;
	cout<<"7. AtBeg"<<endl;
	cout<<"8. IsEmpty"<<endl;
	cout<<"9. Show"<<endl;
	cout<<"0. Exit"<<endl;
	cout<<"Choose: ";
	cin>>control;
	switch(control){
		case 0:{
			return 0;
			}
			
		case 1:{
			cout<<"Insert: ";
			cin>>val;
			
			l.Insert(val);
			break;
		}
		
	case 2:{
		l.Delete();
		break;}
	
	case 3:{
		l.Get(&v);
		cout<<"Current value: "<<v<<endl;
		break;
		}
		
	case 4:{
		double s;
		cout<<"Set: "; 
		cin>>s;
		l.Set(s);
		break;
		}
		
	case 5:{
		l.StepForward();
		break;
		}
	
	case 6:{
		l.GotoBeg();
		break;
		}
		
	case 7:{
		l.AtBeg();
		break;
		}
		
	case 8:{
		if(l.IsEmpty()) cout<<"List is Empty"<<endl;
		else cout<<"List is not empty"<<endl;
		break;
		}
		
	case 9:{
		l.show();
		break;
		}	
		
		
		
	default:{
		cout<<"This function doesn`t exist"<<endl;
		break;} 	
		
		}
	}
	
	return 0;

}
