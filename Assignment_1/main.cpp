/* © ALL RIGHTS RESERVED BY VEDANT DHADGE*/

/* you are given an interger array a of size n, sorted in non decreasin order,you are also given an interger target, you rtask is to write a func to search for
target in the array a if it exists, if yes then return its index. Use the concept of linear search and write program in cpp*/

/*
    EXTRA FEATURE:
    This program also returns ALL LOCATIONS OF TARGET using a new cpp ds type VECTOR.
*/

#include<iostream>
using namespace std;

//ENABLES THE USE OF VECTOR
#include<vector>

//FUNCTION TO GET FIRST OCCURANCE OF TARGET
int first_instance(int arr[], int tar, int arrSize){

    for(int i=0;i<arrSize;i++){

            if(arr[i]==tar){
            
                return i;
            }
    }

    return -1;
}

//FUNCTION TO GET LAST OCCURANCE OF TARGET
int last_instance(int arr[], int tar, int arrSize){
    
    int ret = -1;
        for(int i=0;i<arrSize;i++){

            if(arr[i]==tar){
                ret = i;
            }
    }

    if(ret == -1){
        return -1;
    }
    else{
        return ret;
    }

}

//FUNCTION TO GET LOCATION OF ALL OCCURANCES OF TARGET
vector<int> srch_dupli(int arr[], int tar, int arrSize){

    vector <int> result;
    for(int i=0;i<arrSize;i++){

            if(arr[i]==tar){
            
                result.push_back(i);
            }
    }

    return result;
}



int main(){

    

    //DECLARATIONS
    int arr_size,target;
    

    //INPUTING ARRAY SIZE, ARRAY ELEMENTS AND TARGET
            
            cout<<"Enter size of array: ";
            cin>> arr_size;

            int a[arr_size];

            cout<<"Enter array elements: ";
            //TAKING USER INPUT
            for(int i=0;i<arr_size;i++) cin>>a[i];

            
            cout<<"Enter Target: ";
            cin>> target;


    //USER UI
    int user_choice, flag = 1;
    
      
      while(flag){
        
        //USER MENUE
        cout<<"\n\nMAIN MENUE\n\n\t1. Add new array\n\t2. Search target\n\t3. Search first and last occurances of target\n\t4. Search locations of all duplicates\n\t5. Exit\n\nEnter your choice: ";
        cin>> user_choice;
        
        switch(user_choice){

            case 1:{

                //INPUTING ARRAY SIZE, ARRAY ELEMENTS AND TARGET
                
                cout<<"Enter size of array: ";
                cin>> arr_size;
                
                //TAKING USER INPUT
                cout<<"Enter array elements: ";
                for(int i=0;i<arr_size;i++) cin>>a[i];
                
                cout<<"Enter Target: ";
                cin>> target;
            }
            break;
            
            case 2:{

                int first_ins = first_instance(a,target,arr_size);

                if(first_ins!=-1)
                    cout<<"\nElement found at position "<<first_ins<<endl; 
                else
                    cout<<"\n\nTarget element does not exist in the given array\n";
                }
            break;     


            //CASE HANDELING FRIST AND LAST OCCURANCE OF TARGET
            case 3:{
                
                int first_ins = first_instance(a,target,arr_size);
                int last_ins = last_instance(a,target,arr_size);

            
                if(first_ins!=-1){
                    
                    //CHECKING IF TARGET OCCURS ONLY ONCE
                    if(first_ins == last_ins){
                        cout<<"\n\nOnly one instance of target found at location: "<<first_ins<<endl;
                    }
                    else{
                        cout<<"\n\nFirst occurance of target at: "<<first_ins<<endl;
                        cout<<"Last occurance of target at "<<last_ins<<endl;
                    }
                }
                else
                    cout<<"\n\nTarget element does not exist in the given array\n"; 
                }
            break; 
            

            //CASE HANDELING DISPLAYING ALL LOCATIONS OF TARGET
            case 4:{

                //calling func to search location of dublicates of target;
                vector<int> resv = srch_dupli(a,target,arr_size);

                cout<<"\nDuplicates of target found at location: ";
                for(int i = 0; i < resv.size();i++){
                    cout<<resv[i]<<"\t";
                }
            }
            break;

            //CASE HANDELING EXITING THE PROGRAM
            case 5:
                flag = 0;
                break;
        } 
    }
  return 0;
}
/* © ALL RIGHTS RESERVED BY VEDANT DHADGE*/
