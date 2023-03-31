#include <iostream>
using namespace std;
int** allocated, ** mx, ** need, * available, *done, *ans, p, r;
bool noAnswer=false;

void findSequence(){
int index=0;
bool notSafe;
for (int j = 0; j < p; j++) { 
        for (int i = 0; i < p; i++) { 
            if (done[i] == 0) { 
                notSafe = false;

                for (int j = 0; j < r; j++) { 
                    if (need[i][j] > available[j]){ 
                        notSafe= true;
                    } 
                }
                
                
                if(notSafe) continue;
                ans[index] = i;
                index++;
                for (int y = 0; y < r; y++) 
                    available[y] += allocated[i][y]; 
                done[i] = 1; 
                 
            } 
        } 
    } 
    
}


int main()
{
    cout<<"please enter the number of processes"<<endl;
    cin>>p;
    cout<<"please enter the number of resources"<<endl;
    cin>>r;
    
    allocated = new int*[p];
    for(int i = 0; i < p; ++i)
        allocated[i] = new int[r];
    
    mx = new int*[p];
    for(int i = 0; i < p; ++i)
        mx[i] = new int[r];
    
    need = new int*[p];
    for(int i = 0; i < p; ++i)
        need[i] = new int[r];
    
    available = new int [r];
    ans = new int [p];
    done = new int [p];
    for(int i = 0; i < r; ++i)
        done[i] = 0;
    
    cout<<"enter the number of instances that are available in all resorces in order and separated by spaces "<<endl;
    for(int i=0;i<r;i++)
        cin>>available[i];
    
    
    for(int i=0;i<p;i++){
        cout<<"enter the number of instances that are allocated to process P"<<i<<" of all "<<r<<" resources in order (R0,R1,R2..) and separated by spaces please"<<endl;
        for(int j=0;j<r;j++){
            cin>>allocated[i][j];
        }
    }
    
    for(int i=0;i<p;i++){
            cout<<"how many instances of all "<<r<<" resources  is process P"<<i<<" gonna need MAXIMUM (in order and separated by spaces) ?"<<endl;
            for(int j=0;j<r;j++){
            cin>>mx[i][j];
            }
    }
    
    
    for (int i = 0; i < p; i++) { 
        for (int j = 0; j < r; j++) 
            need[i][j] = mx[i][j] - allocated[i][j]; 
    } 
    
    
    findSequence ();
    
    for(int i=0;i<p;i++)
        if(done[i] != 1) noAnswer=true;
        
    if(noAnswer) cout<<"there is no safe sequence :("<<endl;
    
    else{
    cout << "the safe Sequence is < "; 
    for (int i = 0; i < p - 1; i++) 
        cout << ans[i] << ", "; 
    cout << ans[p - 1] <<">"<<endl; 
    }
      
      
    }