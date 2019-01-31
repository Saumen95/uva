#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <cstdlib>
#include <iostream>

using namespace std;

#define ll long long /*__int64 */

setmp;
int p[] = {0,0,2,3,0,5,0,7,0,0,0,11,0,13,0,0,0,17,0,19};
int sorted[] = {1,2,3,4,5,6,7,8};

typedef struct{
 int a[8];
 int step;
}data;

int is_prime(int n){
 return p[n];
}

bool is_sorted(int a[]){
 for(int i = 0; i < 8; i++){
  if(abs(a[i]) != sorted[i])
   return false;
 }
 return true;
}

void make_visited(int a[]){
 ll val = 0; 
 
 for(int i = 0; i < 8; i++){
  val *= 10;
  val += abs(a[i]);   
 }

 mp.insert(val);
}

int is_visited(int a[]){
 ll val = 0; 
 
 for(int i = 0; i < 8; i++){
  val *= 10;
  val += abs(a[i]);   
 }

 return mp.find(val) != mp.end();
}

void generate_step(int i, int j, int a[], bool before){
 int tmp;
 if(before){
  if(i > j){
   tmp = a[i];
   while(i > j){
    a[i] = a[i-1];
    i--;
   }
   a[i] = tmp;

  }else{
   tmp = a[i];
   while(i < j-1){
    a[i] = a[i+1];
    i++;
   }
   a[i] = tmp;
  }
 }else{
  if(i > j){
   tmp = a[i];
   while(i > j+1){
    a[i] = a[i-1];
    i--;
   }
   a[i] = tmp;

  }else{
   tmp = a[i];
   while(i < j){
    a[i] = a[i+1];
    i++;
   }
   a[i] = tmp;
  }
 }
}

void print(int a[]){
 for(int i = 0; i < 8; i++)
  printf("%d",a[i]);
 printf("\n");
}

int main(){
 int i,j,cas = 1;

 data temp,current;

 //freopen("i.txt", "r", stdin);

 while(scanf("%d", &temp.a[0]) && temp.a[0]){
  for(i = 1; i < 8; i++)
   scanf("%d", &temp.a[i]);

  mp.clear();
  make_visited(temp.a);
  temp.step = 0;
  
  queueq;
  q.push(temp);
  while(1){
   if(q.empty()){
    printf("Case %d: %d\n", cas++, -1);
    break;
   }

   current = q.front();
   q.pop();

   if(is_sorted(current.a)){
    printf("Case %d: %d\n", cas++, current.step);
    break;
   }   
   
   for(i = 0; i < 8; i++){
    if(current.a[i] < 0){
     for(j = 0; j < 8; j++){
      if(current.a[j] > 0 && is_prime(abs(current.a[i]) + current.a[j])){       

       if(abs(current.a[i]) < abs(current.a[j])){
        temp = current;
        generate_step(i,j,temp.a, true);
        if(!is_visited(temp.a)){
         make_visited(temp.a);
         temp.step++;
         q.push(temp);
        }
       }

       if(abs(current.a[j]) < abs(current.a[i])){
        temp = current;
        generate_step(j,i,temp.a, true);
        if(!is_visited(temp.a)){
         make_visited(temp.a);
         temp.step++;
         q.push(temp);
        }
       }

       if(abs(current.a[i]) > abs(current.a[j])){
        temp = current;
        generate_step(i,j,temp.a, false);
        if(!is_visited(temp.a)){
         make_visited(temp.a);
         temp.step++;
         q.push(temp);
        }
       }

       if(abs(current.a[j]) > abs(current.a[i])){
        temp = current;
        generate_step(j,i,temp.a, false);
        if(!is_visited(temp.a)){
         make_visited(temp.a);
         temp.step++;
         q.push(temp);
        }
       }
      }
     }
    }
   }


    
  }
 }

 return 0;
}