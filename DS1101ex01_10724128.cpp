// 10724128 �d�t��

#include <stdio.h>
#include <stdlib.h>
#include <iostream> // cin, cout, endl
#include <string.h>
#include <cstdlib> // strtoul, system
#include <fstream> // ifstream or ofstream
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime> // clock 

using namespace std ;

class actions {
public :

bool Getact( int n, int num, unsigned long long a, unsigned long long b, int time ) {

	unsigned long long temp ;
    if( n == 1 ) {
    	while ( time <= num ) { // �C�X�O��ƦC(�j��) 
    		temp = a + b ;
    		b = a ; 
    		write( temp, time ) ;
    		LoopDiv( temp ) ;
    		a = temp ;
    		time++ ;
		}
		
		return true ;
    	
	} // ���Ȥ@
	
    if( n == 2 ) {
    	if ( time <= num ) { // �C�X�O��ƦC(���j)
    		temp = a + b ;
    		write( temp, time ) ;
    		unsigned long long sqrtNum1 = sqrt( temp ) ; 
			unsigned long long sqrtNum2 = sqrt( temp ) ; // �}�ڸ� 
    		RecurDiv( temp, sqrtNum1, sqrtNum2, 0, false ) ;
    		
    		Getact( 2, num, temp, a, time + 1 ) ; // ���j 
		}
		
		return true ;
    	
	} // ���ȤG 
	
	if ( n == 3 ) {
		int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } ;
		
		/*
		int result[num] ;
		combine_increase(arr, 0, result, num, num, sizeof(arr)/sizeof(int)) ;
		*/
		return true ;
	}
    
    else{
        return  true ;
    } 
} 

bool write( unsigned long long ans, int time ){ 
    cout << endl << "[ " << time << "] " << ans ;
    return true ;
} 

void LoopDiv( unsigned long long temp ) {
// �j�骺��t�Z�̤p�]��

	unsigned long long sqrtNum1 = 0 ; // �]��1 
	unsigned long long sqrtNum2 = 0 ; // �]��2 
	unsigned long long loopCount = 0 ; // �j������ 
	sqrtNum1 = sqrt( temp ) ;
	sqrtNum2 = sqrt( temp ) ; // �}�ڸ� 
	if ( temp == sqrtNum1 * sqrtNum2 ) { // �p�G��]�Ƭۭ�����ӶO��ƦC���� 
		cout << " = " << sqrtNum1 << " * " << sqrtNum2 << " (Inner loop: " << loopCount << " times)";
	}
	else { // �p�G���F�� 
		bool check = false ;
		while ( !check ) { // ��X�ŦX���󪺦]�� 
			
			loopCount++ ;
			
			if ( temp % sqrtNum2 == 0 ) { // ���l��
				cout << " = " << sqrtNum2 << " * " << (temp/sqrtNum2) << " (Inner loop: " << loopCount << " times)";
				check = true ;
			}
			
			sqrtNum2 -- ;
		}
	}
}

bool RecurDiv( unsigned long long temp, unsigned long long sqrtNum1, unsigned long long sqrtNum2, unsigned long long loopCount, bool check ) {
// ���j����t�Z�̤p�]��

	if ( temp == sqrtNum1 * sqrtNum2 && check == false ) {  // �p�G��]�Ƭۭ�����ӶO��ƦC����
		cout << " = " << sqrtNum1 << " * " << sqrtNum2 << " (Inner loop: " << loopCount << " times)";
		check = true ;
		RecurDiv( temp, sqrtNum1, sqrtNum2-1 , loopCount, check ) ;
	}
	if ( temp != sqrtNum1 * sqrtNum2 && check == false ) { // �p�G���F�� 
		loopCount++ ;
		if ( temp % sqrtNum2 == 0 ) { // ���l��
				cout << " = " << sqrtNum2 << " * " << (temp/sqrtNum2) << " (Inner loop: " << loopCount << " times)";
				check = true ;
		}
		RecurDiv( temp, sqrtNum1, sqrtNum2-1 , loopCount, check ) ; // �����j 
	}
	if ( check == true ) return true ;

}


