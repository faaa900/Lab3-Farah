#include <stdio.h>
#include <math.h>

int main()
{
    int balance=1000;
    int transactions[]={200,-150,-500,-400,-50,-200,300};
    int n=sizeof(transactions)/sizeof(transactions[0]);
    int tobeprocessed[n];
    int Unprocessed_count=0;
    for(int i=0;i<n;i++){
        if (transactions[i]>0){
            balance+=transactions[i];
        }
        else if (transactions[i]<0){
            if (fabs(transactions[i])<balance){
                balance+=transactions[i];
            }
            else if (fabs(transactions[i])>balance){
                tobeprocessed[Unprocessed_count]=transactions[i];
                Unprocessed_count++;
                continue;
                
            }
        }
        else if (balance==0){
            printf("Zero balance. No further transactions will be processed.");
            tobeprocessed[Unprocessed_count]=transactions[i];
            Unprocessed_count++;
            
            
        }
        
        
    }
    for(int i=0;i<Unprocessed_count;i++){
        printf(" %i withdrawal transaction(s) worth %i was not processed\n",i+1,tobeprocessed[i]);
    }
    
    printf("The final balance is %i",balance);
    


    return 0;
}