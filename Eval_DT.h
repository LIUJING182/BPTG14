#ifndef DT_BGV_EVAL_DT_H
#define DT_BGV_EVAL_DT_H

#endif //DT_BGV_EVAL_DT_H

#include <iostream>
#include <helib/helib.h>

using namespace std;
using namespace helib;
using namespace NTL;

void Mult2(Ctxt &res, Ctxt x1, Ctxt x2);

void Mult3(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3);

void Mult4(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4);

void Mult5(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4, Ctxt x5);

void Mult6(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4, Ctxt x5, Ctxt x6);

void Eval_DT(Ctxt &res, vector<Ctxt> b, vector<Ctxt> c, int index_tree) {
    Ctxt temp1=res;
    if(index_tree==1)
    {
        //c2 + b1*c1 - b1*c2 - b2*c2 + b2*c3 + b1*b2*c2 - b1*b2*c3
        res+=c[1];
        Mult2(temp1,b[0],c[0]);
        res+=temp1;
        Mult2(temp1,b[0],c[1]);
        res-=temp1;
        Mult2(temp1,b[1],c[1]);
        res-=temp1;
        Mult2(temp1,b[1],c[2]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[1]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[2]);
        res-=temp1;
    }

    if(index_tree==2)
    {
        //c3 + b1*c1 - b1*c3 + b2*c2 - b2*c3 - b3*c3 + b3*c4
        res+=c[2];
        Mult2(temp1,b[0],c[0]);
        res+=temp1;
        Mult2(temp1,b[0],c[2]);
        res-=temp1;
        Mult2(temp1,b[1],c[1]);
        res-=temp1;
        Mult2(temp1,b[1],c[2]);
        res+=temp1;
        Mult2(temp1,b[2],c[2]);
        res+=temp1;
        Mult2(temp1,b[2],c[3]);
        res+=temp1;
        // - b1*b2*c2 + b1*b2*c3 + b1*b3*c3 - b1*b3*c4 + b2*b3*c3 - b2*b3*c4 - b1*b2*b3*c3 + b1*b2*b3*c4
        Mult3(temp1,b[0],b[1],c[1]);
        res-=temp1;
        Mult3(temp1,b[0],b[1],c[2]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[2]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[3]);
        res-=temp1;
        Mult3(temp1,b[1],b[2],c[2]);
        res+=temp1;
        Mult3(temp1,b[1],b[2],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[2],c[2]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[2],c[3]);
        res+=temp1;
    }

    if(index_tree==3)
    {
        //c2 + b0*c0 - b0*c2 + b1*c1 - b1*c2 - b2*c2 + b2*c3
        res+=c[2];
        Mult2(temp1,b[0],c[0]);
        res+=temp1;
        Mult2(temp1,b[0],c[2]);
        res-=temp1;
        Mult2(temp1,b[1],c[1]);
        res+=temp1;
        Mult2(temp1,b[1],c[2]);
        res-=temp1;
        Mult2(temp1,b[2],c[2]);
        res-=temp1;
        Mult2(temp1,b[2],c[3]);
        res+=temp1;
        // - b0*b1*c1 + b0*b1*c2 + b0*b2*c2 - b0*b2*c3 + b1*b2*c2 - b1*b2*c3 - b2*b3*c3 + b2*b3*c4
        Mult3(temp1,b[0],b[1],c[1]);
        res-=temp1;
        Mult3(temp1,b[0],b[1],c[2]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[2]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[3]);
        res-=temp1;
        Mult3(temp1,b[1],b[2],c[2]);
        res+=temp1;
        Mult3(temp1,b[1],b[2],c[3]);
        res-=temp1;
        Mult3(temp1,b[2],b[3],c[3]);
        res-=temp1;
        Mult3(temp1,b[2],b[3],c[4]);
        res+=temp1;

        // - b0*b1*b2*c2 + b0*b1*b2*c3 + b0*b2*b3*c3 - b0*b2*b3*c4 + b1*b2*b3*c3 - b1*b2*b3*c4
        Mult4(temp1,b[0],b[1],b[2],c[2]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[2],c[3]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[3],c[3]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[3],c[4]);
        res-=temp1;
        Mult4(temp1,b[1],b[2],b[3],c[3]);
        res+=temp1;
        Mult4(temp1,b[1],b[2],b[3],c[4]);
        res-=temp1;

        // - b0*b1*b2*b3*c3 + b0*b1*b2*b3*c4
        Mult5(temp1,b[0],b[1],b[2],b[3],c[3]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[2],b[3],c[4]);
        res+=temp1;

    }

    if(index_tree==4)
    {
        //c3 + b0*c0 + b1*c1 - b0*c3 - b1*c3 + b2*c2 - b2*c3 - b3*c3 + b3*c4
        res+=c[3];
        Mult2(temp1,b[0],c[0]);
        res+=temp1;
        Mult2(temp1,b[1],c[1]);
        res+=temp1;
        Mult2(temp1,b[0],c[3]);
        res-=temp1;
        Mult2(temp1,b[1],c[3]);
        res-=temp1;
        Mult2(temp1,b[2],c[2]);
        res+=temp1;
        Mult2(temp1,b[2],c[3]);
        res-=temp1;
        Mult2(temp1,b[3],c[3]);
        res-=temp1;
        Mult2(temp1,b[3],c[4]);
        res+=temp1;



        // - b0*b1*c1 + b0*b1*c3 - b0*b2*c2 + b0*b2*c3
        Mult3(temp1,b[0],b[1],c[1]);
        res-=temp1;
        Mult3(temp1,b[0],b[1],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[2]);
        res-=temp1;
        Mult3(temp1,b[0],b[2],c[3]);
        res+=temp1;

        // - b1*b2*c2 + b0*b3*c3 + b1*b2*c3 - b0*b3*c4
        Mult3(temp1,b[1],b[2],c[2]);
        res-=temp1;
        Mult3(temp1,b[0],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[1],b[2],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[3],c[4]);
        res-=temp1;

        // + b1*b3*c3 - b1*b3*c4 + b2*b3*c3 - b2*b3*c4
        Mult3(temp1,b[1],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[1],b[3],c[4]);
        res-=temp1;
        Mult3(temp1,b[2],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[2],b[3],c[4]);
        res-=temp1;

        // - b3*b4*c4 + b3*b4*c5
        Mult3(temp1,b[3],b[4],c[4]);
        res-=temp1;
        Mult3(temp1,b[3],b[4],c[5]);
        res+=temp1;



        // + b0*b1*b2*c2 - b0*b1*b2*c3 - b0*b1*b3*c3 + b0*b1*b3*c4
        Mult4(temp1,b[0],b[1],b[2],c[2]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[2],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[3],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[3],c[4]);
        res+=temp1;

        // - b0*b2*b3*c3 + b0*b2*b3*c4 - b1*b2*b3*c3 + b1*b2*b3*c4
        Mult4(temp1,b[0],b[2],b[3],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[3],c[4]);
        res+=temp1;
        Mult4(temp1,b[1],b[2],b[3],c[3]);
        res-=temp1;
        Mult4(temp1,b[1],b[2],b[3],c[4]);
        res+=temp1;

        // + b0*b3*b4*c4 - b0*b3*b4*c5 + b1*b3*b4*c4 - b1*b3*b4*c5
        Mult4(temp1,b[0],b[3],b[4],c[4]);
        res+=temp1;
        Mult4(temp1,b[0],b[3],b[4],c[5]);
        res-=temp1;
        Mult4(temp1,b[1],b[3],b[4],c[4]);
        res+=temp1;
        Mult4(temp1,b[1],b[3],b[4],c[5]);
        res-=temp1;

        // + b2*b3*b4*c4 - b2*b3*b4*c5
        Mult4(temp1,b[2],b[3],b[4],c[4]);
        res+=temp1;
        Mult4(temp1,b[2],b[3],b[4],c[5]);
        res-=temp1;



        // + b0*b1*b2*b3*c3 - b0*b1*b2*b3*c4 - b0*b1*b3*b4*c4 + b0*b1*b3*b4*c5
        Mult5(temp1,b[0],b[1],b[2],b[3],c[3]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[2],b[3],c[4]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[3],b[4],c[4]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[3],b[4],c[5]);
        res+=temp1;

        // - b0*b2*b3*b4*c4 + b0*b2*b3*b4*c5 - b1*b2*b3*b4*c4 + b1*b2*b3*b4*c5
        Mult5(temp1,b[0],b[2],b[3],b[4],c[4]);
        res-=temp1;
        Mult5(temp1,b[0],b[2],b[3],b[4],c[5]);
        res+=temp1;
        Mult5(temp1,b[1],b[2],b[3],b[4],c[4]);
        res-=temp1;
        Mult5(temp1,b[1],b[2],b[3],b[4],c[5]);
        res+=temp1;



        // + b0*b1*b2*b3*b4*c4 - b0*b1*b2*b3*b4*c5
        Mult6(temp1,b[0],b[1],b[2],b[3],b[4],c[4]);
        res+=temp1;
        Mult6(temp1,b[0],b[1],b[2],b[3],b[4],c[5]);
        res-=temp1;
    }

    if(index_tree==5)
    {
        //c0 - b0*c0 - b1*c0 + b0*c2 + b1*c1 + b0*b1*c0 - b0*b1*c1 - b0*b2*c2 + b0*b2*c3
        res+=c[0];
        Mult2(temp1,b[0],c[0]);
        res-=temp1;
        Mult2(temp1,b[1],c[0]);
        res-=temp1;
        Mult2(temp1,b[0],c[2]);
        res+=temp1;
        Mult2(temp1,b[1],c[1]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[0]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[1]);
        res-=temp1;
        Mult3(temp1,b[0],b[2],c[2]);
        res-=temp1;
        Mult3(temp1,b[0],b[2],c[3]);
        res+=temp1;
    }

    if(index_tree==6)
    {
        //c0 - b0*c0 - b1*c0 + b1*c2 - b3*c0 + b0*c4 + b3*c1
        res+=c[0];
        Mult2(temp1,b[0],c[0]);
        res-=temp1;
        Mult2(temp1,b[1],c[0]);
        res-=temp1;
        Mult2(temp1,b[1],c[2]);
        res+=temp1;
        Mult2(temp1,b[3],c[0]);
        res-=temp1;
        Mult2(temp1,b[0],c[4]);
        res+=temp1;
        Mult2(temp1,b[3],c[1]);
        res+=temp1;


        // + b0*b1*c0 - b0*b1*c2 + b0*b3*c0 - b0*b3*c1
        Mult3(temp1,b[0],b[1],c[0]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[2]);
        res-=temp1;
        Mult3(temp1,b[0],b[3],c[0]);
        res+=temp1;
        Mult3(temp1,b[0],b[3],c[1]);
        res-=temp1;

        // + b1*b3*c0 - b1*b3*c1 - b0*b2*c4 - b1*b4*c2
        Mult3(temp1,b[1],b[3],c[0]);
        res+=temp1;
        Mult3(temp1,b[1],b[3],c[1]);
        res-=temp1;
        Mult3(temp1,b[0],b[2],c[4]);
        res-=temp1;
        Mult3(temp1,b[1],b[4],c[2]);
        res-=temp1;

        // + b0*b2*c6 + b1*b4*c3 - b0*b5*c4 + b0*b5*c5
        Mult3(temp1,b[0],b[2],c[6]);
        res+=temp1;
        Mult3(temp1,b[1],b[4],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[5],c[4]);
        res-=temp1;
        Mult3(temp1,b[0],b[5],c[5]);
        res+=temp1;


        // - b0*b1*b3*c0 + b0*b1*b3*c1 + b0*b1*b4*c2 - b0*b1*b4*c3
        Mult4(temp1,b[0],b[1],b[3],c[0]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[3],c[1]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[4],c[2]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[4],c[3]);
        res-=temp1;

        // + b0*b2*b5*c4 - b0*b2*b5*c5 - b0*b2*b6*c6 + b0*b2*b6*c7
        Mult4(temp1,b[0],b[2],b[5],c[4]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[5],c[5]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[6],c[6]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[6],c[7]);
        res+=temp1;
    }

    if(index_tree==7)
    {
        //c3 + b1*c0 - b0*c3 - b1*c3 + b3*c1 + b0*c5 - b3*c3 - b6*c3 + b6*c4
        res+=c[3];
        Mult2(temp1,b[1],c[0]);
        res+=temp1;
        Mult2(temp1,b[0],c[3]);
        res-=temp1;
        Mult2(temp1,b[1],c[3]);
        res-=temp1;
        Mult2(temp1,b[3],c[1]);
        res+=temp1;
        Mult2(temp1,b[0],c[5]);
        res+=temp1;
        Mult2(temp1,b[3],c[3]);
        res-=temp1;
        Mult2(temp1,b[6],c[3]);
        res-=temp1;
        Mult2(temp1,b[6],c[4]);
        res+=temp1;



        // - b0*b1*c0 + b0*b1*c3 - b0*b3*c1 - b1*b3*c1
        Mult3(temp1,b[0],b[1],c[0]);
        res-=temp1;
        Mult3(temp1,b[0],b[1],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[3],c[1]);
        res-=temp1;
        Mult3(temp1,b[1],b[3],c[1]);
        res-=temp1;

        // + b0*b3*c3 - b0*b2*c5 + b1*b3*c3 - b0*b4*c5
        Mult3(temp1,b[0],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[5]);
        res-=temp1;
        Mult3(temp1,b[1],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[4],c[5]);
        res-=temp1;

        // + b0*b6*c3 - b0*b6*c4 + b1*b6*c3 + b0*b2*c9
        Mult3(temp1,b[0],b[6],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[6],c[4]);
        res-=temp1;
        Mult3(temp1,b[1],b[6],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[9]);
        res+=temp1;

        // + b0*b4*c7 - b1*b6*c4 - b0*b7*c5 + b3*b6*c3
        Mult3(temp1,b[0],b[4],c[7]);
        res+=temp1;
        Mult3(temp1,b[1],b[6],c[4]);
        res-=temp1;
        Mult3(temp1,b[0],b[7],c[5]);
        res-=temp1;
        Mult3(temp1,b[3],b[6],c[3]);
        res+=temp1;

        // + b0*b7*c6 - b3*b6*c4
        Mult3(temp1,b[0],b[7],c[6]);
        res+=temp1;
        Mult3(temp1,b[3],b[6],c[4]);
        res-=temp1;



        // + b0*b1*b3*c1 - b0*b1*b3*c3 + b0*b2*b5*c2 - b0*b1*b6*c3
        Mult4(temp1,b[0],b[1],b[3],c[1]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[3],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[5],c[2]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[6],c[3]);
        res-=temp1;

        // + b0*b1*b6*c4 + b0*b2*b4*c5 - b0*b3*b6*c3 - b0*b2*b4*c7
        Mult4(temp1,b[0],b[1],b[6],c[4]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[4],c[5]);
        res+=temp1;
        Mult4(temp1,b[0],b[3],b[6],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[4],c[7]);
        res-=temp1;

        // + b0*b3*b6*c4 - b1*b3*b6*c3 + b0*b2*b7*c5 + b1*b3*b6*c4
        Mult4(temp1,b[0],b[3],b[6],c[4]);
        res+=temp1;
        Mult4(temp1,b[1],b[3],b[6],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[7],c[5]);
        res+=temp1;
        Mult4(temp1,b[1],b[3],b[6],c[4]);
        res+=temp1;

        // - b0*b2*b7*c6 - b0*b2*b5*c9 + b0*b4*b7*c5 - b0*b4*b7*c6
        Mult4(temp1,b[0],b[2],b[7],c[6]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[5],c[9]);
        res-=temp1;
        Mult4(temp1,b[0],b[4],b[7],c[5]);
        res+=temp1;
        Mult4(temp1,b[0],b[4],b[7],c[6]);
        res-=temp1;

        // - b0*b4*b8*c7 - b0*b2*b9*c9 + b0*b4*b8*c8 + b0*b2*b9*c10
        Mult4(temp1,b[0],b[4],b[8],c[7]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[9],c[9]);
        res-=temp1;
        Mult4(temp1,b[0],b[4],b[8],c[8]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[9],c[10]);
        res+=temp1;

        // + b0*b1*b3*b6*c3 - b0*b1*b3*b6*c4 - b0*b2*b4*b7*c5 + b0*b2*b4*b7*c6
        Mult5(temp1,b[0],b[1],b[3],b[6],c[3]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[3],b[6],c[4]);
        res-=temp1;
        Mult5(temp1,b[0],b[2],b[4],b[7],c[5]);
        res-=temp1;
        Mult5(temp1,b[0],b[2],b[4],b[7],c[6]);
        res+=temp1;
        // + b0*b2*b4*b8*c7 - b0*b2*b4*b8*c8 + b0*b2*b5*b9*c9 - b0*b2*b5*b9*c10
        Mult5(temp1,b[0],b[2],b[4],b[8],c[7]);
        res+=temp1;
        Mult5(temp1,b[0],b[2],b[4],b[8],c[8]);
        res-=temp1;
        Mult5(temp1,b[0],b[2],b[5],b[9],c[9]);
        res+=temp1;
        Mult5(temp1,b[0],b[2],b[5],b[9],c[10]);
        res-=temp1;

    }

    if(index_tree==8)
    {
        //c3 - b0*c3 - b1*c3 + b3*c1 + b0*c6 - b3*c3 - b6*c3 + b1*c9 + b6*c7
        res+=c[3];
        Mult2(temp1,b[0],c[3]);
        res-=temp1;
        Mult2(temp1,b[1],c[3]);
        res-=temp1;
        Mult2(temp1,b[3],c[1]);
        res+=temp1;
        Mult2(temp1,b[0],c[6]);
        res+=temp1;
        Mult2(temp1,b[3],c[3]);
        res-=temp1;
        Mult2(temp1,b[6],c[3]);
        res-=temp1;
        Mult2(temp1,b[1],c[9]);
        res+=temp1;
        Mult2(temp1,b[6],c[7]);
        res+=temp1;


        // + b0*b2*c0 + b0*b1*c3 - b0*b3*c1 - b1*b3*c1
        Mult3(temp1,b[0],b[2],c[0]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[3],c[1]);
        res-=temp1;
        Mult3(temp1,b[1],b[3],c[1]);
        res-=temp1;

        // + b0*b3*c3 + b0*b5*c2 + b1*b3*c3 - b0*b2*c6
        Mult3(temp1,b[0],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[5],c[2]);
        res+=temp1;
        Mult3(temp1,b[1],b[3],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[2],c[6]);
        res-=temp1;

        // + b0*b6*c3 - b0*b1*c9 + b1*b4*c5 + b1*b6*c3
        Mult3(temp1,b[0],b[6],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[1],c[9]);
        res-=temp1;
        Mult3(temp1,b[1],b[4],c[5]);
        res+=temp1;
        Mult3(temp1,b[1],b[6],c[3]);
        res+=temp1;

        // - b0*b5*c6 + b1*b7*c4 + b3*b6*c3 - b0*b6*c7
        Mult3(temp1,b[0],b[5],c[6]);
        res-=temp1;
        Mult3(temp1,b[1],b[7],c[4]);
        res+=temp1;
        Mult3(temp1,b[3],b[6],c[3]);
        res+=temp1;
        Mult3(temp1,b[0],b[6],c[7]);
        res-=temp1;

        // - b1*b4*c9 - b1*b6*c7 - b0*b9*c6 - b3*b6*c7
        Mult3(temp1,b[1],b[4],c[9]);
        res-=temp1;
        Mult3(temp1,b[1],b[6],c[7]);
        res-=temp1;
        Mult3(temp1,b[0],b[9],c[6]);
        res-=temp1;
        Mult3(temp1,b[3],b[6],c[7]);
        res-=temp1;

        // - b1*b7*c9 - b1*b11*c9 + b0*b9*c13 + b1*b11*c10
        Mult3(temp1,b[1],b[7],c[9]);
        res-=temp1;
        Mult3(temp1,b[1],b[11],c[9]);
        res-=temp1;
        Mult3(temp1,b[0],b[9],c[13]);
        res+=temp1;
        Mult3(temp1,b[1],b[11],c[10]);
        res+=temp1;

        // - b6*b10*c7 + b6*b10*c8
        Mult3(temp1,b[6],b[10],c[7]);
        res-=temp1;
        Mult3(temp1,b[6],b[10],c[8]);
        res+=temp1;



        // + b0*b1*b3*c1 - b0*b1*b3*c3 - b0*b2*b5*c2 - b0*b1*b4*c5 - b0*b1*b6*c3
        Mult4(temp1,b[0],b[1],b[3],c[1]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[3],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[5],c[2]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[4],c[5]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[6],c[3]);
        res-=temp1;

        // - b0*b1*b7*c4 - b0*b3*b6*c3 + b0*b2*b5*c6 - b1*b3*b6*c3 + b0*b1*b4*c9
        Mult4(temp1,b[0],b[1],b[7],c[4]);
        res-=temp1;
        Mult4(temp1,b[0],b[3],b[6],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[2],b[5],c[6]);
        res+=temp1;
        Mult4(temp1,b[1],b[3],b[6],c[3]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[4],c[9]);
        res+=temp1;

        // + b0*b1*b6*c7 + b0*b3*b6*c7 - b1*b4*b7*c4 + b0*b1*b7*c9 + b0*b2*b9*c6
        Mult4(temp1,b[0],b[1],b[6],c[7]);
        res+=temp1;
        Mult4(temp1,b[0],b[3],b[6],c[7]);
        res+=temp1;
        Mult4(temp1,b[1],b[4],b[7],c[4]);
        res-=temp1;
        Mult4(temp1,b[0],b[1],b[7],c[9]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[9],c[6]);
        res+=temp1;

        // + b1*b3*b6*c7 - b1*b4*b8*c5 + b0*b5*b9*c6 + b0*b1*b11*c9 + b1*b4*b7*c9
        Mult4(temp1,b[1],b[3],b[6],c[7]);
        res+=temp1;
        Mult4(temp1,b[1],b[4],b[8],c[5]);
        res-=temp1;
        Mult4(temp1,b[0],b[5],b[9],c[6]);
        res+=temp1;
        Mult4(temp1,b[0],b[1],b[11],c[9]);
        res+=temp1;
        Mult4(temp1,b[1],b[4],b[7],c[9]);
        res+=temp1;

        // - b0*b1*b11*c10 + b0*b6*b10*c7 - b0*b2*b9*c13 - b0*b6*b10*c8 + b1*b4*b8*c11
        Mult4(temp1,b[0],b[1],b[11],c[10]);
        res-=temp1;
        Mult4(temp1,b[0],b[6],b[10],c[7]);
        res+=temp1;
        Mult4(temp1,b[0],b[2],b[9],c[13]);
        res-=temp1;
        Mult4(temp1,b[0],b[6],b[10],c[8]);
        res-=temp1;
        Mult4(temp1,b[1],b[4],b[8],c[11]);
        res+=temp1;

        // + b1*b6*b10*c7 + b1*b4*b11*c9 - b1*b6*b10*c8 - b1*b4*b11*c10 + b3*b6*b10*c7
        Mult4(temp1,b[1],b[6],b[10],c[7]);
        res+=temp1;
        Mult4(temp1,b[1],b[4],b[11],c[9]);
        res+=temp1;
        Mult4(temp1,b[1],b[6],b[10],c[8]);
        res-=temp1;
        Mult4(temp1,b[1],b[4],b[11],c[10]);
        res-=temp1;
        Mult4(temp1,b[3],b[6],b[10],c[7]);
        res+=temp1;

        // - b0*b5*b9*c13 - b3*b6*b10*c8 + b1*b7*b11*c9 - b1*b7*b11*c10 - b0*b9*b13*c13
        Mult4(temp1,b[0],b[5],b[9],c[13]);
        res-=temp1;
        Mult4(temp1,b[3],b[6],b[10],c[8]);
        res-=temp1;
        Mult4(temp1,b[1],b[7],b[11],c[9]);
        res+=temp1;
        Mult4(temp1,b[1],b[7],b[11],c[10]);
        res-=temp1;
        Mult4(temp1,b[0],b[9],b[13],c[13]);
        res-=temp1;

        // + b0*b9*b13*c14
        Mult4(temp1,b[0],b[9],b[13],c[14]);
        res+=temp1;



        // + b0*b1*b3*b6*c3 + b0*b1*b4*b7*c4 - b0*b1*b3*b6*c7 + b0*b1*b4*b8*c5 - b0*b1*b4*b7*c9
        Mult5(temp1,b[0],b[1],b[3],b[6],c[3]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[4],b[7],c[4]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[3],b[6],c[7]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[4],b[8],c[5]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[4],b[7],c[9]);
        res-=temp1;

        // - b0*b2*b5*b9*c6 - b0*b1*b4*b8*c11 - b0*b1*b6*b10*c7 - b0*b1*b4*b11*c9 + b0*b1*b6*b10*c8
        Mult5(temp1,b[0],b[2],b[5],b[9],c[6]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[4],b[8],c[11]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[6],b[10],c[7]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[4],b[11],c[9]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[6],b[10],c[8]);
        res+=temp1;

        // + b0*b1*b4*b11*c10 - b0*b3*b6*b10*c7 + b0*b3*b6*b10*c8 - b1*b3*b6*b10*c7 - b0*b1*b7*b11*c9
        Mult5(temp1,b[0],b[1],b[4],b[11],c[10]);
        res+=temp1;
        Mult5(temp1,b[0],b[3],b[6],b[10],c[7]);
        res-=temp1;
        Mult5(temp1,b[0],b[3],b[6],b[10],c[8]);
        res+=temp1;
        Mult5(temp1,b[1],b[3],b[6],b[10],c[7]);
        res-=temp1;
        Mult5(temp1,b[0],b[1],b[7],b[11],c[9]);
        res-=temp1;

        // + b1*b3*b6*b10*c8 + b0*b1*b7*b11*c10 + b0*b2*b5*b9*c13 - b1*b4*b7*b11*c9 + b1*b4*b7*b11*c10
        Mult5(temp1,b[1],b[3],b[6],b[10],c[8]);
        res+=temp1;
        Mult5(temp1,b[0],b[1],b[7],b[11],c[10]);
        res+=temp1;
        Mult5(temp1,b[0],b[2],b[5],b[9],c[13]);
        res+=temp1;
        Mult5(temp1,b[1],b[4],b[7],b[11],c[9]);
        res-=temp1;
        Mult5(temp1,b[1],b[4],b[7],b[11],c[10]);
        res+=temp1;

        // - b1*b4*b8*b12*c11 + b0*b2*b9*b13*c13 + b1*b4*b8*b12*c12 - b0*b2*b9*b13*c14 + b0*b5*b9*b13*c13
        Mult5(temp1,b[1],b[4],b[8],b[12],c[11]);
        res-=temp1;
        Mult5(temp1,b[0],b[2],b[9],b[13],c[13]);
        res+=temp1;
        Mult5(temp1,b[1],b[4],b[8],b[12],c[12]);
        res+=temp1;
        Mult5(temp1,b[0],b[2],b[9],b[13],c[14]);
        res-=temp1;
        Mult5(temp1,b[0],b[5],b[9],b[13],c[13]);
        res+=temp1;

        // - b0*b5*b9*b13*c14
        Mult5(temp1,b[0],b[5],b[9],b[13],c[14]);
        res-=temp1;



        // + b0*b1*b3*b6*b10*c7 - b0*b1*b3*b6*b10*c8 + b0*b1*b4*b7*b11*c9 - b0*b1*b4*b7*b11*c10 + b0*b1*b4*b8*b12*c11
        Mult6(temp1,b[0],b[1],b[3],b[6],b[10],c[7]);
        res+=temp1;
        Mult6(temp1,b[0],b[1],b[3],b[6],b[10],c[8]);
        res-=temp1;
        Mult6(temp1,b[0],b[1],b[4],b[7],b[11],c[9]);
        res+=temp1;
        Mult6(temp1,b[0],b[1],b[4],b[7],b[11],c[10]);
        res-=temp1;
        Mult6(temp1,b[0],b[1],b[4],b[8],b[12],c[11]);
        res+=temp1;


        // - b0*b1*b4*b8*b12*c12 - b0*b2*b5*b9*b13*c13 + b0*b2*b5*b9*b13*c14
        Mult6(temp1,b[0],b[1],b[4],b[8],b[12],c[12]);
        res-=temp1;
        Mult6(temp1,b[0],b[2],b[5],b[9],b[13],c[13]);
        res-=temp1;
        Mult6(temp1,b[0],b[2],b[5],b[9],b[13],c[14]);
        res+=temp1;
    }
}