/*
void Select (int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk) {
	if (i==n){ 
	
		// cout << endl << "in S" ;
		Print( n, list, list1, temp, flag, i, P, walk ) ;
		
		cout << endl ;
		P++ ;
	} // if 
	
	else { 
		
	 	Sort( n, list, list1, temp, flag, i, P, walk ) ;
	} // else
}

void Print(int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk ) {
	// cout << endl << "in P" ;
	if ( walk < n ) {
		if( walk % n == 0) cout << "[" << P+1 <<"]" ; // �ƦC���ռ�
		cout << temp[walk] << " " ; // �ߤ@��X���f 
		Print( n, list, list1, temp, flag, i, P, walk+1 ) ;
	}
}

void Sort(int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk ) {
	// cout << endl << "in Sort" ;
	if ( walk<=9 ) {
		if ( flag[walk] ) Sort( n, list, list1, temp, flag, i, P, walk+1 ) ;
		flag[walk] = true ;
		temp[i] = list1[walk] ;
	 	Select (n, list, list1, temp, flag, i+1, P, walk) ; //���j�U�@�Ӧ�m 
	 	flag[walk] = false ;
		Sort( n, list, list1, temp, flag, i, P, walk+1 ) ;
	}
}
*/


void Select (int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk) {
	if (i==n){ 
		
		for (int walk = 0; walk<n; walk++) {
			if(walk%n == 0) cout << "[ " << P+1 <<"] " ; // �ƦC���ռ�
			cout << temp[walk] << " " ; // �ߤ@��X���f 
		} // for  
		
		
		cout << endl ;
		P++ ;
	} // if 
	
	else { 
		
		for (int walk=0; walk<=9; walk++) {
			if (flag[walk]) continue ;
			flag[walk] = true ;
			temp[i] = list1[walk] ;
	 		Select (n, list, list1, temp, flag, i+1, P, walk) ; //���j�U�@�Ӧ�m 
	 		flag[walk] = false ;
	 	} // for �Ƨ� 
	 	
	} // else
}

} ;

int main(void){
    
    int command = 0 ; 
    actions act ;
    
    int num ;
    unsigned long long a, b ;
    a = 1 ;
    b = 0 ;
    
    int list[20] = {0} ; // ��l�ư}�C 
    int list1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
    int temp[20] = {0} ; //�Ȧs, ��l��
    bool flag[20] = {0} ; //�P�_��
    int P = 0 ;
    float cT = 0 ;

    do{

        cout << endl << "*** Fibonacci Series Generator ***" ;
        cout << endl << "* 0. Quit                        *" ;
        cout << endl << "* 1. Iterative generation        *" ;
        cout << endl << "* 2. Recursive generation        *" ;
        cout << endl << "* 3. Permutation generator       *" ;
        cout << endl << "**********************************" ;
        cout << endl << "Input a choice(0, 1, 2, 3): " ;
        cin >> command ; // Ū�J���O 

    switch(command){
          	case 0 : break ; 
          
          	case 1 : // ���Ȥ@ : �H�u�j��v���ͫ��w�O��ƦC���]�ƲզX 
        		cout << endl << "Input number smaller than 92 : " ;
        		cin >> num ;
        		if ( num > 92 ) {
        			cout << endl << "Your input number is bigger than 92, so we do 92" ;
        			num = 92 ;
				} // �p�G�Ʀr�W�X92�A�N��92
				 
              	if( !act.Getact( 1, num, a, b, 1 ) ) break ; // �����Ȥ@
              	
            	break ;
                
          	case 2 : // ���ȤG : �H�u���j�v���ͫ��w�O��ƦC���]�ƲզX 
              	cout << endl << "Input number smaller than 92 : " ;
              	cin >> num ;
        		if ( num > 92 ) {
        			cout << endl << "Your input number is bigger than 92, so we do 92" ;
        			num = 92 ;
				} // �p�G�Ʀr�W�X92�A�N��92
				
              	if( !act.Getact( 2, num, a, b, 1 ) ) break ; // �����ȤG 
              
              	break ;
              
          	case 3 : // ���ȤT :  
          		
          		cout << endl << "Input number length( 0 ~ 9 ) : " ;
          		cin >> num ;
          		// if ( !act.Getact( 3, num, a, b, 1 )) break ;
          		// cout << endl << "Which numbers do you want to permutate randomly? : " ;
  				cT=clock() ;
  				
  				while ( !( num>1 && num<10 ) ) {
			  		cout << endl << "Input number length( 0~9 ) : " ;
			  		cin >> num ;
				} 

				P=0 ; // �����ƦC�ռ� 
				act.Select ( num, list, list1, temp, flag, 0, P, 0 ) ;
				cT=clock() - cT ;
				cout << "Recursion: " << cT*1000/CLOCKS_PER_SEC << "ms" << endl ;
  				break ;
              
        	default : cout << endl << "command does not exist !!" << endl ; // �S���o�ӫ��O 
        	
    } // end switch
    
    a = 1 ;
    b = 0 ;
    
  }while(command!=0); // break out the loop
  
  system ("pause") ; 
  return 0 ;
  
} //end main()

