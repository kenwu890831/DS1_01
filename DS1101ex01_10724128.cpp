// 10724128 吳宇哲

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
    	while ( time <= num ) { // 列出費氏數列(迴圈) 
    		temp = a + b ;
    		b = a ; 
    		write( temp, time ) ;
    		LoopDiv( temp ) ;
    		a = temp ;
    		time++ ;
		}
		
		return true ;
    	
	} // 任務一
	
    if( n == 2 ) {
    	if ( time <= num ) { // 列出費氏數列(遞迴)
    		temp = a + b ;
    		write( temp, time ) ;
    		unsigned long long sqrtNum1 = sqrt( temp ) ; 
			unsigned long long sqrtNum2 = sqrt( temp ) ; // 開根號 
    		RecurDiv( temp, sqrtNum1, sqrtNum2, 0, false ) ;
    		
    		Getact( 2, num, temp, a, time + 1 ) ; // 遞迴 
		}
		
		return true ;
    	
	} // 任務二 
	
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
// 迴圈的找差距最小因數

	unsigned long long sqrtNum1 = 0 ; // 因數1 
	unsigned long long sqrtNum2 = 0 ; // 因數2 
	unsigned long long loopCount = 0 ; // 迴圈執行數 
	sqrtNum1 = sqrt( temp ) ;
	sqrtNum2 = sqrt( temp ) ; // 開根號 
	if ( temp == sqrtNum1 * sqrtNum2 ) { // 如果兩因數相乘等於該費氏數列的數 
		cout << " = " << sqrtNum1 << " * " << sqrtNum2 << " (Inner loop: " << loopCount << " times)";
	}
	else { // 如果未達成 
		bool check = false ;
		while ( !check ) { // 找出符合條件的因數 
			
			loopCount++ ;
			
			if ( temp % sqrtNum2 == 0 ) { // 取餘數
				cout << " = " << sqrtNum2 << " * " << (temp/sqrtNum2) << " (Inner loop: " << loopCount << " times)";
				check = true ;
			}
			
			sqrtNum2 -- ;
		}
	}
}

bool RecurDiv( unsigned long long temp, unsigned long long sqrtNum1, unsigned long long sqrtNum2, unsigned long long loopCount, bool check ) {
// 遞迴的找差距最小因數

	if ( temp == sqrtNum1 * sqrtNum2 && check == false ) {  // 如果兩因數相乘等於該費氏數列的數
		cout << " = " << sqrtNum1 << " * " << sqrtNum2 << " (Inner loop: " << loopCount << " times)";
		check = true ;
		RecurDiv( temp, sqrtNum1, sqrtNum2-1 , loopCount, check ) ;
	}
	if ( temp != sqrtNum1 * sqrtNum2 && check == false ) { // 如果未達成 
		loopCount++ ;
		if ( temp % sqrtNum2 == 0 ) { // 取餘數
				cout << " = " << sqrtNum2 << " * " << (temp/sqrtNum2) << " (Inner loop: " << loopCount << " times)";
				check = true ;
		}
		RecurDiv( temp, sqrtNum1, sqrtNum2-1 , loopCount, check ) ; // 做遞迴 
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
		if( walk % n == 0) cout << "[" << P+1 <<"]" ; // 排列的組數
		cout << temp[walk] << " " ; // 唯一輸出窗口 
		Print( n, list, list1, temp, flag, i, P, walk+1 ) ;
	}
}

void Sort(int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk ) {
	// cout << endl << "in Sort" ;
	if ( walk<=9 ) {
		if ( flag[walk] ) Sort( n, list, list1, temp, flag, i, P, walk+1 ) ;
		flag[walk] = true ;
		temp[i] = list1[walk] ;
	 	Select (n, list, list1, temp, flag, i+1, P, walk) ; //遞迴下一個位置 
	 	flag[walk] = false ;
		Sort( n, list, list1, temp, flag, i, P, walk+1 ) ;
	}
}
*/


void Select (int n, int list[], int list1[], int temp[], bool flag[], int i, int &P, int walk) {
	if (i==n){ 
		
		for (int walk = 0; walk<n; walk++) {
			if(walk%n == 0) cout << "[ " << P+1 <<"] " ; // 排列的組數
			cout << temp[walk] << " " ; // 唯一輸出窗口 
		} // for  
		
		
		cout << endl ;
		P++ ;
	} // if 
	
	else { 
		
		for (int walk=0; walk<=9; walk++) {
			if (flag[walk]) continue ;
			flag[walk] = true ;
			temp[i] = list1[walk] ;
	 		Select (n, list, list1, temp, flag, i+1, P, walk) ; //遞迴下一個位置 
	 		flag[walk] = false ;
	 	} // for 排序 
	 	
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
    
    int list[20] = {0} ; // 初始化陣列 
    int list1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
    int temp[20] = {0} ; //暫存, 初始化
    bool flag[20] = {0} ; //判斷用
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
        cin >> command ; // 讀入指令 

    switch(command){
          	case 0 : break ; 
          
          	case 1 : // 任務一 : 以「迴圈」產生指定費氏數列的因數組合 
        		cout << endl << "Input number smaller than 92 : " ;
        		cin >> num ;
        		if ( num > 92 ) {
        			cout << endl << "Your input number is bigger than 92, so we do 92" ;
        			num = 92 ;
				} // 如果數字超出92，就做92
				 
              	if( !act.Getact( 1, num, a, b, 1 ) ) break ; // 做任務一
              	
            	break ;
                
          	case 2 : // 任務二 : 以「遞迴」產生指定費氏數列的因數組合 
              	cout << endl << "Input number smaller than 92 : " ;
              	cin >> num ;
        		if ( num > 92 ) {
        			cout << endl << "Your input number is bigger than 92, so we do 92" ;
        			num = 92 ;
				} // 如果數字超出92，就做92
				
              	if( !act.Getact( 2, num, a, b, 1 ) ) break ; // 做任務二 
              
              	break ;
              
          	case 3 : // 任務三 :  
          		
          		cout << endl << "Input number length( 0 ~ 9 ) : " ;
          		cin >> num ;
          		// if ( !act.Getact( 3, num, a, b, 1 )) break ;
          		// cout << endl << "Which numbers do you want to permutate randomly? : " ;
  				cT=clock() ;
  				
  				while ( !( num>1 && num<10 ) ) {
			  		cout << endl << "Input number length( 0~9 ) : " ;
			  		cin >> num ;
				} 

				P=0 ; // 紀錄排列組數 
				act.Select ( num, list, list1, temp, flag, 0, P, 0 ) ;
				cT=clock() - cT ;
				cout << "Recursion: " << cT*1000/CLOCKS_PER_SEC << "ms" << endl ;
  				break ;
              
        	default : cout << endl << "command does not exist !!" << endl ; // 沒有這個指令 
        	
    } // end switch
    
    a = 1 ;
    b = 0 ;
    
  }while(command!=0); // break out the loop
  
  system ("pause") ; 
  return 0 ;
  
} //end main()

