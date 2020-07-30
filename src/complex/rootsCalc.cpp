#include <iostream>
#include <complex>
#include <cmath>
using namespace std ;

int main(void){

	cout<<"Enter  the  coefficients of your quadratic eqaution"
	    <<"in this manner  a ,b and c" <<endl ;
    int onlyAskOnce=1;
	bool areYuDone=false ;// for checking if the user is done or want to continue .
	while(areYuDone==false){
		string  a;
		double b, c;
		cin>> a; // getting the first value and aslo check if its 'q' or a num 
		if(a=="q"){areYuDone=true;}
		else{
		cin>> b >> c ; //getting the rest of the values
		auto aa=stof(a); //changing string to a detected numerical type
		auto bOverA=-b/(2*aa) ;
		auto  imagOreal=pow(b,2)-4*aa*c ; //checking if this is negative or not. (-)4 imag and (+)4 real
		if(imagOreal<0){
			using cmplx=complex<double>;
			auto imagReal0 = sqrt(cmplx(imagOreal));
			cout<< "Root 1= " << bOverA <<" + "<< imagReal0.imag()/(2*aa) <<"j" << endl;
			cout<< "Root 2= " << bOverA <<" + "<< -imagReal0.imag()/(2*aa) <<"j" << endl;
				}
		else{
			if(aa==0){ // avoiding the case where dividing by a==0
			cout<< "Root = "<<-c/b <<endl;
			}
			else{
			cout<< "Root 1= "<<bOverA+sqrt(imagOreal)/(2*aa) <<endl;
			cout<< "Root 2= "<<bOverA-sqrt(imagOreal)/(2*aa) <<endl;
			}
			}
			
	if(onlyAskOnce==1){
		cout<<endl;
		cout<<"Would you like to continue calculating roots for another Quadratic"
	    	<<" eqaution ?  if No, press 'q' to quit or continue" <<endl ;
		onlyAskOnce=0; //for  the if statement not to execute twice
		}
	cout<<endl ;
		}
	}
return 0;
}
