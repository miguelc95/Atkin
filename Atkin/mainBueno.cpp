//
//  main.cpp
//  Atkin
//
//  Created by Miguel Cuellar on 1/27/16.
//  Copyright © 2016 Miguel Cuellar. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;
int main(int argc, const char * argv[]) {
    int n=100001,M,izq,der,dato,sup=320;;
    vector<bool> bCriba(100001);
    vector<int> Numeros;
    bCriba[2] = true;
    bCriba[3] = true;
    Numeros.push_back(0);
    Numeros.push_back(1);
    Numeros.push_back(2);
    Numeros.push_back(3);
    Numeros.push_back(4);
    for (int ix=5; ix<100000;ix++) {
        Numeros.push_back(ix);
    }
    for (int i=5;i<=n;i++)
    {
        bCriba[i]=false;
    }
    for (int ix=1;ix<=sup;ix++)
    {
        for (int iy=1;iy<=sup;iy++)
        {
            int num=(4*ix*ix+iy*iy);
            if (num<=n&&(num%12==1||num%12==5))
            {
                bCriba[num]=true;
            }
            num=(3*ix*ix+iy*iy);
            if (num<=n&&(num%12==7))
            {
                bCriba[num]=true;
            }
            
            if (ix>iy)
            {
                num=(3*ix*ix-iy*iy);
                if (num<=n&&(num%12==11))
                {
                    bCriba[num]=true;
                }
            }
        }
    }
    for (int i=5;i<=sup;i++)
    {
        if (bCriba[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                bCriba[j]=false;
            }
        }
    }
   /* for (int ix=0; ix<24; ix++) {

      if (bCriba[ix]) {
            cout<<Numeros[ix]<<" ";
      }
    }
    */
    cin>>M;
    for (int i=0; i<M;i++) {
        cin>>dato;
        izq=dato;
        der=dato;
        if (bCriba[dato]==true) {
            cout<<dato<<" "<<dato<<endl;
        }
        else{
            while (bCriba[izq]!=true) {
                izq--;
            }
            while (bCriba[der]!=true) {
                der++;
            }
            cout<<Numeros[izq]<<" "<<Numeros[der]<<endl;

        }
        
    }
    return 0;
    
}
