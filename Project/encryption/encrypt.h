#include <iostream>
#include <stdio.h>

using namespace std;


class encrypt
{

protected:
    string plaintxt;
    int length;
    int array[15];

    string encode(char wd[][2] ,char cd[6][6],int ee)
    {
        int aa,bb,cc,dd;
        char encoded[ee][2],l1,l2,k1,k2,zz,yy;

        for(int i = 0; i < ee;i++)
        {
            l1 = wd[i][0];
            l2 = wd[i][1];
            // cout << l1<<" "<<l2<<" ";
            for(int j = 0; j < 6; j++)
            {

                for(int k = 0; k < 6; k++)
                {
                    if(l1 == cd[j][k])
                    {
                        aa = j;
                        bb = k;
                        //cout<<aa<<" "<<bb<<endl;
                    }
                    else if(l2 == cd[j][k])
                    {
                        cc = j;
                        dd = k;
                        //cout<<cc<<" "<<dd<<endl;
                    }
                }
            }

            if(l1 != l2)
            {
                if(aa != cc && bb != dd)
                {
                    encoded[i][0] = cd[cc][bb];
                    encoded[i][1] = cd[aa][dd];
                }
                if(aa == cc && bb != dd)
                {
                    if(bb == 5 && dd != 5)
                    {
                        encoded[i][0] = cd[aa][0];
                        encoded[i][1] = cd[aa][dd+1];
                    }
                    else if(dd == 5 && bb != 5)
                    {
                        encoded[i][0] = cd[aa][bb+1];
                        encoded[i][1] = cd[aa][0];
                    }
                    else
                    {
                        encoded[i][0] = cd[aa][bb+1];
                        encoded[i][1] = cd[aa][dd+1];
                    }
                }
                if(aa != cc && bb == dd)
                {
                     if(aa == 5 && cc != 5)
                    {
                        encoded[i][0] = cd[0][bb];
                        encoded[i][1] = cd[cc+1][dd];
                    }
                    else if(cc == 5 && aa != 5)
                    {
                        encoded[i][0] = cd[aa+1][bb];
                        encoded[i][1] = cd[0][dd];
                    }
                    else
                    {
                        encoded[i][0] = cd[aa+1][bb];
                        encoded[i][1] = cd[cc+1][dd];
                    }
                }
            }

            if(l1 == l2)
            {
                if( bb == 4)
                {
                    encoded[i][0] = cd[aa][5];
                    encoded[i][1] = cd[aa][0];
                }
                if( bb == 5 )
                {
                    encoded[i][0] = cd[aa][0];
                    encoded[i][1] = cd[aa][1];
                }
                if(bb == 0 || bb == 1 || bb == 2)
                {
                    encoded[i][0] = cd[aa][bb+1];
                    encoded[i][1] = cd[aa][bb+2];
                }
            }
        }
        //cout << endl;
        plaintxt = "";
        for(int pp = 0; pp < ee; pp++)
        {
            yy = encoded[pp][0];
            zz = encoded[pp][1];
            plaintxt+=yy; plaintxt+=zz;
        }
        // cout<<plaintxt<<endl;

        return plaintxt;
    }

    // string rmch(string line1)
    // {
    //     ////// remove extra characters    /// data for decrpyt
    //     for(int i = 0; i < line1.size(); ++i)
    //     {
    //         if (!((line1[i] >= 'a' && line1[i]<='z') || (line1[i] >= 'A' && line1[i]<='Z') || (line1[i]>='0' && line1[i]<='9')))
    //         {
    //             line1[i] = '\0';
    //         }
    //     }
    //
    //     //cout << "Output String: " << line1<<endl;
    //     return line1;
    // }

    string upcs(string line2)
    {
        /// upper case     ////// data for decrypt

        for(int k = 0; k < line2.size(); k++)
        {
            if (line2[k] >= 'a' && line2[k] <= 'z')
            {
                array[k] = k;
                line2[k] = line2[k] - 32;
            }
            else
            {
                array[k] = 100;
            }
        }
        //cout << "upper: "<<line2 << endl;
        return line2;
    }
    string rpch(string line)
    {
        ///remove repeated char        ///// data for decrpyt
        string str;
        for(int j = 0; j < line.size(); j++ )
        {
            for(int jj = j+1; jj < line.size(); jj++ )
            {
                if(line[j] == line[jj])
                {
                    line[jj] = '\0';
                }
            }
            if(j == 0 )
            {
                str = line[j];
            }
            else if(line[j] != '\0')
            {
                str+=line[j];
            }
        }
        return str;
    }

    void null(string str1,string f)
    {
    ///////////////////////////////////////////////////////////////////
                    ////// text pairing
        int z = f.size(),ff,t,n = 0,mm = 0,y = 0,ss,v;
        int sz = str1.size(),count = 0,count1,count2,o=0;
        //cout << "sz "<<sz<<endl;
        char pltxt1[sz] ,chr;
        str1.copy(pltxt1 , sz);
        for( int ii = 0; ii<sz; ii++)
        {
            if(pltxt1[ii] >= 'A' && pltxt1[ii]<='Z')
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
            if(chr >= 'A' && chr<='Z')
            {
                pltxt[o] = chr;
                o+=1;
            }
        }
        // for( int kk = 0; kk<count2; kk++)
        // {

        //     cout<<pltxt[kk];
        // }
        // cout<<endl;


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
        ///////   T A B L E /////////
        // for(int rw = 0; rw<6; rw++)
        // {
        //     for (int cl = 0; cl < 6; cl++){
        //         cout << code[rw][cl]<<"  ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;
        encode(wrd,code,ff);
        return;
    }
    void encrytCode(string s)
    {
        string plaintxt = s, key = "ALI123";
        length = plaintxt.size();
        key = upcs(key);
        plaintxt = upcs(s);
        key = rpch(key);
        null(plaintxt,key);
    }

    string getSTR(string st)
    {
        encrytCode(st);
        return plaintxt;
    }
    encrypt()
    {
        for(int i = 0; i<15; i++ )
        {
            array[i] = 111;
        }
    }
    ~encrypt()
    {}

};
