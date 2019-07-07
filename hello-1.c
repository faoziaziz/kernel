/*
    Author Aiz
*/

#include<linux/module.h>
#include<linux/kernel.h>

int init_module(){
    printk(KERN_INFO "Hello world 1. \n");
    return 0;
}

void celanup_module(void){
    printk(KERN_INFO "Goodbye world 1. \n");
}