void Mult2(Ctxt &res, Ctxt x1, Ctxt x2) {
    x1 *= x2;
    res = x1;
}

void Mult3(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3) {
    x1 *= x2;
    x1 *= x3;
    res = x1;
}

void Mult4(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4) {
    x1 *= x2;
    x1 *= x3;
    x1 *= x4;
    res = x1;
}

void Mult5(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4, Ctxt x5) {
    x1 *= x2;
    x1 *= x3;
    x1 *= x4;
    x1 *= x5;
    res = x1;
}

void Mult6(Ctxt &res, Ctxt x1, Ctxt x2, Ctxt x3, Ctxt x4, Ctxt x5, Ctxt x6) {
    x1 *= x2;
    x1 *= x3;
    x1 *= x4;
    x1 *= x5;
    x1 *= x6;
    res = x1;
}

void DataProcess(double &mean, double &stdev,  double *Time,int cyctimes)
{
    double temp;
    double sum=0;
    for(int i=0;i<cyctimes;i++)
    {
        sum=sum+Time[i];
    }
    mean=sum/cyctimes;

    double temp_sum=0;
    for(int i=0;i<cyctimes;i++)
    {
        temp=mean-Time[i];
        temp=temp*temp;
        temp_sum=temp_sum+temp;
    }

    stdev=sqrt(temp_sum/cyctimes);
}