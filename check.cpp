#include <stdio.h>
#define MAXLEN 100
#define FALSE 0
#define TRUE 1

int check(char,double);
double powe(double,float);
double to_float(char,double);

double powe(double bas, float step)
{
    double rez=1;
    int i=1;


    if (step>0)
    {
        for (i=1;i<=step;i++)
        {
            rez=bas*rez;
        }
    }


    if (step<0)
    {
        for (i=1;i<=-step;i++)
        {
            rez=rez/bas;
        }
    }


    if (step=0)
    {
        rez=1;
    }

    return rez;
}

double to_float(char str[MAXLEN],double rez)
{
    int dot_pos=0;
    int len=0;
    int j,digit_of_str;


    while (str[len]!='\0')
    {
        if (str[len]=='.')
        {
            dot_pos=len;
        }
        len++;
    }

//printf("%i dgfv \n",len);

//dot_pos=0;


    if (dot_pos==0)
    {
      dot_pos=len;
      str[len]='.';
      str[len+1]='0';

    }

    rez=0;




    for (j=1;j<=len-dot_pos-1;j++)
    {
        digit_of_str=str[j+dot_pos]-'0';
        rez=digit_of_str*powe(10,-j)+rez;
    }

    for (j=0;j<=dot_pos-1;j++)
    {
        digit_of_str=str[dot_pos-j-1]-'0';
        rez=digit_of_str*powe(10,j)+rez;
    }

    return rez;

}


int check(char str[MAXLEN],double *rez)
{
    int flag;
    int i;
    int sign_of_str=1;


    if (str[0]=='-')
    {
        for (i=0;str[i+1]!='\0';i++)
        {
            str[i]=str[i+1];
        }

        str[i]='\0';
        sign_of_str=-1;
    }


    flag=FALSE;
    for (i=0;str[i+1]!='\0';i++)
    {
        if ( (str[i]<'0' || str[i]>'9') && (str[i]!='.') )
        {
            flag=TRUE;
        }
    }


//printf("%i\n",flag);

    if (flag==TRUE)
    {
        return 1;
    } else
    {
        *rez=(-1)*to_float(str,*rez);

        return 0;
    }

}


main ()
{
    char a[MAXLEN];
    double rez;

    gets( a );
    if ( check(a,&rez)==0 )
    {
        printf("%lf", rez);
    }


}
