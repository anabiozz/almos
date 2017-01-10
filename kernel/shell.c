#include "vidar/shell.h"
#include "screen.h"
#include "system.h"
#include "drivers/keyboard.h"
#include "common/util.h"
#include "strings/string.h"

void launch_shell(int n)
{
    string ch = (string) malloc(200);
    int counter = 0;
    do {
        print("OS (");
        print(int_to_string(n));
        print(")>");
        ch = read_str();
        if(strcmp(ch, "cmd"))
        {
            print("\nYou are allready in cmd. A new recursive shell is opened\n");
            launch_shell(n+1);
        }
        else if(strcmp(ch, "clear")) clear_screen();
        else if(strcmp(ch, "sum")) sum();
        else if(strcmp(ch, "exit")) print("\nGood Bye!\n");
        else if(strcmp(ch, "echo")) echo();
        else
        {
            print("\nBad command\n");
            print("OS> ");
        }
    } while(!strcmp(ch, "exit"));
}

void sum()
{
    print("\nHow many numbers: ");
    int n = str_to_int(read_str());
    int i = 0;
    print("\n");
    int arr[n];
    fill_array(arr,n);
    int s = sum_array(arr,n);
    print("result: ");
    print(int_to_string(s));
    print("\n");
}

void echo()
{
    print("\n");
    string s = read_str();
    print("\n");
    print(s);
    print("\n");
}

void fill_array(int arr[],int n)
{
    int i = 0;
    for (i = 0;i<n;i++)
    {
        print("ARR[");
        print(int_to_string(i));
        print("]: ");
        arr[i] = str_to_int(read_str());
        print("\n");
    }
}

int sum_array(int arr[],int n)
{
    int i = 0;
    int s = 0;
    for (i = 0;i<n;i++)
    {
        s += arr[i];
    }
    return s;
}