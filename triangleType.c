#include <stdio.h>
#include <stdbool.h>

typedef enum tType
{
T_INVALID = -1,
T_EQUILATERAL,
T_ISOSCELES,
T_SCALENE
} TType;

#define NUM_TEST_CASES 5

//INPUT: the lengths of the triangle's three sides
//OUTPUT: the type of a triangle
TType triangleType(int a, int b, int c)
{
    if((a+b)>c && (b+c)>a && (a+c)>b 
       && a>0 && b>0 && c>0)
    {
        if(a==b && b==c)
        {
            return T_EQUILATERAL;
        }
        else if(a==b || b==c || a==c)
        {
            return T_ISOSCELES;
        }
        else
        {
            return T_SCALENE;
        }
    }
    return T_INVALID;
}

bool validate(int a, int b, int c, TType expected)
{
    if(triangleType(a,b,c) == expected)
    {
        printf("Test %d %d %d passes\n", a, b, c);
        return true;
    }
    printf("Test %d %d %d failes\n", a, b, c);
    return false;
}

int main()
{
    int passes=0;
    int test_cases[NUM_TEST_CASES][4] =
    {
       {5,5,5,T_EQUILATERAL},
       {5,8,5,T_ISOSCELES},
       {-1,5,5,T_INVALID},
       {100,5,5,T_INVALID},
       {0,5,5,T_INVALID}
    };
    for(int i=0; i<NUM_TEST_CASES; i++)
    {
        if(validate(test_cases[i][0],test_cases[i][1],test_cases[i][2],
               test_cases[i][3]) == true)
        {
            passes++;
        }
    }
    printf("%d out of %d passes!\n", passes, NUM_TEST_CASES);
    return 0;
}
