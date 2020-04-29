#include <iostream>
  #include <string>
  using namespace std;

  class person{
     protected:
        string name;


     public:

        void setName()
        { cout << "Enter name: "; cin >> name;

        }
        void printName()
        { cout << name<<endl; }
        string getName()
        { return name; }

  };
  int main(){
     void bsort(person**, int);
     person* persPtr[100];
     int year,sum=0;
     int n = 0;
     char choice;
     string spchar;
     cout<<"ENTER THE 3 DIGIT CODE OF INSTITUTION:";
         cin>>spchar;
     cout<<"Enter the academic year: ";
     cin>>year;
     string branch;
     cout<<"\nSelect the branch: ";
     {
    	 int ch;
     	  cout<<"\n1.Computer Science\n2.Civil\n3.Electronics and Communication\n4.Electricals and Electronics\n5.Information Science\n6.Mechanical\n";
     	  cin>>ch;
     	  switch(ch){
     	  case 1:branch="CS";
     	  	  	 break;
     	  case 2:branch="CI";
     			  break;
     	  case 3:branch="EC";
     	  	  	  break;
     	  case 4:branch="EE";
     	  	  	  break;
     	  case 5:branch="IS";
     	  	  	  break;
     	  case 6:branch="ME";
     	  	  	  break;
     	  }
       }

     cout<<"Enter students name:\n";
     do {
        persPtr[n] = new person;
        persPtr[n]->setName();
        n++;
        cout << "\nEnter another (y/n)? ";
        cin >> choice;
     }while( choice=='y' );

     int id[n];
     bsort(persPtr, n);



    for(int k=0;k<n;k++){
           	  id[k]=k;
             }
    for(int j=0;j<n;j++){
    for(int i=0;i<2;i++){
    	sum=year%100;
    }
    }
     cout << "\nFinal list:";
     for(int j=0; j<n; j++)
     {
        cout<<"\n";
         	  if(j<10){
         		  cout<<spchar<<sum<<branch<<"00"<<id[j];
         	  }
         	  else if(j<100){
         	  		  cout<<spchar<<sum<<branch<<"ec0"<<id[j];
         	  	  }
         	  else if(j<1000){
         	  		  cout<<spchar<<sum<<branch<<"ec"<<id[j];
         	  	  }
         	  cout<<"\t";
       persPtr[j]->printName();
     }
     cout << endl;

     return 0;
  }

  void bsort(person** pp, int n){
     void order(person**, person**);
     int j, k;

     for(j=0; j<n-1; j++)
        for(k=j+1; k<n; k++)
         order(pp+j, pp+k);
    }
  void order(person** pp1, person** pp2){
     if( (*pp1)->getName() > (*pp2)->getName() )  {
        person* tempptr = *pp1;
        *pp1 = *pp2;
        *pp2 = tempptr;
     }
  }
































