#include <iostream>
#include <string>
#include "encrypt.h"
using namespace std;

class decrpytion: public encrypt
{


private:
    string str;

    string decode(char wd[][2] ,char table[6][6],int ee)
    {
        int aa,bb,cc,dd;
        char decoded[ee][2],l1,l2,k1,k2,zz,yy;

        for(int i = 0; i < ee;i++)
        {
            l1 = wd[i][0];
            l2 = wd[i][1];
            // cout << l1<<" "<<l2<<" ";
            for(int j = 0; j < 6; j++)
            {

                for(int k = 0; k < 6; k++)
                {
                    if(l1 == table[j][k])
                    {
                        aa = j;
                        bb = k;
                        //cout<<aa<<" "<<bb<<endl;
                    }
                    else if(l2 == table[j][k])
                    {
                        cc = j;
                        dd = k;
                        //cout<<cc<<" "<<dd<<endl;
                    }
                }
            }
            if(bb != dd)
            {
                if(aa != cc && bb != dd)
                {
                    decoded[i][0] = table[cc][bb];
                    decoded[i][1] = table[aa][dd];
                }
                if(aa == cc && bb != dd)
                {
                    if(bb == 0 && dd != 0)
                    {
                        decoded[i][0] = table[aa][5];
                        decoded[i][1] = table[aa][dd-1];
                    }
                    else if(dd == 0 && bb != 0)
                    {
                        decoded[i][0] = table[aa][bb-1];
                        decoded[i][1] = table[aa][5];
                    }
                    else
                    {
                        decoded[i][0] = table[aa][bb-1];
                        decoded[i][1] = table[aa][dd-1];
                    }
                }
            }
                if(bb == dd)
                {
                    if(aa == 0)
                    {
                        decoded[i][0] = table[5][bb];
                        decoded[i][1] = table[5][dd];
                    }
                    else
                    {
                        decoded[i][0] = table[aa-1][bb];
                        decoded[i][1] = table[cc-1][dd];
                    }
                }

        }
        str = "";
        for(int pp = 0; pp < ee; pp++)
        {
            yy = decoded[pp][0];
            zz = decoded[pp][1];
            str+=yy;str+=zz;
        }
        // cout<<str<<endl;
        return str;

    }
    int null(string str1,string f)
    {
    ///////////////////////////////////////////////////////////////////
                    ////// text pairing
        int z = f.size(),ff,t,n = 0,mm = 0,y = 0,ss,v;
        int sz = str1.size(),count = 0,count1,count2,o=0;
        //cout << "sz "<<sz<<endl;
        char pltxt1[sz] ,chr;
        str1.copy(pltxt1 , sz);
        for( int i = 0; i<sz; i++)
        {
            if((pltxt1[i] >= 'A' && pltxt1[i]<='Z') || (pltxt1[i]>='0' && pltxt1[i]<='9'))
            {
            count+=1;}
        }
        // cout <<endl;
        count1 = count;
        if(count%2 != 0)
        {
            count+=1;
        }
        count2 = count;
        char pltxt[count2];
        if(count2>count1)
        {
            pltxt[count1] = 'X';
        }
        for( int jj = 0; jj < sz; jj++)
        { chr = pltxt1[jj];
            if((chr >= 'A' && chr<='Z') || (chr>='0' && chr<='9'))
            {
                pltxt[o] = chr;
                o+=1;
            }
        }
        v = 0;
        ff = count2/2;
        //cout<<ff<<endl;
        char wrd[ff][2];
        for(int i = 0; i < ff; i++)
            {
                wrd[i][0] = pltxt[v];
                wrd[i][1] = pltxt[v+1];
                v+=2;
            }

    //////////////////////////////////////////////////////////////////////////

        //////// encoding table
        char upalpha[36-z],code[6][6];
        string alpha;
        alpha = "AB8CD9EF4GHI5JKL6MN7OPQRST1UVW3X2Y0Z";
        for(int p = 0; p < z; p++)
        {
            for(int q = 0; q < 36; q++)
            {
                if(f[p] == alpha[q])
                {
                    alpha[q] = ' ';
                }
            }
        }

        for(int t = 0; t < 36; t++)
        {
            if (alpha[t] != ' ')
            {
                upalpha[y] = alpha[t];
                y+=1;
            }
        }

        // for (int n = 0; n < ff; n++)
        // {
        //     cout << wrd[n][0]<<"  "<<wrd[n][1]<< endl;
        // }

        for(int row = 0; row < 6; row++)
        {
            for(int col = 0; col < 6; col++)
            {
                if(n < f.length())
                {
                    code[row][col] = f[n];
                    n+=1;
                }
                else
                {
                    code[row][col] = upalpha[mm];
                    mm+=1;
                }
            }
        }

        ////// TABLE ///////////////
        // for(int rw = 0; rw<6; rw++)
        // {
        //     for (int cl = 0; cl < 6; cl++){
        //         cout << code[rw][cl]<<"  ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;
        decode(wrd,code,ff);
        return 0;
    }

    void encrytCode(string s)
    {
        string key = "ALI123";
        // key = rpch(key);
        null(s,key);
    }
protected:
    string decrpyted(string s)
    {
        string temp = "";
        for(int i = 0; i<length;i++)
        {
            if(array[i] != 100)
            {
                temp+= s[i] + 32;
            }
            else
            {
                temp+=s[i];
            }
        }
        return temp;
    }
    string getstr(string s)
    {
        encrytCode(s);
        return str;
    }
    void showarray()
    {
        for(int i = 0; i<20; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

};
