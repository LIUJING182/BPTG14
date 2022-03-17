#include <iostream>
#include <helib/helib.h>
#include "Eval_DT.h"
using namespace std;
using namespace helib;
using namespace NTL;
void RunningTime_Eval_DT(int index_tree);
void Get_m_bits(long &m , long &bits, int index_tree);
int main() {
    int index;
    int depth;
    cout<< "1. Breast Cancer Data  2. Thoracic Surgery Data "<< endl;
    cout<< "Enter the index (1 or 2) of the data set: "<< endl;
    cin>> index;
    cout<< "Enter the depth (3, 4, 5, 6) of the tree: "<< endl;
    cin>> depth;

    int index_tree;
    index_tree=(index-1)*4+depth-2;
    RunningTime_Eval_DT(index_tree);
    return 0;
}

void RunningTime_Eval_DT(int index_tree)
{
    long num_not_leaf_node = 20;
    long num_leaf_node = 20;

    vector<long> b(num_not_leaf_node);
    vector<long> c(num_leaf_node);
    for(int i=0;i<num_not_leaf_node;i++)
    {
        b[i]=random()%2;
    }
    for(int i=0;i<num_leaf_node;i++)
    {
        c[i]=random()%2;
    }
    long m,bits;
    Get_m_bits(m,bits,index_tree);


    helib::Context context = helib::ContextBuilder<helib::BGV>().m(m).bits(bits).r(1).c(2).build();

    SecKey secretKey(context);
    secretKey.GenSecKey();
    const PubKey &publicKey = secretKey;

    Ctxt single_cipher(publicKey);
    Ctxt cipher_1(publicKey);
    Ctxt res(publicKey);
    PtxtArray p(context, 1);
    p.encrypt(cipher_1);
    vector<Ctxt> cipher_b(num_not_leaf_node, single_cipher);
    vector<Ctxt> cipher_c(num_leaf_node, single_cipher);
    for (int i = 0; i < num_not_leaf_node; i++) {
        PtxtArray p(context, b[i]);
        p.encrypt(cipher_b[i]);
    }
    for (int i = 0; i < num_leaf_node; i++) {
        PtxtArray p(context, c[i]);
        p.encrypt(cipher_c[i]);
    }

    double time;
    int cyctimes=1;
    auto Time= new double[cyctimes];
    for(int i=0;i<cyctimes;i++)
    {
        time=GetTime();
        Eval_DT(res,cipher_b,cipher_c,index_tree);
        time=GetTime()-time;
        Time[i]=time*1000;
    }
    double eval_time=0;
    double stdev=0;
    DataProcess(eval_time,stdev,Time,cyctimes);
    cout<<"the server's running time: "<<eval_time<<" ms\n";



    //dec
    for(int i=0;i<cyctimes;i++)
    {
        time=GetTime();
        PtxtArray temp_res(context);
        temp_res.decrypt(res, secretKey);
        vector<long> classes;
        temp_res.store(classes);
        time=GetTime()-time;
        Time[i]=time*1000;
    }
    PtxtArray temp_res(context);
    temp_res.decrypt(res, secretKey);
    vector<long> classes;
    temp_res.store(classes);
    //cout<<"res:"<<classes[0]<<"\n";


    double dec_time=0;
    stdev=0;
    DataProcess(dec_time,stdev,Time,cyctimes);
    cout<<"the client's running time: "<<dec_time<<" ms\n";
}

void Get_m_bits(long &m , long &bits, int index_tree)
{
    int d=0;
    if(index_tree==1||index_tree==5)
    {
        d=3;
    }
    if(index_tree==2||index_tree==6)
    {
        d=4;
    }
    if(index_tree==3||index_tree==7)
    {
        d=5;
    }
    if(index_tree==4||index_tree==8)
    {
        d=6;
    }

    switch(d)
    {
        case 3:
            m = 10897;
            bits = 120;
            break;
        case 4:
            m = 10897;
            bits = 160;
            break;
        case 5:
            m = 13019;
            bits = 200;
            break;
        case 6:
            m = 17711;
            bits = 240;
            break;
        default :
            cout<<"*********************ERROR!*********************"<<"\n";
            break;
    }
}