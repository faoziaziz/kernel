/*
    Author : Aziz Amerul Faozi
*/

#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aziz Amerul Faozi");

static short int myshort =1;
static int myint = 420;
static long int mylong=9999;
static char *mystring = "blah";
static int myintArray[2]={-1, 1};
static int arr_argc = 0;

/*
    module_param(foo, int, 000)
    The first param is the parameters name
    The second param is its data type
    the final argument is the permissions bits
    for exposing parameters in sysfs (if non-zero) at later stage.
*/

module_param(myshort, short, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
MODULE_PARM_DESC(myint, "Sebuah integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARAM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MUDULE_PARAM_DESC(mystring, "A character string");
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARAM_DESC(myintArray, "An array of integer.")

static int __init hello_5_init(void){
    int i;
    printk(KERN_INFO "Hello, world 5 \n===================\n");
    printk(KERN_INFO "myshort is a short integer:  %hd\n", myshort);
    printk(KERN_INFO "myint is an integer : %d\n", myint);
    printk(KERN_INFO "mylong is a long integer %ld\n", mylong);
    for (i=0; i<(sizeof myintArray/sizeof(int)); i++){
        printk(KERN_INFO "myintArray[%d] =%d\n", i, myintArray[i]);
    }
    printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
    return 0;
}

static void __exit hello_5_exit(void){
    printk(KERN_INFO "Goodbye, world 5\n.");
}

module_init(hello_5_init);
module_exit(hello_5_exit);