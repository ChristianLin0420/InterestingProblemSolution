class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2 ) {
        
        int n = arr1.size() ; 
        int m = arr2.size() ;
        
        if ( n == 0 and m == 0  ) {
                return 0.0000 ; 
        }
        
        if ( n == 0 ) {
            if ( m & 1 )
                    return double ( arr2 [ m / 2 ]  );
            
            return  double ( arr2 [ m / 2 ]  + arr2 [ m / 2 - 1 ] )/ 2.0 ;
        }
        
        
        
        if ( m == 0 ) {
            if ( n & 1 )
                    return double ( arr1 [ n / 2 ]  );
            
            return  double ( arr1 [ n / 2 ]  + arr1 [ n / 2 - 1 ] )/ 2.0 ;
        }
        
        if ( n > m ) {
            vector < int > temp = arr1 ; 
            arr1 = arr2 ;
            arr2 = temp ; 
            swap ( n , m ) ;
        }
        
        int low = 0 ; 
        int high  = n   ;
      
        while ( low <= high ) {   
            
            int i = low + ( high - low ) / 2 ; 
            int j = ( m + n + 1 ) / 2 - i ; 
            
            int imaxi = i - 1 >= 0 ? arr1 [ i - 1 ] : INT_MIN ; 
            int jmaxi = j - 1 >= 0 ? arr2 [ j - 1 ] : INT_MIN ; 
            int imini = i == n ? INT_MAX : arr1 [ i ] ; 
            int jmini = j == m ? INT_MAX : arr2 [ j ] ;
            
            if ( jmaxi  <= imini and imaxi <= jmini ) {
                if ( (m + n) & 1 )
                        return double ( max ( imaxi , jmaxi ) ) ; 
                
                return  ( max ( imaxi , jmaxi ) + min ( imini , jmini ) )/ 2.0 ; 
                
            } else if ( jmaxi > imini ) {
                low = i + 1 ; 
            } else { 
                high = i - 1 ; 
            }            
        }
        
        return 000.00 ; 
        
    }
};